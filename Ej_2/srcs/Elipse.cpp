#include "../headers/Elipse.hpp"

// --Class Elipse--
Elipse::Elipse(Punto c, float SMa, float SMe) : centro(c), semiEjeMayor(SMa), semiEjeMenor(SMe) {}
void Elipse::setCentro(Punto centro) {
    this->centro = centro;
}
Punto Elipse::getCentro() const {
    return centro;
}
void Elipse::setSemiEjeMayor(float radioMayor) {
    this->semiEjeMayor = radioMayor;
}
float Elipse::getSemiEjeMayor() const {
    return semiEjeMayor;
}
void Elipse::setSemiEjeMenor(float radioMenor) {
    this->semiEjeMenor = radioMenor;
}
float Elipse::getSemiEjeMenor() const {
    return semiEjeMenor;
}