// Alejandro Sánchez Calderón A01754913

#ifndef PROYECTO_PELICULA_HPP
#define PROYECTO_PELICULA_HPP
#include "Video.hpp"
using namespace std;

class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(string,string,int, string);
    string getTipo() override;
    string mostrarInfo() override;



};


#endif //PROYECTO_PELICULA_HPP
