cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

find_package(GTest REQUIRED)

add_executable(fast_stdex
  src/test_stdext_traits.cpp)

target_link_libraries(fast_stdex
  PRIVATE
    stdex
    GTest::GTest
    GTest::Main)

target_compile_options(fast_stdex
  PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
    -Werror
    -Wall
    -Wextra
    $<$<BOOL:${CMAKE_COMPILER_IS_CLANGCXX}>:-Weverything>)

add_test(fast_stdex fast_stdex)
