#ifndef CONTENEDOR_HPP
#define CONTENEDOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <sstream>
#include <limits>
using namespace std;

// funcion util para convertir los datos a un string
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

// especializaciones de la funcion vec para tipos especificos
template<>
string vec<string>(vector<string> vec);

template<>
string vec<vector<int>>(vector<vector<int>> vec);


//clase contenedor que almacena datos de tipo T
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

//constructo del JSON para almacenar los datos procesados e imprimirlos
class JSONCreador{
    private:
        vector<pair<string, string>> datos_procesados;
    public:
        JSONCreador(){}

        template <typename T>
        void agregar_procesado(Contenedor<T>& Contenedor_T){
            if constexpr (is_floating_point<T>::value){
                datos_procesados.push_back(make_pair("vec_doubles", Contenedor_T.generar()));
            }
            else if constexpr (is_same<T, string>::value){
                datos_procesados.push_back(make_pair("palabras", Contenedor_T.generar()));
            }
            else if constexpr (is_same<T, vector<int>>::value){;
                datos_procesados.push_back(make_pair("listas", Contenedor_T.generar()));
            }
            else {
                cout << "Tipo no soportado" << endl;
            }
            return;
        }

        void generar_json(){
            string json = "{ ";
            for (size_t i = 0; i < datos_procesados.size(); i++){
                json += "\"" + datos_procesados[i].first + "\" : " + datos_procesados[i].second;
                if (i != datos_procesados.size()-1)
                    json += ",";
                json += "\n";
            }
            json += "}";
            cout << json << endl;
            return;
        }
};


#endif