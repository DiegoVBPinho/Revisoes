/*
==================================================
📘 PONTEIROS - LEVEL 1 - EX 01: GPS de Variável
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: DONE

DIFICULDADE: Fácil (Level 1)

COMPETENCIAS:
- USO_DO_OPERADOR_&
- IDENTIFICAÇÃO_DE_ENDEREÇO

🧠 CONCEITO:
Toda variável ocupa um espaço físico na memória RAM. O operador '&'
funciona como um GPS que nos diz a latitude e longitude (endereço) desse espaço.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma variável 'int idItem = 500'.
2. Imprima o valor da variável.
3. Imprima o endereço de memória dessa variável usando '&'.
--------------------------------------------------
*/

#include <iostream>
#include <string>

int main()
{
    int idItem = 500; // criação da variavel normal
    int *p = nullptr; // ponteiro p apontando para NULO
    p = &idItem;      // variavel P recebe o endereço de idItem.

    std::cout << "VALOR da variavel apontado pelo ponteiro *P(=500): " << *p << std::endl; // imprimindo o valor que P está apontado
    std::cout << "ENDEREÇO da variavel apontado pelo ponteiro P: " << p << std::endl;      // imprimindo o endereço que P está apontando.

    // alterando o valor via ponteiro

    *p = 900; // o VALOR da variavel foi alterado pelo ponteiro, logo, se imprimir a variavel, ela deveria ficar 900 e nao mais 500

    std::cout << "VALOR da variavel apontado pelo ponteiro *P (=900): " << *p << std::endl; // imprimindo o valor que P está apontado
    std::cout << "ENDEREÇO da variavel apontado pelo ponteiro P: " << p << std::endl;       // imprimindo o endereço que P está apontando.

    return 0;
}