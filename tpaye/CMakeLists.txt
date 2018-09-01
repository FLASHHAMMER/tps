cmake_minimum_required(VERSION 3.5)
project(tpaye)

set(CMAKE_CXX_STANDARD 11)

# Leemos todos los archivos fuentes en ./src
file(GLOB SOURCE_FILES *.cpp *.h *.hpp)

add_executable(ej1 Ejercicio1.cpp)
add_executable(ej2 Ejercicio2.cpp)
add_executable(ej3 Ejercicio3.cpp)
