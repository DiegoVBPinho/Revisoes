/*
==================================================
📘 PONTEIROS - LEVEL 2 - EX 03: Soma Remota
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Médio (Level 2)

COMPETENCIAS:
- OPERAÇÕES_MATEMÁTICAS_COM_PONTEIROS
- PRECEDÊNCIA_DE_OPERADORES

⚠️ DICA: Para somar valores via ponteiro, use parênteses: (*p) = (*p) + 10;

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie 'int xp = 1000'.
2. Crie um ponteiro para 'xp'.
3. Através do ponteiro, some 500 ao valor de xp.
4. Imprima o xp final.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int xp = 1000;
    int *p = &xp;

    cout << "valor original de xp: " << xp << endl;

    *p += 500;

    cout << "novo valor de xp: " << xp << endl;

    return 0;
}