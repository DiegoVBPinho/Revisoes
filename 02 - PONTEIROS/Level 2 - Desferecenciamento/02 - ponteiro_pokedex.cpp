/*
==================================================
📘 PONTEIROS - LEVEL 2 - EX 02: Evolução via Ponteiro
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Médio (Level 2)

COMPETENCIAS:
- PONTEIRO_DE_STRING
- SUBSTITUIÇÃO_DE_CONTEÚDO

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma string 'pokemon = "Charmander"'.
2. Crie um ponteiro para essa string.
3. Use o ponteiro para mudar o nome do pokemon para "Charmeleon".
4. Imprima a variável original 'pokemon'.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string pokemon = "Charmander";
    string *p = &pokemon;

    cout << "*p antes da alteração: " << *p << endl;
    cout << "VAR POKEMON ANTES DA ALTERAÇÃO: " << pokemon << endl;
    *p = "Charmeleon";

    cout << "----------------------" << endl;

    cout << "*p após a alteração: " << *p << endl;
    cout << "VAR POKEMON APÓS  A ALTERAÇÃO: " << pokemon << endl;

    return 0;
}