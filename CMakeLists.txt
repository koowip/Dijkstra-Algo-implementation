cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(CSE310_Proj3)

add_executable(CSE310_Proj3 main.cpp heap.cpp graph.cpp util.cpp)