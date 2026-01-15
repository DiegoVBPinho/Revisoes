// STATUS: DONE

/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 9/5: O INTERRUPTOR
==================================================

🎯 OBJETIVO:
1. Declare uma variável 'bool ligado = false'.
2. Crie uma função 'acionar(bool* estado)'.
3. A função deve inverter o estado atual
   (se for true vira false, se for false vira true).
   Dica: *estado = !(*estado).
4. Chame a função e imprima o resultado (0 ou 1).

🔹 TESTES (Entrada e Saída Esperadas)
--------------------------------------------------
ENTRADA:
ligado = false (0)

SAÍDA ESPERADA:
Apos acionar: 1
--------------------------------------------------
*/

#include <iostream>

void acionar(bool *estado)
{
   *estado = !*estado;
}

int main()
{
   bool ligado = false;
   bool *pligado = &ligado;

   std::cout << "Antes de Acionar: " << ligado << std::endl;

   // chamando função para mudar o estado;
   acionar(pligado);

   std::cout << "Apos acionar: " << ligado << std::endl;

   return 0;
}