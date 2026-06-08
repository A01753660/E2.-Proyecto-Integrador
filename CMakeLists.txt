cmake_minimum_required(VERSION 4.2)
project(Proyecto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto
        main.cpp
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

add_custom_command(TARGET Proyecto POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/Proyecto.txt
        $<TARGET_FILE_DIR:Proyecto>)