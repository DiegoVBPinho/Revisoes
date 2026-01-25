/*
==================================================
📘 FUNDAMENTOS - LEVEL 1 - 02: O Ano Bissexto
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Difícil (Level 1)

🧠 CONCEITO:
Um ano é bissexto se: (Divisível por 4 E não por 100) OU (Divisível por 400).

🎯 OBJETIVO DO EXERCICIO:
1. Receba um ano.
2. Aplique a lógica acima usando apenas uma estrutura de 'if/else' (use operadores lógicos).

📥 ENTRADA: 2000
📤 SAIDA ESPERADA: "O ano 2000 é bissexto."
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int ano;
    cout << "digite um ano: " << endl;
    cin >> ano;

    if (ano % 4 == 0 && ano % 100 == 0)
    {
        cout << " O Ano " << ano << " é bissexto.";
    }
    else
    {
        cout << "Não é ano bissexto!";
    }

    return 0;
}