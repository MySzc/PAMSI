cmake_minimum_required(VERSION 3.13)
project(Sortowanie)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Sortowanie main.cpp merge_sort.cpp merge_sort.h array_init.cpp array_init.h heap_sort.cpp heap_sort.h)