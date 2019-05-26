#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <array>
#include <math.h>

typedef double real;

class Vector{
    public:
        real x, y, z;
        int d;

        Vector();
        Vector(real x, real y, real z);
        ~Vector();

        static constexpr real nulo = 0.0;
        static constexpr real unitario = 1.0;

        std::array<real, 3> getCoordenadas();
        real getNorma();
        std::array<real, 3> getNormalizado();
        real getProdEscalar(std::array<real, 3> v1, std::array<real, 3> v2);
        real getAnguloVetores(real prodS, real nv1, real nv2);
        real getDistanciaVetores(std::array<real, 3> v2);

        std::array<real, 3> getOperacaoVetores(std::array<real, 3> v2, char op);
        static std::array<real, 3> getOperacaoVetores(std::array<real, 3> v1, std::array<real, 3> v2, char op);

        static real getNorma(real x, real y, real z);
        static real getDistanciaVetores(std::array<real, 3> v1, std::array<real, 3> v2);

        friend Vector operator+(const Vector &v1, const Vector &v2);
        friend Vector operator-(const Vector &v1, const Vector &v2);
        friend Vector operator*(const Vector &v1, const Vector &v2);
        friend Vector operator/(const Vector &v1, const Vector &v2);

        friend Vector operator*(const Vector &v1, real valor);
        friend Vector operator/(const Vector &v1, real valor);

        friend Vector operator^(const Vector &v1, const Vector &v2);

        Vector getProjVetores(const Vector &v1, const Vector &v2);
        Vector getProjVetores(const Vector &v2);

};

#endif