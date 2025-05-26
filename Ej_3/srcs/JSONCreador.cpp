#include "../headers/JSONCreador.hpp"

JSONCreador::JSONCreador(){}

void JSONCreador::generar_json(){
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