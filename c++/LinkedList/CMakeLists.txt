cmake_minimum_required(VERSION 3.0.1)

project(linkedlist)

set(HEADERS "include/linked_list.hpp")
set(SOURCES "src/linked_list.cpp")
set(ENTRY_POINT "src/main.cpp")

include_directories(include)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${ENTRY_POINT})