// Alan Farid Hernández Sanmartín - A01753660

#ifndef PROYECTO_CALIFICACIONINVALIDA_HPP
#define PROYECTO_CALIFICACIONINVALIDA_HPP

#include <stdexcept>
#include <string>

using namespace std;

class CalificacionInvalida : public invalid_argument {
public:
    CalificacionInvalida();
};

#endif //PROYECTO_CALIFICACIONINVALIDA_HPP
