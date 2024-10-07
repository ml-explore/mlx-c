ctor_code = """
inline CTYPE CTYPE_new_() {
  return CTYPE({DEFAULT_CTOR});
}

inline CTYPE CTYPE_new_(const CPPTYPE& s) {
  return CTYPE({new CPPTYPE(s)});
}

inline CTYPE CTYPE_new_(CPPTYPE&& s) {
  return CTYPE({new CPPTYPE(std::move(s))});
}
"""

code = """
inline CTYPE& CTYPE_set_(CTYPE& d, const CPPTYPE& s) {
  if (d.ctx) {
    *static_cast<CPPTYPE*>(d.ctx) = s;
  } else {
    d.ctx = new CPPTYPE(s);
  }
  return d;
}

inline CTYPE& CTYPE_set_(CTYPE& d, CPPTYPE&& s) {
  if (d.ctx) {
    *static_cast<CPPTYPE*>(d.ctx) = s;
  } else {
    d.ctx = new CPPTYPE(s);
  }
  return d;
}

inline CPPTYPE& CTYPE_get_(CTYPE d) {
  if (!d.ctx) {
    throw std::runtime_error("expected a non-empty CTYPE");
  }
  return *static_cast<CPPTYPE*>(d.ctx);
}

inline void CTYPE_free_(CTYPE d) {
  if (d.ctx) {
    delete static_cast<CPPTYPE*>(d.ctx);
  }
}
"""


def generate(
    ctype, cpptype, empty_ctor=True, ctor=True, code=code, ctor_code=ctor_code
):
    if ctor:
        code = ctor_code + code

    if empty_ctor:
        default_ctor = "nullptr"
    else:
        default_ctor = "new CPPTYPE()"

    code = code.replace("DEFAULT_CTOR", default_ctor)
    code = code.replace("CTYPE", ctype)
    code = code.replace("CPPTYPE", cpptype)
    return code


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser("MLX C private type generator", add_help=False)
    parser.add_argument("--ctype", type=str)
    parser.add_argument("--cpptype", type=str)
    args = parser.parse_args()

    short_ctype = args.ctype.replace("mlx_", "")
    print("/* Copyright © 2023-2024 Apple Inc.                   */")
    print("/*                                                    */")
    print("/* This file is auto-generated. Do not edit manually. */")
    print("/*                                                    */")
    print()
    print("#ifndef MLX_" + short_ctype.upper() + "_PRIVATE_H")
    print("#define MLX_" + short_ctype.upper() + "_PRIVATE_H")
    print()
    print('#include "mlx/c/' + short_ctype + '.h"')
    print('#include "mlx/mlx.h"')
    print(generate(args.ctype, args.cpptype))
    print("#endif")
