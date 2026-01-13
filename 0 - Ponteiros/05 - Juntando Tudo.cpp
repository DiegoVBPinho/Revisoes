/*
==================================================
⚔️ DESAFIO FINAL: O TREINADOR DE ELITE
==================================================

🎯 OBJETIVO:
Criar um time de Pokémons de tamanho definido pelo
usuário (Runtime), preencher os dados e limpar a memória.
==================================================
*/

#include <iostream>
#include <string>

using namespace std;

// 1. DEFINIÇÃO DA ESTRUTURA
struct Pokemon
{
    string nome;
    int vida;
};

int main()
{
    int quantidade;

    cout << "=== CENTRO POKEMON ===" << endl;
    cout << "Quantos Pokemons voce vai levar para a batalha? ";
    cin >> quantidade;

    // 2. ALOCAÇÃO DO TIME (A Mágica)
    // TODO: Crie um ponteiro 'time' do tipo Pokemon
    // TODO: Aloque um array de Pokemons do tamanho 'quantidade'
    // Dica: Pokemon* ... = new Pokemon[...];
    Pokemon *time = nullptr;
    time = new Pokemon[quantidade];

    // 3. CAPTURA (Preenchendo os dados)
    cout << "\n--- Cadastrando o Time ---" << endl;
    for (int i = 0; i < quantidade; i++)
    {
        cout << "Nome do Pokemon " << i + 1 << ": ";
        // TODO: Leia o nome e guarde em time[i].nome
        // Dica: cin >> time[i].nome;
        cin >> time[i].nome;

        // Vamos dar 100 de vida inicial para todos
        // TODO: Defina a vida como 100 (time[i].vida = 100)
        time[i].vida = 100;
    }

    // 4. STATUS DA EQUIPE
    cout << "\n--- Equipe Pronta para Batalha ---" << endl;
    for (int i = 0; i < quantidade; i++)
    {
        // TODO: Imprima o Nome e a Vida de cada um
        cout << "P" << i + 1 << ": " << time[i].nome << " | HP: " << time[i].vida << endl;
    }

    // 5. LIBERAÇÃO (Muito Importante!)
    // TODO: Delete o array 'time' da memória para não vazar RAM
    // Dica: delete[] ...
    delete[] time;

    // 6. SEGURANÇA
    // TODO: Zere o ponteiro (nullptr)
    time = nullptr;

    cout << "\nMemoria limpa. Boa viagem, treinador!" << endl;

    return 0;
}