#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <map>
#include <iomanip> // Para porcentagem bonita
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

string toUpper(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Verifica status DONE dentro do arquivo
bool checkDone(string path)
{
    ifstream f(path);
    if (!f.is_open())
        return false;
    string l;
    while (getline(f, l))
    {
        string u = toUpper(l);
        if (u.find("STATUS") != string::npos && u.find("DONE") != string::npos)
            return true;
    }
    return false;
}

struct LevelStats
{
    string nomePasta;
    int total = 0;
    int feitos = 0;
};

int main()
{
    SetConsoleOutputCP(65001); // UTF-8

    vector<LevelStats> niveis;
    int globalTotal = 0;
    int globalFeitos = 0;

    cout << "--- 🌍 GLOBAL TRACKER: INICIANDO ESCANEAMENTO ---" << endl;

    // 1. Escanear pastas que começam com "Level"
    for (const auto &entry : fs::directory_iterator("."))
    {
        if (entry.is_directory())
        {
            string nomePasta = entry.path().filename().string();

            // Filtro: Só olha pastas que tenham "Level" ou "Nivel" no nome
            // (Ou você pode tirar o if se quiser escanear TUDO)
            string nomeUpper = toUpper(nomePasta);
            if (nomeUpper.find("LEVEL") != string::npos || nomeUpper.find("NIVEL") != string::npos)
            {

                LevelStats stats;
                stats.nomePasta = nomePasta;

                // Entra na pasta e conta os .cpp
                for (const auto &subEntry : fs::directory_iterator(entry.path()))
                {
                    string subNome = subEntry.path().filename().string();
                    if (subNome.find(".cpp") != string::npos && isdigit(subNome[0]))
                    {
                        stats.total++;
                        if (checkDone(subEntry.path().string()))
                        {
                            stats.feitos++;
                        }
                    }
                }

                if (stats.total > 0)
                {
                    niveis.push_back(stats);
                    globalTotal += stats.total;
                    globalFeitos += stats.feitos;
                    cout << "   📁 " << nomePasta << ": " << stats.feitos << "/" << stats.total << endl;
                }
            }
        }
    }

    // Ordenar pastas por nome (Level 1, Level 2...)
    sort(niveis.begin(), niveis.end(), [](const LevelStats &a, const LevelStats &b)
         { return a.nomePasta < b.nomePasta; });

    // 2. Gerar README.md GLOBAL
    ofstream readme("README.md");
    readme << "# 📊 PAINEL DE CONTROLE GLOBAL: PONTEIROS" << endl
           << endl;

    // Barra de progresso global
    double porcGlobal = (globalTotal > 0) ? (double)globalFeitos / globalTotal * 100.0 : 0.0;
    readme << "## 🏆 PROGRESSO TOTAL: " << globalFeitos << "/" << globalTotal << " (" << fixed << setprecision(1) << porcGlobal << "%)" << endl;

    // Barrinha visual ASCII
    readme << "`[";
    int barras = (int)(porcGlobal / 5); // Cada barra = 5%
    for (int i = 0; i < 20; i++)
        readme << (i < barras ? "█" : "░");
    readme << "]`" << endl
           << endl;

    readme << "---" << endl
           << endl;

    // Tabela detalhada
    readme << "## 📂 Detalhes por Nível" << endl
           << endl;
    readme << "| Nível | Progresso | % | Status |" << endl;
    readme << "| :--- | :---: | :---: | :---: |" << endl;

    for (const auto &nv : niveis)
    {
        double porc = (double)nv.feitos / nv.total * 100.0;
        string statusIcon = (porc == 100.0) ? "🥇 Completo" : (porc > 50.0 ? "🔥 Em Andamento" : "💤 Início");

        readme << "| **" << nv.nomePasta << "** | " << nv.feitos << "/" << nv.total << " | " << (int)porc << "% | " << statusIcon << " |" << endl;
    }

    readme << endl
           << "---" << endl;
    readme << "*Atualizado automaticamente pelo Global Tracker.*" << endl;
    readme.close();

    cout << "\n✅ RELATÓRIO GLOBAL ATUALIZADO COM SUCESSO!" << endl;
    return 0;
}