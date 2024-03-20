cmake_minimum_required(VERSION 3.0)
project(DBMS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(DBMS main.cpp src/table.cpp)
