//
// Created by Farid on 07/06/2026.
//

#include "Serie.hpp"

#include <iostream>
#include <ostream>


Serie::Serie(string id, string nombre, int duracionMinutos, string genero)
    : Video(id, nombre, duracionMinutos, genero) {
    numEpisodios = 0;
}

void Serie::agregarCapitulo(Capitulo c) {
    if (numEpisodios < 50) {
        episodios[numEpisodios] = c;
        numEpisodios++;
    }
}

string Serie::mostrarInfo() {
    return mostrarInfo(false);
}

string Serie::mostrarInfo(bool detalle) {
    string resultado = "Serie: " + getNombre() + "\n" + "Genero: " + getGenero() + "\n" + "Clasificación Promedio: " + to_string(getPromedio()) + "\n" + "Episodios: " + to_string(numEpisodios) + "\n";
    if (detalle) {
        for (int i = 0; i < numEpisodios; i++) {
            resultado +=  to_string(i+1) + "- " + episodios[i].mostrarInfo() + "\n";
        }
    }
    return resultado;

}