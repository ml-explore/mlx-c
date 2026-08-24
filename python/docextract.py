# Copyright © 2023-2024 Apple Inc.

"""Extract doc comments from MLX C++ headers and associate them with the
declarations they document.

The C++ headers document most public functions with a /** ... */ block
immediately preceding the declaration. cxxheaderparser discards comments, so
this module recovers them from the raw header text and matches each comment to
a parsed overload by qualified name and parameter arity (falling back to
first-unconsumed when arities tie).
"""

import re

_COMMENT_RE = re.compile(r"/\*\*(.*?)\*/", re.DOTALL)


def _split_top_level(text, sep=","):
    """Split text on sep occurring outside any (), [], <> nesting."""
    parts = []
    depth = 0
    cur = []
    for ch in text:
        if ch in "(<[{" :
            depth += 1
        elif ch in ")>]}" :
            depth -= 1
        if ch == sep and depth == 0:
            parts.append("".join(cur))
            cur = []
        else:
            cur.append(ch)
    parts.append("".join(cur))
    return parts


def _decl_after(match, content):
    """Return the declaration text following a comment match, up to ';' or '{'."""
    start = match.end()
    # skip whitespace and any non-doc comments between
    i = start
    while i < len(content):
        j = content.find("\n", i)
        line = content[i : j + 1 if j != -1 else len(content)]
        stripped = line.strip()
        if stripped == "" or stripped.startswith("//") or stripped.startswith("/*"):
            i = j + 1 if j != -1 else len(content)
            continue
        break
    # accumulate until ; or { at depth 0
    out = []
    depth = 0
    k = content.rfind("\n", 0, i) + 1  # include the first code line fully
    for ch in content[k:]:
        out.append(ch)
        if ch in "(<[{" :
            depth += 1
        elif ch in ")>]}" :
            depth -= 1
        elif ch in ";{" and depth == 0:
            break
    return "".join(out)


def _decl_info(decl):
    """Return (function_name, param_arity) from a declaration string."""
    m = re.search(r"([A-Za-z_]\w*)\s*\(", decl)
    if not m:
        return None, None
    name = m.group(1)
    # param list: from this paren to its matching close
    depth = 0
    start = m.end() - 1
    end = start
    for i in range(start, len(decl)):
        ch = decl[i]
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                end = i
                break
    params = decl[start + 1 : end]
    # count parameters as written: cxxheaderparser keeps defaulted params,
    # so arity must include them for the counts to line up.
    arity = len([p for p in _split_top_level(params) if p.strip() != ""])
    if params.strip() in ("", "void"):
        arity = 0
    return name, arity


def format_doc(body_lines, indent=""):
    """Format extracted comment body lines as a /** */ block."""
    lines = [indent + "/**"]
    for ln in body_lines:
        ln = ln.rstrip()
        lines.append((indent + " * " + ln).rstrip())
    lines.append(indent + " */")
    return "\n".join(lines)


class HeaderDocs:
    """Docs for one header: docs["mlx::core::name"] -> list of entries."""

    def __init__(self, content):
        self.docs = {}
        for m in _COMMENT_RE.finditer(content):
            body = [ln.lstrip(" \t*") for ln in m.group(1).splitlines()]
            # drop leading/trailing empties
            while body and body[0] == "":
                body.pop(0)
            while body and body[-1] == "":
                body.pop()
            decl = _decl_after(m, content)
            name, arity = _decl_info(decl)
            if not name or arity is None:
                continue
            self.docs.setdefault(name, []).append(
                {"arity": arity, "body": body, "used": False}
            )

    def take(self, cpp_qualified_name, namespace, name, arity):
        """Pop the doc entry matching name+arity under any plausible key."""
        candidates = [
            cpp_qualified_name,
            (namespace + "::" + name) if namespace else name,
            name,
        ]
        for key in candidates:
            entries = self.docs.get(key.split("::")[-1])
            if not entries:
                continue
            for e in entries:
                if not e["used"] and e["arity"] == arity:
                    e["used"] = True
                    return e["body"]
        return None
