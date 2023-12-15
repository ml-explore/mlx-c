import cxxheaderparser
from cxxheaderparser.simple import parse_string
import argparse

parser = argparse.ArgumentParser("MLX C bindings generator", add_help=False)
parser.add_argument("--header", type=str)
parser.add_argument("--implementation", default=False, action="store_true")
args = parser.parse_args()

Z = cxxheaderparser.simple.parse_file(args.header)


def getname(t):
    if type(t) == cxxheaderparser.types.TemplateArgument:
        return getname(t.arg)
    elif type(t) == cxxheaderparser.types.Reference:
        return getname(t.ref_to)
    elif type(t) == cxxheaderparser.types.PQName:
        res = []
        for s in t.segments:
            res.append(getname(s))
        return "::".join(res)
    elif type(t) == cxxheaderparser.types.FundamentalSpecifier:
        return t.name
    elif type(t) == cxxheaderparser.types.NameSpecifier:
        res = t.name
        if t.specialization is not None:
            res += getname(t.specialization)
        return res
    elif type(t) == cxxheaderparser.types.Type:
        return getname(t.typename)
    elif type(t) == cxxheaderparser.types.TemplateSpecialization:
        res = []
        for s in t.args:
            res.append(getname(s))
        return "<" + ", ".join(res) + ">"

    raise "unsupported type: " + t


funcs = {}
l = Z.namespace.namespaces["mlx"].namespaces["core"]
for f in l.functions:
    name = getname(f.name)
    if name.startswith("operator"):
        continue
    params_t = []
    params_name = []
    return_t = getname(f.return_type)
    if return_t == "Stream":  # unsupported
        continue
    for p in f.parameters:
        params_t.append(getname(p.type))
        params_name.append(p.name)
    func = {
        "name": name,
        "params_t": params_t,
        "params_name": params_name,
        "return_t": return_t,
    }
    if name in funcs:
        funcs[name].append(func)
    else:
        funcs[name] = [func]

sorted_funcs = []
for name in funcs:
    variants = funcs[name]
    if len(variants) == 1:
        sorted_funcs.append(variants[0])
    else:
        variants.sort(key=lambda x: len(x["params_name"]), reverse=True)

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
        elif (
            "axes" in variants[0]["params_name"] or "axis" in variants[0]["params_name"]
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

if args.implementation:
    print(
        """
#include "mlx/c/ops.h"
#include "mlx/c/private/array.h"
#include "mlx/c/private/stream.h"
#include "mlx/c/private/utils.h"

"""
    )
else:
    print(
        """
#ifndef MLX_OPS_H
#define MLX_OPS_H

#include <stdio.h>

#include "mlx/c/array.h"
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
    elif return_t == "std::vector<array>":
        signature.append("mlx_array*")
    else:
        raise RuntimeError("unsupported return type: " + return_t)
    if "variant" in f:
        signature.append("mlx_" + f["name"] + "_" + f["variant"])
    else:
        signature.append("mlx_" + f["name"])
    signature.append("(")

    c_call = []
    cpp_call = []
    pt = f["params_t"]
    pn = f["params_name"]
    for i in range(len(pt)):
        pti = pt[i]
        pni = pn[i]
        if pti == "array":
            c_call.append("mlx_array " + pni)
            cpp_call.append(pni + "->ctx")
        elif pti == "StreamOrDevice":
            c_call.append("mlx_stream " + pni)
            cpp_call.append(pni + "->ctx")
        elif pti == "Dtype":
            c_call.append("mlx_array_dtype " + pni)
            cpp_call.append("MLX_CPP_ARRAY_DTYPE(" + pni + ")")
        elif pti == "bool" or pti == "double" or pti == "int" or pti == "size_t":
            c_call.append(pti + " " + pni)
            cpp_call.append(pni)
        elif pti == "std::vector<int>":
            c_call.append("int* " + pni)
            c_call.append("size_t num_" + pni)
            cpp_call.append("MLX_CPP_INTVEC(" + pni + ", num_" + pni + ")")
        elif pti == "std::vector<size_t>":
            c_call.append("size_t* " + pni)
            c_call.append("size_t num_" + pni)
            cpp_call.append("MLX_CPP_SIZEVEC(" + pni + ", num_" + pni + ")")
        elif pti == "std::vector<array>":
            c_call.append("mlx_array* " + pni)
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
        else:
            raise RuntimeError("unsupported type: " + pti)
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
    else:
        raise RuntimeError("unsupported return type: " + return_t)

    cpp_code.append("(")
    cpp_code.append("mlx::core::" + f["name"])
    cpp_code.append("(")
    cpp_code.append(cpp_call)
    cpp_code.append(")")
    cpp_code.append(")")
    cpp_code.append(";")
    cpp_code.append("}")
    if args.implementation:
        print(" ".join(cpp_code))
    else:
        print(" ".join(c_code))

if args.implementation:
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
