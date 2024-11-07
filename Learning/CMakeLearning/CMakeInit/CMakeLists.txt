cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    CMakeInit
    VERSION 0.1.0
    DESCRIPTION "Test the cmake init"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    CMakeInit_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    CMakeInit_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(CMakeInit_lib PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(CMakeInit_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(CMakeInit_exe source/main.cpp)
add_executable(CMakeInit::exe ALIAS CMakeInit_exe)

set_property(TARGET CMakeInit_exe PROPERTY OUTPUT_NAME CMakeInit)

target_compile_features(CMakeInit_exe PRIVATE cxx_std_17)

target_link_libraries(CMakeInit_exe PRIVATE CMakeInit_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT CMakeInit_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of CMakeInit"
  )
endif()

include(cmake/dev-mode.cmake)
