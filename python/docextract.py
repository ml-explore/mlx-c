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

# Tokens that only appear in C++ code. A @code block containing any of these
# cannot be used verbatim in a C header's documentation.
_CPP_TOKENS = re.compile(
    r"\bauto\s|std::|->|::|array\{|vector\{|\bnew\b|\.c_str\(\)")


def sanitize(body_lines, indent=""):
    """Light, conservative cleaning of a doc-comment body.

    Rules (each visible in the output, nothing silently rewritten):
      1. Drop @code/@endcode blocks that contain C++-only tokens, replacing
         the whole block with a single note line. Blocks without such tokens
         are kept verbatim.
      2. Collapse runs of blank lines to one.
    Returns (lines, applied_rules).
    """
    out = []
    rules = []
    i = 0
    while i < len(body_lines):
        ln = body_lines[i]
        if ln.strip() == "@code":
            j = i
            while j < len(body_lines) and body_lines[j].strip() != "@endcode":
                j += 1
            block = body_lines[i + 1 : j]
            if any(_CPP_TOKENS.search(b) for b in block):
                # drop a dangling lead-in like "For example:" or "is
                # equivalent to:" directly above (skipping blank lines)
                while out and out[-1].strip() == "":
                    out.pop()
                if out and out[-1].rstrip().endswith(":"):
                    out.pop()
                    while out and out[-1].strip() == "":
                        out.pop()
                note = "Code example omitted: written in C++."
                if not (out and out[-1] == note):
                    if out and out[-1].strip() != "":
                        out.append("")
                    out.append(note)
                rules.append("dropped C++ @code block")
            else:
                out.extend(body_lines[i : j + 1])
            i = j + 1
            continue
        out.append(ln)
        i += 1
    # collapse blank runs
    cleaned = []
    for ln in out:
        if ln.strip() == "" and cleaned and cleaned[-1].strip() == "":
            continue
        cleaned.append(ln)
    return cleaned, rules


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
            # Skip structural Doxygen commands (file-level \defgroup groups):
            # they document the module, not the next declaration, and must not
            # be attached to a function or re-emitted mid-header (c.py already
            # emits the file-level group from --docstring/committed form).
            joined = "\n".join(body)
            if re.search(r"\\defgroup|\\addtogroup|\\ingroup|@\{|@\}", joined):
                continue
            decl = _decl_after(m, content)
            name, arity = _decl_info(decl)
            if not name or arity is None:
                continue
            body, rules = sanitize(body)
            self.docs.setdefault(name, []).append(
                {"arity": arity, "body": body, "used": False,
                 "rules": rules}
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
