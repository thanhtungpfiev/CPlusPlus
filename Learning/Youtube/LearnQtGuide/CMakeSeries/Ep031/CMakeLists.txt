cmake_minimum_required(VERSION 3.15)
project(foo CXX)

find_package(sfml COMPONENTS graphics window system REQUIRED)

add_executable(foo src/main.cpp)
target_link_libraries(foo sfml-graphics)

install(TARGETS foo DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)
