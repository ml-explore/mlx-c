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
    if name in variants:
        variants = variants[name]
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
            if variants[i] is not None:
                if variants[i] != "":
                    d["variant"] = variants[i]
                newdefs.append(d)

        return newdefs
    else:
        return [defs[0]]  # with largest number of arguments


def mlx_core(name, defs):
    variants = {
        "arange": ["", None, None, None, None, None, None, None, None],
        "squeeze": ["", None, "all"],
        "slice": ["", None, None, None],
        "slice_update": ["", None, None],
        "split": ["equal_parts", "", None, None],
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
