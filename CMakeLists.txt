cmake_minimum_required(VERSION 3.8)

project(projekt)

add_executable(main main.cpp)
set_target_properties(main PROPERTIES
    CXX_STANDARD 19
)
