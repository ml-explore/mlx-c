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
typedef struct mlx_map_SCTYPE1_to_SCTYPE2_ { void* ctx; } mlx_map_SCTYPE1_to_SCTYPE2;

/**
 * Returns a new empty SCTYPE1-to-SCTYPE2 map.
 */
mlx_map_SCTYPE1_to_SCTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_new(void);
/**
 * Free a SCTYPE1-to-SCTYPE2 map.
 */
void mlx_map_SCTYPE1_to_SCTYPE2_free(mlx_map_SCTYPE1_to_SCTYPE2 map);
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
typedef struct mlx_map_SCTYPE1_to_SCTYPE2_iterator_ { void * ctx; void* map_ctx; }
    mlx_map_SCTYPE1_to_SCTYPE2_iterator;
/**
 * Returns a new iterator over the given map.
 */
mlx_map_SCTYPE1_to_SCTYPE2_iterator mlx_map_SCTYPE1_to_SCTYPE2_iterator_new(
    mlx_map_SCTYPE1_to_SCTYPE2 map);
/**
 * Free iterator.
 */
void mlx_map_SCTYPE1_to_SCTYPE2_iterator_free(mlx_map_SCTYPE1_to_SCTYPE2_iterator it);
/**
 * Increment iterator.
 * Returns `true` if iterator could actually be incremented.
 */
bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_next(mlx_map_SCTYPE1_to_SCTYPE2_iterator it, RCTYPE1 key, RCTYPE2 value);
"""

impl_code = """
extern "C" mlx_map_SCTYPE1_to_SCTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_new(void) {
  return mlx_map_SCTYPE1_to_SCTYPE2{new std::unordered_map<CPPTYPE1, CPPTYPE2>()};
}

