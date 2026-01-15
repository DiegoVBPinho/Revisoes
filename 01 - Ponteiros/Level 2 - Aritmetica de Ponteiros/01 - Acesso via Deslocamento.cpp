/*
==================================================
📘 LEVEL 2 - EXERCÍCIO 1/10: O SALTO DIMENSIONAL
==================================================

STATUS: DONE

COMPETENCIAS:
- PTR_DESLOCAMENTO
- PTR_ARITMETICA

🎯 OBJETIVO:
1. Crie um array 'int numeros[] = {10, 20, 30, 40}'.
2. Crie um ponteiro 'p' apontando para o início.
3. SEM alterar o ponteiro (sem p++), imprima o primeiro
   e o terceiro elemento usando matemática: *(p + 0) e *(p + 2).

🔹 TESTES (Entrada e Saída Esperadas)
--------------------------------------------------
ENTRADA:
{10, 20, 30, 40}

SAÍDA ESPERADA:
1o: 10
3o: 30
--------------------------------------------------
*/

#include <iostream>

int main()
{
   int numeros[] = {10, 20, 30, 40};
   int *p = numeros;

   // impressão

   std::cout << "1º : " << *(p + 0) << std::endl; // ande, depois aponte
   std::cout << "3º : " << *(p + 2) << std::endl; // ande, depois aponte

   return 0;
}

// o trick deste exercício é a forma que o vc usa o ponteiro para andar dentro do vetor.
// o Parenteses importa muito.