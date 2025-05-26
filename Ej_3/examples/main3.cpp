#include "main3.hpp"

int prueba_3(){
    Contenedor<double> contenedor_double;
    Contenedor<string> contenedor_string;
    Contenedor<vector<int>> contenedor_vector_int;

    contenedor_double.agregar(1.3);
    contenedor_double.agregar(2.1);
    contenedor_double.agregar(3.2);

    contenedor_string.agregar("Hola");
    contenedor_string.agregar("Mundo");

    contenedor_vector_int.agregar({1,2});
    contenedor_vector_int.agregar({3,4});

    JSONCreador jsonCreador;
    jsonCreador.agregar_procesado(contenedor_double);
    jsonCreador.agregar_procesado(contenedor_string);
    jsonCreador.agregar_procesado(contenedor_vector_int);
    jsonCreador.generar_json();
    return 0;
}