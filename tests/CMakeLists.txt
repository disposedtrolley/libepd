find_package(Catch2 REQUIRED)

add_executable(testlib ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
target_link_libraries(testlib PRIVATE libepd Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(testlib)

add_test(NAME testlibtest COMMAND testlib)