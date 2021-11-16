cmake_minimum_required(VERSION 3.13)

project(cafetiere LANGUAGES CXX)

set(CXX_STANDARD C++17)

add_executable(cafeteria Bouilloire.cpp Cafeteria.cpp Cafetiere.cpp CafetierePoudre.cpp CafetiereSoluble.cpp Reservoir.cpp
                         ReservoirEau.cpp ReservoirPoudre.cpp ReservoirSoluble.cpp)

