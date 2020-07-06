cmake_minimum_required(VERSION 3.0.1)

project(stack)

include_directories(include)

set(HEADERS "include/stack.hpp")
set(SOURCES "src/stack.cpp")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})