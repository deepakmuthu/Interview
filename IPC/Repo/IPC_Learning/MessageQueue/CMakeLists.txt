cmake_minimum_required(VERSION 3.10)

project(MessageQueueDemo)

set(CMAKE_CXX_STANDARD 17)

add_executable(sender sender.cpp)
add_executable(receiver receiver.cpp)

target_link_libraries(sender rt)
target_link_libraries(receiver rt)