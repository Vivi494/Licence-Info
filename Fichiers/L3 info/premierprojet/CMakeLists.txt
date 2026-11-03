cmake_minimum_required(VERSION 3.16)

project(premierprojet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(premierprojet main.cpp
    sequence.hpp
    sequence.cpp)

include(GNUInstallDirs)
install(TARGETS premierprojet
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
