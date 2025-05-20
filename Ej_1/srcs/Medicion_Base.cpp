#include "../headers/Mediciones_Base.hpp"

// --Class Medicion_Base--
Medicion_Base::Medicion_Base(unique_ptr<float> tiempoMedicion) : 
TiempoMedicion(move(tiempoMedicion)) {}

float Medicion_Base::getTiempo() const{
    return *TiempoMedicion.get();
}
void Medicion_Base::serializar(ofstream& out)  {
    out.write(reinterpret_cast<const char*>(TiempoMedicion.get()), sizeof(*TiempoMedicion));
}  

void Medicion_Base::deserializar(ifstream& in)  {
    TiempoMedicion = make_unique<float>(0);
    in.read(reinterpret_cast<char*>(TiempoMedicion.get()), sizeof(*TiempoMedicion));
}