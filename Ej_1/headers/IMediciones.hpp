#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
using namespace std;

class IMediciones{
    public:
        virtual ~IMediciones() = default;
        virtual void serializar(ofstream& out) = 0;
        virtual void deserializar(ifstream& in) = 0;
};