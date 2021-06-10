cmake_minimum_required(VERSION 3.17)
project(dom_mandelbrot)

set(CMAKE_CXX_STANDARD 14)

add_executable(dom_mandelbrot main.cpp Complejo.cpp Complejo.h)