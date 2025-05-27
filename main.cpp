#include "Ej_1/examples/main1.hpp"
#include "Ej_2/examples/main2.hpp"
#include "Ej_3/examples/main3.hpp"

int main(){
    cout << "Bienvenido al homework 3" << endl;
    cout << "ELija que ejercicio quieres hacer" << endl;
    cout << "1. Ejercicio 1" << endl;
    cout << "2. Ejercicio 2" << endl;
    cout << "3. Ejercicio 3" << endl;
    cout << "4. Salir" << endl;

    int option;
    cin >> option;
    while (!cin.good() || option < 1 || option > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcion invalida. Por favor, elija una opcion entre 1 y 4: ";
        cin >> option;
    }
    switch (option) {
        case 1:
            Ejercicio1();
            break;
        case 2:
            prueba_2();
            break;
        case 3:
            prueba_3();
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            return 0;
    }
}