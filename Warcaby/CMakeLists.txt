cmake_minimum_required(VERSION 3.14)
project(Warcaby)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )


add_executable(Warcaby main.cpp plansza.cpp plansza.h wielkosci.h usprawnienia.cpp usprawnienia.h akcesoriaDoGry.cpp akcesoriaDoGry.h gra.cpp gra.h)

set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window audio network system REQUIRED)

target_link_libraries(Warcaby sfml-graphics sfml-window sfml-audio sfml-network sfml-system)