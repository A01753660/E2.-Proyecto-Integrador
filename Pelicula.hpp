//
// Created by Farid on 07/06/2026.
//

#ifndef PROYECTO_PELICULA_HPP
#define PROYECTO_PELICULA_HPP
#include "Video.hpp"
using namespace std;

class Pelicula : Video {
    public:
    Pelicula();
    Pelicula(string,string,int, string);
    string mostrarInfo() override;



};


#endif //PROYECTO_PELICULA_HPP
