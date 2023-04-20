cmake_minimum_required(VERSION 3.12)

project (Foo)

file(GLOB_RECURSE Foo_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE Foo_HEADERS CONFIGURE_DEPENDS "include/*.h")

set(Foo_INCLUDE_DIRS "")

foreach(_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()

list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

add_executable(FooExe main.cpp ${Foo_SOURCES})
target_include_directories(FooExe PRIVATE ${Foo_INCLUDE_DIRS})