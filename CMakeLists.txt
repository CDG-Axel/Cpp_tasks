cmake_minimum_required(VERSION 3.24)
project(Cpp_tasks)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Cpp_tasks main.cpp stepik.cpp stepik.h)
