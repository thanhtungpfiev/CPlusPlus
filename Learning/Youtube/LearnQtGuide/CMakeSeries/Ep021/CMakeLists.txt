#[=[
     Exploring FetchContent.
#]=]

cmake_minimum_required(VERSION 3.21)
project(rooster)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(AddFmt)

add_executable(${PROJECT_NAME} main.cpp person.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

include(ClangFormat)
add_clang_format_target(format-code ${PROJECT_SOURCE_DIR})