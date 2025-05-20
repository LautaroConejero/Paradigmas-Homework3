#include "main1.hpp"

void Ejercicio1(){
    cout << "Bienvenido al ejercicio 1" << endl;

    cout << "Creando objetos de medicion..." << endl;
    Presion presion(101.3f, 5.8f, 6.1f);
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    SaveFlightData saveFlightData(presion, posicion);
    cout << "Valores de medicion creados." << endl;

    cout << endl;
    cout << "Imprimiendo datos de vuelo..." << endl;
    saveFlightData.imprimir();

    cout << endl;
    cout << "Serializando..." << endl;
    ofstream out("datos_vuelo.dat", ios::binary);
    if (!out) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }
    saveFlightData.serializar(out);
    out.close();
    cout << "Datos de vuelo serializados." << endl;
    cout << endl;

    cout << "Deserializando..." << endl;

    ifstream in("datos_vuelo.dat", ios::binary);
    if(!in) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }
    Presion presion2(0, 0, 0);
    Posicion posicion2(0, 0, 0, 0);
    SaveFlightData saveFlightData2(presion2, posicion2);
    saveFlightData2.deserializar(in);
    in.close();

    cout << "Imprimiendo datos de vuelo deserializados..." << endl;
    saveFlightData2.imprimir();

    return;
}