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
                # use defaults only if it is the short version
                if v == "s":
                    d["use_defaults"] = True
                newdefs.append(d)

                # add a short version if there are defaults
                if (
                    v != "s"
                    and not v.endswith("_s")
                    and any(d["params_default"])
                ):
                    d = d.copy()
                    d["variant"] = "s" if v == "" else v + "_s"
                    d["use_defaults"] = True
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
        if any(defs[0]["params_default"]):
            dx = d.copy()
            dx["variant"] = "s"
            dx["use_defaults"] = True
            return [d, dx]
        else:
            return [d]


def mlx_core(name, defs):
    variants = {
        "arange": ["", None, None, None, None, None, None, "s", None],
        "eye": ["", None, None, None, "s"],
        "tri": ["", "s"],
        "flatten": ["", "s"],
        "squeeze": ["axes", "axis", ""],
        "expand_dims": ["axes", ""],
        "slice": ["", None, "dynamic", None],
        "slice_update": ["", None, "dynamic"],
        "split": ["", "sections_x", "s", "sections"],
        "concatenate": ["axis", ""],
        "stack": ["axis", ""],
        "repeat": ["axis", ""],
        "transpose": ["axes", None, ""],
        "all": ["axes", "axis", "", None],
        "any": ["axes", "axis", "", None],
        "sum": ["axes", "axis", "", None],
        "mean": ["axes", "axis", "", None],
        "var": ["axes", "axis", "", None],
        "std": ["axes", "axis", "", None],
        "prod": ["axes", "axis", "", None],
        "max": ["axes", "axis", "", None],
        "min": ["axes", "axis", "", None],
        "argmax": ["axis", "", None],
        "argmin": ["axis", "", None],
        "load": ["file", ""],
        "load_safetensors": ["file", ""],
        "pad": ["", None, None, "symmetric"],
        "save": ["file", ""],
        "save_safetensors": ["file", ""],
        "argpartition": ["axis", ""],
        "partition": ["axis", ""],
        "argsort": ["axis", ""],
        "sort": ["axis", ""],
        "topk": ["axis", ""],
        "take": ["axis", None, "", None],
        "roll": [None, None, "axes", "axis", None, ""],
        "logsumexp": ["axes", "axis", "", None],
        "softmax": ["axes", "axis", ""],
        "tensordot": ["", "axis"],
        "array_equal": ["", "s"],
        "round": ["", "s"],
        "trace": ["", None, "s"],
    }
    return _make_variant_suffixes(name, defs, variants)


def mlx_core_linalg(name, defs):
    variants = {"norm": ["", None, "matrix", None, "l2", None]}
    return _make_variant_suffixes(name, defs, variants)


def mlx_core_random(name, defs):
    variants = {
        "categorical": ["shape", "num_samples", ""],
        "permutation": ["", "arange"],
        "split": ["num", ""],
        "uniform": ["", None, None, "s"],
        "normal": ["", None, None, "s"],
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
