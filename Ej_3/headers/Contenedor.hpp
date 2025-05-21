#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string vec_double(vector<double> vec);
string vec_string(vector<string> vec);
string vec_int(vector<vector<int>> vec);

template <typename T>
class Contenedor {
    private:
        vector<T> datos;
    public:
        Contenedor(){}

        bool agregar(const T& dato){
            if constexpr (is_floating_point<T>::value || is_same<T, vector<int>>::value || is_same<T, string>::value){
                datos.push_back(dato);
                return true;
            }
            return false;
        }

        string generar(){
            if constexpr (is_floating_point<T>::value)
                return vec_double(datos);
            if constexpr (is_same<T, vector<int>>::value)
                return vec_int(datos);
            if constexpr (is_same<T, string>::value)
                return vec_string(datos);
            else
                return "Tipo no soportado";
        }
};