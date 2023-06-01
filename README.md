# cubpackpp

I needed a solid cubature library and stumbled upon `cubpack++`. However, the version I received hadn't been touched since 1997 and therefore wouldn't compile. This repo is my attempt at getting it to work with C++17 and above with CMake.

## Changes

- Use of STL tools
- Namespaces to avoid naming conflicts with other libraries
- CMake build system

## Usage

Add `cubpackpp` as a submodule to your project:

```bash
mkdir extern && cd extern
git submodule add https://github.com/iwishiwasaneagle/cubpackpp
git submodule update --init
```

Then include it in your `CMakeLists.txt` with `add_subdirectory(extern/cubpackpp)`. Finally, link the library using `cubpackpp::cubpackpp`.


## Authors

- Ronald Cools
- Luc Pluym
- Dirk Laurie


## References

- `Algorithm 764: Cubpack++: a C++ package for automatic two-dimensional cubature` [🔗](https://dl.acm.org/doi/10.1145/244768.244770)
