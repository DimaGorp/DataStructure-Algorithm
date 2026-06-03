cmake_minimum_required(VERSION 3.28)

project(DSAA)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
add_library(linked_list ${PROJECT_SOURCE_DIR}/src/list/linked_list.cpp)
target_include_directories(linked_list PUBLIC ${PROJECT_SOURCE_DIR}/include/list/) 

add_library(array INTERFACE ${PROJECT_SOURCE_DIR}/include/array/array.hpp) 
target_include_directories(array INTERFACE ${PROJECT_SOURCE_DIR}/include/array/)

add_subdirectory(examples)
