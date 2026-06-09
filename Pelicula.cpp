Alejandro Sánchez Calderón A01754913


#include "Pelicula.hpp"

Pelicula::Pelicula() : Video() {}
Pelicula::Pelicula(string id, string nombre , int duracionMinutos, string genero)
      : Video(id, nombre, duracionMinutos, genero) {}

string Pelicula::mostrarInfo() {
    string resultado = "Pelicula: " + getNombre() + "\n" + "Genero: " + getGenero() + "\n" + "Clasificación Promedio: " + to_string(getPromedio()) + "\n";
    return resultado;
}

string Pelicula::getTipo() { return "Pelicula"; }
