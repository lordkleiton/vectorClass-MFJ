#include <iostream>
#include "Vector2.h"

using namespace std;

#define divisor cout << "----------------------------" << endl;

int main(int argc, char const *argv[])
{
    Vector v1 = Vector();
    Vector v2 = Vector(1.0, 2.0);
    Vector v3 = Vector(1.0, 2.0, 3.0);
    Vector v4 = Vector(1.1, 2.1, 3.1, 4.5);

    v4.imprime();

    divisor;

    cout << "Norma do v4: " << v4.norma() << endl;

    divisor;

    return 0;
}