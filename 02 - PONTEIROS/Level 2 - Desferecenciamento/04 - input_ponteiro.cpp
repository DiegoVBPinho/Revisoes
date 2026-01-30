/*
==================================================
📘 PONTEIROS - LEVEL 2 - EX 04: Input via Ponteiro
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Médio (Level 2)

COMPETENCIAS:
- USO_DE_CIN_COM_DESREFERENCIAÇÃO

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie um 'int level'.
2. Crie um ponteiro para ele.
3. Peça ao usuário: "Digite o novo level: ".
4. Use o cin para salvar o valor DIRETO no ponteiro: cin >> *ptr;
5. Mostre o valor da variável 'level'.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int level = 1;
    int *p = &level;

    cout << "Digite o novo level: ";
    cin >> *p;

    cout << *p;

    return 0;
}