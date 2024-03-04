Overview
========

MLX C wraps and follows as closely as possible the C++ API of `MLX
<https://github.com/ml-explore/mlx>`_.

C Object
--------

MLX C relies on several C ``struct`` which are all compatible with a private
:doc:`object struct <object>` (that we will refer as a MLX C object),
which implements basic memory management. When using MLX C, it is important
to note that:

* All returned C objects come with a reference count of 1, which needs to
  be decreased with a matching :func:`mlx_free()` call.

* When the reference count of an object gets to 0, the object is freed.

* Reference count may be increased via :func:`mlx_retain()`, in which case it
  should be matched at some point with a :func:`mlx_free()` to avoid any memory
  leak. Increasing the reference count may be necessary when storing a
  MLX C object into a custom C structure.

In addition, MLX C objects come with a convenience :func:`mlx_tostring()`
function which returns a string describing the contents of the object
(which is particularly interesting for array objects).

Array
-----

The most important object in MLX C is certainly the :doc:`array <array>`
(:class:`mlx_array`), which holds the data on which computations are
performed. As MLX is `lazy
<https://ml-explore.github.io/mlx/build/html/usage/lazy_evaluation.html>`_,
the contents of the array obtained via the :func:`mlx_array_data_*()` functions are
valid only if :func:`mlx_eval()` as been called (see
:doc:`transforms <transforms>`).


Vector of Arrays, and Vector of Vector of Arrays
------------------------------------------------

:doc:`Vector of arrays <vecarray>` (:class:`mlx_vector_array`) can hold
multiple arrays, and :doc:`vector of vector arrays <vecvecarray>`
(:class:`mlx_vector_vector_array`) can hold multiple vector of arrays.

An array added to a :class:`mlx_vector_array` will stay alive until the
vector of arrays is destroyed (via :func:`mlx_free()`). Arrays returned by
:func:`mlx_vector_array_get()` will need to be matched with a corresponding
:func:`mlx_free()`.

Same idea applies to :class:`mlx_vector_vector_array`.


Device and Stream
-----------------

In MLX, arrays are not tied to a device. Instead, operations on arrays are
scheduled on a :doc:`stream <stream>`, which is associated to a particular
:doc:`device <device>`.

MLX C provides :class:`MLX_CPU_STREAM` and
:class:`MLX_GPU_STREAM`, which point to the default CPU and GPU
streams. See the basic `MLX C example
<https://github.com/ml-explore/mlx-c/blob/main/examples/example.c>`_.

String and Maps
---------------

MLX C has a :class:`mlx_string` which :doc:`encapsulates a C char
pointer <string>`. Just like other MLX C objects, it must be freed with 
:func:`mlx_free()`.

MLX C also has a :doc:`string-to-array map <map>` named
:class:`mlx_map_string_to_array`.

Array Operations
----------------

Many array :doc:`operations <ops>` are available, with additional support
for :doc:`random number generation <random>`, and :doc:`FFTs <fft>`. Advanced
:doc:`linear algebra operations <linalg>` are in their early stages.

IO Operations
-------------

MLX C wraps a number of :doc:`array IO operations <io>`, which save and
load arrays in several common formats. See :doc:`IO utils <ioutils>` for
specific MLX objects defined for IO purposes.


Function Transformations
------------------------

MLX supports the concept of `function transforms
<https://ml-explore.github.io/mlx/build/html/python/transforms.html>`_.

These are also available in MLX C through the use of
:doc:`closures <closure>` that contain a C function pointer and
optional payloads. Closures obey the same memory management rules as
other MLX C objects and must be release with a matching :func:`mlx_free()`
call.

MLX C :doc:`transforms <transforms>` will are applied on closures and may
return closures.

For more details, see the `example using closures
<https://github.com/ml-explore/mlx-c/blob/main/examples/example-grad.c>`_.

Compilation
-----------

When using the same function multiple times, compilation may be beneficial.
Compiling functions makes them more efficient by reducing redundant work,
fusing kernels, and reducing overhead. :doc:`Compilation operations <compile>`
are function transformations which take a closure and return a new closure
(which is the compiled version of the given closure).

Fast Custom Ops
===============

To maximize performance MLX has :doc:`fast <fast>` custom implementations
for some common operations.

Metal backend-specific functions
================================

MLX C exposes some useful functions related to the MLX :doc:`Metal backend
<metal>`.
