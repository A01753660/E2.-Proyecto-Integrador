//
// Created by Farid on 07/06/2026.
//

#ifndef PROYECTO_CAPITULO_HPP
#define PROYECTO_CAPITULO_HPP

#include <string>
#include "ICalificable.hpp"
using namespace std;

class Capitulo : public ICalificable {
private:
    string titulo;
    int temporada;
    int calificaciones[100];
    int numCalif;

    public:
    Capitulo();
    Capitulo(string, int);
    string mostrarInfo();
    void calificar(int) override;
    float getPromedio() override;
};

#endif //PROYECTO_CAPITULO_HPP
