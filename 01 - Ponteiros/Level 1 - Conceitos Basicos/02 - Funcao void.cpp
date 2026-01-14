/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 2/10: A SOMA SILENCIOSA
==================================================

🎯 OBJETIVO:
1. Crie uma função void 'somar(int* a, int* b)'.
2. A função deve somar o valor de 'b' em 'a'
   (ex: *a = *a + *b).
3. No main, declare x=5, y=10.
4. Chame a função e mostre o novo valor de x.

📥 ENTRADA ESPERADA:
   <Nenhuma> (Valores fixos: x=5, y=10)

📤 SAÍDA ESPERADA:
   15

==================================================
*/

#include <iostream>

void somar(int *a, int *b)
{
   *a = *a + *b;
}

int main()
{
   int x = 5, y = 10;
   int *px, *py = nullptr;
   px = &x;
   py = &y;

   std::cout << "Valor Atual de X:" << *px << std::endl;

   somar(px, py);
   std::cout << "Novo valor de X:" << *px << std::endl;

   return 0;
}