// STATUS: DONE

/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 4/10: A CALCULADORA FANTASMA
   (Arquivo: 04 - Lógica com Ponteiros.cpp)
==================================================

🎯 OBJETIVO:
1. Declare uma variável 'numero' e leia um valor do teclado (cin).
2. Crie um ponteiro 'p' apontando para 'numero'.
3. SEM usar a variável 'numero', faça as seguintes contas
   usando APENAS o ponteiro:
   a) Some 10 ao valor atual (*p += 10).
   b) Subtraia 2 do resultado.
   c) Multiplique o resultado final por 2.
4. Exiba o valor final.

📥 ENTRADA ESPERADA (Exemplo):
   5

📤 SAÍDA ESPERADA:
   26

   (Explicação: 5 + 10 = 15; 15 - 2 = 13; 13 * 2 = 26)
==================================================
*/

#include <iostream>

int main()
{
   // declaração de VAR e leitura;

   int numero;

   std::cout << "Digite um numero: " << std::endl;
   std::cin >> numero;

   // Criação do Ponteiro p
   int *p = nullptr;
   p = &numero;

   // calculando usando ponteiro

   *p = *p + 10; // *p += 10
   *p = *p - 2;  // *p -= 2
   *p = *p * 2;  // *p *=2

   std::cout << *p << std::endl;

   return 0;
}