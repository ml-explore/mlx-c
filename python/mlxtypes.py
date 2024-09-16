import string

types = []

for t in [
    ["mlx_array", "mlx::core::array", "array"],
    ["mlx_vector_array", "std::vector<mlx::core::array>", "std::vector<array>"],
    [
        "mlx_tuple_array_array",
        "std::pair<mlx::core::array, mlx::core::array>",
        "std::pair<array, array>",
    ],
    [
        "mlx_tuple_array_array_array",
        "std::tuple<mlx::core::array, mlx::core::array, mlx::core::array>",
        "std::tuple<array, array, array>",
    ],
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
    [
        "mlx_map_string_to_variant_string_size_t",
        "std::unordered_map<std::string, std::variant<std::string, size_t>>",
    ],
    [
        "mlx_closure",
        "std::function<std::vector<array>(std::vector<array>)>",
    ],
    [
        "mlx_closure_value_and_grad",
        "mlx::core::fast::ValueAndGradFn",
        "ValueAndGradFn",
    ],
    [
        "mlx_closure_metal_kernel_function",
        "mlx::core::fast::MetalKernelFunction",
        "MetalKernelFunction",
    ],
    [
        "mlx_tuple_vector_array_vector_array",
        "std::pair<std::vector<mlx::core::array>, std::vector<mlx::core::array>>",
        "std::pair<std::vector<array>, std::vector<array>>",
    ],
]:
    if len(t) == 2:
        ctype, cpptype = t
        alt = None
    else:
        ctype, cpptype, alt = t
    types.append(
        {
            "c": ctype,
            "cpp": cpptype,
            "alt": alt,
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

for ctype in ["void", "size_t", "float", "bool"]:
    types.append(
        {
            "c": ctype,
            "cpp": ctype,
            "alt": None,
            "free": lambda s: "",
            "cpp_to_c": lambda s: s,
            "c_to_cpp": lambda s: s,
            "return": lambda s: "return" + s,
            "c_arg": lambda s, ctype=ctype: (ctype + " " + s).strip(),
            "cpp_arg": lambda s, ctype=ctype: (ctype + " " + s).strip(),
        }
    )
    types.append(
        {
            "c": "mlx_optional_" + ctype,
            "cpp": "std::optional<" + ctype + ">",
            "alt": None,
            "free": lambda s: "",
            "cpp_to_c": lambda s, ctype=ctype: "("
            + s
            + ".has_value() ? mlx_optional_"
            + ctype
            + "_"
            + "({"
            + s
            + ".value(), true}) : mlx_optional_"
            + ctype
            + "_({0, false}))",
            "c_to_cpp": lambda s, ctype=ctype: "("
            + s
            + ".has_value ? std::make_optional<"
            + ctype
            + ">("
            + s
            + ".value) : std::nullopt)",
            "return": lambda s: "return" + s,
            "c_arg": lambda s, ctype=ctype: ("mlx_optional_" + ctype + " " + s).strip(),
            "cpp_arg": lambda s, ctype=ctype: (
                "std::optional<" + ctype + "> " + s
            ).strip(),
        }
    )

ctypes = {}
cpptypes = {}
alttypes = {}
for t in types:
    ctype = t["c"]
    ctypes[ctype] = t

    cpptype = t["cpp"]
    cpptypes[cpptype] = t

    alttype = t["alt"]
    if alttype:
        alttypes[alttype] = t
