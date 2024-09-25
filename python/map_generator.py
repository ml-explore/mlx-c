import argparse
import regex

parser = argparse.ArgumentParser("MLX C map code generator", add_help=False)
parser.add_argument("--implementation", default=False, action="store_true")
parser.add_argument("--private", default=False, action="store_true")
args = parser.parse_args()


def replace_match_parenthesis(string, keyword, fun):
    pattern = regex.compile(keyword + r"(\((?:[^()]++|(?1))++\))")
    res = []
    pos = 0
    for m in pattern.finditer(string):
        res.append(string[pos : m.start()])
        res.append(fun(m[1][1:-1]))
        pos = m.end()
    res.append(string[pos:])
    return "".join(res)


decl_code = """
/**
 * A SCTYPE1-to-SCTYPE2 map
 */
typedef struct mlx_map_SCTYPE1_to_SCTYPE2_* mlx_map_SCTYPE1_to_SCTYPE2;

/**
 * Returns a new empty SCTYPE1-to-SCTYPE2 map.
 */
mlx_map_SCTYPE1_to_SCTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_new(void);
/**
 * Insert a new `value` at the specified `key` in the map.
 * Returns `true` if the value was actually inserted.
 */
bool mlx_map_SCTYPE1_to_SCTYPE2_insert(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    CTYPE1 key,
    CTYPE2 value);
/**
 * Returns the value indexed at the specified `key` in the map.
 * Returns `NULL` if no value was found for `key`.
 */
bool mlx_map_SCTYPE1_to_SCTYPE2_get(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    CTYPE1 key,
    RCTYPE2 value);

/**
 * An iterator over a SCTYPE1-to-SCTYPE2 map.
 */
typedef struct mlx_map_SCTYPE1_to_SCTYPE2_iterator_*
    mlx_map_SCTYPE1_to_SCTYPE2_iterator;
/**
 * Returns a new iterator over the given map.
 */
mlx_map_SCTYPE1_to_SCTYPE2_iterator mlx_map_SCTYPE1_to_SCTYPE2_iterate(
    mlx_map_SCTYPE1_to_SCTYPE2 map);
/**
 * Increment iterator.
 * Returns `true` if iterator could actually be incremented.
 */
bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_next(mlx_map_SCTYPE1_to_SCTYPE2_iterator it, RCTYPE1 key, RCTYPE2 value);
"""

impl_code = """
mlx_string_* mlx_map_SCTYPE1_to_SCTYPE2_::tostring() {
  MLX_TRY_CATCH(return new mlx_string_("mlx_map_SCTYPE1_to_SCTYPE2"),
                       return nullptr);
}

mlx_string_* mlx_map_SCTYPE1_to_SCTYPE2_iterator_::tostring() {
  MLX_TRY_CATCH(return new mlx_string_("mlx_map_SCTYPE1_to_SCTYPE2_iterator"),
                       return nullptr);
}

extern "C" mlx_map_SCTYPE1_to_SCTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_new(void) {
  MLX_TRY_CATCH(return new mlx_map_SCTYPE1_to_SCTYPE2_(), return nullptr);
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_insert(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    CTYPE1 key,
    CTYPE2 value) {
  MLX_TRY_CATCH(
      auto res = map->ctx.insert(std::make_pair(CTYPE1_TO_CPP(key), CTYPE2_TO_CPP(value)));
      return res.second, return false);
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_get(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    CTYPE1 key, RCTYPE2 value) {
  auto search = map->ctx.find(CTYPE1_TO_CPP(key));
  if (search == map->ctx.end()) {
    return false;
  } else {
    CTYPE2_ASSIGN(value) = CTYPE2_ASSIGN_GET(search->second);
    return true;
  }
}

extern "C" mlx_map_SCTYPE1_to_SCTYPE2_iterator mlx_map_SCTYPE1_to_SCTYPE2_iterate(
    mlx_map_SCTYPE1_to_SCTYPE2 map) {
  MLX_TRY_CATCH(return new mlx_map_SCTYPE1_to_SCTYPE2_iterator_(map),
                       return nullptr);
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_next(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it, RCTYPE1 key, RCTYPE2 value) {
  if (it->ctx == it->map->ctx.end()) {
    return false;
  } else {
    CTYPE1_ASSIGN(key) = CTYPE1_ASSIGN_GET(it->ctx->first);
    CTYPE2_ASSIGN(value) = CTYPE2_ASSIGN_GET(it->ctx->second);
    it->ctx++;
    return true;
  }
}
"""

