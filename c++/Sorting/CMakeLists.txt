cmake_minimum_required(VERSION 3.0.1)

set(CMAKE_CXX_STANDARD 11)
project(sorting)


include_directories(include)

set(HEADERS "include/bubblesort.hpp" "include/mergesort.hpp" "include/quicksort.hpp")
set(SOURCES "src/bubblesort.cpp" "src/mergesort.cpp" "src/quicksort.cpp")
set(ENTRY_POINT "src/main.cpp")

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} ${SOURCES})
# add_executable(${PROJECT_NAME} ${ENTRY_POINT})

