cmake_minimum_required(VERSION 3.26)
project(polynomials)

set(CMAKE_CXX_STANDARD 17)

add_executable(polynomials main.cpp
        polynomials.cpp
        polynomials.h)
