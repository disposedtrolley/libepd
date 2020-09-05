# libepd

![CI](https://github.com/disposedtrolley/libepd/workflows/CI/badge.svg)

## Tests

Tests are handled by [Catch2](https://github.com/catchorg/Catch2) and built via CMake in the `/tests` directory.

To run the tests:

1. Build the CMake project:
    - `mkdir build && cd build`
    - `cmake ..`
2. Execute test target:
    - `make test`
