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

struct LevelStats
{
    string nome;
    int total = 0, feitos = 0;
};

struct TemaStats
{
    int totalTema = 0, feitosTema = 0;
    vector<LevelStats> niveis;
    set<string> competencias; // Competências específicas deste tema
};

int main()
{
    SetConsoleOutputCP(65001);
    map<string, TemaStats> dashboard;
    int xpGlobal = 0;

    // Varredura
    for (const auto &entryTema : fs::directory_iterator("."))
    {
        if (entryTema.is_directory())
        {
            string nomeTema = entryTema.path().filename().string();
            if (nomeTema[0] == '.' || nomeTema == "progresso")
                continue;

            TemaStats tStats;
            for (const auto &entryLevel : fs::directory_iterator(entryTema.path()))
            {
                if (entryLevel.is_directory())
                {
                    LevelStats lStats;
                    lStats.nome = entryLevel.path().filename().string();
                    for (const auto &arq : fs::directory_iterator(entryLevel.path()))
                    {
                        if (arq.path().extension() == ".cpp")
                        {
                            lStats.total++;
                            ifstream f(arq.path());
                            string linha;
                            bool done = false, lendoComp = false;
                            while (getline(f, linha))
                            {
                                string up = linha;
                                transform(up.begin(), up.end(), up.begin(), ::toupper);
                                if (up.find("STATUS: DONE") != string::npos)
                                    done = true;
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
                                        tStats.competencias.insert(c);
                                }
                            }
                            if (done)
                            {
                                lStats.feitos++;
                                xpGlobal++;
                            }
                        }
                    }
                    tStats.niveis.push_back(lStats);
                    tStats.totalTema += lStats.total;
                    tStats.feitosTema += lStats.feitos;
                }
            }
            dashboard[nomeTema] = tStats;
        }
    }

    // 1. README GLOBAL (Agrupado por Tema)
    ofstream global("README.md");
    global << "# 🚀 CENTRAL DE COMANDO C++\n\n### 👑 XP TOTAL: " << xpGlobal << "\n\n";
    global << "## 📊 DASHBOARD DE TEMAS\n| Tema | Status | Rank |\n| :--- | :---: | :--- |\n";
    for (auto const &[nome, st] : dashboard)
    {
        float p = (st.totalTema > 0) ? (float)st.feitosTema / st.totalTema * 100 : 0;
        global << "| [" << nome << "](./" << nome << ") | " << st.feitosTema << "/" << st.totalTema << " | " << rankTema(p) << " |\n";
    }

    global << "\n## 🧬 ÁRVORE DE COMPETÊNCIAS (POR ASSUNTO)\n";
    for (auto const &[nome, st] : dashboard)
    {
        if (!st.competencias.empty())
        {
            global << "### 📂 " << nome << "\n";
            for (auto const &c : st.competencias)
                global << "- [x] " << c << "\n";
            global << "\n";
        }
    }
    global.close();

    // 2. README DO TEMA (Com Detalhes do Level)
    for (auto const &[nome, st] : dashboard)
    {
        ofstream fTema("./" + nome + "/README.md");
        fTema << "# 📂 Assunto: " << nome << "\n\n## 📈 Níveis\n| Level | Progresso | % |\n| :--- | :---: | :---: |\n";
        for (auto const &lv : st.niveis)
        {
            float p = (lv.total > 0) ? (float)lv.feitos / lv.total * 100 : 0;
            fTema << "| " << lv.nome << " | " << lv.feitos << "/" << lv.total << " | " << (int)p << "% |\n";
        }
        fTema << "\n## 🧬 Competências Adquiridas\n";
        for (auto const &c : st.competencias)
            fTema << "- ✅ " << c << "\n";
        fTema.close();
    }

    return 0;
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master