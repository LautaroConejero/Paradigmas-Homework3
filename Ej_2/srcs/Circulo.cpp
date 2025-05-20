#include "../headers/Circulo.hpp"

// --Class Circulo--
Circulo::Circulo(Punto c, float r) : centro(c), radio(r) {}
void Circulo::setCentro(Punto centro) {
    this->centro = centro;
}
Punto Circulo::getCentro() const {
    return centro;
}
void Circulo::setRadio(float radio) {
    this->radio = radio;
}
float Circulo::getRadio() const {
    return radio;
}