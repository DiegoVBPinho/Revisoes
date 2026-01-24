/*
==================================================
📘 01 - POO - EXERCICIO 03: Métodos e Comportamentos
==================================================

STATUS: DONE

COMPETENCIAS:
- DEFINICAO_METODOS
- ESCOPO_DE_CLASSE
- MANIPULACAO_DE_ATRIBUTOS

🧠 O QUE SÃO MÉTODOS? (Aula 04)
Métodos são funções declaradas dentro de uma classe que determinam
o que o objeto pode fazer.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Carro'.
2. Adicione os atributos: marca, modelo, velocidade.
3. Crie dois métodos públicos:
   - void acelerar(int incremento): Soma à velocidade.
   - void exibirStatus(): Mostra os dados atuais.
4. Na função main:
   - Instancie, acelere e exiba o status do carro.
--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:

class Carro
{
public:
   std::string marca, modelo;
   int velocidade;

   // métodos
   void acelerar(int incremento)
   {
      velocidade += incremento;
   } // somará a velocidade ao incremento;

   void exibirStatus()
   {
      std::cout << "Marca: " << marca << std::endl;
      std::cout << "Modelo: " << modelo << std::endl;
      std::cout << "Velocidade: " << velocidade << std::endl;

   }; // mostra dados atuais
};

int main()
{
   Carro car;
   car.marca = "Toyota";
   car.modelo = "Corolla";
   car.velocidade = 30;

   // chamando função status antes de acelerar
   car.exibirStatus();

   // chamando acelerar
   car.acelerar(20);
   std::cout << std::endl;
   // chamando função status depois de acelerar
   car.exibirStatus();

   return 0;
}