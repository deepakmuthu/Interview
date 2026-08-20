cmake_minimum_required(VERSION 3.10)

project(StudentManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(StudentManagement
    src/main.cpp
    src/Student.cpp
)