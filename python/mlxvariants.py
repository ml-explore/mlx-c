import sys


def _pretty_string_def(d):
    txt = []
    txt.append(d["return_t"])
    txt.append(d["namespace"] + "::" + d["name"])
    txt.append("(")
    args = []
    for i in range(len(d["params_t"])):
        args.append(d["params_t"][i] + " " + (d["params_name"][i] or ""))
    txt.append(", ".join(args))
    txt.append(")")
    return " ".join(txt)


def _make_variant_suffixes(name, defs, variants):
    if len(defs) > 1:
        print("OVL", file=sys.stderr)
    if name in variants:
        variants = variants[name]
        for i, d in enumerate(defs):
            print("OVL", i, _pretty_string_def(d), " -> ", variants[i], file=sys.stderr)
        if len(variants) != len(defs):
            print("function overloads length:", len(defs), file=sys.stderr)
            for i, d in enumerate(defs):
                print(i, _pretty_string_def(d), file=sys.stderr)
            print("namings length:", len(variants), file=sys.stderr)
            for i, v in enumerate(variants):
                print(i, v, file=sys.stderr)
            raise RuntimeError("function overloads and namings do not match")
        newdefs = []
        for i, d in enumerate(defs):
            v = variants[i]
            if v is not None:
                # do we need to specify variant name?
                if v != "":
                    d["variant"] = v
                # use defaults only if not the full eXtended version
                if v != "x":
                    d["use_defaults"] = True
                newdefs.append(d)

                # add an eXtended version if there are defaults
                if (
                    v != ""
                    and v != "x"
                    and not v.endswith("_x")
                    and any(d["params_default"])
                ):
                    d = d.copy()
                    d["variant"] = v + "_x"
                    d["use_defaults"] = False
                    newdefs.append(d)
        return newdefs
    else:
        if len(defs) > 1:
            for i, d in enumerate(defs):
                print(
                    "OVL",
                    i,
                    _pretty_string_def(d),
                    " -> ",
                    "" if i == 0 else "None",
                    file=sys.stderr,
                )
        d = defs[0]
        d["use_defaults"] = True
        if any(defs[0]["params_default"]):
            dx = d.copy()
            dx["variant"] = "x"
            dx["use_defaults"] = None
            return [d, dx]
        else:
            return [d]


def mlx_core(name, defs):
    variants = {
        "arange": ["x", None, None, None, None, None, None, "", None],
        "eye": ["x", None, None, None, ""],
        "tri": ["x", ""],
        "flatten": ["x", ""],
        "squeeze": ["axes", "axis", ""],
        "expand_dims": ["axes", ""],
        "slice": ["", None, "dynamic", None],
        "slice_update": ["", None, "dynamic"],
        "split": ["x", "sections_x", "", "sections"],
        "concatenate": ["", "all"],
        "stack": ["", "all"],
        "repeat": ["", "all"],
        "transpose": ["", None, "all"],
        "all": ["axes", "axis", "all", None],
        "any": ["", None, "all", None],
        "sum": ["", None, "all", None],
        "mean": ["", None, "all", None],
        "var": ["", None, "all", None],
        "std": ["", None, "all", None],
        "prod": ["", None, "all", None],
        "max": ["", None, "all", None],
        "min": ["", None, "all", None],
        "argmax": ["", "all", None],
        "argmin": ["", "all", None],
        "load": ["file", ""],
        "load_safetensors": ["file", ""],
        "save": ["file", ""],
        "save_safetensors": ["file", ""],
        "argpartition": ["", "all"],
        "partition": ["", "all"],
        "argsort": ["", "all"],
        "sort": ["", "all"],
        "topk": ["", "all"],
        "take": ["", None, "all", None],
        "roll": [None, "", None, None, "all", None],
        "logsumexp": ["", None, "all", None],
        "softmax": ["", None, "all"],
        "tensordot": ["", "along_axis"],
    }
    return _make_variant_suffixes(name, defs, variants)


def mlx_core_linalg(name, defs):
    variants = {"norm": ["p", None, "ord", None, "", None]}
    return _make_variant_suffixes(name, defs, variants)


def mlx_core_random(name, defs):
    variants = {
        "categorical": ["shape", "num_samples", ""],
        "permutation": ["", "arange"],
        "split": ["num", ""],
    }
    return _make_variant_suffixes(name, defs, variants)


def mlx_core_detail(name, defs):
    if name not in [
        "compile",
        "compile_clear_cache",
        "compile_erase",
        "vmap_replace",
        "vmap_trace",
    ]:
        defs = []

    return defs
