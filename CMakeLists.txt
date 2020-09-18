cmake_minimum_required(VERSION 3.17)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB RESOURCES "src/*.cpp")


add_executable(leetcode main.cpp ${RESOURCES})