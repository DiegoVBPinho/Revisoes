// STATUS: DONE

/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 8/10: CALCULO DUPLO
==================================================

🎯 OBJETIVO:
Este é o maior poder dos ponteiros no Level 1:
Retornar duas coisas ao mesmo tempo.

1. Crie uma função 'estatisticas(int n, int* dobro, int* triplo)'.
2. A função recebe um número 'n', e nos ponteiros
   ela grava o dobro e o triplo desse número.
3. No main, declare as variáveis para receber isso
   e chame a função.

🔹 TESTES (Entrada e Saída Esperadas)
--------------------------------------------------
ENTRADA:
n = 5

SAÍDA ESPERADA:
Dobro: 10
Triplo: 15
--------------------------------------------------
*/

#include <iostream>

void estatisticas(int n, int *dobro, int *triplo)

{
   *dobro = n * 2;
   *triplo = n * 3;
}

int main()
{
   // declaração de variáveis
   int n = 5;
   int dobro = 0, triplo = 0;

   // gerando o ponteiro apontado para nulo.

   int *pdobro = nullptr;
   int *ptriplo = nullptr;

   // passando endereços para ponteiros.
   pdobro = &dobro;
   ptriplo = &triplo;

   // chamando a função
   estatisticas(n, pdobro, ptriplo);

   // saída
   std::cout << "Dobro: " << dobro << std::endl;
   std::cout << "Triplo: " << triplo << std::endl;

   return 0;
}
