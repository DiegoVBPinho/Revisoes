/*
==================================================
📘 LEVEL 2 - EXERCÍCIO 2/10: O NAVEGADOR
==================================================
STATUS: DONE

COMPETENCIAS:
- PTR_INCREMENTO
- PTR_LOOP_FOR

🎯 OBJETIVO:
1. Crie um array 'int arr[] = {1, 2, 3, 4, 5}'.
2. Use um ponteiro 'p' e um loop 'for'.
3. Percorra o array incrementando o ponteiro (p++)
   para imprimir todos os valores.

🔹 TESTES (Entrada e Saída Esperadas)
--------------------------------------------------
ENTRADA:
{1, 2, 3, 4, 5}

SAÍDA ESPERADA:
1 2 3 4 5
--------------------------------------------------
*/

#include <iostream>

int main()

{
   // declarações:

   int arr[] = {1, 2, 3, 4, 5};
   int *p = arr;

   // criando for:
   for (int i = 0; i < 5; i++)
   {
      std::cout << *p << " ";
      (p++);
   }

   return 0;
}