cmake_minimum_required(VERSION 3.13)
project(StrukturyDanych)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(StrukturyDanych main.cpp stack.h node.h queue.h priorityqueue.h linkedlist.h hashmap.h)