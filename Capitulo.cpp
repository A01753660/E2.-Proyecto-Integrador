//
// Created by Farid on 07/06/2026.
//

#include "Capitulo.hpp"
#include "CalificacionInvalida.hpp"

using namespace std;

Capitulo::Capitulo() : titulo{""}, temporada{0}, numCalif{0} {}

Capitulo::Capitulo(string titulo, int temporada)
    : titulo{titulo}, temporada{temporada}, numCalif{0} {}

string Capitulo::mostrarInfo() {
    return "Capitulo(" + titulo + "," + to_string(temporada) + "," + to_string(getPromedio()) + ")";
}

void Capitulo::calificar(int valor) {
    if (valor < 1 || valor > 5) {
        throw CalificacionInvalida{};
    }
    calificaciones[numCalif] = valor;
    numCalif++;
}

float Capitulo::getPromedio() {
    if (numCalif == 0) return 0.0;
    int suma = 0;
    for (int i = 0; i < numCalif; i++) {
        suma += calificaciones[i];
    }
    return suma / (float)numCalif;
}