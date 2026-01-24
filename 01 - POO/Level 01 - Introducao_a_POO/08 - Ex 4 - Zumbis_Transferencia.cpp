/*
==================================================
📘 01 - POO - EXERCICIO 08: Ex 4 - Zumbis_Transferencia
==================================================

STATUS: DONE

COMPETENCIAS:
- OBJETOS_COMO_PARAMETROS
- REFERENCIA_DE_INSTANCIAS
- LOGICA_DE_SISTEMAS_COOPERATIVOS

🧠 CONCEITO: INTERAÇÃO ENTRE OBJETOS (Aula 04)
Da mesma forma que passamos um 'int' por referência, podemos passar um objeto
inteiro. Isso permite que um objeto acesse e modifique os atributos de outro
objeto da mesma classe.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO (Baseado no Slide 14):
1. Crie uma classe 'Zumbi' com:
   - Atributos públicos: std::string nome, int vida.
2. Crie um método chamado 'transferirVida(Zumbi &destino, int quantidade)':
   - O parâmetro 'destino' DEVE ser uma referência para outro Zumbi.
   - A 'quantidade' deve ser subtraída da vida do zumbi atual (quem chama o método).
   - A mesma 'quantidade' deve ser somada à vida do zumbi 'destino'.
3. Na função main:
   - Instancie 'zumbiA' (100 de vida) e 'zumbiB' (50 de vida).
   - Faça 'zumbiA' transferir 30 de vida para 'zumbiB'.
   - Exiba a vida final de ambos para confirmar a transferência (70 e 80).
--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:

class Zumbi
{

public:
   // atributos
   std::string nome;
   int vida;

   // métodos
   void transferirVida(Zumbi &destino, int quantidade)
   {
      vida -= quantidade;
      destino.vida += quantidade;
   };
};

int main()
{
   // instancias
   Zumbi A;
   A.nome = "Frog";
   A.vida = 100;

   Zumbi B;
   B.nome = "Chrono";
   B.vida = 50;

   A.transferirVida(B, 30);

   std::cout << A.vida << std::endl;
   std::cout << B.vida << std::endl;

   return 0;
}