#include <iostream>
using namespace std;

#include "Punto.hpp"

class Rectangulo{
    private:
        Punto esquinaInferiorIzquierda;
        float ancho;
        float alto;
    public:
        Rectangulo(Punto e, float a, float al);
        void setEsquinaInferiorIzquierda(Punto esquina);
        Punto getEsquinaInferiorIzquierda() const;

        void setAncho(float ancho);
        float getAncho() const;

        void setAlto(float alto);
        float getAlto() const;
};
