#include "Vector.h"

//construtor padrão
Vector::Vector() : x(0.0), y(0.0), z(0.0){
}

//construtor com argumentos
Vector::Vector(real x, real y, real z) : x(x), y(y), z(z) {
}

//retorna um array com as coordenadas
array<real, 3> Vector::getCoordenadas(){
    array<real, 3> r;

    r[0] = x;
    r[1] = y;
    r[2] = z;

    return r;
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

array<real, 3> Vector::getNormalizado(){
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

/* array<real, 3> Vector::getSomaVetores(array<real, 3> v2){
    array<real, 3> r = {(this->x + v2[0]), (this->y + v2[1]), (this->z + v2[2])};

    return r;
}

array<real, 3> Vector::getSomaVetores(array<real, 3> v1, array<real, 3> v2){
    array<real, 3> r = {(v1[0] + v2[0]), (v1[1] + v2[1]), (v1[2] + v2[2])};

    return r;
}
 */

array<real, 3> Vector::getOperacaoVetores(array<real, 3> v2, char op){
    return this->getOperacaoVetores({this->x, this->y, this->z}, v2, op);
}

array<real, 3> Vector::getOperacaoVetores(array<real, 3> v1, array<real, 3> v2, char op){
    if (op != '+' && op != '-' && op != '*' && op != '/') return {NAN, NAN, NAN};

    array<real, 3> r;

    switch (op){
        case '+':
            r = {(v1[0] + v2[0]), (v1[1] + v2[1]), (v1[2] + v2[2])};
            break;
        case '-':
            r = {(v1[0] - v2[0]), (v1[1] - v2[1]), (v1[2] - v2[2])};
            break;
        case '*':
            r = {(v1[0] * v2[0]), (v1[1] * v2[1]), (v1[2] * v2[2])};
            break;
        case '/':
            ((v2[0] != 0) && (v2[1] != 0) && (v2[2] != 0)) ? r = {(v1[0] / v2[0]), (v1[1] / v2[1]), (v1[2] / v2[2])} : r = {NAN, NAN, NAN};
            break;
    }

    return r;
}


//destrutor
Vector::~Vector()
{
    //cout << "objeto destruido" << endl;
}