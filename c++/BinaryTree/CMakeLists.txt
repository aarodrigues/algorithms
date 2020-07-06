cmake_minimum_required(VERSION 3.0.1)

project(binarytree)

include_directories(include)

# set(HEADERS "include/binary_tree")
# set(SOURCES "src/binary_tree")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT})