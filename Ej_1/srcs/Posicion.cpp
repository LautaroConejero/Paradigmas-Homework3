#include "../headers/Posicion.hpp"

// --Class Posicion--
Posicion::Posicion(float posicionX, float posicionY, float posicionZ,float tiempoMedicion) : 
    Medicion_Base(make_unique<float>(tiempoMedicion)), PosicionX(posicionX), PosicionY(posicionY), PosicionZ(posicionZ) {}
    
Posicion::Posicion(const Posicion& p) : 
    Medicion_Base(make_unique<float>(p.getTiempo())),
    PosicionX(p.PosicionX), PosicionY(p.PosicionY), PosicionZ(p.PosicionZ) {}
Posicion::~Posicion() {}

// serializo y deserializo todo en el mismo orden en que se guardo
void Posicion::serializar(ofstream& out)  {
    Medicion_Base::serializar(out);
    out.write(reinterpret_cast<const char*>(&PosicionX), sizeof(PosicionX));
    out.write(reinterpret_cast<const char*>(&PosicionY), sizeof(PosicionY));
    out.write(reinterpret_cast<const char*>(&PosicionZ), sizeof(PosicionZ));
}

void Posicion::deserializar(ifstream& in)  {
    Medicion_Base::deserializar(in);
    in.read(reinterpret_cast<char*>(&PosicionX), sizeof(PosicionX));
    in.read(reinterpret_cast<char*>(&PosicionY), sizeof(PosicionY));
    in.read(reinterpret_cast<char*>(&PosicionZ), sizeof(PosicionZ));
}

void Posicion::imprimir() const {
    cout << "Posicion X: " << PosicionX << endl;
    cout << "Posicion Y: " << PosicionY << endl;
    cout << "Posicion Z: " << PosicionZ << endl;
    cout << "Tiempo de medicion: " << getTiempo() << endl;
}
