/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 1/10: O ESPELHO
==================================================

🎯 OBJETIVO:
1. Declare uma variável inteira 'numero' = 10.
2. Declare um ponteiro 'pNum' apontando para ela.
3. Imprima o VALOR de 'numero' usando o ponteiro.
4. Imprima o ENDEREÇO de 'numero' usando o ponteiro.
5. Mude o valor para 20 usando apenas o ponteiro.

📥 ENTRADA ESPERADA:
   <Nenhuma> (O valor 10 é fixo no código)

📤 SAÍDA ESPERADA (Exemplo):
   10
   0x7ffd1a... (Este endereço hexadecimal muda a cada execução)
   20
==================================================
*/

#include <iostream>

int main()
{

   int numero = 10;
   int *pnum = nullptr;
   pnum = &numero;

   std::cout << "O Valor apontado pelo ponteiro é: " << *pnum << std::endl;

   std::cout << "O Endereço da variável onde o ponteiro está é : " << pnum << std::endl;

   // alterando o valor
   *pnum = 20;

   // imprimindo novo valor do ponteiro

   std::cout << "O Novo valor apontado pelo ponteiro é: " << *pnum << std::endl;

   return 0;
}