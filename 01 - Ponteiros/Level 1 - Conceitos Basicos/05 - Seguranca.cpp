// STATUS: DONE

/*
==================================================
📘 LEVEL 1 - EXERCÍCIO 5/10: O GUARDIÃO (SEGURANÇA)
   (Arquivo: 05 - Segurança.cpp)
==================================================

🎯 OBJETIVO:
1. Declare uma variável inteira 'cofre' com valor 1000.
2. Declare um ponteiro 'p' inicializado com 'nullptr' (Nulo).
3. Pergunte ao usuário: "Deseja conectar o ponteiro? (1=Sim, 0=Não)".
4. Se o usuário digitar 1, faça 'p' apontar para 'cofre'.
5. AGORA O PASSO CRUCIAL:
   - Tente imprimir o valor de '*p'.
   - MAS... você SÓ pode imprimir se o ponteiro NÃO for nulo.
   - Use um 'if' para verificar se o ponteiro é válido antes de acessar.
   - Se for nulo, imprima "Erro: Ponteiro desconectado".

📥 ENTRADA ESPERADA (Caso 1):
   0
📥 ENTRADA ESPERADA (Caso 2):
   1

📤 SAÍDA ESPERADA (Caso 1):
   Erro: Ponteiro desconectado

📤 SAÍDA ESPERADA (Caso 2):
   Valor do Cofre: 1000
==================================================
*/

#include <iostream>

int main()
{
   int cofre = 1000; // VAR COFRE
   int *p = nullptr; // ponteiro null
   int resposta = 0; // resposta do segurança

   // perguntando ao usuário se deseja conectar ao cofre
   std::cout << "Deseja conectar o ponteiro? (1 = Sim, 0 = Nao)" << std::endl;
   std::cin >> resposta;

   if (resposta == 1)
   {
      p = &cofre; // conectou
   }

   // tentando imprimir *P

   if (p != nullptr)
      std::cout << "Valor do Cofre: " << *p;
   else
      std::cout << "Erro: Ponteiro desconectado" << std::endl;

   return 0;
}