priv_code = """
struct mlx_map_SCTYPE1_to_SCTYPE2_ : mlx_object_ {
  mlx_map_SCTYPE1_to_SCTYPE2_() : mlx_object_(){};
  mlx_map_SCTYPE1_to_SCTYPE2_(
      std::unordered_map<CPPTYPE1, CPPTYPE2>&& ctx)
      : mlx_object_(), ctx(ctx){};
  virtual mlx_string_* tostring() override;
  std::unordered_map<CPPTYPE1, CPPTYPE2> ctx;
};

struct mlx_map_SCTYPE1_to_SCTYPE2_iterator_ : mlx_object_ {
  mlx_map_SCTYPE1_to_SCTYPE2_iterator_(mlx_map_SCTYPE1_to_SCTYPE2_* map)
      : mlx_object_(), map(map), ctx(map->ctx.begin()) {
    mlx_retain(map);
  };
  virtual mlx_string_* tostring() override;
  mlx_map_SCTYPE1_to_SCTYPE2_* map;
  std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator ctx;
  virtual ~mlx_map_SCTYPE1_to_SCTYPE2_iterator_() {
    mlx_free(map);
  }
};
"""


def generate(code, type1, type2):
    code = replace_match_parenthesis(code, "CTYPE1_TO_CPP", type1["c_to_cpp"])
    code = replace_match_parenthesis(code, "CTYPE2_TO_CPP", type2["c_to_cpp"])
    code = replace_match_parenthesis(code, "CTYPE1_ASSIGN", type1["c_assign"])
    code = replace_match_parenthesis(code, "CTYPE2_ASSIGN", type2["c_assign"])
    code = replace_match_parenthesis(code, "CTYPE1_ASSIGN_GET", type1["c_assign_get"])
    code = replace_match_parenthesis(code, "CTYPE2_ASSIGN_GET", type2["c_assign_get"])
    code = code.replace("SCTYPE1", type1["nick"])
    code = code.replace("SCTYPE2", type2["nick"])
    code = code.replace("RCTYPE1", type1["c_return"])
    code = code.replace("RCTYPE2", type2["c_return"])
    code = code.replace("CTYPE1", type1["c"])
    code = code.replace("CTYPE2", type2["c"])
    code = code.replace("CPPTYPE1", type1["cpp"])
    code = code.replace("CPPTYPE2", type2["cpp"])
    return code


decl_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_MAP_H
#define MLX_MAP_H

#include "mlx/c/array.h"
#include "mlx/c/string.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup mlx_map Maps
 * MLX map objects.
 */
/**@{*/
"""

decl_end = """
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
"""

impl_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#include "mlx/c/map.h"
#include "mlx/c/object.h"
#include "mlx/c/private/map.h"
#include "mlx/c/private/string.h"
#include "mlx/c/private/utils.h"
"""

impl_end = """
"""

priv_begin = """/* Copyright © 2023-2024 Apple Inc. */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */

#ifndef MLX_MAP_PRIVATE_H
#define MLX_MAP_PRIVATE_H

#include "mlx/c/map.h"
#include "mlx/c/object.h"
#include "mlx/c/private/object.h"
#include "mlx/mlx.h"
"""

priv_end = """
#endif
"""

if args.implementation:
    begin = impl_begin
    code = impl_code
    end = impl_end
elif args.private:
    begin = priv_begin
    code = priv_code
    end = priv_end
else:
    begin = decl_begin
    code = decl_code
    end = decl_end

array_t = {
    "c": "const mlx_array",
    "cpp": "mlx::core::array",
    "nick": "array",
    "c_return": "mlx_array",
    "c_to_cpp": lambda s: s + "->ctx",
    "c_assign": lambda s: s + "->ctx",
    "c_assign_get": lambda s: s,
}

string_t = {
    "c": "const char*",
    "cpp": "std::string",
    "nick": "string",
    "c_return": "const char**",
    "c_to_cpp": lambda s: "std::string(" + s + ")",
    "c_assign": lambda s: "* " + s,
    "c_assign_get": lambda s: s + ".data()",
}

print(begin)
print(generate(code, string_t, array_t))
print(generate(code, string_t, string_t))
print(end)
