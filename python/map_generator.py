import argparse

parser = argparse.ArgumentParser("MLX C map code generator", add_help=False)
parser.add_argument("--implementation", default=False, action="store_true")
parser.add_argument("--private", default=False, action="store_true")
args = parser.parse_args()

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
    const CTYPE1 key,
    const CTYPE2 value);
/**
 * Returns the value indexed at the specified `key` in the map.
 * Returns `NULL` if no value was found for `key`.
 */
CTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_get(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    const CTYPE1 key);

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
bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_next(mlx_map_SCTYPE1_to_SCTYPE2_iterator it);
/**
 * Returns `true` iif iterator is at the end of the map.
 */
bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_end(mlx_map_SCTYPE1_to_SCTYPE2_iterator it);
/**
 * Returns the key associated to the current iterator position in the map.
 */
CTYPE1 mlx_map_SCTYPE1_to_SCTYPE2_iterator_key(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it);
/**
 * Returns the value associated to the current iterator position in the map.
 */
CTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_iterator_value(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it);
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
    const CTYPE1 key,
    const CTYPE2 value) {
  MLX_TRY_CATCH(
      auto res = map->ctx.insert(std::make_pair(key->ctx, value->ctx));
      return res.second, return false);
}

extern "C" CTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_get(
    mlx_map_SCTYPE1_to_SCTYPE2 map,
    const CTYPE1 key) {
  auto search = map->ctx.find(key->ctx);
  if (search == map->ctx.end()) {
    return nullptr;
  } else {
    return new CTYPE2_(search->second);
  }
}

extern "C" mlx_map_SCTYPE1_to_SCTYPE2_iterator mlx_map_SCTYPE1_to_SCTYPE2_iterate(
    mlx_map_SCTYPE1_to_SCTYPE2 map) {
  MLX_TRY_CATCH(return new mlx_map_SCTYPE1_to_SCTYPE2_iterator_(map),
                       return nullptr);
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_next(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it) {
  it->ctx++;
  if (it->ctx == it->map->ctx.end()) {
    return false;
  } else {
    return true;
  }
}

extern "C" bool mlx_map_SCTYPE1_to_SCTYPE2_iterator_end(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return true;
  } else {
    return false;
  }
}

extern "C" CTYPE1 mlx_map_SCTYPE1_to_SCTYPE2_iterator_key(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return nullptr;
  } else {
    return new CTYPE1_(it->ctx->first);
  }
}

extern "C" CTYPE2 mlx_map_SCTYPE1_to_SCTYPE2_iterator_value(
    mlx_map_SCTYPE1_to_SCTYPE2_iterator it) {
  if (it->ctx == it->map->ctx.end()) {
    return nullptr;
  } else {
    return new CTYPE2_(it->ctx->second);
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


def define_map(ctype1, ctype2, sctype1, sctype2):
    code = decl_code
    code = code.replace("SCTYPE1", sctype1)
    code = code.replace("SCTYPE2", sctype2)
    code = code.replace("CTYPE1", ctype1)
    code = code.replace("CTYPE2", ctype2)
    return code


def impl_map(ctype1, ctype2, sctype1, sctype2):
    code = impl_code
    code = code.replace("SCTYPE1", sctype1)
    code = code.replace("SCTYPE2", sctype2)
    code = code.replace("CTYPE1", ctype1)
    code = code.replace("CTYPE2", ctype2)
    return code


def priv_map(cpptype1, cpptype2, sctype1, sctype2):
    code = priv_code
    code = code.replace("SCTYPE1", sctype1)
    code = code.replace("SCTYPE2", sctype2)
    code = code.replace("CPPTYPE1", cpptype1)
    code = code.replace("CPPTYPE2", cpptype2)
    return code


define_begin = """/* Copyright © 2023-2024 Apple Inc. */
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

define_end = """
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
    print(impl_begin)
    print(impl_map("mlx_string", "mlx_array", "string", "array"))
    print(impl_map("mlx_string", "mlx_string", "string", "string"))
    print(impl_end)
elif args.private:
    print(priv_begin)
    print(priv_map("std::string", "mlx::core::array", "string", "array"))
    print(priv_map("std::string", "std::string", "string", "string"))
    print(priv_end)
else:
    print(define_begin)
    print(define_map("mlx_string", "mlx_array", "string", "array"))
    print(define_map("mlx_string", "mlx_string", "string", "string"))
    print(define_end)
