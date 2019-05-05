cmake_minimum_required(VERSION 3.13)
project(Hirolsy)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Hirolsy main.cpp)
target_link_libraries(Hirolsy sfml-graphics sfml-audio)
target_link_libraries(Hirolsy "stdc++fs")

