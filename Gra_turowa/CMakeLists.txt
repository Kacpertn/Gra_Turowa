cmake_minimum_required(VERSION 3.22)
project(Gra_turowa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Gra_turowa main.cpp Creatures.cpp creatures.hpp effectiveness.cpp effectiveness.hpp player.hpp player.cpp gameround.cpp gameround.hpp save.cpp save.hpp)
