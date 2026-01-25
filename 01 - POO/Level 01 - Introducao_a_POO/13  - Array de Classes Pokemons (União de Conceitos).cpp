/*
==================================================
📘 01 - RELAÇÕES - EXERCICIO 02: Agregação com Array
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO

COMPETENCIAS:
- AGREGAÇÃO_MUITOS_PARA_UM
- ARRAY_DE_PONTEIROS
- ACESSO_VIA_SETA (->)

🧠 O QUE É AGREGAÇÃO COM ARRAY? (Aula 11/12)
É quando um objeto possui uma coleção de referências para outros objetos.
No seu jogo, um 'Cenario' pode ter um array de ponteiros para 'Inimigos'.
Se o Cenario mudar, os Inimigos ainda existem na memória.

⚠️ REGRA DE OURO:
Como estamos usando um array de ponteiros (*), acessamos os membros do
objeto usando o operador de seta (->) em vez do ponto (.).

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie a classe 'Pokemon' com: string nome, string tipo.
2. Crie a classe 'Treinador' com: string nome e um array de ponteiros: Pokemon* time[3].
3. No main:
   - Crie 3 objetos Pokemon individualmente.
   - Crie 1 objeto Treinador.
   - Guarde o ENDEREÇO (&) de cada Pokemon em uma posição do array do Treinador.
   - Use um loop 'for' para exibir o nome do treinador e os Pokemons do seu time.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

// Desenvolva as classes aqui:

class Pokemon
{
public:
    string nome;
    string tipo;

    Pokemon(string n, string t)
    {
        nome = n;
        tipo = t;
    }
};

class Treinador
{
public:
    string nome;
    // O molde do Array de Ponteiros:
    Pokemon *time[3];

    void mostrarEquipe()
    {
        cout << "Treinador: " << nome << endl;
        cout << "--- EQUIPE ---" << endl;
        // Desenvolva o loop for aqui para mostrar os nomes:
    }
};

int main()
{
    // 1. Instancie os Pokemons (ex: p1, p2, p3)

    // 2. Instancie o Treinador

    // 3. Associe usando o endereço: t.time[0] = &p1;

    // 4. Chame a função de mostrar equipe

    return 0;
}