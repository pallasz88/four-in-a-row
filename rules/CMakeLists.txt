cmake_minimum_required(VERSION 3.16)
project(rules)

set(library rules)
include(${CMAKE_SOURCE_DIR}/tools/cmake/conan.cmake)

find_package(GTest REQUIRED)

set(SOURCES
        src/board.hpp
        src/board.cpp
)

set(game four_in_row)

add_library(${game}_${PROJECT_NAME} SHARED)
target_sources(${game}_${PROJECT_NAME} PRIVATE ${SOURCES})
target_compile_features(${game}_${PROJECT_NAME} PRIVATE cxx_std_20)

add_executable(${game}_${PROJECT_NAME}_test test/unittest_board.cpp)
add_test(NAME ${game}_${PROJECT_NAME}_test COMMAND ${game}_${PROJECT_NAME}_test WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/rules/bin)
target_compile_features(${game}_${PROJECT_NAME}_test PRIVATE cxx_std_20)
target_link_libraries(${game}_${PROJECT_NAME}_test PRIVATE optimized ${game}_${PROJECT_NAME} CONAN_PKG::gtest)
