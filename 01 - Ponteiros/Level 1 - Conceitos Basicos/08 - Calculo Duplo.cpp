/*
==================================================
📘 LEVEL 1 - CONCEITOS BASICOS - EXERCICIO 08/10: Calculo Duplo
==================================================

STATUS: DONE

COMPETENCIAS:
- PTR_RETORNO_MULTIPLO
- FUNC_PARAM_PTR

🎯 OBJETIVO:
1. Funcao que retorna void mas 'devolve' soma e dobro via ponteiros.

🔹 TESTES (Entrada e Saida Esperadas)
--------------------------------------------------
Entrada: 10
Saida: 10, 20
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
