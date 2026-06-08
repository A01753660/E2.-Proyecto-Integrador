//
// Created by Farid on 07/06/2026.
//

#include "Catalogo.hpp"
#include <iostream>
#include <fstream>

Catalogo::Catalogo() {
    numVideos = 0;
}

void Catalogo::cargarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }

    string tipo;
    while (archivo >> tipo) {

        if (tipo == "Pelicula") {
            string id, nombre, genero;
            int duracion;
            archivo >> id >> nombre >> duracion >> genero;
            if (numVideos < 200) {
                videos[numVideos] = new Pelicula(id, nombre, duracion, genero);
                numVideos++;
            }

        } else if (tipo == "Serie") {
            string id, nombre, genero;
            int duracion;
            archivo >> id >> nombre >> duracion >> genero;
            if (numVideos < 200) {
                videos[numVideos] = new Serie(id, nombre, duracion, genero);
                numVideos++;
            }

        } else if (tipo == "Capitulo") {
            string idSerie, titulo;
            int temporada;
            archivo >> idSerie >> titulo >> temporada;
            for (int i = 0; i < numVideos; i++) {
                if (videos[i]->getTipo() == "Serie") {
                    Serie* s = (Serie*) videos[i];
                    if (s->getId() == idSerie) {
                        s->agregarCapitulo(Capitulo(titulo, temporada));
                        break;
                    }
                }
            }
        }
    }

    archivo.close();
    cout << "Archivo cargado correctamente." << endl;
}

void Catalogo::mostrarVideos(int califMin) {
    cout << "\nVideos con clasificación >= " << califMin << endl;
    bool hayResultados = false;
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getPromedio() >= califMin) {
            cout << videos[i]->mostrarInfo() << endl;
            hayResultados = true;
        }
    }
    if (!hayResultados) {
        cout << "No hay videos con esa calificacion." << endl;
    }
}

void Catalogo::mostrarPorGenero(string genero) {
    cout << "\nVideos de genero: " << genero << endl;
    bool hayResultados = false;
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getGenero() == genero) {
            cout << videos[i]->mostrarInfo() << endl;
            hayResultados = true;
        }
    }
    if (!hayResultados) {
        cout << "No hay videos de ese genero." << endl;
    }
}

void Catalogo::mostrarPeliculas(int califMin) {
    cout << "\nPeliculas con clasificación >= " << califMin << endl;
    bool hayResultados = false;
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getTipo() == "Pelicula") {
            if (videos[i]->getPromedio() >= califMin) {
                cout << videos[i]->mostrarInfo() << endl;
                hayResultados = true;
            }
        }
    }
    if (!hayResultados) {
        cout << "No hay peliculas con esa calificacion." << endl;
    }
}

void Catalogo::mostrarEpisodios(string nombreSerie, int califMin) {
    cout << "\nEpisodios de: " << nombreSerie << endl;
    for (int i = 0; i < numVideos; i++) {
        if (videos[i]->getTipo() == "Serie") {
            Serie* s = (Serie*) videos[i];
            if (s->getNombre() == nombreSerie) {
                cout << s->mostrarInfo(true) << endl;
                return;
            }
        }
    }
    cout << "Serie no encontrada." << endl;
}

void Catalogo::calificarVideo(string nombre, int valor) {
    try {
        for (int i = 0; i < numVideos; i++) {
            if (videos[i]->getNombre() == nombre) {
                videos[i]->calificar(valor);
                cout << "Calificacion registrada correctamente." << endl;
                return;
            }
        }
        cout << "Video no encontrado." << endl;
    } catch (CalificacionInvalida&) {
        cout << "Error: Calificacion invalida. Debe ser entre 1 y 5." << endl;
    }
}
