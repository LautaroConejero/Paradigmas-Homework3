#pragma once
#include "IMediciones.hpp"


class Medicion_Base : public IMediciones {
    protected:
        unique_ptr<float> TiempoMedicion;
    public:
        Medicion_Base(unique_ptr<float> tiempoMedicion);
        virtual ~Medicion_Base() = default;
        float getTiempo() const;
        void serializar(ofstream& out) override;
        void deserializar(ifstream& in) override; 
        virtual void imprimir() const = 0;
};
