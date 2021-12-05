cmake_minimum_required(VERSION 3.19)
project(mirlon_0206)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mirlon_0206
        StringSet.cpp
        StringSet.h
        basictest.cpp)
