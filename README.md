# Dusk

The Dusk repository contains a series of examples which show usage of
the Dawn native API. Each example is designed to be standalone so each
example contains copies of all the required code for that example. This should
make it easier to determine exactly what code is needed at any given point.

Note, the README.md files in each folder only talk about the new ideas and
concepts provided in that example. So, looking at README.md files in earlier
examples maybe needed to understand the concepts that were introduced earlier.

This is not an officially supported Google product.

## Requirements
 * `depot_tools`
 * `cmake`
 * `ninja`
 * `clang` or `gcc`


## Building
```
gclient sync --jobs=16
mkdir -p out/Debug
cd out/Debug
CC=clang CXX=clang++ cmake -GNinja ../..
ninja
```

## Setup
Dawn has a lot of dependencies, in order to simplify things this repo is using
the `gclient` command from
[depot_tools](https://commondatastorage.googleapis.com/chrome-infra-docs/flat/depot_tools/docs/html/depot_tools_tutorial.html#_setting_up)
to handle the heavy lifting of checkout out all the needed dependencies.

In order to make `gclient` happy we require a `git` repo for our project and it
needs to have an commit. Simply doing the following will get things setup for
`.gclient`.

```
mkdir <project> && cd <project>
git init
touch README.md
git add .
git commit -m 'Initial commit'
```

Two files are needed for `gclient`. First copy in [.gclient](./.gclient) which is
the basic `gclient` setup file. Then, copy in [DEPS](./DEPS) which is the
dependency configuration file.

For our purposes a specific revision of Dawn is chosen (the tip-of-tree commit
at random point in time). This is done such that every checkout will get the
same version of Dawn and we can upgrade Dawn in a controlled fashion.

The `recursedeps` section tells `gclient` to go into the `third_party/dawn`
folder and run the `DEPS` file found there. This will checkout all of the Dawn
dependencies at the correct commit for Dawn (and recursively as needed).

The examples are using `CMake` for build configuration. The CMake is pretty
standard, c++20 is used for a few of the newer features. The only things of note
are, adding the `third_party/dawn/include` directory to the `target_include_directories`
and when linking the executable we add the following to the `target_link_libraries`:

* `webgpu_dawn`
* `webgpu_cpp`
* `webgpu_glfw`
* `glfw`

The last two are only needed because `GLFW` is being used for the window management.
If something else is providing the window, and code is written to create the
needed surface, the last two libraries can be removed.

## Examples

The following examples are provided:

* [01 - Adapter and Device Information](src/example_01/README.md)
* [02 - Coloured Triangle](src/example_02/README.md)
* [03 - Using an Index Buffer](src/example_03/README.md)
* [04 - Rotating Cube](src/example_04/README.md)

## Doc Site
The documentation site is served by GitHub pages. The generate is Jekyll. There
are current two parts to the docs site, the C and C++ API generator and the site
itself.

### C and C++ API Generator
The generator for the C and C++ API is `scripts/api_doc_generator.rb`. This script
reads the `dawn.json` file in the `third_party/dawn` folder along with the
`src/api.yaml` file and generates the API documentation.

Warning messages are emitted for items in the `dawn.json` file which are not found
in the `api.yaml` file. This should help in making sure all the appropriate
values are documented, and hopefully catch API changes in `dawn.json` during
future upgrades.

Running the generator should just consist of:

```shell
./scripts/api_doc_generator.rb
```

### Jekyll Site
The Jekyll site lives in the `docs` folder. In order to test the doc changes you'll
need to install some RubyGems. This can be done with:

```shell
cd docs
bundle install
```

With the appropriate gems installed, the site can be run by executing (still in
the docs folder):

```
jekyll serve
```

This should launch the site on `localhosts:4000`.
