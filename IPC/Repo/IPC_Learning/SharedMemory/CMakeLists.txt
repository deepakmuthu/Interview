cmake_minimum_required(VERSION 3.10)

project(SharedMemoryDemo)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(writer Src/Writer.cpp)
add_executable(reader Src/reader.cpp)