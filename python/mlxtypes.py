import string

types = []

for t in [
    ["mlx_vector_array", "std::vector<mlx::core::array>"],
    [
        "mlx_tuple_vector_array_vector_array",
        "std::pair<std::vector<mlx::core::array>, std::vector<mlx::core::array>>",
    ],
    ["mlx_vector_int", "std::vector<int>"],
    ["mlx_vector_vector_int", "std::vector<std::vector<int>>"],
    [
        "mlx_tuple_vector_array_vector_int",
        "std::pair<std::vector<mlx::core::array>, std::vector<int>>",
    ],
    ["mlx_vector_array_dtype", "std::vector<mlx::core::Dtype>"],
    ["mlx_tuple_int_int_int", "std::tuple<int, int, int>"],
    [
        "mlx_vector_tuple_string_variant_int_bool_array_dtype",
        "std::vector<std::pair<std::string, mlx::core::fast::TemplateArg>>",
    ],
    [
        "mlx_stream",
        "mlx::core::Stream",
    ],
]:
    ctype, cpptype = t
    types.append(
        {
            "c": ctype,
            "cpp": cpptype,
            "free": lambda s: "mlx_free(" + s + ")",
            "cpp_to_c": lambda s, ctype=ctype: "new " + ctype + "_(" + s + ")",
            "c_to_cpp": lambda s: s + "->ctx",
            "return": lambda s: "RETURN_MLX_C_PTR(" + s + ")",
            "c_arg": lambda s, ctype=ctype: ("const " + ctype + " " + s).strip(),
            "cpp_arg": lambda s, cpptype=cpptype: (
                "const " + cpptype + "& " + s
            ).strip(),
        }
    )

for ctype in ["float", "bool"]:
    types.append(
        {
            "c": ctype,
            "cpp": ctype,
            "free": lambda s: "",
            "cpp_to_c": lambda s: s,
            "c_to_cpp": lambda s: s,
            "return": lambda s: "return" + s,
            "c_arg": lambda s, ctype=ctype: (ctype + " " + s).strip(),
            "cpp_arg": lambda s, ctype=ctype: (ctype + " " + s).strip(),
        }
    )

ctypes = {}
for t in types:
    ctype = t["c"]
    ctypes[ctype] = t
