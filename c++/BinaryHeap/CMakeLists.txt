cmake_minimum_required(VERSION 3.0.1)

project(binary_heap)

include_directories(include)

set(HEADERS "include/max_heap.hpp")
set(SOURCES "src/max_heap.cpp")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})