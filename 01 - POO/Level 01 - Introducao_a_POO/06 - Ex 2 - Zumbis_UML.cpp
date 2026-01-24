/*
==================================================
📘 01 - POO - EXERCICIO 06: Ex 2 - Zumbis_UML
==================================================

STATUS: DONE

COMPETENCIAS:
- INTERPRETACAO_UML
- VISIBILIDADE_MÉTODOS
- PADRONIZACAO_DE_NOMES

🧠 CONCEITO: DIAGRAMA DE CLASSES (Aula 04)
No Slide 12, o professor apresenta um diagrama com sinais de + e -.
1. SINAL DE (+): Significa que o membro é PUBLICO (acessível de fora).
2. SINAL DE (-): Significa que o membro é PRIVADO (veremos em Encapsulamento).

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO (Baseado no Slide 12):
1. Modele a classe 'Zumbi' seguindo exatamente este padrão UML:

   CLASSE: Zumbi
   --------------------------
   + nome : std::string
   + saude : int
   --------------------------
   + rugir() : void
   + tomarDano(valor : int) : void
   --------------------------

2. Na função main:
   - Instancie um zumbi.
   - Chame o método 'rugir()' (deve exibir algo como "Graaaaawr!").
   - Use 'tomarDano(50)' para reduzir a saúde.
   - Exiba o valor final da saúde no console.
--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:
class Zumbi
{
public:
   std::string nome;
   int saude;

   // metodos
   void rugir()
   {
      std::cout << " Graaaaawr !" << std::endl;
   }

   void tomarDano(int dano)
   {
      saude -= dano;
   }
};

int main()
{
   // instanciando 1 zumbi

   Zumbi z1;
   z1.nome = "Victor";
   z1.saude = 100;

   z1.rugir();
   z1.tomarDano(50);

   std::cout << "A vida atual é: " << z1.saude << std::endl;

   return 0;
}