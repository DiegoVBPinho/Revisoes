/*
==================================================
📘 01 - POO - EXERCICIO 05: Ex 1 - Zumbis_Basico
==================================================

STATUS: DONE

COMPETENCIAS:
- MODELAGEM_DE_SISTEMAS
- ALTERACAO_DE_ESTADO
- LOGICA_DE_METODOS

🧠 CONCEITO: MÉTODOS DE AÇÃO (Aula 04)
Um método não serve apenas para exibir dados, mas para processar lógica que
altera os atributos. No caso de um jogo, o dano recebido deve ser subtraído
diretamente da vida do objeto.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO (Baseado no Slide 10):
1. Crie uma classe 'Zumbi' com os seguintes membros públicos:
   - std::string tipo
   - int vida
2. Crie um método chamado 'receberDano(int dano)' que:
   - Subtraia o valor do parâmetro 'dano' da vida atual do zumbi.
3. Crie um método chamado 'exibirStatus()' que:
   - Mostre o tipo e a vida atual do zumbi.
4. Na função main:
   - Instancie um zumbi (ex: tipo "Lento", vida 100).
   - Exiba o status inicial.
   - Chame o método 'receberDano(30)'.
   - Exiba o status novamente para conferir se a vida baixou para 70.
--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:

class Zumbi
{
public:
   std::string tipo;
   int vida;

   void receberDano(int dano)
   {
      vida -= dano;
   }

   void exibirStatus()
   {
      std::cout << "O Tipo do Zumbi é : " << tipo << std::endl;
      std::cout << "A vida atual é : " << vida << std::endl;
   }
};

int main()
{
   Zumbi z1;
   z1.tipo = "lento";
   z1.vida = 100;

   z1.exibirStatus();
   z1.receberDano(30);
   z1.exibirStatus();

   return 0;
}