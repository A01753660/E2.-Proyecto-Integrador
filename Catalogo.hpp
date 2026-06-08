//
// Created by Farid on 07/06/2026.
//

#ifndef PROYECTO_CATALOGO_HPP
#define PROYECTO_CATALOGO_HPP

#include <string>
#include "Video.hpp"

using namespace std;

class Catalogo {
private:
    Video* videos[200];
    int numVideos;

public:
    Catalogo();
    void cargarArchivo(string);
    void mostrarVideos(int califMin);
    void mostrarPorGenero(string);
    void mostrarPeliculas(int califMin);
    void mostrarEpisodios(string, int);
    void calificarVideo(string, int);
};

#endif //PROYECTO_CATALOGO_HPP
