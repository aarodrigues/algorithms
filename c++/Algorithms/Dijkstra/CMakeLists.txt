cmake_minimum_required(VERSION 3.0.1)

project(dijkstra)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...

set(HEADERS "dijkstra.hpp")
set(ENTRY_POINT "main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} )