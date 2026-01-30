/*
==================================================
📘 PONTEIROS - LEVEL 2 - EX 01: Alteração Direta
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Médio (Level 2)

COMPETENCIAS:
- DESREFERENCIAÇÃO (*)
- MANIPULAÇÃO_DE_VALOR_VIA_ENDEREÇO

🧠 CONCEITO:
O asterisco (*) antes do nome do ponteiro permite acessar o "conteúdo"
do endereço que ele guarda. É como abrir a gaveta que o GPS indicou.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma variável 'int vida = 100'.
2. Crie um ponteiro 'p' apontando para 'vida'.
3. Mude o valor da vida para 50 usando apenas o ponteiro.
4. Imprima a variável 'vida' (ela deve mostrar 50).
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int vida = 100;
    int *p = &vida;

    cout << *p << endl;

    *p = 50;

    cout << *p << endl;

    return 0;
}