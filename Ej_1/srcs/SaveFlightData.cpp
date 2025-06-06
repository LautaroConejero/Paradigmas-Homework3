#include "../headers/SaveFlightData.hpp"

SaveFlightData::SaveFlightData(const Presion& p, const Posicion& pos): presion(p), posicion(pos) {
}
SaveFlightData::~SaveFlightData() {}

// serializo y deserializo todo en el mismo orden en que se guardo
void SaveFlightData::serializar(ofstream& out) {
    presion.serializar(out);
    posicion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in) {
    presion.deserializar(in); 
    posicion.deserializar(in);
}
void SaveFlightData::imprimir() const {
    cout << "Datos de vuelo:" << endl;
    presion.imprimir();
    posicion.imprimir();
}