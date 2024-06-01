/* Copyright © 2023-2024 Apple Inc.                   */
/*                                                    */
/* This file is auto-generated. Do not edit manually. */
/*                                                    */


            #include <stdio.h>

        
#ifndef MLX_TRY_TRANSFORMS_IMPL_H
#define MLX_TRY_TRANSFORMS_IMPL_H
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
    
mlx_vector_array_result mlx_detail_try_vmap_replace ( const mlx_vector_array inputs, const mlx_vector_array s_inputs, const mlx_vector_array s_outputs, const int* in_axes, size_t num_in_axes, const int* out_axes, size_t num_out_axes ) ;
mlx_vector_vector_array_result mlx_detail_try_vmap_trace ( mlx_closure fun, const mlx_vector_array inputs, const int* in_axes, size_t num_in_axes ) ;

    #ifdef __cplusplus
    }
    #endif

    #endif
    
