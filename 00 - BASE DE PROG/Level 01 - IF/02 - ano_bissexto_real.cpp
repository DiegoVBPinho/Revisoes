/*
==================================================
📘 FUNDAMENTOS - LEVEL 1 - 02: O Ano Bissexto
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Difícil (Level 1)

COMPETENCIAS:
- LOGICA_BOOLEANA_AVANÇADA (&&, ||, !=)
- OPERADOR_MODULO (%)
- PRECEDENCIA_DE_OPERADORES

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

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        cout << " O Ano " << ano << " é bissexto.";
    }
    else
    {
        cout << "Não é ano bissexto!";
    }

    return 0;
}

// EXPLICAÇÃO RÁPIDA:
// 1. (ano % 4 == 0 && ano % 100 != 0) -> Verifica se é múltiplo de 4, mas ignora viradas de século (1700, 1800, 1900).
// 2. || (ano % 400 == 0) -> Abre a exceção: se for divisível por 400, volta a ser bissexto (ex: 2000, 2400).