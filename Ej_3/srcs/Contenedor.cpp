#include "../headers/Contenedor.hpp"

template<>
string vec<string>(vector<string> vec) {
    ostringstream dato;
    dato << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        dato << "\"" << vec[i] << "\"";
        if (i != vec.size() - 1)
            dato << ", ";
    }
    dato << "]";
    return dato.str();
}

template<>
string vec<vector<int>>(vector<vector<int>> vec) {
    ostringstream dato;
    dato << "[\n";
    for (size_t i = 0; i < vec.size(); i++){
        dato << "\t[";
        for (size_t j = 0; j < vec[i].size(); j++){
            dato << to_string(vec[i][j]);
            if (j != vec[i].size()-1)
                dato << ",";
        }
        dato << "]";
        if (i != vec.size()-1)
            dato << ",";
        dato << "\n";
    }
    dato << "\t]";
    return dato.str();
}
