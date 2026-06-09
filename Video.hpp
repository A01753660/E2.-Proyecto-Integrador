// Alan Farid Hernández Sanmartín - A01753660

#ifndef PROYECTO_VIDEO_HPP
#define PROYECTO_VIDEO_HPP

#include <string>
#include "ICalificable.hpp"

using namespace std;

class Video : public ICalificable {
private:
    string id;
    string nombre;
    int duracionMinutos;
    string genero;
    int calificaciones[100];
    int numCalif;

protected:
    Video();
    Video(string, string, int, string);

public:
    string getNombre();
    string getGenero();
    string getId();
    virtual string getTipo() = 0;
    virtual string mostrarInfo() = 0;
    virtual string mostrarInfo(bool detalle);
    virtual void calificar(int) override;
    virtual float getPromedio() override;
    friend bool operator>(Video& v1, Video& v2);
    friend bool operator==(Video& v1, Video& v2);
};

#endif //PROYECTO_VIDEO_HPP
