cmake_minimum_required(VERSION 3.0.1)

project(queue)

include_directories(include)

set(HEADERS "include/queue.hpp")
set(SOURCES "src/queue.cpp")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})