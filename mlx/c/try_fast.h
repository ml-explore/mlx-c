/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */


            #include <stdio.h>

        
#ifndef MLX_TRY_FAST_H
#define MLX_TRY_FAST_H
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
    
mlx_array_result mlx_fast_try_layer_norm ( mlx_array x, mlx_array weight, mlx_array bias, float eps, mlx_stream s ) ;
mlx_array_result mlx_fast_try_rms_norm ( mlx_array x, mlx_array weight, float eps, mlx_stream s ) ;
mlx_array_result mlx_fast_try_rope ( mlx_array x, int dims, bool traditional, float base, float scale, int offset, mlx_stream s ) ;
mlx_array_result mlx_fast_try_scaled_dot_product_attention ( mlx_array queries, mlx_array keys, mlx_array values, float scale, mlx_array mask, mlx_stream s ) ;

    #ifdef __cplusplus
    }
    #endif

    #endif
    
