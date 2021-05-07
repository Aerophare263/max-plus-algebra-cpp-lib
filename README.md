# Max-Plus Algebra Library
Also known as a [max tropical semiring](https://en.wikipedia.org/wiki/Tropical_semiring) is useful
when working with timetabling (e.g. railway timetables). This library supports all basic oplus and
otimes operations on integer literals and integer matrices.

# Installation
The project is built with [bazel](https://bazel.build) and what follows are the steps to include
this library in another bazel project.
1. Add the following to the ```WORKSPACE.bazel``` file 
```
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "libmaxplus",
    url = "https://github.com/tomasz-lisowski/libmaxplus/archive/master.zip",
    strip_prefix = "libmaxplus-master",
)
```
2. Edit or add the `deps` argument in the `cc_binary` rule to contain `"@libmaxplus//:libmaxplus"`.
   The argument should look something like `deps = ["@libmaxplus//:libmaxplus"],`.
3. In the source files it's now possible to `#include "libmaxplus.hpp">`.
