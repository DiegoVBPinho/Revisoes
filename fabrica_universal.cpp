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
    string titulo;
    string dificuldade;
    string competencias;
    string objetivo;
};

struct Trilha
{
    string nomePasta;
    vector<Exercicio> exercicios;
};

void gerarCabecalho(string path, string categoria, Exercicio ex)
{
    ofstream arq(path);
    arq << "/*" << endl;
    arq << "==================================================" << endl;
    arq << "📘 " << categoria << " - EXERCICIO " << ex.id << ": " << ex.titulo << endl;
    arq << "DIFICULDADE: " << ex.dificuldade << endl;
    arq << "==================================================" << endl
        << endl;
    arq << "STATUS: TO DO" << endl
        << endl;
    arq << "COMPETENCIAS:" << endl;
    arq << "- " << ex.competencias << endl
        << endl;
    arq << "🎯 OBJETIVO DO EXERCICIO:" << endl;
    arq << ex.objetivo << endl
        << endl;
    arq << "--------------------------------------------------" << endl;
    arq << "*/" << endl
        << endl;

    arq << "#include <iostream>" << endl;
    arq << "using namespace std;" << endl
        << endl;
    arq << "int main() {" << endl;
    arq << "    // TODO: Implemente sua solução aqui" << endl;
    arq << "    " << endl;
    arq << "    return 0;" << endl;
    arq << "}" << endl;
    arq.close();
}

int main()
{
    SetConsoleOutputCP(65001);

    // Árvore de evolução baseada no material do Prof. Chris
    vector<Trilha> mapaDeEstudos = {
        {"01 - Introducao", {{"01", "Classe Vazia", "Fácil", "ABSTRACAO", "Crie uma classe 'Celular' sem atributos ainda."}, {"02", "Atributos Basicos", "Fácil", "MODELAGEM", "Adicione 'marca' e 'modelo' à classe Celular."}}},
        {"02 - Metodos", {{"01", "Metodo Ligar", "Médio", "METODOS", "Crie um método que exiba 'O celular está iniciando...'"}}}};

    cout << "🛠️  INICIANDO CONSTRUÇÃO DA FÁBRICA..." << endl;

    for (const auto &trilha : mapaDeEstudos)
    {
        if (!fs::exists(trilha.nomePasta))
            fs::create_directory(trilha.nomePasta);

        for (const auto &ex : trilha.exercicios)
        {
            string nomeArquivo = ex.id + " - " + ex.titulo + ".cpp";
            string caminhoCompleto = trilha.nomePasta + "/" + nomeArquivo;

            if (!fs::exists(caminhoCompleto))
            {
                gerarCabecalho(caminhoCompleto, trilha.nomePasta, ex);
                cout << "   ✅ Criado: " << caminhoCompleto << endl;
            }
        }
    }

    cout << "\n🌟 TUDO PRONTO! Agora é só codar e rodar o g++ -std=c++17 fabrica.cpp -o fabrica.exe e também o ./fabrica.exe" << endl;

    return 0;
}

/*
================================================================================
❗ LEMBRETE DE OPERAÇÃO NO VS CODE:
================================================================================
1. Toda vez que adicionar novos exercícios no 'vector<Trilha>', salve o arquivo.
2. No terminal do VS Code (PowerShell), compile com:
   g++ -std=c++17 fabrica_universal.cpp -o fabrica.exe

3. Execute a fábrica para gerar as novas pastas e arquivos:
   .\fabrica_universal.exe

4. Após codar os exercícios, troque 'STATUS: TO DO' para 'STATUS: DONE'.
5. Por fim, rode .\atualizar_tudo.bat para subir tudo pro GitHub.
================================================================================
*/