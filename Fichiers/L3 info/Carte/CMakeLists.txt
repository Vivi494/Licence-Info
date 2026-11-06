cmake_minimum_required(VERSION 3.16)

project(Carte LANGUAGES CXX)

find_package(SFML COMPONENTS graphics window system)
include(FetchContent)
FetchContent_Declare(Catch2 URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.7.1.zip )
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
enable_testing()

add_executable(Carte
    tailleposition.hpp tailleposition.cpp main_test.cc
    element.hpp element.cpp)

target_compile_features(Carte PUBLIC cxx_std_17)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
target_compile_options(Carte PRIVATE -Wall -Wpedantic)
endif()
target_link_libraries(Carte PRIVATE Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(Carte)
