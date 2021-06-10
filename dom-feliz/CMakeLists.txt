cmake_minimum_required(VERSION 3.17)
project(dom_feliz)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dom_feliz
        Error.h
        main.cpp
        SetOfInts3.cpp
        SetOfInts3.h)
