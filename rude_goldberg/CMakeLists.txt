cmake_minimum_required(VERSION 3.26)
project(rude_goldberg)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(rude_goldberg main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(rude_goldberg PRIVATE box2d::box2d sfml-graphics)