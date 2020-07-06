cmake_minimum_required(VERSION 3.0.1)
project(arraylist)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(HEADERS "include/array_list.hpp")
set(SOURCES "src/array_list.cpp")
set(ENTRY_POINT "src/main.cpp")

# add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${ENTRY_POINT})

set(PROJECT_LIB ${PROJECT_NAME}_library)
add_library(${PROJECT_LIB} ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_LIB} PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} ${ENTRY_POINT})
target_link_libraries (${PROJECT_NAME} ${PROJECT_LIB})

# enable ctest tool
enable_testing()
add_subdirectory(test)
