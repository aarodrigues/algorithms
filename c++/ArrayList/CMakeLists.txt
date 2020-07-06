cmake_minimum_required(VERSION 3.0.1)
project(arraylist)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(HEADERS "include/array_list.hpp")
set(SOURCES "src/array_list.cpp")
set(ENTRY_POINT "src/main.cpp")

# add_library(${HEADERS} ${SOURCES} ${ENTRY_POINT})
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${ENTRY_POINT})
