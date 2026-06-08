cmake_minimum_required(VERSION 4.2)
project(Proyecto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto
        ICalificable.hpp
        Video.cpp
        Video.hpp
        Capitulo.cpp
        Capitulo.hpp
        Serie.cpp
        Serie.hpp
        Pelicula.cpp
        Pelicula.hpp
        CalificacionInvalida.cpp
        CalificacionInvalida.hpp
        Catalogo.cpp
        Catalogo.hpp
)
