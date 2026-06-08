//
// Created by Farid on 07/06/2026.
//

#ifndef PROYECTO_SERIE_HPP
#define PROYECTO_SERIE_HPP

#include <string>
#include "Video.hpp"
#include "Capitulo.hpp"

using namespace std;

class Serie : public Video {
private:
    Capitulo episodios[50];
    int numEpisodios;

public:
    Serie(string, string, int, string);
    void agregarCapitulo(Capitulo);
    string getTipo() override;
    string mostrarInfo() override;
    string mostrarInfo(bool detalle) override;
};

#endif //PROYECTO_SERIE_HPP
