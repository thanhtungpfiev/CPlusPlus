# CMakeList.txt : CMake project for SimpleCPlusPlusClass, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (SimpleCPlusPlusClass "SimpleCPlusPlusClass.cpp" "SimpleCPlusPlusClass.h" "ComplexNumber.h" "ComplexNumber.cpp" "Student.h" "Student.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SimpleCPlusPlusClass PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
