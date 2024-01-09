#include "mlx/c/array.h"
#include "mlx/c/device.h"
#include "mlx/c/fft.h"
#include "mlx/c/ops.h"
#include "mlx/c/random.h"
#include "mlx/c/stream.h"

#ifdef __cplusplus
extern "C" {
#endif

char* mlx_tostring(void* obj);
void mlx_retain(void* obj);
void mlx_free(void* obj);

#ifdef __cplusplus
}
#endif
