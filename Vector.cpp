#include "Vector.h"

//construtor padrão
Vector::Vector() : x(0.0), y(0.0), z(0.0) {}

//construtor com argumentos
Vector::Vector(real x, real y, real z) : x(x), y(y), z(z) {}

//retorna um array com as coordenadas
array<real, 3> Vector::getCoordenadas(){
    array<real, 3> r = {x, y, z};

    return r;
}

//retorna a norma do vetor
real Vector::getNorma(){
    return Vector::getNorma(x, y, z);
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

//retorna o angulo entre vetores
real Vector::getAnguloVetores(real pS, real nv1, real nv2){
    return ((nv1 > 0.0) && (nv2 > 0.0)) ? acos(pS / (nv1 * nv2)) * (180 / M_PI) : NAN;
}

//normaliza o vetor
array<real, 3> Vector::getNormalizado(){
    real n = getNorma();
    array<real, 3> r = {(x / n), (y / n), (z / n)};

    return r;
}

//distancia entre vetor e outro
real Vector::getDistanciaVetores(array<real, 3> v2){
    return Vector::getNorma((x - v2[0]), (y - v2[1]), (z - v2[2]));
}

//distancia entre vetores
real Vector::getDistanciaVetores(array<real, 3> v1, array<real, 3> v2){
    return Vector::getNorma((v1[0] - v2[0]), (v1[1] - v2[1]), (v1[2] - v2[2]));
}

//operações entre vetor e outro
array<real, 3> Vector::getOperacaoVetores(array<real, 3> v2, char op){
    return getOperacaoVetores({x, y, z}, v2, op);
}

//operações entre vetores
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

Vector operator+(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    array<real, 3> p1 = a1.getCoordenadas();
    array<real, 3> p2 = a2.getCoordenadas();

    return Vector((p1[0] + p2[0]), (p1[1] + p2[1]), (p1[2] + p2[2]));
}

Vector operator-(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    array<real, 3> p1 = a1.getCoordenadas();
    array<real, 3> p2 = a2.getCoordenadas();

    return Vector((p1[0] - p2[0]), (p1[1] - p2[1]), (p1[2] - p2[2]));
}

Vector operator*(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    array<real, 3> p1 = a1.getCoordenadas();
    array<real, 3> p2 = a2.getCoordenadas();

    return Vector((p1[0] * p2[0]), (p1[1] * p2[1]), (p1[2] * p2[2]));
}

Vector operator/(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    array<real, 3> p1 = a1.getCoordenadas();
    array<real, 3> p2 = a2.getCoordenadas();

    return ((p2[0] != 0.0) && (p2[1] != 0.0) && (p2[2] != 0.0)) ? Vector((p1[0] / p2[0]), (p1[1] / p2[1]), (p1[2] / p2[2])) : Vector(NAN, NAN, NAN);
}

Vector operator*(const Vector &v1, real valor){
    Vector a1 = v1;

    array<real, 3> p1 = a1.getCoordenadas();

    return Vector((p1[0] * valor), (p1[1] * valor), (p1[2] * valor));
}

Vector operator/(const Vector &v1, real valor){
    Vector a1 = v1;

    array<real, 3> p1 = a1.getCoordenadas();

    return (valor != 0.0) ? Vector((p1[0] / valor), (p1[1] / valor), (p1[2] / valor)) : Vector(NAN, NAN, NAN);
}


//fazer o produto vetorial aqui
real operator^(const Vector &v1, const Vector &v2){
    /* Vector a1 = v1;
    Vector a2 = v2;

    array<real, 3> p1 = a1.getCoordenadas();
    array<real, 3> p2 = a2.getCoordenadas();

    real r = 0.0;

    for (int i = 0; i < p1.size(); i++){
        r += p1[i] * p2[i];
    }

    return r; */
}

//destrutor
Vector::~Vector(){}