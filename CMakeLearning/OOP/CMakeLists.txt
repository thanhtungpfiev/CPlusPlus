cmake_minimum_required(VERSION 3.12)

project (OOP)

add_executable(OOPExe main.cpp src/Shape/Shape.cpp src/Shape/Triangle/Triangle.cpp)
target_include_directories(OOPExe PRIVATE include/Shape include/Shape/Triangle)