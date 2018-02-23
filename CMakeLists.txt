cmake_minimum_required(VERSION 3.9)
project(viking)

set(CMAKE_CXX_STANDARD 98)

add_executable(viking main.cpp Pid.cpp Pid.h Scanner.cpp Scanner.h)