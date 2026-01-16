#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <iomanip>

using namespace std;
namespace fs = std::filesystem;

// Verifica se o arquivo contém a marcação de conclusão
bool verificarDone(string path)
{
    ifstream f(path);
    if (!f.is_open())
        return false;
    string linha;
    while (getline(f, linha))
    {
        transform(linha.begin(), linha.end(), linha.begin(), ::toupper);
        if (linha.find("STATUS: DONE") != string::npos)
            return true;
    }
    return false;
}

int main()
{
    string nomeLevel = fs::current_path().filename().string();
    vector<pair<string, bool>> exercicios;
    int total = 0, feitos = 0;

    // Busca apenas arquivos .cpp que começam com números (ex: 01 - ...)
    for (const auto &entry : fs::directory_iterator("."))
    {
        string fName = entry.path().filename().string();
        if (entry.path().extension() == ".cpp" && isdigit(fName[0]))
        {
            bool status = verificarDone(entry.path().string());
            exercicios.push_back({fName, status});
            total++;
            if (status)
                feitos++;
        }
    }

    sort(exercicios.begin(), exercicios.end());

    // Gerando o README.md Local bonitão
    ofstream readme("README.md");
    double porc = (total > 0) ? (double)feitos / total * 100.0 : 0.0;

    readme << "# 🎯 FOCO NO NÍVEL: " << nomeLevel << endl
           << endl;
    readme << "### 📊 PROGRESSO DO NÍVEL: " << feitos << "/" << total << " (" << fixed << setprecision(1) << porc << "%)" << endl;

    // Barra de progresso visual
    readme << "`[";
    int barras = (int)(porc / 5);
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

    cout << "✅ README local atualizado em: " << nomeLevel << endl;
    return 0;
}