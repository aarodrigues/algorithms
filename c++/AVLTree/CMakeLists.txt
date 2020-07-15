cmake_minimum_required(VERSION 3.0.1)

project(avl)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(HEADERS "include/avl_tree.hpp")
set(SOURCES "src/avl_tree.cpp")
set(ENTRY_POINT "src/main.cpp")


# add_executable(${PROJECT_NAME} ${ENTRY_POINT})
add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})