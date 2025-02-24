cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PersonProject)

# Add the executable
add_executable(PersonProject src/Person.cpp src/main.cpp)