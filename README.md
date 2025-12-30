# SimpleJucePluginTemplate

## Installation

You'll need to build `fftw` the first time you install it:

```shell
conan install . --output-folder build --build=fftw/3.3.10
```

Every other time you can exclude the `--build` flag
```shell
conan install . --output-folder build 
```

### CMake

Configure the project:
```shell
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
```

The build:
```shell
cmake --build build
```