extern "C" void mlx_map_SCTYPE1_to_SCTYPE2_free(mlx_map_SCTYPE1_to_SCTYPE2 map) {
  mlx_map_SCTYPE1_to_SCTYPE2_free_(map);
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_insert(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    CTYPE1 key,
    CTYPE2 value) {
  MLX_TRY_CATCH(
      auto res = mlx_map_SCTYPE1_to_SCTYPE2_get_(map).insert(std::make_pair(CTYPE1_TO_CPP(key), CTYPE2_TO_CPP(value)));
      return true, return false);
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_get(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    CTYPE1 key, RCTYPE2 value) {
  auto search = mlx_map_SCTYPE1_to_SCTYPE2_get_(map).find(CTYPE1_TO_CPP(key));
  if (search == mlx_map_SCTYPE1_to_SCTYPE2_get_(map).end()) {
    return false;
  } else {
    CTYPE2_ASSIGN_FROM_CPP(value, search->second);
    return true;
  }
}

extern "C" mlx_map_SCTYPE1_to_SCTYPE2_iterator mlx_map_SCTYPE1_to_SCTYPE2_iterator_new(
    mlx_map_SCTYPE1_to_SCTYPE2 map) {
  auto& cpp_map = mlx_map_SCTYPE1_to_SCTYPE2_get_(map);
  return mlx_map_SCTYPE1_to_SCTYPE2_iterator{new std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator(cpp_map.begin()), &cpp_map};
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_next(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it, RCTYPE1 key, RCTYPE2 value) {
  if (mlx_map_SCTYPE1_to_SCTYPE2_iterator_get_(it) == mlx_map_SCTYPE1_to_SCTYPE2_iterator_get_map_(it).end()) {
    return false;
  } else {
    CTYPE1_ASSIGN_FROM_CPP(key, mlx_map_SCTYPE1_to_SCTYPE2_iterator_get_(it)->first);
    CTYPE2_ASSIGN_FROM_CPP(value, mlx_map_SCTYPE1_to_SCTYPE2_iterator_get_(it)->second);
    mlx_map_SCTYPE1_to_SCTYPE2_iterator_get_(it)++;
    return true;
  }
}

extern "C" void mlx_map_SCTYPE1_to_SCTYPE2_iterator_free(mlx_map_SCTYPE1_to_SCTYPE2_iterator it) {
  mlx_map_SCTYPE1_to_SCTYPE2_iterator_free_(it);
}

"""

priv_code = """
inline mlx_map_SCTYPE1_to_SCTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_new_(std::unordered_map<CPPTYPE1, CPPTYPE2> s) {
  return mlx_map_SCTYPE1_to_SCTYPE2({new std::unordered_map<CPPTYPE1, CPPTYPE2>(s)});
}

inline mlx_map_SCTYPE1_to_SCTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_set_(mlx_map_SCTYPE1_to_SCTYPE2* d, std::unordered_map<CPPTYPE1, CPPTYPE2> s) {
  if (d->ctx) {
    *static_cast<std::unordered_map<CPPTYPE1, CPPTYPE2>*>(d->ctx) = s;
  } else {
    d->ctx = new std::unordered_map<CPPTYPE1, CPPTYPE2>(s);
  }
  return *d;
}

inline std::unordered_map<CPPTYPE1, CPPTYPE2>& mlx_map_SCTYPE1_to_SCTYPE2_get_(mlx_map_SCTYPE1_to_SCTYPE2 d) {
  return *static_cast<std::unordered_map<CPPTYPE1, CPPTYPE2>*>(d.ctx);
}

inline void mlx_map_SCTYPE1_to_SCTYPE2_free_(mlx_map_SCTYPE1_to_SCTYPE2 d) {
  if(d.ctx) {
    delete static_cast<std::unordered_map<CPPTYPE1, CPPTYPE2>*>(d.ctx);
  }
}

inline mlx_map_SCTYPE1_to_SCTYPE2_iterator mlx_map_SCTYPE1_to_SCTYPE2_iterator_new_(std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator&& s) {
  return mlx_map_SCTYPE1_to_SCTYPE2_iterator({new std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator(std::move(s))});
}

inline mlx_map_SCTYPE1_to_SCTYPE2_iterator mlx_map_SCTYPE1_to_SCTYPE2_iterator_set_(mlx_map_SCTYPE1_to_SCTYPE2_iterator* d, std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator s) {
  if (d->ctx) {
    *static_cast<std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator*>(d->ctx) = s;
  } else {
    d->ctx = new std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator(s);
  }
  return *d;
}

inline std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator& mlx_map_SCTYPE1_to_SCTYPE2_iterator_get_(mlx_map_SCTYPE1_to_SCTYPE2_iterator d) {
  return *static_cast<std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator*>(d.ctx);
}
inline std::unordered_map<CPPTYPE1, CPPTYPE2>& mlx_map_SCTYPE1_to_SCTYPE2_iterator_get_map_(mlx_map_SCTYPE1_to_SCTYPE2_iterator d) {
  return *static_cast<std::unordered_map<CPPTYPE1, CPPTYPE2>*>(d.map_ctx);
}
inline void mlx_map_SCTYPE1_to_SCTYPE2_iterator_free_(mlx_map_SCTYPE1_to_SCTYPE2_iterator d) {
  if(d.ctx) {
    delete static_cast<std::unordered_map<CPPTYPE1, CPPTYPE2>::iterator*>(d.ctx);
  }
}
"""


def callback_split_string_args(func):
    def func_split_string_args(args):
        args = args.split(",")
        return func(*args)

    return func_split_string_args


def generate(code, type1, type2):
    code = replace_match_parenthesis(code, "CTYPE1_TO_CPP", type1["c_to_cpp"])
    code = replace_match_parenthesis(code, "CTYPE2_TO_CPP", type2["c_to_cpp"])
    code = replace_match_parenthesis(
        code,
        "CTYPE1_ASSIGN_FROM_CPP",
        callback_split_string_args(type1["c_assign_from_cpp"]),
    )
    code = replace_match_parenthesis(
        code,
        "CTYPE2_ASSIGN_FROM_CPP",
        callback_split_string_args(type2["c_assign_from_cpp"]),
    )
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
#include "mlx/c/private/array.h"
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
    "c_return": "mlx_array*",
    "c_to_cpp": lambda s: "mlx_array_get_(" + s + ")",
    "c_assign_from_cpp": lambda d, s: "mlx_array_set_(*" + d + ", " + s + ")",
}

string_t = {
    "c": "const char*",
    "cpp": "std::string",
    "nick": "string",
    "c_return": "const char**",
    "c_to_cpp": lambda s: "std::string(" + s + ")",
    "c_assign_from_cpp": lambda d, s: "*" + d + " = " + s + ".data()",
}

print(begin)
print(generate(code, string_t, array_t))
print(generate(code, string_t, string_t))
print(end)
