#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <iomanip>

using namespace std;
namespace fs = std::filesystem;

// Função para converter para maiúsculo
string paraMaiusculo(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Verifica se o arquivo tem a marcação STATUS: DONE
bool estaConcluido(string caminho)
{
    ifstream arquivo(caminho);
    if (!arquivo.is_open())
        return false;
    string linha;
    while (getline(arquivo, linha))
    {
        string u = paraMaiusculo(linha);
        if (u.find("STATUS") != string::npos && u.find("DONE") != string::npos)
            return true;
    }
    return false;
}

int main()
{
    // 1. Coleta informações da pasta atual
    string nomeLevel = fs::current_path().filename().string();
    vector<pair<string, bool>> exercicios;
    int total = 0, feitos = 0;

    for (const auto &entry : fs::directory_iterator("."))
    {
        string fName = entry.path().filename().string();
        // Filtra apenas arquivos .cpp que começam com números
        if (fName.find(".cpp") != string::npos && isdigit(fName[0]))
        {
            bool concluido = estaConcluido(entry.path().string());
            exercicios.push_back({fName, concluido});
            total++;
            if (concluido)
                feitos++;
        }
    }

    // Ordenar por nome/número
    sort(exercicios.begin(), exercicios.end());

    // 2. Gerar o README.md bonitão
    double porcentagem = (total > 0) ? (double)feitos / total * 100.0 : 0.0;

    ofstream readme("README.md");
    readme << "# 🎯 FOCO NO NÍVEL: " << nomeLevel << endl
           << endl;

    readme << "### 📊 PROGRESSO DO NÍVEL: " << feitos << "/" << total
           << " (" << fixed << setprecision(1) << porcentagem << "%)" << endl;

    // Barra de progresso visual
    readme << "`[";
    int barras = (int)(porcentagem / 5);
    for (int i = 0; i < 20; i++)
        readme << (i < barras ? "█" : "░");
    readme << "]`" << endl
           << endl;

    readme << "---" << endl
           << endl;
    readme << "| Status | Ícone | Exercício |" << endl;
    readme << "| :---: | :---: | :--- |" << endl;

    for (const auto &ex : exercicios)
    {
        string check = ex.second ? "[x]" : "[ ]";
        string icon = ex.second ? "✅" : "🔨";
        readme << "| " << check << " | " << icon << " | " << ex.first << " |" << endl;
    }

    readme << endl
           << "---" << endl;
    readme << "*Gerado por Tracker Local (C++ Auto-Update)*" << endl;
    readme.close();

    cout << "✅ README do Level [" << nomeLevel << "] atualizado com sucesso!" << endl;
    return 0;
}