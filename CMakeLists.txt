# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(Todos)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

# Set the compiler config
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(flags "-std=c++1z -stdlib=libc++ -m64 -Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(flags "/std:c++17 /W4 /WX /EHsc /ZI /MACHINE:X64")
endif()
  
if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${flags}")
endif()

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(Todos ${PROJECT_SOURCE_DIR}/main.cpp
  ${PROJECT_SOURCE_DIR}/todos.cpp)

