/*
==================================================
📘 FUNDAMENTOS - LEVEL 1 - 03: Classificação IMC
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Difícil (Level 1)

COMPETENCIAS:
- MANIPULAÇÃO_DE_PONTO_FLUTUANTE (float/double)
- FORMATAÇÃO_DE_SAIDA (iomanip/setprecision)
- ESTRUTURA_CONDICIONAL_ENCADEADA (if/else if/else)
- EXERCICIO_DE_ORDEM_LOGICA (Intervalos de valores)

🎯 OBJETIVO DO EXERCICIO:
1. Receba peso e altura. Calcule IMC = peso / (altura * altura).
2. Classifique: < 18.5 (Abaixo), 18.5-24.9 (Normal), 25-29.9 (Sobrepeso),
   30-34.9 (Obesidade I), 35-39.9 (Obesidade II), >= 40 (Mórbida).

📥 ENTRADA: 80kg, 1.80m
📤 SAIDA ESPERADA: "IMC: 24.69 | Classificação: Peso Normal"
--------------------------------------------------
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float IMC, peso, altura;

    cout << "Digite peso: ";
    cin >> peso;

    cout << "Digite Altura: ";
    cin >> altura;

    // Calculo de IMC
    IMC = peso / (altura * altura);

    // Configuração global de saída para 2 casas decimais
    cout << fixed << setprecision(2);
    cout << "IMC: " << IMC << " | Classificação: ";

    // Lógica de intervalos (Importante: usar <= ou >= para não deixar "buracos" entre os números)
    if (IMC < 18.5)
        cout << "Abaixo do peso" << endl;
    else if (IMC < 25.0) // Se chegou aqui, ja sabemos que é >= 18.5
        cout << "Peso Normal" << endl;
    else if (IMC < 30.0)
        cout << "Sobrepeso" << endl;
    else if (IMC < 35.0)
        cout << "Obesidade I" << endl;
    else if (IMC < 40.0)
        cout << "Obesidade II" << endl;
    else
        cout << "Obesidade Morbida" << endl;

    return 0;
}