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
        int dimensao;
        real x, y, z, w;
        vetor coord;
        static constexpr real nulo = 0.0;
        static constexpr real unitario = 1.0;

        Vector();
        Vector(real x, real y);
        Vector(real x, real y, real z);
        Vector(real x, real y, real z, real w);
        Vector(vetor v);
        ~Vector();

        void atualiza();                                                        //atualiza as coordenadas
        void imprime();                                                         //imprime as coordenadas
        vetor coordenadas();                                                    //coordenadas do vetor

        real norma();                                                           //norma do vetor
        real prodEscalar(Vector& v2);                                           //produto escalar entre o vetor e outro
        real angulo(Vector& v2);                                                //angulo entre o vetor e outro
        real distancia(Vector& v2);                                             //distancia entre o vetor e outro
        Vector normalizado();                                                   //normaliza o vetor
        Vector projecao(Vector& v2);                                            //projeta o vetor em outro

        static real norma(Vector& v1);                                          //norma de um vetor
        static real prodEscalar(Vector& v1, Vector& v2);                        //produto escalar entre dois vetores
        static real angulo(real produtoEscalar, real normaV1, real normaV2);    //angulo em graus entre dois vetores
        static real distancia(Vector& v1, Vector& v2);                          //distância entre dois vetores
        static Vector invalido();                                               //vetor inválido
        static Vector normalizado(Vector& v1);                                  //normaliza um vetor
        static Vector projecao(Vector& v1, Vector& v2);                         //projeta um vetor em outro

        friend Vector operator*(const Vector& v1, real escalar);                //multiplica vetor por escalar
        friend Vector operator/(const Vector& v1, real escalar);                //divide vetor por escalar

        friend Vector operator+(const Vector& v1, const Vector& v2);            //soma de vetor por vetor
        friend Vector operator-(const Vector& v1, const Vector& v2);            //subtração de vetor por vetor
        friend Vector operator*(const Vector& v1, const Vector& v2);            //multiplicação de vetor por vetor
        friend Vector operator/(const Vector& v1, const Vector& v2);            //divisão de vetor por vetor
        friend Vector operator^(const Vector& v1, const Vector& v2);            //produto vetorial
};

#endif