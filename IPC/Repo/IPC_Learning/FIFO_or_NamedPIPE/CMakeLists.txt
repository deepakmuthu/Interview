cmake_minimum_required( VERSION 3.10)
project(FIFO_or_NamedPIPE)

set (CMAKE_CXX_STANDARD 17)

add_executable(Reader Reader.c)
add_executable(Writer Writer.c)