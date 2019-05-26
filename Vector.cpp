#include "Vector.h"

Vector::Vector() : x(0.0), y(0.0), z(0.0), dimensao(3), coord(coordenadas()) {}

Vector::Vector(real x, real y) : x(x), y(y), dimensao(2), coord(coordenadas()) {}

Vector::Vector(real x, real y, real z) : x(x), y(y), z(z), dimensao(3), coord(coordenadas()) {}

Vector::Vector(real x, real y, real z, real w) : x(x), y(y), z(z), w(w), dimensao(4), coord(coordenadas()) {}

Vector::Vector(vetor v){
    dimensao = v.size();

    switch (dimensao){
        case 2:
            x = v[0];
            y = v[1];
            break;
        case 3:
            x = v[0];
            y = v[1];
            z = v[2];
            break;
        case 4:
            x = v[0];
            y = v[1];
            z = v[2];
            w = v[3];
            break;
    }

    atualiza();
}

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

void Vector::atualiza(){
    coord = coordenadas();
}

void Vector::imprime(){
    texto o = {"x", "y", "z", "w"};

    for (int i = 0; i < dimensao; i++) printf("Coordenada %s: %.2f \n", o[i].c_str(), coord[i]);
}

real Vector::norma(Vector& v1){
    real r = 0.0;
    vetor v = v1.coordenadas();

    for (int i = 0; i < v1.dimensao; i++){
        r += pow(v[i], 2);
    }

    return sqrt(r);
}

real Vector::norma(){
    return norma(*this);
}

real Vector::prodEscalar(Vector& v1, Vector& v2){
    if (v1.dimensao != v2.dimensao) return NAN;

    real r = 0.0;
    
    for (int i = 0; i < v1.dimensao; i++) r += v1.coord[i] * v2.coord[i];

    return r;
}

real Vector::prodEscalar(Vector& v2){
    return prodEscalar(*this, v2);
}

real Vector::angulo(real produtoEscalar, real normaV1, real normaV2){
    return ((normaV1 > 0.0) && (normaV2 > 0.0)) ? acos(produtoEscalar / (normaV1 * normaV2)) * (180 / M_PI) : NAN;
}

real Vector::angulo(Vector& v2){
    return angulo(prodEscalar(v2), norma(), v2.norma());
}

real Vector::distancia(Vector& v1, Vector& v2){
    if (v1.dimensao != v2.dimensao) return NAN;

    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++) a[i] = v1.coord[i] - v2.coord[i];

    Vector v = Vector(a);

    return Vector::norma(v);
}

real Vector::distancia(Vector& v2){
    return distancia(*this, v2);
}

Vector Vector::invalido(){
    return Vector(NAN, NAN, NAN);
}

Vector Vector::normalizado(Vector& v1){
    real n = v1.norma();

    if (n == 0) return v1.invalido();
    
    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++) a[i] = v1.coord[i] / n;

    return Vector(a);
}

Vector Vector::normalizado(){
    return normalizado(*this);
}

Vector Vector::projecao(Vector& v1, Vector& v2){
    real s = Vector::prodEscalar(v1, v2) / pow(Vector::norma(v2), 2);

    return v2 * s;
}

Vector Vector::projecao(Vector& v2){
    return projecao(*this, v2);
}

Vector operator*(const Vector &v1, real valor){
    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++) a[i] = v1.coord[i] * valor;

    return Vector(a);
}

Vector operator*(const Vector &v1, const Vector& v2){
    if (v1.dimensao != v2.dimensao) return Vector::invalido();

    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++) a[i] = v1.coord[i] * v2.coord[i];

    return Vector(a);
}

Vector operator/(const Vector& v1, real valor){
    if (valor == 0) return Vector::invalido();

    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++) a[i] = v1.coord[i] / valor;

    return Vector(a);
}

Vector operator/(const Vector &v1, const Vector& v2){
    if (v1.dimensao != v2.dimensao) return Vector::invalido();

    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++){
        if (v2.coord[i] == 0) return Vector::invalido();

        a[i] = v1.coord[i] / v2.coord[i];
    }

    return Vector(a);
}

Vector operator+(const Vector &v1, const Vector& v2){
    if (v1.dimensao != v2.dimensao) return Vector::invalido();

    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++) a[i] = v1.coord[i] - v2.coord[i];

    return Vector(a);
}

Vector operator-(const Vector &v1, const Vector& v2){
    if (v1.dimensao != v2.dimensao) return Vector::invalido();

    vetor a(v1.dimensao);

    for (int i = 0; i < v1.dimensao; i++) a[i] = v1.coord[i] + v2.coord[i];

    return Vector(a);
}

Vector operator^(Vector &v1, Vector &v2){
    if (v1.dimensao != 3) return Vector::invalido();
    if (v1.dimensao != v2.dimensao) return Vector::invalido();

    vetor a1 = v1.coord;
    vetor a2 = v2.coord;

    return Vector((a1[1] * a2[2] - a1[2] * a2[1]), (a1[2] * a2[0] - a1[0] * a2[2]), (a1[0] * a2[1] - a1[1] * a2[0]));
}