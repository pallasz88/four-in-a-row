cmake_minimum_required(VERSION 3.16)
project(four_in_a_row
        VERSION 1.0.0
        DESCRIPTION "4 in a row board game with NN engine"
        LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(rules)
# add_subdirectory(gui)
# add_subdirectory(nn_engine)

add_executable(main main.cpp)
