#pragma once
#include "Mediciones_Base.hpp"
class Posicion : public Medicion_Base {
    public:
        float PosicionX;
        float PosicionY;
        float PosicionZ;
        Posicion(float posicionX, float posicionY, float posicionZ, float tiempoMedicion);
        Posicion(const Posicion& p);
        ~Posicion();
        void serializar(ofstream& out) override;
        void deserializar(ifstream& in) override; 
        void imprimir() const override;

};