// STATUS: DONE

/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 3/10: O VIZINHO
==================================================

🎯 OBJETIVO:
1. Declare duas variáveis: int a, int b.
2. Crie ponteiros para ambas.
3. Crie um IF para verificar qual das duas variáveis
   foi criada em um endereço de memória MAIOR
   (comparar os ponteiros, não os valores).
4. Imprima "A tem endereço maior" ou "B tem endereço maior".

🔹 TESTES (Entrada e Saída Esperadas)
--------------------------------------------------
ENTRADA:
(Valores fixos no código)
a = 10
b = 20

SAÍDA ESPERADA:
(Nota: Os endereços 0x... mudam a cada execução)

Endereco de A: 0x7ffee4b8
Endereco de B: 0x7ffee4b4
A tem endereco maior.
--------------------------------------------------
*/

#include <iostream>

int main()
{

   // 1 - declaração de variáveis:
   int a = 10, b = 20;

   // 2 - criação de ponteiros
   int *pa, *pb = nullptr;
   pa = &a;
   pb = &b;

   // 3 - Comparando Endereços "Maiores"

   std::cout << "Endereço de A: " << pa << std::endl;
   std::cout << "Endereço de B: " << pb << std::endl;

   if (pa > pb)
      std::cout << "A tem o endereço maior";
   else
      std::cout << "B tem o endereço maior";

   return 0;
}