#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

struct Exercicio
{
    std::string level;
    std::string arquivo;
    std::string comps;
    std::string objetivo;
};

void criarEstrutura(const Exercicio &ex)
{
    // Cria a pasta do Level (ex: Level 01 - Introducao_a_POO)
    if (!fs::exists(ex.level))
    {
        fs::create_directory(ex.level);
    }

    std::string caminho = ex.level + "/" + ex.arquivo;
    if (fs::exists(caminho))
        return;

    std::ofstream f(caminho);
    f << "/*\n"
      << "==================================================\n"
      << "📘 " << ex.level << "\n"
      << "==================================================\n\n"
      << "STATUS: TO DO\n\n"
      << "COMPETENCIAS:\n"
      << ex.comps << "\n"
      << "🎯 OBJETIVO:\n"
      << ex.objetivo << "\n"
      << "--------------------------------------------------\n"
      << "*/\n\n"
      << "#include <iostream>\n"
      << "#include <string>\n\n"
      << "int main() {\n"
      << "    // Pratique aqui os conceitos da " << ex.level << "\n"
      << "    return 0;\n"
      << "}\n";
    f.close();
}

int main()
{
    std::vector<Exercicio> roteiro = {
        // LEVEL 01 - INTRODUÇÃO
        {"Level 01 - Introducao_a_POO", "Ex 1 - Classe.cpp", "- CLASSES", "Definir o molde (projeto) de um objeto."},
        {"Level 01 - Introducao_a_POO", "Ex 2 - Atributos.cpp", "- ATRIBUTOS", "Definir as caracteristicas da classe."},
        {"Level 01 - Introducao_a_POO", "Ex 3 - Metodos.cpp", "- METODOS", "Definir os comportamentos da classe."},
        {"Level 01 - Introducao_a_POO", "Ex 4 - Objetos.cpp", "- OBJETOS", "Instanciar a classe na main."},
        {"Level 01 - Introducao_a_POO", "Ex 5 - Zoologico.cpp", "- POO_BASICA\n- INTEGRACAO", "Criar Zebra e Leao com correr() e comer()."},

        // LEVEL 02 - ESTRUTURA DE DADOS
        {"Level 02 - Estrutura_de_Dados", "Ex 1 - Arrays_Primitivos.cpp", "- ARRAYS", "Trabalhar com vetores de tipos simples."},
        {"Level 02 - Estrutura_de_Dados", "Ex 2 - Arrays_Objetos.cpp", "- ARRAYS_OBJETOS", "Criar um array que armazena objetos."},
        {"Level 02 - Estrutura_de_Dados", "Ex 3 - Gestao_Escolar.cpp", "- LOGICA_ARRAYS", "Sistema para armazenar notas de Alunos em array."},

        // LEVEL 04 - ENCAPSULAMENTO
        {"Level 04 - Encapsulamento", "Ex 1 - Modificadores.cpp", "- PUBLIC_PRIVATE", "Testar visibilidade de membros."},
        {"Level 04 - Encapsulamento", "Ex 2 - Conta_Bancaria.cpp", "- ENCAPSULAMENTO", "Proteger saldo e usar metodos de acesso."}};

    std::cout << "--- 🏭 FABRICA: GERANDO CURRICULO PROF. CHRIS ---" << std::endl;

    for (const auto &ex : roteiro)
    {
        criarEstrutura(ex);
        std::cout << "✔ Gerado: " << ex.level << " -> " << ex.arquivo << std::endl;
    }

    std::cout << "\n✅ Estrutura criada! Agora seu projeto reflete os slides do professor." << std::endl;
    return 0;
}