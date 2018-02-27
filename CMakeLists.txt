cmake_minimum_required(VERSION 3.9)
project(viking)

set(CMAKE_CXX_STANDARD 98)

add_executable(viking src/main.cpp src/Pid.cpp src/Pid.h src/Controller.cpp src/Controller.h src/Envelop.cpp src/Envelop.h src/PowerEnvelop.cpp src/PowerEnvelop.h)