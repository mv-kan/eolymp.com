cmake_minimum_required(VERSION 3.27)

set(
    TARGET
    problem
)

project(${TARGET} CXX)

set(
    SOURCES
    src/main.cpp
)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Werror")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g -Werror -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_STANDARD 20)

add_executable(${TARGET} ${SOURCES})