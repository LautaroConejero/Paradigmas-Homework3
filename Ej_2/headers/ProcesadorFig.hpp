#pragma once

#include "Circulo.hpp"
#include "Elipse.hpp"
#include "Rectangulo.hpp"
#include "Punto.hpp"
#define PI 3.14159265358979323846

template <typename T>
class ProcesadorFigura{
    public:
        double calcularArea(T&) { return 0; }
};

template <>
class ProcesadorFigura<Circulo>{
    public:
        ProcesadorFigura() {} // Define inline
        double calcularArea(Circulo& figura){
            return PI * figura.getRadio() * figura.getRadio();
        }
};

template <>
class ProcesadorFigura<Elipse>{
    public:
        ProcesadorFigura() {} // Define inline
        double calcularArea(Elipse& figura){
            return PI * figura.getSemiEjeMayor() * figura.getSemiEjeMenor();
        }
};

template <>
class ProcesadorFigura<Rectangulo>{
    public:
        ProcesadorFigura() {} // Define inline
        double calcularArea(Rectangulo& figura){
            return figura.getAncho() * figura.getAlto();
        }   
};
