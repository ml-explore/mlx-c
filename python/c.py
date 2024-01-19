import sys


def generate(funcs, headername, namespace, implementation):
    namespace_prefix = namespace.split("::")
    if namespace_prefix[0] == "mlx" and namespace_prefix[1] == "core":
        namespace_prefix.pop(1)  # we pop core
    namespace_prefix = "_".join(namespace_prefix)

    sorted_funcs = []
    for name in funcs:
        variants = funcs[name]
        if len(variants) == 1:
            sorted_funcs.append(variants[0])
        else:
            variants.sort(key=lambda x: len(x["params_name"]), reverse=True)

            if name != "all":
                idx = 0
                while idx < len(variants) - 1:
                    pidx = variants[idx]["params_name"]
                    pidxp1 = variants[idx + 1]["params_name"]
                    mpidx = [p if p != "axis" else "axes" for p in pidx]
                    mpidxp1 = [p if p != "axis" else "axes" for p in pidxp1]
                    if mpidx == mpidxp1:
                        if pidx == mpidx:
                            variants.pop(idx + 1)
                        else:
                            variants.pop(idx)
                    else:
                        idx = idx + 1

            if len(variants) == 1:
                sorted_funcs.append(variants[0])
            elif name == "split":
                var0 = variants[0]
                var1 = variants[1]
                var0["variant"] = "equal_parts"
                sorted_funcs.append(var0)
                sorted_funcs.append(var1)
            elif name == "pad":
                sorted_funcs.append(variants[0])
            elif name == "all":
                variants[0]["variant"] = "axes"
                variants[1]["variant"] = "axis"
                variants[2]["variant"] = "all"
                sorted_funcs.append(variants[0])
                sorted_funcs.append(variants[1])
                sorted_funcs.append(variants[2])
            elif name == "categorical":
                variants[0]["variant"] = "shape"
                variants[1]["variant"] = "num_samples"
                sorted_funcs.append(variants[0])
                sorted_funcs.append(variants[1])
                sorted_funcs.append(variants[2])
            elif (
                "axes" in variants[0]["params_name"]
                or "axis" in variants[0]["params_name"]
            ) and (
                "axes" not in variants[1]["params_name"]
                and "axis" not in variants[1]["params_name"]
            ):
                var0 = variants[0]
                var1 = variants[1]
                var1["variant"] = "all"
                sorted_funcs.append(var0)
                sorted_funcs.append(var1)
            else:
                sorted_funcs.append(variants[0])  # abandon

    sorted_funcs.sort(key=lambda x: x["name"])

    if implementation:
        print('#include "mlx/c/' + headername + '.h"')
        print(
            """
    #include "mlx/c/private/array.h"
    #include "mlx/c/private/closure.h"
    #include "mlx/c/private/stream.h"
    #include "mlx/c/private/utils.h"

    """
        )
    else:
        print("#ifndef MLX_" + headername.upper() + "_H")
        print("#define MLX_" + headername.upper() + "_H")
        print(
            """
    #include <stdio.h>

    #include "mlx/c/array.h"
    #include "mlx/c/closure.h"
    #include "mlx/c/stream.h"

    #ifdef __cplusplus
    extern "C" {
    #endif
    """
        )

    for f in sorted_funcs:
        # print(f["return_t"])
        signature = []
        return_t = f["return_t"]
        if return_t == "void":
            signature.append("void")
        elif return_t == "array":
            signature.append("mlx_array")
        elif (
            return_t == "std::vector<array>"
            or return_t == "std::pair<array, array>"
            or return_t == "std::tuple<array, array, array>"
        ):
            signature.append("mlx_vector_array")
        elif return_t == "std::pair<std::vector<array>, std::vector<array>>":
            signature.append("mlx_vector_vector_array")
        elif return_t == "std::function<std::vector<array>(std::vector<array>)>":
            signature.append("mlx_closure")
        elif return_t == "ValueAndGradFn":
            signature.append("mlx_closure_value_and_grad")
        else:
            print("unsupported return type: " + return_t, file=sys.stderr)
            print("skipping", f, file=sys.stderr)
            continue
        if "variant" in f:
            signature.append(namespace_prefix + "_" + f["name"] + "_" + f["variant"])
        else:
            signature.append(namespace_prefix + "_" + f["name"])
        signature.append("(")

        c_call = []
        cpp_call = []
        pt = f["params_t"]
        pn = f["params_name"]
        encountered_unsupported_type = False
        for i in range(len(pt)):
            pti = pt[i]
            pni = pn[i]
            if pti == "array":
                c_call.append("mlx_array " + pni)
                cpp_call.append(pni + "->ctx")
            elif pti == "std::optional<array>":
                c_call.append("mlx_array " + pni)
                cpp_call.append(
                    "("
                    + pni
                    + " ? std::make_optional("
                    + pni
                    + "->ctx) : std::nullopt)"
                )
            elif pti == "StreamOrDevice":
                c_call.append("mlx_stream " + pni)
                cpp_call.append(pni + "->ctx")
            elif pti == "Dtype":
                c_call.append("mlx_array_dtype " + pni)
                cpp_call.append("MLX_CPP_ARRAY_DTYPE(" + pni + ")")
            elif (
                pti == "bool"
                or pti == "double"
                or pti == "int"
                or pti == "size_t"
                or pti == "uint64_t"
            ):
                c_call.append(pti + " " + pni)
                cpp_call.append(pni)
            elif pti == "std::vector<int>":
                c_call.append("const int* " + pni)
                c_call.append("size_t num_" + pni)
                cpp_call.append("MLX_CPP_INTVEC(" + pni + ", num_" + pni + ")")
            elif pti == "std::vector<size_t>":
                c_call.append("const size_t* " + pni)
                c_call.append("size_t num_" + pni)
                cpp_call.append("MLX_CPP_SIZEVEC(" + pni + ", num_" + pni + ")")
            elif pti == "std::vector<array>":
                c_call.append("const mlx_array* " + pni)
                c_call.append("size_t num_" + pni)
                cpp_call.append("MLX_CPP_ARRVEC(" + pni + ", num_" + pni + ")")
            elif pti == "std::pair<int, int>":
                c_call.append("int f_" + pni)
                c_call.append("int s_" + pni)
                cpp_call.append("MLX_CPP_INTPAIR(f_" + pni + ", s_" + pni + ")")
            elif pti == "std::shared_ptr<io::Reader>":
                c_call.append("FILE* " + pni)
                cpp_call.append("MLX_CPP_READER(" + pni + ")")
            elif pti == "std::shared_ptr<io::Writer>":
                c_call.append("FILE* " + pni)
                cpp_call.append("MLX_CPP_WRITER(" + pni + ")")
            elif pti == "std::function<std::vector<array>(std::vector<array>)>":
                c_call.append("mlx_closure " + pni)
                cpp_call.append("MLX_CPP_CLOSURE(" + pni + ")")
            else:
                print("unsupported type: " + pti, file=sys.stderr)
                encountered_unsupported_type = True
                break

        if encountered_unsupported_type:
            print("skipping", f, file=sys.stderr)
            continue

        # print(f)
        c_call = ", ".join(c_call)
        cpp_call = ", ".join(cpp_call)
        signature.append(c_call)
        signature.append(")")
        signature = " ".join(signature)

        c_code = [signature, ";"]
        cpp_code = ['extern "C"', signature, "{", "return"]

        if return_t == "void":
            cpp_code.append("MLX_C_VOID")
        elif return_t == "array":
            cpp_code.append("MLX_C_ARRAY")
        elif return_t == "std::vector<array>":
            cpp_code.append("MLX_C_ARRAYS")
        elif return_t == "std::pair<array, array>":
            cpp_code.append("MLX_C_ARRAYPAIR")
        elif return_t == "std::tuple<array, array, array>":
            cpp_code.append("MLX_C_ARRAYTUPLE3")
        elif return_t == "std::pair<std::vector<array>, std::vector<array>>":
            cpp_code.append("MLX_C_VECTORARRAYPAIR")
        elif return_t == "std::function<std::vector<array>(std::vector<array>)>":
            cpp_code.append("MLX_C_CLOSURE")
        elif return_t == "ValueAndGradFn":
            cpp_code.append("MLX_C_CLOSURE_VALUE_AND_GRAD")
        else:
            print("unsupported return type: " + return_t, file=sys.stderr)
            print("skipping", f, file=sys.stderr)
            continue

        cpp_code.append("(")
        cpp_code.append(namespace + "::" + f["name"])
        cpp_code.append("(")
        cpp_code.append(cpp_call)
        cpp_code.append(")")
        cpp_code.append(")")
        cpp_code.append(";")
        cpp_code.append("}")
        if implementation:
            print(" ".join(cpp_code))
        else:
            print(" ".join(c_code))

    if implementation:
        pass
    else:
        print(
            """
    #ifdef __cplusplus
    }
    #endif

    #endif
    """
        )
