#pragma once

#include <iostream>
using namespace std;

class Punto{
    private:
        float x;
        float y;

    public:
        Punto(float x, float y);
        float getX() const;
        float getY() const;
        void setX(float x);
        void setY(float y);
};