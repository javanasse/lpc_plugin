# Linear Predictive Coding Plugin with JUCE

## Build

### CMake
This project uses CMake as a build system generator. You will also need a C++ compiler installed on your machine.

### Dependencies

Collect `JUCE` with:
```
git submodule update --init --recursive
```

<!-- Install dependencies that are managed using `conan`:
```shell
conan install . --build=missing -s build_type=Release
conan install . --build=missing -s build_type=Debug
``` -->

Configure the project:
```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

The build:
```shell
cmake --build build
```

## References
Thanks to the [Princeton Sound Lab](https://soundlab.cs.princeton.edu/) for the LPC implementation!