/*
==================================================
📘 FUNDAMENTOS - LEVEL 1 - 01: Triângulo Completo
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Difícil (Level 1)

COMPETENCIAS:
- LOGICA_DE_CONDIÇÃO_COMPOSTA (&&)
- TRIANGULO_INEQUALITY_THEOREM

🎯 OBJETIVO DO EXERCICIO:
1. Receba 3 valores (A, B, C).
2. Primeiro: Verifique se eles podem formar um triângulo (A < B+C e B < A+C e C < A+B).
3. Segundo: Se for válido, classifique em Equilátero, Isósceles ou Escaleno.
4. Se não for válido, avise o usuário.

📥 ENTRADA: 3, 4, 5
📤 SAIDA ESPERADA: "Triângulo Válido: Escaleno"
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()

{
    // 1
    int A, B, C;

    cin >> A;
    cin >> B >> C;

    // 2 - VERIFICAÇÃO DE TRIANGULO

    if (A < B + C && B < A + C && C < A + B)
    {
        cout << "Triangulo Válido: ";

        if (A == B && B == C)
        {
            cout << "Equilatero";
        }

        else if (A != B && B != C && A != C)
        {
            cout << "Escaleno";
        }

        else
        {
            cout << "Isoceles";
        }
    }
    else
    {
        cout << "Triangulo Invalido!";
    }

    return 0;
}

// todos iguais → Equilátero
// dois iguais → Isósceles
// todos diferentes → Escaleno