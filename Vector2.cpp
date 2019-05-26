#include "Vector2.h"
#include <iostream>


Vector::Vector() : x(0.0), y(0.0), z(0.0), dimensao(3) {}

Vector::Vector(real x, real y) : x(x), y(y), dimensao(2) {}

Vector::Vector(real x, real y, real z) : x(x), y(y), z(z), dimensao(3) {}

Vector::Vector(real x, real y, real z, real w) : x(x), y(y), z(z), w(w), dimensao(4) {}

Vector::~Vector(){}

vetor Vector::coordenadas(){
    vetor r(dimensao);

    switch (dimensao){
        case 2:
            r[0] = x;
            r[1] = y;
            break;
        case 3:
            r[0] = x;
            r[1] = y;
            r[2] = z;
            break;
        case 4:
            r[0] = x;
            r[1] = y;
            r[2] = z;
            r[3] = w;
            break;
    }
    
    return r;
}

void Vector::imprime(){
    texto o = {"x", "y", "z", "w"};
    vetor c = coordenadas();

    for (int i = 0; i < dimensao; i++) printf("Coordenada %s: %.2f \n", o[i].c_str(), c[i]);
}