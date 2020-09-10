cmake_minimum_required(VERSION 3.0.1)

project(sorting)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...

set(HEADERS "quicksort.hpp" "mergesort.hpp" "radixsort" "bubblesort.hpp" "insertionsort.hpp" "selectionsort.hpp")
set(ENTRY_POINT "main.cpp")

# include_directories(include)

add_executable(${PROJECT_NAME} ${ENTRY_POINT} ${HEADERS} )

# enable ctest tool
# enable_testing()
# add_subdirectory(test)