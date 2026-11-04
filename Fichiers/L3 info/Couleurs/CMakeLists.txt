cmake_minimum_required(VERSION 3.16)

project(Couleurs LANGUAGES CXX)

add_executable(Couleurs main.cpp
    sequence.cpp
    sequence.hpp)

target_compile_features(Couleurs PUBLIC cxx_std_17)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
target_compile_options(Couleurs PRIVATE -Wall -Wpedantic)
endif()
