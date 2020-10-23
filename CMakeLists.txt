cmake_minimum_required(VERSION 3.11)

project(ximd)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -O2 -msse3 -lrt -DNDEBUG")

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(bench)
