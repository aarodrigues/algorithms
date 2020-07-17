cmake_minimum_required(VERSION 3.0.1)

project(memoization)
include_directories(include)

set(HEADER "include/memoization.cpp")
set(SOURCES "src/memoization.cpp")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})