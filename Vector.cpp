#include "Vector.h"

//construtor padrão
Vector::Vector() : x(0.0), y(0.0), z(0.0){
}

//construtor com argumentos
Vector::Vector(real x, real y, real z) : x(x), y(y), z(z) {
}

//retorna um array com as coordenadas
array<real, 3> Vector::getCoordinates(){
    array<real, 3> resultado;

    resultado[0] = x;
    resultado[1] = y;
    resultado[2] = z;

    return resultado;
}

//retorna a norma do vetor
real Vector::getNorma(){
    return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

//retorna a norma de um vetor passado manualmente
real Vector::getNorma(real x, real y, real z){
    return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

//retorna o produto escalar entre 2 vetores
real Vector::getProdEscalar(array<real, 3> v1, array<real, 3> v2){
    real r = 0.0;

    for (int i = 0; i < v1.size(); i++){
        r += (v1[i] * v2[i]);
    }

    return r;
}

real Vector::getAnguloVetores(real prodS, real nv1, real nv2){
    return ((nv1 > 0.0) && (nv2 > 0.0)) ? acos(prodS/(nv1*nv2)) * (180/M_PI) : NAN;
}

array<real, 3> Vector::getNormalized(){
    array<real, 3> r;
    real n = this->getNorma();

    r[0] = x/n;
    r[1] = y/n;
    r[2] = z/n;

    return r;
}

real Vector::getDistanciaVetores(array<real, 3> v2){
    return Vector::getNorma((this->x - v2[0]), (this->y - v2[1]), (this->z - v2[2]));
}

real Vector::getDistanciaVetores(array<real, 3> v1, array<real, 3> v2){
    return Vector::getNorma((v1[0] - v2[0]), (v1[1] - v2[1]), (v1[2] - v2[2]));
}

//destrutor
Vector::~Vector()
{
    //cout << "objeto destruido" << endl;
}