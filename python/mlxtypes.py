import string

types = []

for t in [
    ["mlx_array", "mlx::core::array", "array"],
    ["mlx_vector_array", "std::vector<mlx::core::array>", "std::vector<array>"],
    [
        "mlx_stream",
        "mlx::core::Stream",
    ],
    [
        "mlx_map_string_to_array",
        "std::unordered_map<std::string, mlx::core::array>",
        "std::unordered_map<std::string, array>",
    ],
    [
        "mlx_map_string_to_string",
        "std::unordered_map<std::string, std::string>",
        "std::unordered_map<std::string, std::string>",
    ],
    [
        "mlx_stream",
        "mlx::core::Stream",
    ],
    [
        "mlx_closure",
        "std::function<std::vector<array>(std::vector<array>)>",
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
            "c_assign_from_cpp": lambda d, s: d + "->ctx = " + s,
            "c_arg": lambda s, ctype=ctype: ("const " + ctype + " " + s).strip(),
            "c_return_arg": lambda s, ctype=ctype: (ctype + " " + s).strip(),
            "cpp_arg": lambda s, cpptype=cpptype: (
                "const " + cpptype + "& " + s
            ).strip(),
        }
    )


def find_cpp_type(cpp_type):
    for t in types:
        if t["cpp"] == cpp_type:
            return t
    raise RuntimeError("Could not find type " + cpp_type)


def register_return_tuple_type(cpp_types, alts=[]):
    n = len(cpp_types)
    c_types = []
    alt_types = []
    for cpp_type in cpp_types:
        typedef = find_cpp_type(cpp_type)
        c_types.append(typedef["c"])
        alt_types.append(typedef["alt"])
    cpp_tuple = "std::pair" if n == 2 else "std::tuple"
    types.append(
        {
            "cpp": cpp_tuple + "<" + ", ".join(cpp_types) + ">",
            "alt": [cpp_tuple + "<" + ", ".join(alt_types) + ">"] + alts,
            "c_return_arg": lambda s: ", ".join(
                [c_types[i] + " " + s + "_" + str(i) for i in range(n)]
            ),
            "c_assign_from_cpp": lambda d, s: "std::tie("
            + ", ".join([d + "_" + str(i) + "->ctx" for i in range(n)])
            + ") = "
            + s,
        }
    )


register_return_tuple_type(["mlx::core::array", "mlx::core::array"])
register_return_tuple_type(["mlx::core::array", "mlx::core::array", "mlx::core::array"])
register_return_tuple_type(
    ["std::vector<mlx::core::array>", "std::vector<mlx::core::array>"]
)
register_return_tuple_type(
    [
        "std::unordered_map<std::string, mlx::core::array>",
        "std::unordered_map<std::string, std::string>",
    ],
    ["SafetensorsLoad"],
)

types.append(
    {
        "cpp": "void",
        "c_return_arg": lambda s: "",
        "c_assign_from_cpp": lambda d, s: s,
    }
)

for ctype in ["size_t", "float", "bool"]:
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
            "c_return_arg": lambda s, ctype=ctype: ctype + "* " + s,
            "c_assign_from_cpp": lambda d, s: "*" + d + " = " + s,
        }
    )
#     types.append(
#         {
#             "c": "mlx_optional_" + ctype,
#             "cpp": "std::optional<" + ctype + ">",
#             "alt": None,
#             "free": lambda s: "",
#             "cpp_to_c": lambda s, ctype=ctype: "("
#             + s
#             + ".has_value() ? mlx_optional_"
#             + ctype
#             + "_"
#             + "({"
#             + s
#             + ".value(), true}) : mlx_optional_"
#             + ctype
#             + "_({0, false}))",
#             "c_to_cpp": lambda s, ctype=ctype: "("
#             + s
#             + ".has_value ? std::make_optional<"
#             + ctype
#             + ">("
#             + s
#             + ".value) : std::nullopt)",
#             "return": lambda s: "return" + s,
#             "c_arg": lambda s, ctype=ctype: ("mlx_optional_" + ctype + " " + s).strip(),
#             "cpp_arg": lambda s, ctype=ctype: (
#                 "std::optional<" + ctype + "> " + s
#             ).strip(),
#         }
#     )

ctypes = {}
cpptypes = {}
alttypes = {}
for t in types:
    if "c" in t:
        ctype = t["c"]
        ctypes[ctype] = t

    if "cpp" in t:
        cpptype = t["cpp"]
        cpptypes[cpptype] = t

    if "alt" in t:
        alts = t["alt"]
        if alts is not None:
            if isinstance(alts, str):
                alts = [alts]
            for alttype in alts:
                alttypes[alttype] = t
