#pragma once
#include "Mediciones_base.hpp"

class Presion : public Medicion_Base {
    public:
        float PresionDinamica;
        float PresionEstatica;
        Presion(float presionDinamica, float presionEstatica, float tiempoMedicion);
        Presion(const Presion& p);
        ~Presion();
        void serializar(ofstream& out) override;
        void deserializar(ifstream& in) override; 
        void imprimir() const override;
};
