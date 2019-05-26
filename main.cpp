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

void operacao(Vector& v1, Vector& v2, int o){
    Vector r;
    real a = 0;
    int o2 = 0;
    real escalar = 0;

    switch(o){
        case 0: 
            r = v1 + v2;
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 1:
            cout << "0 - (v1 - v2)" << endl;
            cout << "1 - (v2 - v1)" << endl;
            cout << "Escolha a operação a ser executada (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            r = (o2 == 0) ? v1 - v2 : v2 - v1;
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 2:
            r = v1 * v2;
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 3: 
            cout << "0 - (v1 / v2)" << endl;
            cout << "1 - (v2 / v1)" << endl;
            cout << "Escolha a operação a ser executada (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            r = (o2 == 0) ? v1 / v2 : v2 / v1;
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 4:
            cout << "0 - Vetor v1" << endl;
            cout << "1 - Vetor v2" << endl;
            cout << "Escolha o vetor a ser dada a norma (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            a = (o2 == 0) ? v1.norma() : v2.norma();

            cout << "A norma do vetor é: " << a << endl;
            break;
        case 5:
            cout << endl;
            cout << "A distância entre v1 e v2 é " << v1.distancia(v2) << endl;
            break;
        case 6:
            cout << "0 - Vetor v1" << endl;
            cout << "1 - Vetor v2" << endl;
            cout << "Escolha o vetor a ser normalizado (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            r = (o2 == 0) ? v1.normalizado() : v2.normalizado();
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 7:
            cout << "0 - Vetor v1" << endl;
            cout << "1 - Vetor v2" << endl;
            cout << "Escolha o vetor a ser multiplicado (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            cout << "Digite o escalar: ";
            cin >> escalar;

            r = (o2 == 0) ? v1 * escalar : v2 * escalar;
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 8:
            cout << "0 - Vetor v1" << endl;
            cout << "1 - Vetor v2" << endl;
            cout << "Escolha o vetor a ser dividido (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            cout << "Digite o escalar: ";
            cin >> escalar;

            r = (o2 == 0) ? v1 * escalar : v2 / escalar;
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 9:
            cout << "0 - v1 escalar v2" << endl;
            cout << "1 - v2 escalar v1" << endl;
            cout << "Escolha uma operação (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            r = (o2 == 0) ? v1 ^ v2 : v2 ^ v1;
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 10:
            cout << "0 - v1 projetado em v2" << endl;
            cout << "1 - v2 projetado em v1" << endl;
            cout << "Escolha uma operação (0 ou 1): ";
            cin >> o2;

            while (o2 != 0 && o2 != 1){
                cout << "Digite uma opção válida (0 ou 1): ";
                cin >> o2;
            }

            r = (o2 == 0) ? v1.projecao(v2) : v2.projecao(v1);
            cout << endl;
            cout << "O vetor resultante da operação possui as seguintes características:" << endl;
            r.imprime();
            break;
        case 11:
            cout << endl;
            cout << "O ângulo entre v1 e v2 é de " << v1.angulo(v2) << "º" << endl;
            break;
    }

    cout << endl;
}

void menuOperacoes(Vector& v1, Vector& v2){
    int o = 0;

    divisor;
    cout << endl;
    cout << "v1 = {";
    for (int i = 0; i < v1.dimensao; i++){
        cout << v1.coord[i];
        if (i < (v1.dimensao - 1)) cout << ", ";
    }
    cout << "}" << endl;
    cout << "v2 = {";
    for (int i = 0; i < v2.dimensao; i++){
        cout << v2.coord[i];
        if (i < (v2.dimensao - 1)) cout << ", ";
    }
    cout << "}" << endl;
    cout << endl;
    cout << "Operações disponíveis:" << endl;
    cout << "0  - Adição" << endl;
    cout << "1  - Subtração" << endl;
    cout << "2  - Multiplicação" << endl;
    cout << "3  - Divisão" << endl;
    cout << "4  - Comprimento" << endl;
    cout << "5  - Distância" << endl;
    cout << "6  - Normalização" << endl;
    cout << "7  - Produto por escalar" << endl;
    cout << "8  - Divisão por escalar" << endl;
    cout << "9  - Produto vetorial" << endl;
    cout << "10 - Projeção de vetor sobre o outro" << endl;
    cout << "11 - Ângulo entre os vetores" << endl;
    cout << "Insira a opção desejada (0 à 11): ";
    cin >> o;

    while (o < 0 || o > 11){
        cout << "Digite uma opção válida (0 à 11): ";
        cin >> o;
    }

    operacao(v1, v2, o);
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

    while (true){
        menuOperacoes(vec1, vec2);
    }
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

int main(int argc, char const *argv[]){
    menu();

    return 0;
}