cmake_minimum_required(VERSION 3.5)

project(test)

add_executable(${CMAKE_PROJECT_NAME} test.c example.c)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE .)
