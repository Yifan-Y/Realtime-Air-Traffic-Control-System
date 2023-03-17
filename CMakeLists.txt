cmake_minimum_required(VERSION 3.24)
project(ATC)

set(CMAKE_CXX_STANDARD 17)

add_executable(ATC main.cpp src/position.h src/position.cpp src/speed.h src/flight.cpp src/speed.cpp src/flight.h src/constants.h)
