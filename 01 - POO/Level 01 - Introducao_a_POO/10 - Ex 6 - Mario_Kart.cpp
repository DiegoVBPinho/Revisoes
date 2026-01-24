/*
==================================================
📘 01 - POO - EXERCICIO 10: Ex 6 - Mario_Kart
==================================================

STATUS: DONE


COMPETENCIAS:
- LOGICA_DE_ATRIBUTOS
- CALCULOS_EM_METODOS
- REPRESENTACAO_UML

🧠 CONCEITO: ATRIBUTOS DINÂMICOS (Aula 04)
Nem todo atributo precisa ser definido manualmente. Alguns podem ser
calculados por métodos internos baseados em outros dados do próprio objeto,
mantendo a coerência da simulação.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO (Baseado no Slide 16):
1. Modele a classe 'Kart' baseada no desafio do material:
   - Atributos: std::string corredor, int cilindradas, float velocidadeMax.
2. Crie um método 'calcularVelocidade()':
   - A velocidadeMax deve ser igual a (cilindradas * 0.8).
3. Crie um método 'exibirPainel()':
   - Mostre quem está pilotando e a velocidade máxima atingida.
4. Na função main:
   - Instancie o kart do "Mario" (150cc) e do "Bowser" (200cc).
   - Calcule a velocidade de ambos e exiba os painéis.
--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:
class Kart
{
public:
   std::string corredor;
   int cilidradas;
   float velocidadeMax;

   void calcularVelocidade()
   {
      velocidadeMax = cilidradas * 0.8;
   }

   void exibirPainel()
   {
      std::cout << "O Corredor é: " << corredor << std::endl;
      std::cout << "A velocidade máxima atingida é: " << velocidadeMax << std ::endl;
   }
};

int main()
{
   Kart Mario;
   Mario.corredor = "Mário";
   Mario.cilidradas = 150;

   Kart Bowser;
   Bowser.corredor = "Bowser";
   Bowser.cilidradas = 200;

   Mario.calcularVelocidade();
   Bowser.calcularVelocidade();

   Mario.exibirPainel();
   Bowser.exibirPainel();

   return 0;
}