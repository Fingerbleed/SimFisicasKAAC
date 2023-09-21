cmake_minimum_required(VERSION 3.26)
project(hello_world)

set(CMAKE_CXX_STANDARD 17)

add_executable(hello_world main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(hello_world PRIVATE box2d::box2d)