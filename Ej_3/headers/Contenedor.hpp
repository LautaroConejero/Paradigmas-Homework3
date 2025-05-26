#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <sstream>
using namespace std;

template <typename T>
string vec(vector<T> vec) {
    ostringstream dato;
    dato << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        dato << vec[i];
        if (i != vec.size() - 1)
            dato << ", ";
    }
    dato << "]";
    return dato.str();
}

template<>
string vec<string>(vector<string> vec);

template<>
string vec<vector<int>>(vector<vector<int>> vec);

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
                return vec(datos);
            if constexpr (is_same<T, vector<int>>::value)
                return vec(datos);
            if constexpr (is_same<T, string>::value)
                return vec(datos);
            else
                return "Tipo no soportado";
        }
};