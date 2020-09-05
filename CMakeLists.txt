cmake_minimum_required(VERSION 3.17)
project(libepd LANGUAGES CXX VERSION 0.0.1)

enable_testing()

add_subdirectory(tests)

add_subdirectory(src)