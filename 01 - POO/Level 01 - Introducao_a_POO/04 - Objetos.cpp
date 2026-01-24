/*
==================================================
📘 01 - POO - EXERCICIO 04: Objetos
==================================================

STATUS: DONE

COMPETENCIAS:
- CRIACAO_DE_OBJETOS
- MEMORIA_INDEPENDENTE
- ACESSO_A_MEMBROS

🧠 O QUE SÃO OBJETOS? (Aula 04)
Um objeto é uma instância real de uma classe. Enquanto a classe é o projeto
estático, o objeto é a entidade viva que ocupa espaço na memória e possui
valores próprios em seus atributos.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO (Baseado no Slide 8):
1. Crie uma classe 'Smartphone' com dois atributos públicos:
   - std::string marca
   - int armazenamento
2. Na função main:
   - Instancie dois objetos: 'meuFone' e 'seuFone'.
   - Atribua valores diferentes para cada um (ex: Apple/128 e Samsung/256).
   - Exiba os dados de ambos no console para validar que cada objeto guarda
     sua própria informação de forma independente.
--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:
class Smartphone
{
public:
   std::string marca;
   int armazenamento;
};
int main()
{
   Smartphone meuFone;
   Smartphone seuFone;

   meuFone.marca = "Apple";
   meuFone.armazenamento = 128;

   seuFone.marca = "Samsung";
   seuFone.armazenamento = 256;

   std::cout << meuFone.marca << "/" << meuFone.armazenamento << std::endl;
   std::cout << seuFone.marca << "/" << seuFone.armazenamento << std::endl;

   return 0;
}