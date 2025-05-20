#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
using namespace std;
#include "Presion.hpp"
#include "Posicion.hpp"

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