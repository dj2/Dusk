# Dusk

The Dusk repository contains a series of examples which show usage of
the Dawn native API. 

This is not an officially supported Google product.

## Requirements
 * `git`
 * `cmake`
 * `ninja`
 * `clang` or `gcc`


## Building
```
git submodule init
git submodule update
mkdir -p out/Debug
cd out/Debug
CC=clang CXX=clang++ cmake -GNinja ../..
ninja
```

## Setup
Dawn has a lot of dependencies, in order to simplify things we're using git
submodules to handle the heavy lifting of checkout out all the needed
dependencies.

The examples are using `CMake` for build configuration. The CMake is pretty
standard, c++23 is used for a few of the newer features. When linking the executables we add the following to the `target_link_libraries`:

* `webgpu_dawn`
* `webgpu_cpp`
* `webgpu_glfw`
* `glfw`

The last two are only needed because `GLFW` is being used for the window
management. If something else is providing the window, and code is written to
create the needed surface, the last two libraries can be removed.

## Examples

The following examples are provided:

* [01 - Adapter and Device Information](src/example_01/README.md)
* [02 - Coloured Triangle](src/example_02/README.md)
* [03 - Using an Index Buffer](src/example_03/README.md)
* [04 - Rotating Cube](src/example_04/README.md)

