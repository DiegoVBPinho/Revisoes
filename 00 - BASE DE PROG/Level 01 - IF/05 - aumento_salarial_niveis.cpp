/*
==================================================
📘 FUNDAMENTOS - LEVEL 1 - 05: Reajuste Progressivo
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Difícil (Level 1)

🎯 OBJETIVO DO EXERCICIO:
1. Receba o salário atual.
2. Até R$ 1500: aumento de 20%.
3. Entre R$ 1500 e R$ 3000: aumento de 15%.
4. Entre R$ 3000 e R$ 5000: aumento de 10%.
5. Acima de R$ 5000: aumento de 5%.
6. Imprima: Salário Antigo, % aplicado, Valor do aumento e Salário Novo.

📥 ENTRADA: 2000
📤 SAIDA ESPERADA: "Novo Salário: R$ 2300.00 (Aumento de 15%)"
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    float salarioAtual = 0;
    cin >> salarioAtual;

    int novoSalario = 0;

    cout << "Novo Salário: ";

    if (salarioAtual <= 1500)
        novoSalario = salarioAtual * 1.20;

    return 0;
}