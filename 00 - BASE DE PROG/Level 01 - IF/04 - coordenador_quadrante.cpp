/*
==================================================
📘 FUNDAMENTOS - LEVEL 1 - 04: Plano Cartesiano
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Difícil (Level 1)

🎯 OBJETIVO DO EXERCICIO:
1. Receba X e Y (float).
2. Determine se está no Q1, Q2, Q3, Q4, na Origem (0,0) ou sobre um dos Eixos (X ou Y).

📥 ENTRADA: X = 0, Y = 5
📤 SAIDA ESPERADA: "A posição está sobre o Eixo Y."
--------------------------------------------------
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    float x, y;

    cout << "Digite um valor para X: ";
    cin >> x;
    cout << "Digite um valor para y: ";
    cin >> y;

    cout << fixed << setprecision(2);
    cout << " A posição está sobre : ";

    if (x == 0 && y == 0)
        cout << "a Origem." << endl;

    else if (y == 0)
        cout << "o Eixo X." << endl;

    else if (x == 0)
        cout << "o Eixo Y." << endl;

    else if (x > 0 && y > 0)
        cout << "Q1" << endl;

    else if (x < 0 && y > 0)
        cout << "Q2" << endl;

    else if (x < 0 && y < 0)
        cout << "Q3" << endl;

    else if (x > 0 && y < 0)
        cout << "Q4" << endl;

    return 0;
}

/* A ORDEM SEMPRE IMPORTA

Por que a ordem importa?
Ao testar x == 0 e y == 0 logo no início,
você simplifica os testes seguintes.
Por exemplo, se o código chega no else if (x == 0),
nós já sabemos que o y não pode ser zero (pois o primeiro if teria capturado),
 economizando uma verificação lógica.
 */