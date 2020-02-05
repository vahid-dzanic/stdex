cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(stdex VERSION 1.0.0)

set(HEADER_FILES
  include/stdex/array_ex.h
  include/stdex/deque_ex.h
  include/stdex/forward_list_ex.h
  include/stdex/functional_ex.h
  include/stdex/list_ex.h
  include/stdex/map_ex.h
  include/stdex/pair_ex.h
  include/stdex/queue_ex.h
  include/stdex/set_ex.h
  include/stdex/stack_ex.h
  include/stdex/std_type_sets.h
  include/stdex/string_ex.h
  include/stdex/traits_ex.h
  include/stdex/tuple_ex.h
  include/stdex/unordered_map_ex.h
  include/stdex/unordered_set_ex.h
  include/stdex/vector_ex.h)

add_library(${PROJECT_NAME} SHARED
  src/functional_ext.cpp
  src/string_ext.cpp)
add_library(vdc::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    PUBLIC_HEADER "${HEADER_FILES}"
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}")

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    src)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    -Werror
    -Wall
    -Wextra
    $<$<BOOL:${CMAKE_COMPILER_IS_CLANGCXX}>:-Weverything>)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-config
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})
configure_file(${PROJECT_SOURCE_DIR}/config/config.cmake ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake @ONLY)
install(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake DESTINATION cmake)

# init variables if not defined
if(NOT DEFINED STDEX_BUILD_WITH_TESTS)
  set(STDEX_BUILD_WITH_TESTS ON)
endif()

if (${STDEX_BUILD_WITH_TESTS})
  enable_testing()
  add_subdirectory(test)
endif()
