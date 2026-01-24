/*
==================================================
📘 01 - POO - EXERCICIO 07: Ex 3 - Zumbis_Referencias
==================================================

STATUS: DONE

COMPETENCIAS:
- PASSAGEM_POR_REFERENCIA
- INTERACAO_OBJETO_VARIAVEL
- LOGICA_DE_COMBATE

🧠 CONCEITO: REFERÊNCIAS EM MÉTODOS (Aula 04)
Quando passamos uma variável comum para um método, o C++ cria uma cópia.
Para que o Zumbi consiga "morder" e realmente diminuir a vida do jogador
que está na função main, precisamos usar o símbolo '&' para passar a
referência real da memória.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO (Baseado no Slide 13):
1. Crie uma classe 'Zumbi' com:
   - Atributo: std::string nome.
2. Crie um método chamado 'atacarPlayer(int &vidaPlayer)':
   - O parâmetro DEVE ser uma referência (int &).
   - O método deve subtrair 20 unidades da 'vidaPlayer'.
   - Exiba uma mensagem dizendo que o zumbi atacou o humano.
3. Na função main:
   - Crie uma variável inteira 'vidaHumano' começando com 100.
   - Instancie um zumbi.
   - Chame o método 'atacarPlayer(vidaHumano)'.
   - Exiba o valor da 'vidaHumano' após o ataque para confirmar a redução.
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

   // métodos
   void atacarPlayer(int &vidaPlayer)
   {
      vidaPlayer -= 20;
      std::cout << "O Zumbi atacou o jogador! " << std::endl;
   };
};

int main()
{
   int vidaHumano = 100;

   // instancia zumbi
   Zumbi z1;

   // metodo

   z1.atacarPlayer(vidaHumano);

   std::cout << "A vida do Humano é: " << vidaHumano << std::endl;

   return 0;
}