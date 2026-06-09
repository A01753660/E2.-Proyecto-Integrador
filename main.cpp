// Alejandro Sánchez Calderón A01754913
// Alan Farid Hernández Sanmartín - A01753660

#include "Catalogo.hpp"

#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int pideEntero(string mensaje) {
    int valor;
    bool correct = false;
    while (!correct) {
        try {
            cout << mensaje;
            cin >> valor;
            if (cin.fail()) {
                throw invalid_argument{"Se espera un dato de tipo int."};
            } else {
                correct = true;
            }
        } catch (invalid_argument e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
    return valor;
}

string pideTexto(string mensaje) {
    string texto;
    cout << mensaje;
    cin >> texto;
    return texto;
}

int main() {
    Catalogo catalogo;
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n MENU" << endl;
        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Mostrar los videos en general con cierta calificacion o cierto genero" << endl;
        cout << "3. Mostrar los episodios de una determinada serie" << endl;
        cout << "4. Mostrar las peliculas con cierta calificacion" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;

        opcion = pideEntero("Elige una opcion: ");

        if (opcion == 1) {
            catalogo.cargarArchivo("Proyecto.txt");
        } else if (opcion == 2) {
            int filtro = pideEntero("Filtrar por (1) calificacion o (2) genero: ");
            if (filtro == 1) {
                int califMin = pideEntero("Calificacion minima: ");
                catalogo.mostrarVideos(califMin);
            } else if (filtro == 2) {
                string genero = pideTexto("Genero: ");
                catalogo.mostrarPorGenero(genero);
            } else {
                cout << "Opcion de filtro invalida." << endl;
            }
        } else if (opcion == 3) {
            string serie = pideTexto("Nombre de la serie: ");
            int califMin = pideEntero("Calificacion minima: ");
            catalogo.mostrarEpisodios(serie, califMin);
        } else if (opcion == 4) {
            int califMin = pideEntero("Calificacion minima: ");
            catalogo.mostrarPeliculas(califMin);
        } else if (opcion == 5) {
            string titulo = pideTexto("Titulo a calificar: ");
            int valor = pideEntero("Valor otorgado (1-5): ");
            catalogo.calificarVideo(titulo, valor);
        } else if (opcion == 0) {
            cout << "Saliendo" << endl;
        } else {
            cout << "Opcion invalida." << endl;
        }
    }
    return 0;
}
