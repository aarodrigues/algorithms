cmake_minimum_required(VERSION 3.0.1)

project(hash_table)

include_directories(include)

set(HEADERS "include/hash_table.hpp")
set(SOURCES "src/hash_table.cpp")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})