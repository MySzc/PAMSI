cmake_minimum_required(VERSION 3.13)
project(Grafy)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Grafy main.cpp MacierzSasiedztwa.cpp MacierzSasiedztwa.h ListaSasiedztwa.cpp ListaSasiedztwa.h Dijkstra.cpp Dijkstra.h BellmanFord.cpp BellmanFord.h)