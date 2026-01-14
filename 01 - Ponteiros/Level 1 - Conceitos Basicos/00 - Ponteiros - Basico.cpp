/*
==================================================
📘 EXERCÍCIO DE FIXAÇÃO – 0/10 - PONTEIROS BÁSICOS
==================================================

🎯 OBJETIVO:
Declarar, inicializar e utilizar um ponteiro para
alterar o valor de uma variável indiretamente.


*/

#include <iostream>

using namespace std;

int main()
{
    int vida = 100;
    cout << "Valor inicial: " << vida << endl;

    // 1. DECLARAR PONTEIRO
    // Declare 'ptrVida' como ponteiro de int
    int *ptrvida;

    // 2. VINCULAR
    // Faça 'ptrVida' receber o endereço de 'vida' (use &)
    ptrvida = &vida;

    // 3. EXIBIR ENDEREÇO
    // Mostre o endereço guardado em 'ptrVida'
    cout << "Endereco memoria: " << ptrvida << endl;

    // 4. MODIFICAR INDIRETAMENTE
    //  Mude o valor para 200 usando apenas '*ptrVida'
    *ptrvida = 200;

    cout << "Valor final (esperado 200): " << vida << endl;

    return 0;
}