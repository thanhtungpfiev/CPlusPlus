# FILEPATH: /C:/Wind/PrivateDocuments/CodePractices/CPlusPlus/CMakeLearning/CMakeProjectWithMultiFiles/CMakeLists.txt

# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Set the project name to "Foo"
project(Foo)

# Find all source files in the "src" directory and its subdirectories
file(GLOB_RECURSE Foo_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Find all header files in the "include" directory and its subdirectories
file(GLOB_RECURSE Foo_HEADERS CONFIGURE_DEPENDS "include/*.h")

# Create an empty list to store the include directories
set(Foo_INCLUDE_DIRS "")

# Iterate over each header file
foreach(_headerFile ${Foo_HEADERS})
    # Get the directory of the header file
    get_filename_component(_dir ${_headerFile} PATH)
    # Append the directory to the include directories list
    list(APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()

# Remove duplicate include directories from the list
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

# Create an executable named "FooExe" with the main.cpp file and all source files
add_executable(FooExe main.cpp ${Foo_SOURCES})

# Set the include directories for the "FooExe" target
target_include_directories(FooExe PRIVATE ${Foo_INCLUDE_DIRS})