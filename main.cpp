#include <iostream>
#include <cmath>
#include <array>
#include <math.h>

using namespace std;

typedef double real;

class Vector{
    private:
        real x, y, z;
    public:
        Vector();
        Vector(real x, real y, real z);
        array<real, 3> getCoordinates();
        real getNorma();
        static real getNorma(real x, real y, real z);
        real getNormalized();
        real getProdEscalar(array<real, 3> v1, array<real, 3> v2);
        real getAnguloVetores(real prodS, real nv1, real nv2);
        ~Vector();
};

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

/* real Vector::getNormalized(){
    return 
} */

//destrutor
Vector::~Vector()
{
    //cout << "objeto destruido" << endl;
}


int main(int argc, char const *argv[])
{
    //Vector v1 = Vector(1.0, 2.0, 3.0);
    //Vector v2 = Vector(5.0, 5.0, 5.0);
    Vector v1 = Vector(2.0, 2.0, 0.0);
    Vector v2 = Vector(0.0, 3.0, 0.0);
    array<real, 3> p1 = v1.getCoordinates();
    array<real, 3> p2 = v2.getCoordinates();
    string l[3] = {"x", "y", "z"};

    for (int i = 0; i < 3; i++){
        cout << "coord " << l[i] << ": " << p1[i] << " " << p2[i] << endl;
    }

    cout << "norma de vetor estatico: " << Vector::getNorma(3.0, 4.0, 5.0) << endl;
    cout << "norma do vetor v1: " << v1.getNorma() << endl;
    cout << "norma do vetor v2: " << v2.getNorma() << endl;

    cout << "produto escalar de v1 por v2: " << v1.getProdEscalar(p1, p2) << endl;

    cout << "angulo entre v1 e v2: " << v1.getAnguloVetores(v1.getProdEscalar(p1, p2), v1.getNorma(), v2.getNorma()) << " graus" << endl;  

    return 0;
}
