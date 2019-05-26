#include "Vector2.h"

//construtor padrão
Vector::Vector() : x(0.0), y(0.0), z(0.0) {}

//construtor com argumentos
Vector::Vector(real x, real y, real z) : x(x), y(y), z(z) {}

//retorna um std::array com as coordenadas
std::array<real, 3> Vector::getCoordenadas(){
    std::array<real, 3> r = {x, y, z};

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
real Vector::getProdEscalar(std::array<real, 3> v1, std::array<real, 3> v2){
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
std::array<real, 3> Vector::getNormalizado(){
    real n = getNorma();
    std::array<real, 3> r = {(x / n), (y / n), (z / n)};

    return r;
}

//distancia entre vetor e outro
real Vector::getDistanciaVetores(std::array<real, 3> v2){
    return Vector::getNorma((x - v2[0]), (y - v2[1]), (z - v2[2]));
}

//distancia entre vetores
real Vector::getDistanciaVetores(std::array<real, 3> v1, std::array<real, 3> v2){
    return Vector::getNorma((v1[0] - v2[0]), (v1[1] - v2[1]), (v1[2] - v2[2]));
}

//operações entre vetor e outro
std::array<real, 3> Vector::getOperacaoVetores(std::array<real, 3> v2, char op){
    return getOperacaoVetores({x, y, z}, v2, op);
}

//operações entre vetores
std::array<real, 3> Vector::getOperacaoVetores(std::array<real, 3> v1, std::array<real, 3> v2, char op){
    if (op != '+' && op != '-' && op != '*' && op != '/') return {NAN, NAN, NAN};

    std::array<real, 3> r;

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

    std::array<real, 3> p1 = a1.getCoordenadas();
    std::array<real, 3> p2 = a2.getCoordenadas();

    return Vector((p1[0] + p2[0]), (p1[1] + p2[1]), (p1[2] + p2[2]));
}

Vector operator-(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    std::array<real, 3> p1 = a1.getCoordenadas();
    std::array<real, 3> p2 = a2.getCoordenadas();

    return Vector((p1[0] - p2[0]), (p1[1] - p2[1]), (p1[2] - p2[2]));
}

Vector operator*(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    std::array<real, 3> p1 = a1.getCoordenadas();
    std::array<real, 3> p2 = a2.getCoordenadas();

    return Vector((p1[0] * p2[0]), (p1[1] * p2[1]), (p1[2] * p2[2]));
}

Vector operator/(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    std::array<real, 3> p1 = a1.getCoordenadas();
    std::array<real, 3> p2 = a2.getCoordenadas();

    return ((p2[0] != 0.0) && (p2[1] != 0.0) && (p2[2] != 0.0)) ? Vector((p1[0] / p2[0]), (p1[1] / p2[1]), (p1[2] / p2[2])) : Vector(NAN, NAN, NAN);
}

Vector operator*(const Vector &v1, real escalar){
    Vector a1 = v1;

    std::array<real, 3> p1 = a1.getCoordenadas();

    return Vector((p1[0] * escalar), (p1[1] * escalar), (p1[2] * escalar));
}

Vector operator/(const Vector &v1, real escalar){
    Vector a1 = v1;

    std::array<real, 3> p1 = a1.getCoordenadas();

    return (escalar != 0.0) ? Vector((p1[0] / escalar), (p1[1] / escalar), (p1[2] / escalar)) : Vector(NAN, NAN, NAN);
}

Vector operator^(const Vector &v1, const Vector &v2){
    Vector a1 = v1;
    Vector a2 = v2;

    std::array<real, 3> p1 = a1.getCoordenadas();
    std::array<real, 3> p2 = a2.getCoordenadas();
    
    return Vector((p1[1] * p2[2] - p1[2] * p2[1]), (p1[2] * p2[0] - p1[0] * p2[2]), (p1[0] * p2[1] - p1[1] * p2[0]));
}

Vector Vector::getProjVetores(const Vector &v1, const Vector &v2){
    real s = getProdEscalar({v1.x, v1.y, v1.z}, {v2.x, v2.y, v2.z}) / pow(getNorma(v2.x, v2.y, v2.z), 2);

    return v2 * s;
}

Vector Vector::getProjVetores(const Vector &v2){
    real s = getProdEscalar({x, y, z}, {v2.x, v2.y, v2.z}) / pow(getNorma(v2.x, v2.y, v2.z), 2);

    return v2 * s;
}

//destrutor
Vector::~Vector(){}