/*
==================================================
📘 01 - POO - EXERCICIO 02: Atributos e Estados
==================================================

STATUS: DONE

COMPETENCIAS:
- DEFINICAO_ATRIBUTOS
- TIPAGEM_EM_CLASSES
- MODIFICADORES_ACESSO (PUBLIC)

🧠 O QUE SÃO ATRIBUTOS? (Aula 04)
Atributos são as propriedades ou características de uma classe. Eles
representam o "estado" de um objeto. Se a classe é o molde de um carro,
os atributos seriam 'cor', 'modelo' e 'ano'.

1. DECLARAÇÃO: Funciona como uma variável comum, mas dentro do escopo da classe.
2. PUBLIC: Modificador que permite que os atributos sejam acessados fora da classe.

--------------------------------------------------
SINTAXE BÁSICA C++:

class Celular {
public:
    string marca;
    int bateria;
    float preco;
};
--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Pokemon'.
2. Adicione quatro atributos públicos:
   - string nome;
   - string tipo;
   - int nivel;
   - float saude;
3. Na função main:
   - Instancie um pokemon chamado 'p1'.
   - Atribua valores para todos os atributos dele (ex: Pikachu, Elétrico, 10, 100.0).
   - Exiba cada atributo individualmente no console usando cout.

--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:
class Pokemon
{
public:
    std::string nome;
    std::string tipo;
    int nivel;
    float saude;
};

int main()
{
    Pokemon p1;

    p1.nome = "Squirtle";
    p1.tipo = "Agua";
    p1.nivel = 16;
    p1.saude = 100.0;

    std::cout << p1.nome << " " << p1.tipo << " " << p1.nivel << " " << p1.saude << std::endl;

    return 0;
}

// exercicio gerado por IA para aprender as sintaxes.
