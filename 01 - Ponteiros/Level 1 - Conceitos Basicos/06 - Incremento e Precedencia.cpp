/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 6/10: O UPGRADE
==================================================

🎯 OBJETIVO:
1. Crie uma variável 'nivel' = 1.
2. Crie uma função 'upar(int* p)' que incrementa
   o valor recebido (soma +1).
3. ATENÇÃO: Use parênteses (*p)++ para garantir
   que está somando no VALOR, não no endereço.
4. Chame a função 3 vezes no main e imprima o
   nível final (deve ser 4).

🔹 TESTES (Entrada e Saída Esperadas)
--------------------------------------------------
ENTRADA:
nivel inicial = 1

SAÍDA ESPERADA:
Nivel final: 4
--------------------------------------------------
*/

#include <iostream>

void upar(int *p)
{
   (*p)++; // precisa usar parenteses. PQ?

   // PRECEDÊNCIA: O PARENTESES É PRIORIDADE:
   //"Primeiro, resolva o *p (entre na casa e pegue o valor).
   //  AGORA que você tem o valor na mão, faça o ++ nele."
}

int main()
{
   int nivel = 1;
   int *pnivel = nullptr;
   pnivel = &nivel;

   upar(pnivel); // chamada 1 - nivel = 2
   upar(pnivel); // chamada 2 - nivel = 3
   upar(pnivel); // chamada 3 - nivel = 4

   std::cout << "Nivel Final: " << nivel << std::endl; // resposta deveria ser 4;

   return 0;
}