import string

types = []

for t in [
    ["mlx_array", "mlx::core::array", "array"],
    ["mlx_vector_int", "@std::vector<int>", "@std::vector<int>"],
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
            "c_arg": lambda s, untyped=False, ctype=ctype: s
            if untyped
            else ("const " + ctype + " " + s).strip(),
            "c_return_arg": lambda s, untyped=False, ctype=ctype: (
                ("" if untyped else ctype + " ") + s
            ).strip(),
            "c_new": lambda s, ctype=ctype: "auto " + s + " = new " + ctype + "_()",
            "cpp_arg": lambda s, cpptype=cpptype: (
                "const " + cpptype.replace("@", "") + "& " + s
            ).strip(),
        }
    )


def find_cpp_type(cpp_type):
    for t in types:
        if t["cpp"] == cpp_type:
            return t
    raise RuntimeError("Could not find type " + cpp_type)


def register_raw_array_type(cpptype):
    types.append(
        {
            # "c": "mlx_vector_" + cpptype, # DEBUG: ONLY FOR RETURN?
            # "alt": "std::vector<" + cpptype + ">", # DEBUG: ONLY FOR RETURN?
            "cpp": "std::vector<" + cpptype + ">",
            "free": lambda s: "",
            # "cpp_to_c": lambda s, ctype=ctype: "new " + ctype + "_(" + s + ")",
            "c_to_cpp": lambda s, cpptype=cpptype: "std::vector<"
            + cpptype
            + ">("
            + s
            + ", "
            + s
            + " + "
            + s
            + "_num"
            + ")",
            # "return": lambda s: "RETURN_MLX_C_PTR(" + s + ")",
            "c_assign_from_cpp": lambda d, s: d
            + " = "
            + s
            + ".data(); "
            + d
            + "_num = "
            + s
            + ".size()",
            "c_arg": lambda s, untyped=False, cpptype=cpptype: (s + ", " + s + "_num")
            if untyped
            else ("const " + cpptype + "* " + s + ", size_t " + s + "_num").strip(),
            "c_new": lambda s, cpptype=cpptype: "const "
            + cpptype
            + "* "
            + s
            + "= nullptr;  size_t "
            + s
            + "_num = 0",
            # "c_return_arg": lambda s, untyped=False, ctype=ctype: (
            #     ("" if untyped else ctype + " ") + s
            # ).strip(),
            # "c_new": lambda s, ctype=ctype: "auto " + s + " = new " + ctype + "_()",
            "cpp_arg": lambda s, cpptype=cpptype: (
                "const std::vector<" + cpptype + ">& " + s
            ).strip()
            # ).strip(),
        }
    )


register_raw_array_type("int")


def register_return_tuple_type(cpp_types, alts=[]):
    n = len(cpp_types)
    c_types = []
    alt_types = []
    c_to_cpps = []
    for cpp_type in cpp_types:
        typedef = find_cpp_type(cpp_type)
        c_types.append(typedef["c"])
        alt_types.append(typedef["alt"])
        c_to_cpps.append(typedef["c_to_cpp"])
    cpp_tuple = "std::pair" if n == 2 else "std::tuple"
    types.append(
        {
            "cpp": cpp_tuple + "<" + ", ".join(cpp_types) + ">",
            "alt": [cpp_tuple + "<" + ", ".join(alt_types) + ">"] + alts,
            "c_to_cpp": lambda s: "std::tie("
            + ", ".join([c_to_cpps[i](s + "_" + str(i)) for i in range(n)])
            + ")",
            "c_return_arg": lambda s, untyped=False: ", ".join(
                [
                    ("" if untyped else c_types[i])
                    + (" " + s + "_" + str(i) if s else "")
                    for i in range(n)
                ]
            ),
            "c_new": lambda s: "\n".join(
                [
                    "auto " + s + "_" + str(i) + " = new " + ctype + "_();"
                    for i, ctype in enumerate(c_types)
                ]
            ),
            "free": lambda s: "\n".join(
                ["mlx_free(" + s + "_" + str(i) + ");" for i in range(n)]
            ),
            "c_assign_from_cpp": lambda d, s: "std::tie("
            + ", ".join([d + "_" + str(i) + "->ctx" for i in range(n)])
            + ") = "
            + s,
        }
    )


# raw_cpp_type = "int"
# types.append(
#     {
#         "cpp": "@std::vector<" + raw_cpp_type + ">",
#         "alt": "@std::vector<" + raw_cpp_type + ">",
#         "c_to_cpp": lambda s: s + "->ctx",
#         "c_return_arg": lambda s, untyped=False: (
#             ("" if untyped else "mlx_vector_" + raw_cpp_type + " ") + s
#         ).strip(),
#         "c_new": lambda s: "\n".join(
#             [
#                 "auto " + s + "_" + str(i) + " = new " + ctype + "_();"
#                 for i, ctype in enumerate(c_types)
#             ]
#         ),
#         "free": lambda s: "\n".join(
#             ["mlx_free(" + s + "_" + str(i) + ");" for i in range(n)]
#         ),
#         "c_assign_from_cpp": lambda d, s: "std::tie("
#         + ", ".join([d + "_" + str(i) + "->ctx" for i in range(n)])
#         + ") = "
#         + s,
#     }

register_return_tuple_type(["mlx::core::array", "mlx::core::array"])
register_return_tuple_type(["mlx::core::array", "mlx::core::array", "mlx::core::array"])
register_return_tuple_type(
    ["std::vector<mlx::core::array>", "std::vector<mlx::core::array>"]
)
register_return_tuple_type(["std::vector<mlx::core::array>", "@std::vector<int>"])
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

for ctype in ["int", "size_t", "float", "bool"]:
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
