cmake_minimum_required(VERSION 3.2)
project(ex1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wextra")

set(SOURCE_FILES StringChange.c)
add_executable(ex1 ${SOURCE_FILES}  NimGame.c)