/*
==================================================
📘 01 - POO - EXERCICIO 01: O Primeiro Molde
==================================================

STATUS: DONE

COMPETENCIAS:
- CLASSE_CONCEITO
- ATRIBUTOS_BASICOS
- INSTANCIACAO

🧠 O QUE É UMA CLASSE? (Aula 04)
Uma classe é o "projeto" ou "molde" de um objeto. Ela define quais dados
um objeto terá (Atributos) e o que ele pode fazer (Métodos).

1. ATRIBUTOS: São as variáveis dentro da classe (características).
2. MÉTODOS: São as funções dentro da classe (comportamentos).

--------------------------------------------------
SINTAXE BÁSICA C++:

class NomeDaClasse {
public:            // Modificador de acesso (permite uso fora da classe)
    string atributo;

    void metodo() {
        // Código aqui
    }
}; // <-- Não esqueça o ponto e vírgula!
--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Guerreiro'.
2. Adicione um atributo público: string nome.
3. Adicione um atributo público: int forca.
4. Na função main:
   - Instancie (crie) um guerreiro chamado 'g1'.
   - Atribua um nome e um valor de força para ele.
   - Exiba os dados no console usando cout.

--------------------------------------------------
*/

#include <iostream>
#include <string>

// Desenvolva sua classe aqui:

class Guerreiro
{
public:
    std::string nome;
    int forca;
};

int main()
{
    // Desenvolva a instância e exibição aqui:
    Guerreiro g1;

    // atribuindo valores
    g1.nome = "Victor";
    g1.forca = 95;

    // apresentando valores

    std::cout << "O nome do guerreiro é: " << g1.nome << std::endl;
    std::cout << "A forca do guerreiro é: " << g1.forca << std::endl;

    return 0;
}