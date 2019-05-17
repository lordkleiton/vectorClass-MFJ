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
        array<real, 3> getCoordinates();
        real getNorma();
        static real getNorma(real x, real y, real z);
        array<real, 3> getNormalized();
        real getProdEscalar(array<real, 3> v1, array<real, 3> v2);
        real getAnguloVetores(real prodS, real nv1, real nv2);
        real getDistanciaVetores(array<real, 3> v2);
        static real getDistanciaVetores(array<real, 3> v1, array<real, 3> v2);
        static constexpr real unitario = 1.0;
        static constexpr real nulo = 0.0;
        ~Vector();
};


#endif