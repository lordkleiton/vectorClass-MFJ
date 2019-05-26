#include <iostream>
#include "Vector.h"

int main(int argc, char const *argv[])
{
    //Vector v1 = Vector(1.0, 2.0, 3.0);
    //Vector v2 = Vector(5.0, 5.0, 5.0);
    Vector v1 = Vector(2.0, 2.0, 0.0);
    Vector v2 = Vector(0.0, 3.0, 0.0);
    Vector v3 = Vector(3.0, 4.0, 0.0);

    array<real, 3> p1 = v1.getCoordenadas();
    array<real, 3> p2 = v2.getCoordenadas();
    array<real, 3> p3 = v3.getCoordenadas();

    string l[3] = {"x", "y", "z"};

    cout << "_____________ impressão __________" << endl;
    for (int i = 0; i < 3; i++){
        cout << "coord " << l[i] << ": " << p1[i] << " " << p2[i] << endl;
    }

    cout << "_____________ norma __________" << endl;

    cout << "norma de vetor estatico: " << Vector::getNorma(3.0, 4.0, 5.0) << endl;
    cout << "norma do vetor v1: " << v1.getNorma() << endl;
    cout << "norma do vetor v2: " << v2.getNorma() << endl;

    cout << "_____________ produto escalar __________" << endl;

    cout << "produto escalar de v1 por v2: " << v1.getProdEscalar(p1, p2) << endl;
    cout << "produto escalar de v1 por v1: " << v1.getProdEscalar(p1, p1) << endl;


    cout << "_____________ angulo entre vetores __________" << endl;

    cout << "angulo entre v1 e v2: " << v1.getAnguloVetores(v1.getProdEscalar(p1, p2), v1.getNorma(), v2.getNorma()) << " graus" << endl;  
    cout << "angulo entre v2 e v3: " << v1.getAnguloVetores(v2.getProdEscalar(p2, p3), v2.getNorma(), v3.getNorma()) << " graus" << endl;  
    cout << "angulo entre v1 e v3: " << v1.getAnguloVetores(v1.getProdEscalar(p1, p3), v1.getNorma(), v3.getNorma()) << " graus" << endl;
    cout << "angulo entre v1 e v3: " << v1.getAnguloVetores(v1.getProdEscalar(p1, p1), v1.getNorma(), v1.getNorma()) << " graus" << endl;  

    cout << "_____________ normalização __________" << endl;

    cout << Vector::unitario << " " << v1.unitario << endl;

    cout << v3.getNormalizado()[0] << endl;
    cout << v3.getNormalizado()[1] << endl;
    cout << v3.getNormalizado()[2] << endl;

    cout << Vector::getNorma(v3.getNormalizado()[0], v3.getNormalizado()[1], v3.getNormalizado()[2]) << endl;
   
    cout << "_____________ distancia entre vetores __________" << endl;   
    Vector v5 = Vector(1.0, 2.0, 0.0);
    Vector v6 = Vector(3.0, 1.0, 0.0);
    array<real, 3> p5 = v5.getCoordenadas();
    array<real, 3> p6 = v6.getCoordenadas();
    cout << Vector::getDistanciaVetores(p5, p6) << endl;
    cout << v5.getDistanciaVetores(p5) << endl;

    cout << "_____________ soma entre vetores __________" << endl;  

    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '+')[0] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '+')[1] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '+')[2] << endl;

    cout << "_____________ sub entre vetores __________" << endl;  

    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '-')[0] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '-')[1] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '-')[2] << endl;

    cout << "_____________ mult entre vetores __________" << endl;  

    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '*')[0] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '*')[1] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '*')[2] << endl;

    cout << "_____________ div entre vetores __________" << endl;  

    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '/')[0] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '/')[1] << endl;
    cout << Vector::getOperacaoVetores({0, 1, 2}, {1, 2, 3}, '/')[2] << endl;

    cout << "_____________ overload de operador __________" << endl;
    Vector a = v1 + v2;

    cout << a.getCoordenadas()[0] << endl;
    cout << a.getCoordenadas()[1] << endl;
    cout << a.getCoordenadas()[2] << endl;

    Vector b = v1 / v2;

    cout << b.getCoordenadas()[0] << endl;
    cout << b.getCoordenadas()[1] << endl;
    cout << b.getCoordenadas()[2] << endl;

    Vector b1 = v1 * 2.0;

    cout << b1.getCoordenadas()[0] << endl;
    cout << b1.getCoordenadas()[1] << endl;
    cout << b1.getCoordenadas()[2] << endl;

    Vector aa = Vector(1.0, 7.0, 0.0);
    Vector bb = Vector(2.0, -3.0, 0.0);

    Vector aaa = Vector(1.0, 2.0, -3.0);
    Vector bbb = Vector(2.0, 1.0, -2.0);

    Vector uh = aa ^ bb;

    cout << uh.getCoordenadas()[0] << endl;
    cout << uh.getCoordenadas()[1] << endl;
    cout << uh.getCoordenadas()[2] << endl;

    Vector f = uh.getProjVetores(aaa, bbb);

    cout << f.getCoordenadas()[0] << endl;
    cout << f.getCoordenadas()[1] << endl;
    cout << f.getCoordenadas()[2] << endl;

    return 0;
}