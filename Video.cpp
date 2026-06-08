//
// Created by Farid on 07/06/2026.
//

#include "Video.hpp"
#include "CalificacionInvalida.hpp"
#include <iostream>

using namespace std;

Video::Video() : id{""}, nombre{""}, duracionMinutos{0}, genero{""}, numCalif{0} {}

Video::Video(string id, string nombre, int duracionMinutos, string genero)
    : id{id}, nombre{nombre}, duracionMinutos{duracionMinutos}, genero{genero}, numCalif{0} {}
string Video::getNombre() {
    return nombre;
}

string Video::getGenero() {
    return genero;
}

string Video::getId() {
    return id;
}

void Video::calificar(int valor) {
    if (valor < 1 || valor > 5) {
        throw CalificacionInvalida{};
    }
    calificaciones[numCalif] = valor;
    numCalif++;
}

float Video::getPromedio() {
    if (numCalif == 0) return 0.0;
    int suma = 0;
    for (int i = 0; i < numCalif; i++) {
        suma += calificaciones[i];
    }
    return suma / (float)numCalif;
}

bool operator>(Video& v1, Video& v2) {
    return v1.getPromedio() > v2.getPromedio();
}

bool operator==(Video& v1, Video& v2) {
    return v1.id == v2.id;
}

string Video::mostrarInfo() {
    return "Video(" + nombre + "," + to_string(duracionMinutos) + "," + genero + ")";
}

string Video::mostrarInfo(bool detalle) {
    return mostrarInfo();
}


