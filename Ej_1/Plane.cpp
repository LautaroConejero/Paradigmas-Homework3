#include "Plane.hpp"

// --Class Medicion_Base--
Medicion_Base::Medicion_Base(unique_ptr<float> tiempoMedicion) : 
TiempoMedicion(move(tiempoMedicion)) {}

float Medicion_Base::getTiempo() const{
    return *TiempoMedicion.get();
}
void Medicion_Base::serializar(ofstream& out)  {
    out.write(reinterpret_cast<const char*>(&TiempoMedicion), sizeof(TiempoMedicion));
    
}  

void Medicion_Base::deserializar(ifstream& in)  {
    TiempoMedicion = make_unique<float>(0);
    in.read(reinterpret_cast<char*>(TiempoMedicion.get()), sizeof(*TiempoMedicion));
}


// --Class Presion--
Presion::Presion(float tiempoMedicion, float presionDinamica, float presionEstatica) : 
    Medicion_Base(make_unique<float>(tiempoMedicion)), PresionDinamica(presionDinamica), PresionEstatica(presionEstatica) {}

Presion::Presion(const Presion& p) : 
    Medicion_Base(make_unique<float>(p.getTiempo())),
    PresionDinamica(p.PresionDinamica), PresionEstatica(p.PresionEstatica) {}

Presion::~Presion() {}

void Presion::serializar(ofstream& out)  {
    Medicion_Base::serializar(out);
    out.write(reinterpret_cast<const char*>(&PresionDinamica), sizeof(PresionDinamica));
    out.write(reinterpret_cast<const char*>(&PresionEstatica), sizeof(PresionEstatica));
}

void Presion::deserializar(ifstream& in)  {
    Medicion_Base::deserializar(in);
    in.read(reinterpret_cast<char*>(&PresionDinamica), sizeof(PresionDinamica));
    in.read(reinterpret_cast<char*>(&PresionEstatica), sizeof(PresionEstatica));
}

void Presion::imprimir() const {
    cout << "Presion Dinamica: " << PresionDinamica << endl;
    cout << "Presion Estatica: " << PresionEstatica << endl;
}


// --Class Posicion--
Posicion::Posicion(float posicionX, float posicionY, float posicionZ,float tiempoMedicion) : 
    Medicion_Base(make_unique<float>(tiempoMedicion)), PosicionX(posicionX), PosicionY(posicionY), PosicionZ(posicionZ) {}
    
Posicion::Posicion(const Posicion& p) : 
    Medicion_Base(make_unique<float>(p.getTiempo())),
    PosicionX(p.PosicionX), PosicionY(p.PosicionY), PosicionZ(p.PosicionZ) {}
Posicion::~Posicion() {}

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
}



// --Class SaveFlightData
SaveFlightData::SaveFlightData(const Presion& p, const Posicion& pos): presion(p), posicion(pos) {
}
SaveFlightData::~SaveFlightData() {}

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


