#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
using namespace std;

class IMediciones{
    public:
        virtual ~IMediciones() = default;
        virtual void serializar(ofstream& out) = 0;
        virtual void deserializar(ifstream& in) = 0;
};

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

class SaveFlightData {
    public:
    Presion presion;
    Posicion posicion;

    SaveFlightData(const Presion& p, const Posicion& pos);
    ~SaveFlightData();
    void serializar(ofstream& out);
    void deserializar(ifstream& in);
    void imprimir() const;
};