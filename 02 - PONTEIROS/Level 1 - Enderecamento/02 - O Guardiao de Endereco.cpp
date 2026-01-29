/*
==================================================
📘 PONTEIROS - LEVEL 1 - EX 02: O Guardião de Endereço
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Fácil (Level 1)

COMPETENCIAS:
- DECLARAÇÃO_TIPO_PONTEIRO (*)
- ATRIBUIÇÃO_DE_ENDEREÇO

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma variável 'float velocidade = 80.5'.
2. Declare um ponteiro para float: 'float* ptrVel'.
3. Atribua o endereço da velocidade ao ponteiro.
4. Imprima o valor armazenado dentro de 'ptrVel' (deve ser o endereço).
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 1

    float velocidade = 80.5;
    float *ptrVel = nullptr;
    ptrVel = &velocidade;

    cout << "Imprimindo endereço de PRTVEL: " << ptrVel << endl;

    return 0;
}