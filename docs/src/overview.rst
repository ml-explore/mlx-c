Overview
========

MLX C wraps and follows as closely as possible the C++ API of `MLX
<https://github.com/ml-explore/mlx>`_.

C Object
--------

MLX C relies on several C `struct` which are all compatible with a private
:doc:`object struct <object>` (that we will refer as a MLX C object),
which implements basic memory management. When using MLX C, it is important
to note that:

* All returned C objects come with a reference count of 1, which needs to
  be decreased with a matching :func:`mlx_free()` call.

* When the reference count of an object gets to 0, the object is freed.

* Reference count may be increased via :func:`mlx_retain()`, in which case it
  should be matched at some point with a :func:`mlx_free()` to avoid any memory
  leak. Increa ing the reference count may be necessary when one stores a
  MLX C object into a custom C structure.

In addition, MLX C objects come with a convenience :func:`mlx_tostring()`
function which returns a string describing the contents of the object
(which is particularly interesting for array objects).

Array
-----

The most important object in MLX C is certainly the :doc:`array <array>`
(:class:`mlx_array`), which holds data on which computation are
performed. As MLX is `lazy
<https://ml-explore.github.io/mlx/build/html/usage/lazy_evaluation.html>`_,
contents of the array obtained via :func:`mlx_array_data_*()` functions are
valid only if :func:`mlx_eval()` as been called before (see
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
scheduled on a :doc:`stream <stream>`, itself attached to a particular
:doc:`device <device>`.

MLX C provides convenient :class:`MLX_CPU_STREAM` and
:class:`MLX_GPU_STREAM`, which point to the default CPU and GPU
streams. See the basic `MLX C example
<https://github.com/ml-explore/mlx-c/blob/main/examples/example.c>`_.

String and Maps
---------------

MLX C comes with a :class:`mlx_string` which :doc:`encapsulates a C char
pointer <string>`. As for other MLX C objects, it must be freed via
:func:`mlx_free()`.

We also have a :doc:`string-to-array map <map>`, called
:class:`mlx_map_string_to_array`.


Array Operations
----------------

Many array :doc:`operations <ops>` are available, with additional support
for :doc:`random number generation <random>`, :doc:`FFT <fft>`. Advanced
:doc:`linear algebra operations <linalg>` are in their early stages.

IO Operations
-------------

MLX C comes with a number of :doc:`array IO operations <io>`, which help to
serialize and deserialize arrays in several popular formats.

Function Transformations
------------------------

MLX supports the concept of `function transforms
<https://ml-explore.github.io/mlx/build/html/python/transforms.html>`_.

The same idea is transposed in MLX C, with support for several type of
:doc:`closures <closure>` which can encapsulate a C function pointer, with
optional payloads. Closures obey the same memory management rules than
other MLX C objects, and must be release with a matching :func:`mlx_free()`
call.

MLX C :doc:`transforms <transforms>` will be applied on closures, and may
return closures.

For a quickstart, see our `example using closures
<https://github.com/ml-explore/mlx-c/blob/main/examples/example-grad.c>`_.

Compilation
-----------

If one re-uses over and over a given function, then it may be beneficial to
compile this function, to limit the overhead induced by the construction of
the graph representing the function. MLX compilation also supports some
kernel fusion. :doc:`Compilation operations <compile>` are a form of
function transformations, taking a closure, and return a new closure (which
is the compiled version of the given closure).
