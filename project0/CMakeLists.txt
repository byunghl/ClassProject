cmake_minimum_required(VERSION 2.8)


set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)


set(TARGET_NAME "a.out")

project(${TARGET_NAME})

file(GLOB_RECURSE ALL_SRC_FILES "src/*.cpp")

add_definitions("-std=c++11 -Wall -g")

include_directories(/usr/local/lib/llvm-3.4/clang/3.4/include)
include_directories(src)

add_executable(${TARGET_NAME} ${ALL_SRC_FILES})

