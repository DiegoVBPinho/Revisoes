/*
==================================================
📘 FUNDAMENTOS - LEVEL 1 - 03: Classificação IMC
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Difícil (Level 1)

🎯 OBJETIVO DO EXERCICIO:
1. Receba peso e altura. Calcule IMC = peso / (altura * altura).
2. Classifique: < 18.5 (Abaixo), 18.5-24.9 (Normal), 25-29.9 (Sobrepeso),
   30-34.9 (Obesidade I), 35-39.9 (Obesidade II), >= 40 (Mórbida).

📥 ENTRADA: 80kg, 1.80m
📤 SAIDA ESPERADA: "IMC: 24.69 | Classificação: Peso Normal"
--------------------------------------------------
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    float IMC, peso, altura;

    cout << "Digite peso: ";
    cin >> peso;

    cout << "Digite Altura: ";
    cin >> altura;

    // calculo de IMC
    IMC = peso / (altura * altura);

    if (IMC < 18.5)
        cout << fixed << setprecision(2) << "IMC: " << IMC << " | Classificação: Peso Abaixo" << endl;

    else if (IMC > 18.5 && IMC < 24.9)
        cout << fixed << setprecision(2) << "IMC: " << IMC << " | Classificação: Peso Normal" << endl;

    else if (IMC > 25 && IMC < 29.9)
        cout << fixed << setprecision(2) << "IMC: " << IMC << " | Classificação: Peso Sobrepeso" << endl;

    else if (IMC > 30 && IMC < 34.9)
        cout << fixed << setprecision(2) << "IMC: " << IMC << " | Classificação: Peso Obesidade I" << endl;

    else if (IMC > 35 && IMC < 39.9)
        cout << fixed << setprecision(2) << "IMC: " << IMC << " | Classificação: Peso Obesidade II" << endl;

    else
        cout << fixed << setprecision(2) << "IMC: " << IMC << " | Classificação: Peso Morbida" << endl;
    return 0;
}
