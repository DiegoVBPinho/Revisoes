/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 7/10: O TROCADOR
==================================================

🎯 OBJETIVO:
1. Crie duas variáveis: 'A' = 100, 'B' = 0.
2. Crie uma função 'trocar(int* p1, int* p2)'.
3. A função deve inverter os valores (A vira 0, B vira 100).
   (Dica: Use uma variável 'temp' auxiliar dentro da função).
4. Mostre os valores no main após a troca.

🔹 TESTES (Entrada e Saída Esperadas)
--------------------------------------------------
ENTRADA:
A = 100
B = 0

SAÍDA ESPERADA:
Antes: A = 100, B = 0
Depois: A = 0, B = 100
--------------------------------------------------
*/

#include <iostream>

void trocar(int *p1, int *p2)
{
   int temp = *p1;
   *p1 = *p2;
   *p2 = temp;
}

int main()
{
   int A = 100, B = 0;
   int *pa = nullptr;
   int *pb = nullptr;

   pa = &A;
   pb = &B;

   // saída antes

   std::cout << "Antes: A = " << A << ", B = " << B << std::endl;

   trocar(pa, pb); // sempre informar endereço, para que virem ponteiros e eles troquem valores na função.

   // saida depois
   std::cout << "Depois: A = " << A << ", B = " << B << std::endl;

   return 0;
}

/*Se a função foi declarada esperando um ponteiro (int *p1), ela está gritando: "Não me mande uma cópia do valor, me mande o endereço de onde ele mora!"
Ao mandar o endereço (pa ou &A), a função consegue ir lá na memória original e alterar o valor de verdade.
Se você mandasse apenas o valor, a função alteraria uma cópia e o main nunca saberia o que aconteceu.*/