# Copyright © 2023-2024 Apple Inc.

import cxxheaderparser
from cxxheaderparser.simple import parse_string
import argparse
import os

parser = argparse.ArgumentParser("MLX C bindings generator", add_help=False)
parser.add_argument("--header", type=str)
parser.add_argument("--namespace", default="mlx::core", type=str)
parser.add_argument("--implementation", default=False, action="store_true")
parser.add_argument("--language", default="C", type=str)
parser.add_argument("--docstring", default="", type=str)
args = parser.parse_args()

headername = os.path.basename(args.header)
if headername.endswith(".h"):
    headername = headername[:-2]
else:
    raise RuntimeError("are you sure you are providing a header?")

Z = cxxheaderparser.simple.parse_file(args.header)


def getname(t):
    if type(t) == cxxheaderparser.types.TemplateArgument:
        return getname(t.arg)
    elif type(t) == cxxheaderparser.types.Reference:
        return getname(t.ref_to)
    elif type(t) == cxxheaderparser.types.MoveReference:
        return getname(t.moveref_to)
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
    elif type(t) == cxxheaderparser.types.FunctionType:
        return_t = getname(t.return_type)
        params_t = []
        for p in t.parameters:
            params_t.append(getname(p.type))
        res = return_t + "(" + ",".join(params_t) + ")"
        return res

    raise RuntimeError("unsupported type: " + str(t))


funcs = {}
l = Z.namespace
for namespace in args.namespace.split("::"):
    l = l.namespaces[namespace]

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

if args.language == "C":
    from c import generate
else:
    raise RuntimeError("Unsupported language")

generate(funcs, headername, args.namespace, args.implementation, args.docstring)
