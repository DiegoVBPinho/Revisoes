#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

// Ranks de Especialidade por Tema
string rankTema(float porcentagem)
{
    if (porcentagem == 0)
        return "DESEMPREGADO 😶";
    if (porcentagem < 30)
        return "INICIANTE 🧪";
    if (porcentagem < 60)
        return "PRATICANTE 🔧";
    if (porcentagem < 90)
        return "ESPECIALISTA 🛡️";
    return "MESTRE DO TEMA 👑";
}

struct TemaStats
{
    int total = 0;
    int feitos = 0;
    set<string> competencias;
};

int main()
{
    SetConsoleOutputCP(65001);
    map<string, TemaStats> dashboard;
    int xpGlobal = 0;

    cout << "🔍 Escaneando Temas para o Dashboard..." << endl;

    // Varre as pastas raízes (01 - POO, 02 - Ponteiros...)
    for (const auto &entry : fs::directory_iterator("."))
    {
        if (entry.is_directory())
        {
            string nomeTema = entry.path().filename().string();
            // Pula pastas ocultas ou de controle
            if (nomeTema[0] == '.' || nomeTema == "progresso" || nomeTema == "bin")
                continue;

            TemaStats stats;
            // Entra em tudo que tem dentro do Tema (Levels e arquivos)
            for (const auto &subEntry : fs::recursive_directory_iterator(entry.path()))
            {
                if (subEntry.path().extension() == ".cpp")
                {
                    stats.total++;

                    ifstream arq(subEntry.path());
                    string linha;
                    bool feito = false, lendoComp = false;

                    while (getline(arq, linha))
                    {
                        string up = linha;
                        transform(up.begin(), up.end(), up.begin(), ::toupper);
                        if (up.find("STATUS: DONE") != string::npos)
                            feito = true;

                        if (up.find("COMPETENCIAS:") != string::npos)
                        {
                            lendoComp = true;
                            continue;
                        }
                        if (lendoComp && (up.find("---") != string::npos || up.find("*/") != string::npos || up.empty()))
                            lendoComp = false;

                        if (lendoComp)
                        {
                            string c = linha;
                            if (c.find("- ") != string::npos)
                                c = c.substr(c.find("- ") + 2);
                            c.erase(0, c.find_first_not_of(" \t"));
                            c.erase(c.find_last_not_of(" \t") + 1);
                            if (!c.empty() && c[0] != '=')
                                stats.competencias.insert(c);
                        }
                    }
                    if (feito)
                    {
                        stats.feitos++;
                        xpGlobal++;
                    }
                }
            }
            if (stats.total > 0)
                dashboard[nomeTema] = stats;
        }
    }

    // --- GERAÇÃO DO README.md (RAIZ) ---
    ofstream global("README.md");
    global << "# 🚀 CENTRAL DE COMANDO\n\n";
    global << "### 👑 RANK GLOBAL: " << (xpGlobal <= 20 ? "ESTAGIÁRIO" : "EM EVOLUÇÃO") << " (XP: " << xpGlobal << ")\n\n";

    global << "## 📊 STATUS POR TEMA\n";
    global << "| Pasta do Tema | Progresso | % | Rank do Assunto |\n";
    global << "| :--- | :---: | :---: | :--- |\n";

    for (auto const &[nome, st] : dashboard)
    {
        float porc = (float)st.feitos / st.total * 100.0f;
        global << "| [" << nome << "](./" << nome << ") | " << st.feitos << "/" << st.total
               << " | " << fixed << setprecision(0) << porc << "% | " << rankTema(porc) << " |\n";
    }

    global << "\n## 🧬 TODAS AS COMPETÊNCIAS\n";
    set<string> todas;
    for (auto const &[n, st] : dashboard)
        todas.insert(st.competencias.begin(), st.competencias.end());
    for (auto const &c : todas)
        global << "- [x] " << c << "\n";

    global.close();
    cout << "✨ Dashboard Principal Atualizado!" << endl;
    return 0;
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master