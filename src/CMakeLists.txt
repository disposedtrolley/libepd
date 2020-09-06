set(HEADER_LIST "${CMAKE_CURRENT_SOURCE_DIR}/../include/libepd/libepd.hpp")

add_library(libepd ${CMAKE_CURRENT_SOURCE_DIR}/libepd.cpp ${HEADER_LIST})

target_include_directories(libepd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_compile_features(libepd PUBLIC cxx_std_14)