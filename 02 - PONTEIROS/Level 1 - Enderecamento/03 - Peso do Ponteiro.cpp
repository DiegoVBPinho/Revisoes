/*
==================================================
📘 PONTEIROS - LEVEL 1 - EX 03: Peso do Ponteiro
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Fácil (Level 1)

COMPETENCIAS:
- OPERADOR_SIZEOF
- COMPREENSÃO_DE_ARQUITETURA

🧠 CONCEITO:
Não importa se o ponteiro aponta para um 'char' (1 byte) ou um 'double' (8 bytes),
o ponteiro em si sempre tem o mesmo tamanho, pois ele guarda apenas um endereço.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie um 'char* pChar', um 'int* pInt' e um 'double* pDouble'.
2. Use 'sizeof()' para mostrar o tamanho de cada um dos TRÊS ponteiros.
3. Observe se os tamanhos são iguais ou diferentes.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    char *pChar;
    int *pInt;
    double *pDouble;

    // imprimindo os endereços//

    cout << "Ponteiro char ocupa tantos bytes: " << sizeof(pChar) << endl;
    cout << "Ponteiro int ocupa tantos bytes: " << sizeof(pInt) << endl;
    cout << "Ponteiro double ocupa tantos bytes: " << sizeof(pDouble) << endl;

    return 0;
}

// Todo ponteiro tem o tamanho do endereço da arquitetura, não do dado apontado.