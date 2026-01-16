#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

struct ItemLab
{
    std::string pasta;
    std::string arquivo;
};

int main()
{
    std::vector<ItemLab> roteiro = {
        // Level 01 - Intro
        {"Level 01 - Introducao_a_POO", "01 - Classe.cpp"},
        {"Level 01 - Introducao_a_POO", "02 - Atributos.cpp"},
        {"Level 01 - Introducao_a_POO", "03 - Metodos.cpp"},
        {"Level 01 - Introducao_a_POO", "04 - Objetos.cpp"},
        {"Level 01 - Introducao_a_POO", "Exercicio - Zoologico.cpp"},

        // Level 02 - Arrays
        {"Level 02 - Estrutura_de_Dados", "01 - Arrays_Primitivos.cpp"},
        {"Level 02 - Estrutura_de_Dados", "02 - Arrays_Objetos.cpp"},
        {"Level 02 - Estrutura_de_Dados", "Exercicio - Gestao_Escolar.cpp"},

        // Level 03 - Pacotes
        {"Level 03 - Pacotes_e_Organizacao", "01 - Pacotes.cpp"},
        {"Level 03 - Pacotes_e_Organizacao", "02 - Importacoes.cpp"},

        // Level 04 - Acesso
        {"Level 04 - Encapsulamento", "01 - Modificadores_Acesso.cpp"},
        {"Level 04 - Encapsulamento", "Exercicio - Conta_Bancaria.cpp"},

        // Level 05 - Ciclo de Vida
        {"Level 05 - Ciclo_de_Vida_e_Static", "01 - Construtores.cpp"},
        {"Level 05 - Ciclo_de_Vida_e_Static", "02 - Static.cpp"},
        {"Level 05 - Ciclo_de_Vida_e_Static", "Exercicio - Contador_Pecas.cpp"},

        // Level 06 - Herança
        {"Level 06 - Heranca_e_Polimorfismo", "01 - Heranca.cpp"},
        {"Level 06 - Heranca_e_Polimorfismo", "02 - Polimorfismo.cpp"},
        {"Level 06 - Heranca_e_Polimorfismo", "Exercicio - Sistema_RH.cpp"},

        // Level 07 - Abstração
        {"Level 07 - Abstracao_e_Interfaces", "01 - Classes_Abstratas.cpp"},
        {"Level 07 - Abstracao_e_Interfaces", "02 - Interfaces.cpp"},
        {"Level 07 - Abstracao_e_Interfaces", "Exercicio - Formas_Geometricas.cpp"},

        // Level 08 - Coleções
        {"Level 08 - Colecoes_Dinamicas", "01 - Listas.cpp"},
        {"Level 08 - Colecoes_Dinamicas", "02 - Maps.cpp"},
        {"Level 08 - Colecoes_Dinamicas", "Exercicio - Inventario.cpp"},

        // Level 09 - Erros
        {"Level 09 - Robustez_Excecoes", "01 - Try_Catch.cpp"},
        {"Level 09 - Robustez_Excecoes", "Exercicio - Calculadora_Segura.cpp"},

        // Level 10 - Persistência
        {"Level 10 - Persistencia_Arquivos", "01 - NIO.cpp"},
        {"Level 10 - Persistencia_Arquivos", "Exercicio - Log_Sistema.cpp"},

        // Level 11 - Threads
        {"Level 11 - Threads_e_Concorrencia", "01 - Threads.cpp"},
        {"Level 11 - Threads_e_Concorrencia", "Exercicio - MultiTasking.cpp"},

        // Level 12 - Engenharia
        {"Level 12 - Engenharia_e_Padroes", "01 - Maven.cpp"},
        {"Level 12 - Engenharia_e_Padroes", "02 - Git.cpp"},
        {"Level 12 - Engenharia_e_Padroes", "03 - Testes.cpp"},
        {"Level 12 - Engenharia_e_Padroes", "04 - Design_Patterns.cpp"}};

    std::cout << "--- 🏭 FABRICA: ESTRUTURA PROF. CHRIS ---" << std::endl;

    for (const auto &item : roteiro)
    {
        if (!fs::exists(item.pasta))
        {
            fs::create_directories(item.pasta);
        }
        std::string caminhoFinal = item.pasta + "/" + item.arquivo;
        if (!fs::exists(caminhoFinal))
        {
            std::ofstream arquivo(caminhoFinal);
            arquivo.close(); // Cria o arquivo totalmente em branco
            std::cout << "Criado: " << caminhoFinal << std::endl;
        }
    }

    std::cout << "\n✅ Roteiro completo do Level 01 ao 12 gerado com sucesso!" << std::endl;
    return 0;
}

// g++ fabrica.cpp -o fabrica.exe
//./fabrica.exe