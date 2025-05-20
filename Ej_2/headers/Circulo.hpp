#pragma once

#include <iostream>
using namespace std;

#include "Punto.hpp"

class Circulo{
    private:
        Punto centro;
        float radio;

    public:
        Circulo(Punto c, float r);
        void setCentro(Punto centro);
        Punto getCentro() const;

        void setRadio(float radio);
        float getRadio() const;
};