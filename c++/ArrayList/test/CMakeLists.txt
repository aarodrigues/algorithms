cmake_minimum_required(VERSION 3.0.1)

include_directories(../include)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF)
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

set(SOURCES "test_array_list.cpp")

add_executable(${PROJECT_NAME}_test ${SOURCES})

message(STATUS "include dir: ${PROJECT_NAME}")

# linking libraries 
target_link_libraries(
    ${PROJECT_NAME}_test PUBLIC
    ${GTEST_LIBRARY}
    ${GTEST_MAIN_LIBRARY}
    ${PROJECT_LIB}
)

# Allow ctest find availables tests
add_test(
    NAME ${PROJECT_NAME}_test
    COMMAND ${PROJECT_NAME}_test
)