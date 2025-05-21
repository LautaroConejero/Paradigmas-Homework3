#pragma once
#include "Contenedor.hpp"

class JSONCreador{
    private:
        vector<pair<string, string>> datos_procesados;
    public:
        JSONCreador();

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

        void generar_json();
};