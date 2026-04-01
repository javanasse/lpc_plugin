# Linear Predictive Coding Plugin with JUCE

## Build

This project is built using CMake. The dependency on JUCE is collected using `FetchContent`.

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