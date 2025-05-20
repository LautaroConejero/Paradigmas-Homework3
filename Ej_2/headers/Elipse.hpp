#pragma once

#include <iostream>
#include "Punto.hpp" 
using namespace std;

class Elipse{
    private:
        Punto centro;
        float semiEjeMayor;
        float semiEjeMenor;

    public:
        Elipse(Punto c, float SMa, float SMe);
        void setCentro(Punto centro);
        Punto getCentro() const;

        void setSemiEjeMayor(float radioMayor);
        float getSemiEjeMayor() const;

        void setSemiEjeMenor(float radioMenor);
        float getSemiEjeMenor() const;
};
