#include "../headers/Rectangulo.hpp"

// --Class Rectangulo--

Rectangulo::Rectangulo(Punto e, float a, float al) : esquinaInferiorIzquierda(e), ancho(a), alto(al) {}
void Rectangulo::setEsquinaInferiorIzquierda(Punto esquina) {
    this->esquinaInferiorIzquierda = esquina;
}
Punto Rectangulo::getEsquinaInferiorIzquierda() const {
    return esquinaInferiorIzquierda;
}
void Rectangulo::setAncho(float ancho) {
    this->ancho = ancho;
}
float Rectangulo::getAncho() const {
    return ancho;
}
void Rectangulo::setAlto(float alto) {
    this->alto = alto;
}
float Rectangulo::getAlto() const {
    return alto;
}