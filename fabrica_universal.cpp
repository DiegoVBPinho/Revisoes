#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

struct Exercicio
{
    string id;
    string nome;
};

struct Level
{
    string pasta;
    string titulo;
    vector<Exercicio> exercicios;
};

int main()
{
    SetConsoleOutputCP(65001);

    string pastaTema = "02 - POO";
    if (!fs::exists(pastaTema))
        fs::create_directory(pastaTema);

    vector<Level> niveis = {
        {"Level 1 - Classes",
         "LEVEL 1 - CLASSES",
         {
             {"01", "Classe Basica"},
             {"02", "Objeto"},
             {"03", "Metodo Simples"},
             {"04", "Atributos"},
             {"05", "Construtor"},
         }},
        {"Level 2 - Encapsulamento",
         "LEVEL 2 - ENCAPSULAMENTO",
         {
             {"01", "Public vs Private"},
             {"02", "Getters"},
             {"03", "Setters"},
             {"04", "Validacao"},
             {"05", "Estado Seguro"},
         }},
        {"Level 3 - Heranca",
         "LEVEL 3 - HERANCA",
         {
             {"01", "Classe Base"},
             {"02", "Classe Derivada"},
             {"03", "Reaproveitamento"},
             {"04", "Override Simples"},
             {"05", "Hierarquia"},
         }},
        {"Level 4 - Polimorfismo",
         "LEVEL 4 - POLIMORFISMO",
         {
             {"01", "Metodo Virtual"},
             {"02", "Override"},
             {"03", "Ponteiro Base"},
             {"04", "Chamada Dinamica"},
             {"05", "Comportamento Diferente"},
         }},
        {"Level 5 - Integracao",
         "LEVEL 5 - INTEGRACAO",
         {
             {"01", "Sistema Simples"},
             {"02", "Entidades"},
             {"03", "Interacao"},
             {"04", "Organizacao"},
             {"05", "Desafio Final"},
         }},
        {"Level 6 - Exercicios PPT - XYZ",
         "LEVEL 6 - EXERCICIOS PPT - XYZ",
         {
             {"01", "Exercicio 01"},
             {"02", "Exercicio 02"},
             {"03", "Exercicio 03"},
             {"04", "Exercicio 04"},
             {"05", "Exercicio 05"},
         }}};

    for (auto &nivel : niveis)
    {
        string pathLevel = pastaTema + "/" + nivel.pasta;
        if (!fs::exists(pathLevel))
            fs::create_directory(pathLevel);

        // Cria arquivos CPP VAZIOS
        for (auto &ex : nivel.exercicios)
        {
            string nomeArquivo = ex.id + " - " + ex.nome + ".cpp";
            ofstream arq(pathLevel + "/" + nomeArquivo);
            arq.close();
        }

        // Cria README.md VAZIO
        ofstream readme(pathLevel + "/README.md");
        readme.close();
    }

    cout << "\n✅ PROCESSO CONCLUIDO!" << endl;
    cout << "🤖 Estrutura de POO criada com sucesso." << endl;
    cout << "👉 Execute 'atualizar_tudo.bat' para sincronizar o progresso." << endl;

    return 0;
}
