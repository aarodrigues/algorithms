cmake_minimum_required(VERSION 3.0.1)

project(binarytree)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(HEADERS "include/binary_tree")
set(SOURCES "src/binary_tree")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})