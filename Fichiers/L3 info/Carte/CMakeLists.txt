cmake_minimum_required(VERSION 3.16)

project(Carte LANGUAGES CXX)

add_executable(Carte main.cpp
    tailleposition.h tailleposition.cpp)

target_compile_features(Carte PUBLIC cxx_std_17)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
target_compile_options(Carte PRIVATE -Wall -Wpedantic)
endif()
