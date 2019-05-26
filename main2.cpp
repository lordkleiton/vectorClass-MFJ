#include <iostream>
#include "Vector2.h"

using namespace std;

#define divisor cout << "----------------------------" << endl;

int main(int argc, char const *argv[])
{
    Vector v1 = Vector();
    Vector v2 = Vector(1.0, 2.0);
    Vector v3 = Vector(1.0, 2.0, 3.0);
    Vector v4 = Vector(2.0, 2.0, 2.0);
    Vector v5 = Vector(1.1, 2.1, 3.1, 4.5);

    v3.imprime();

    divisor;

    cout << "Norma do v3: " << v3.norma() << endl;

    divisor;

    cout << "Produto escalar entre v3 e v4: " << v3.prodEscalar(v4) << endl;

    divisor;

    cout << "Angulo entre v3 e v4: " << v3.angulo(v4) << endl;

    divisor;

    vetor a = {2, 1};

    Vector teste = Vector(a);

    teste.imprime();

    divisor;

    cout << "Distancia entre os vetores v2 e teste: " << v2.distancia(teste) << endl;

    return 0;
}