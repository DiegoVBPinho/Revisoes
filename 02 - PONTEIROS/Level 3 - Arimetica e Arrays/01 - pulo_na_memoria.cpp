/*
==================================================
📘 PONTEIROS - LEVEL 3 - 01: Pulo na Memória
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE
DIFICULDADE: Médio (Level 3)

COMPETENCIAS:
- ARITMETICA_DE_PONTEIROS
- COMPREENSÃO_DE_SALTOS (sizeof)

🧠 CONCEITO:
Quando você faz 'ponteiro + 1', o C++ não soma 1 ao endereço.
Ele soma o tamanho do tipo (ex: 4 bytes para int). É um salto para a próxima casa!

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie um array 'int valores[2] = {10, 20}'.
2. Crie um ponteiro 'p' apontando para 'valores'.
3. Imprima o endereço de 'p'.
4. Imprima o endereço de 'p + 1'.
5. Subtraia os endereços e veja quantos bytes o C++ pulou.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int valores[2] = {10, 20};
    int *p = valores;

    cout << "Endereco de p:     " << p << endl;
    cout << "Endereco de p + 1: " << p + 1 << endl;

    cout << "Bytes pulados (sizeof): "
         << sizeof(*p) << endl;

    cout << "Bytes pulados (calculado): "
         << sizeof(valores) / 2 << endl; // sizeof(valores) = 2 * sizeof(int)  - 2 É O NÚMERO DE ELEMTENTOS DO ARRAY * O TAMANHO DE INT

    return 0;
}
