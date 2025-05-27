#include "../headers/Presion.hpp"


// --Class Presion--
Presion::Presion(float tiempoMedicion, float presionDinamica, float presionEstatica) : 
    Medicion_Base(make_unique<float>(tiempoMedicion)), PresionDinamica(presionDinamica), PresionEstatica(presionEstatica) {}

Presion::Presion(const Presion& p) : 
    Medicion_Base(make_unique<float>(p.getTiempo())),
    PresionDinamica(p.PresionDinamica), PresionEstatica(p.PresionEstatica) {}

Presion::~Presion() {}

// serializo y deserializo todo en el mismo orden en que se guardo
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
    cout << "Tiempo de medicion: " << getTiempo() << endl;
}

