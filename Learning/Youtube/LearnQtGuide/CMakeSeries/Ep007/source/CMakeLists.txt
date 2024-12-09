cmake_minimum_required(VERSION 3.5)
project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The leading Hello World App"
        LANGUAGES CXX)

set(CXX_STANDARD_REQUIRED ON) #Make C++20 a hard requirement
set(CMAKE_CXX_STANDARD 20) # Default C++ standard for targets

# Library
SET(OPERATIONS_LIB "operations")
add_library(${OPERATIONS_LIB} STATIC src/operations.cpp)
target_include_directories(${OPERATIONS_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

SET(LOGGER_LIB "logger")
add_library(${LOGGER_LIB} STATIC logger/src/log.cpp)
target_include_directories(${LOGGER_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logger/include)

# Target
add_executable(${PROJECT_NAME} main.cpp
        src/dog.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPERATIONS_LIB} ${LOGGER_LIB})