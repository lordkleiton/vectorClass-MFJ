#include <iostream>
#include "Vector.h"

using namespace std;

#define divisor cout << "----------------------------" << endl;

void testes(){
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

    divisor;

    Vector z = teste / 2;

    z.imprime();

    divisor;
}

void menuOperacoes(Vector& v1, Vector& v2){
    int o = 0;

    cout << "Operações disponíveis:" << endl;
    cout << "0  - Adição" << endl;
    cout << "1  - Subtração" << endl;
    cout << "2  - Multiplicação" << endl;
    cout << "3  - Comprimento" << endl;
    cout << "4  - Distância" << endl;
    cout << "5  - Normalização" << endl;
    cout << "6  - Produto por escalar" << endl;
    cout << "7  - Divisão por escalar" << endl;
    cout << "8  - Produto vetorial" << endl;
    cout << "9  - Projeção de vetor sobre o outro" << endl;
    cout << "10 - Ângulo entre os vetores" << endl;
    cout << "Insira a opção desejada (0 à 10): ";
    cin >> o;

    while (o < 0 || o > 10){
        cout << "Digite uma opção válida (0 à 10): ";
        cin >> o;
    }

    cout << o << endl;

    v1.imprime();

}

void insereManual(){
    int o = 0;

    cout << "Insira a quantidade de dimensões do vetor." << endl;
    cout << "Dimensões (2, 3 ou 4): ";
    cin >> o;

    while (o != 2 && o != 3 && o != 4){
        cout << "Digite uma dimensão válida (2, 3 ou 4): ";
        cin >> o;
    }

    cout << endl;

    texto t = {"x", "y", "z", "w"};
    vetor v1(o);
    vetor v2(o);

    cout << "Primeiro vetor:" << endl;

    for (int i = 0; i < o; i++){
        cout << "Insira a coordenada " << t[i] << ": ";
        cin >> v1[i];
    }

    cout << endl;

    cout << "Segundo vetor:" << endl;

    for (int i = 0; i < o; i++){
        cout << "Insira a coordenada " << t[i] << ": ";
        cin >> v2[i];
    }

    cout << endl;

    Vector vec1 = Vector(v1);
    Vector vec2 = Vector(v2);

    menuOperacoes(vec1, vec2);
}

void menu(){
    int o = 0;

    cout << "0 - Inserir manualmente." << endl;
    cout << "1 - Rodar testes." << endl;
    cout << "Opção (0 ou 1): ";
    cin >> o;

    while (o != 0 && o != 1){
        cout << "Digite uma opção válida (0 ou 1): ";
        cin >> o;
    }

    cout << endl;

    if (o == 1) testes();
    if (o == 0) insereManual();
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}