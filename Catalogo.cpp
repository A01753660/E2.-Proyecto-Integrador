//
// Created by Farid on 07/06/2026.
//

#include "Catalogo.hpp"
#include "Pelicula.hpp"
#include "Serie.hpp"
#include "Capitulo.hpp"
#include "CalificacionInvalida.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Catalogo::Catalogo() : numVideos{0} {}

void Catalogo::cargarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string tipo;
    while (archivo >> tipo) {
        if (tipo == "PELICULA") {
            string id, nombre, genero;
            int duracion;
            archivo >> id >> nombre >> duracion >> genero;
            videos[numVideos] = new Pelicula(id, nombre, duracion, genero);
            numVideos++;
        } else if (tipo == "SERIE") {
            string id, nombre, genero;
            int duracion;
            archivo >> id >> nombre >> duracion >> genero;
            videos[numVideos] = new Serie(id, nombre, duracion, genero);
            numVideos++;
        } else if (tipo == "CAPITULO") {
            string idSerie, titulo;
            int temporada;
            archivo >> idSerie >> titulo >> temporada;
            for (int i = 0; i < numVideos; i++) {
                if (videos[i]->getTipo() == "Serie" && videos[i]->getId() == idSerie) {
                    Serie* s = static_cast<Serie*>(videos[i]);
                    s->agregarCapitulo(Capitulo(titulo, temporada));
                }
            }
        }
    }
    archivo.close();
    cout << "Archivo cargado. Videos cargados: " << numVideos << endl;
}

void Catalogo::mostrarVideos(int califMin) {
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getPromedio() >= califMin) {
            cout << videos[i]->mostrarInfo() << endl;
        }
    }
}

void Catalogo::mostrarPorGenero(string genero) {
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getGenero() == genero) {
            cout << videos[i]->mostrarInfo() << endl;
        }
    }
}

void Catalogo::mostrarPeliculas(int califMin) {
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getTipo() == "Pelicula" && videos[i]->getPromedio() >= califMin) {
            cout << videos[i]->mostrarInfo() << endl;
        }
    }
}

void Catalogo::mostrarEpisodios(string nombreSerie, int califMin) {
    bool encontrada = false;
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getTipo() == "Serie" && videos[i]->getNombre() == nombreSerie) {
            cout << videos[i]->mostrarInfo(true) << endl;
            encontrada = true;
        }
    }
    if (!encontrada) {
        cout << "No se encontro la serie: " << nombreSerie << endl;
    }
}

void Catalogo::calificarVideo(string nombre, int valor) {
    bool encontrado = false;
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getNombre() == nombre) {
            encontrado = true;
            try {
                videos[i]->calificar(valor);
                cout << "Video calificado correctamente." << endl;
            } catch (CalificacionInvalida e) {
                cout << e.what() << endl;
            }
        }
    }
    if (!encontrado) {
        cout << "No se encontro el video: " << nombre << endl;
    }
}
