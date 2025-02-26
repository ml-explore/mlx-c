def mlx_core(name, defs):
    if name != "all" and name != "linalg::norm":
        idx = 0
        while idx < len(defs) - 1:
            pidx = defs[idx]["params_name"]
            pidxp1 = defs[idx + 1]["params_name"]
            mpidx = [p if p != "axis" else "axes" for p in pidx]
            mpidxp1 = [p if p != "axis" else "axes" for p in pidxp1]
            if mpidx == mpidxp1:
                if pidx == mpidx:
                    defs.pop(idx + 1)
                else:
                    defs.pop(idx)
            else:
                idx = idx + 1

    if name == "tensordot":
        defs[1]["variant"] = "along_axis"
        defs = [defs[0], defs[1]]
    elif name == "split":
        defs[0]["variant"] = "equal_parts"
        defs = [defs[0], defs[1]]
    elif name == "all":
        defs[0]["variant"] = "axes"
        defs[1]["variant"] = "axis"
        defs[2]["variant"] = "all"
        defs = [defs[0], defs[1], defs[2]]
    elif name == "take":
        defs[2]["variant"] = "all"
        defs = [defs[0], defs[2]]
    elif (
        len(defs) > 1
        and ("axes" in defs[0]["params_name"] or "axis" in defs[0]["params_name"])
        and (
            "axes" not in defs[1]["params_name"]
            and "axis" not in defs[1]["params_name"]
        )
    ):
        defs[1]["variant"] = "all"
        defs = [defs[0], defs[1]]
    elif len(defs) > 1 and (
        "std::shared_ptr<io::Reader>" in defs[0]["params_t"]
        or "std::shared_ptr<io::Reader>" in defs[1]["params_t"]
        or "std::shared_ptr<io::Writer>" in defs[0]["params_t"]
        or "std::shared_ptr<io::Writer>" in defs[1]["params_t"]
    ):
        if (
            "std::shared_ptr<io::Reader>" in defs[0]["params_t"]
            or "std::shared_ptr<io::Writer>" in defs[0]["params_t"]
        ):
            defs[0]["variant"] = "file"
        else:
            defs[1]["variant"] = "file"
        defs = [defs[0], defs[1]]

    return defs


def mlx_core_linalg(name, defs):
    if name == "norm":
        defs[0]["variant"] = "p"
        defs[2]["variant"] = "ord"
        defs = [defs[0], defs[2], defs[4]]

    return defs


def mlx_core_random(name, defs):
    if name == "categorical":
        defs[0]["variant"] = "shape"
        defs[1]["variant"] = "num_samples"
        defs = [defs[0], defs[1], defs[2]]

    if name == "permutation":
        defs[1]["variant"] = "arange"

    if name == "split":
        defs[0]["variant"] = "num"

    return defs


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
