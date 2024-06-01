/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */


            #include <stdio.h>

        
#ifndef MLX_TRY_TRANSFORMS_H
#define MLX_TRY_TRANSFORMS_H
#include "mlx/c/result.h"

    #include "mlx/c/array.h"
    #include "mlx/c/closure.h"
    #include "mlx/c/future.h"
    #include "mlx/c/ioutils.h"
    #include "mlx/c/map.h"
    #include "mlx/c/stream.h"
    #include "mlx/c/string.h"

    #ifdef __cplusplus
    extern "C" {
    #endif
    
mlx_vector_vector_array_result mlx_try_jvp ( mlx_closure fun, const mlx_vector_array primals, const mlx_vector_array tangents ) ;
mlx_vector_vector_array_result mlx_try_vjp ( mlx_closure fun, const mlx_vector_array primals, const mlx_vector_array cotangents ) ;

    #ifdef __cplusplus
    }
    #endif

    #endif
    
