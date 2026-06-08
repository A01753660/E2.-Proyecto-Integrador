//
// Created by Farid on 07/06/2026.
//

#ifndef PROYECTO_CATALOGO_HPP
#define PROYECTO_CATALOGO_HPP
#include <string>
#include "Video.hpp"
#include "Serie.hpp"
#include "Pelicula.hpp"
#include "CalificacionInvalida.hpp"
using namespace std;

class Catalogo {
    private:
    int videos[200]= Video*;
    int numVideos;
    public:
    Catalogo();
    void cargarArchivo(string);
    void mostrarVideos( int califMin);
    void mostrarPorGenero(string);
    void mostrarPeliculas(int califMin);
    void mostrarEpisocidos(string, int);
    void calificarVideo(string, int);


};


#endif //PROYECTO_CATALOGO_HPP
