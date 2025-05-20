#include "main2.hpp"

int prueba_2(){
    cout << "Bienvenido al ejercicio 2" << endl;
    cout << "Creando objetos de medicion..." << endl;
    Circulo circulo(Punto(0, 0), 5);
    Elipse elipse(Punto(0, 0), 5, 3);
    Rectangulo rectangulo(Punto(0, 0), 5, 3);
    cout << "Objetos creados." << endl;

    cout << endl;
    cout << "Imprimiendo datos de figuras..." << endl;
    cout << "Radio Circulo: "<<circulo.getRadio() << endl;
    cout << "Centro Circulo: (" << circulo.getCentro().getX() << ", " << circulo.getCentro().getY() << ")" << endl;
    cout << endl;

    cout << "SemiEje Mayor Elipse: "<<elipse.getSemiEjeMayor() << endl;
    cout << "SemiEje Menor Elipse: "<<elipse.getSemiEjeMenor() << endl;
    cout << "Centro Elipse: (" << elipse.getCentro().getX() << ", " << elipse.getCentro().getY() << ")" << endl;
    cout << endl;

    cout << "Ancho Rectangulo: "<<rectangulo.getAncho() << endl;
    cout << "Alto Rectangulo: "<<rectangulo.getAlto() << endl;
    cout << "Esquina Inferior Izquierda Rectangulo: (" << rectangulo.getEsquinaInferiorIzquierda().getX() << ", " << rectangulo.getEsquinaInferiorIzquierda().getY() << ")" << endl;
    cout << endl;
    
    cout << "Calculando areas..." << endl;
    ProcesadorFigura<Circulo> procesadorCirculo;
    ProcesadorFigura<Elipse> procesadorElipse;
    ProcesadorFigura<Rectangulo> procesadorRectangulo;

    double areaCirculo = procesadorCirculo.calcularArea(circulo);
    double areaElipse = procesadorElipse.calcularArea(elipse);
    double areaRectangulo = procesadorRectangulo.calcularArea(rectangulo);

    cout << "Area del circulo: " << areaCirculo << endl;
    cout << "Area de la elipse: " << areaElipse << endl;
    cout << "Area del rectangulo: " << areaRectangulo << endl;

    return 0;
}