#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <array>
#include <vector>
#include <math.h>

typedef double real;
typedef std::vector<real> vetor;
typedef std::vector<std::string> texto;

class Vector{
    public:
        real x, y, z, w;
        int dimensao;
        static constexpr real nulo = 0.0;
        static constexpr real unitario = 1.0;

        //contrutores
        Vector();
        Vector(real x, real y);
        Vector(real x, real y, real z);
        Vector(real x, real y, real z, real w);
        ~Vector();

        vetor coordenadas();                                            //coordenadas do vetor

        real norma();                                                   //norma do vetor
        real prodEscalar(const Vector& v2);                             //produto escalar entre o vetor e outro
        real angulo(real produtoEscalar, real normaV1, real normaV2);
        real distancia(const Vector& v2);

        void imprime();

        Vector normalizado();                                           //normaliza um vetor
        Vector projecao(const Vector& v2);                              //projeta um vetor em outro

        static real norma(const Vector& v1);                            //norma de um vetor
        static real distancia(const Vector& v1, const Vector& v2);      //distância entre dois vetores
        static Vector projecao(const Vector& v1, const Vector& v2);     //projeta um vetor em outro
        static real prodEscalar(const Vector& v1, const Vector& v2);           //produto escalar entre dois vetores
        //static real angulo(real produtoEscalar, real normaV1, real normaV2);










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

        Vector getProjVetores(const Vector& v1, const Vector& v2);
        Vector getProjVetores(const Vector& v2);

        friend Vector operator+(const Vector& v1, const Vector& v2);
        friend Vector operator-(const Vector& v1, const Vector& v2);
        friend Vector operator*(const Vector& v1, const Vector& v2);
        friend Vector operator/(const Vector& v1, const Vector& v2);

        friend Vector operator*(const Vector& v1, real escalar);
        friend Vector operator/(const Vector& v1, real escalar);

        friend Vector operator^(const Vector& v1, const Vector& v2);


};

#endif