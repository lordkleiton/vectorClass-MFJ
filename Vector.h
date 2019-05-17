#ifndef VECTOR_H
#define VECTOR_H

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
        ~Vector();

        static constexpr real nulo = 0.0;
        static constexpr real unitario = 1.0;

        array<real, 3> getCoordenadas();
        real getNorma();
        array<real, 3> getNormalizado();
        real getProdEscalar(array<real, 3> v1, array<real, 3> v2);
        real getAnguloVetores(real prodS, real nv1, real nv2);
        real getDistanciaVetores(array<real, 3> v2);

        array<real, 3> getOperacaoVetores(array<real, 3> v2, char op);
        static array<real, 3> getOperacaoVetores(array<real, 3> v1, array<real, 3> v2, char op);

        static real getNorma(real x, real y, real z);
        static real getDistanciaVetores(array<real, 3> v1, array<real, 3> v2);


        //testes
        friend Vector operator+(Vector &v1, Vector &v2);
        friend Vector operator-(Vector &v1, Vector &v2);
        friend Vector operator*(Vector &v1, Vector &v2);
        friend Vector operator/(Vector &v1, Vector &v2);
};

#endif