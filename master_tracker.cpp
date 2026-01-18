#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <map>
#include <set>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

// Ranks Gerais e por Tema
string rankGeral(int xp)
{
    if (xp <= 20)
        return "ESTAGIÁRIO NOOB 👶";
    if (xp <= 40)
        return "JUNIOR EM EVOLUÇÃO 🛠️";
    if (xp <= 70)
        return "PLENO RESPEITADO 🛡️";
    if (xp <= 90)
        return "SENIOR DO QUARTEL ⚔️";
    return "C++ EXPERT 👑";
}

string rankEspecialidade(int xp)
{
    if (xp <= 5)
        return "INICIANTE 🧪";
    if (xp <= 15)
        return "PRATICANTE 🔧";
    if (xp <= 30)
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
    set<string> competencias;
};

int main()
{
    SetConsoleOutputCP(65001);
    map<string, TemaStats> mapaTemas;
    int grandTotal = 0, grandFeitos = 0;

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
                                lStats.feitos++;
                        }
                    }
                    tStats.niveis.push_back(lStats);
                    tStats.totalTema += lStats.total;
                    tStats.feitosTema += lStats.feitos;
                }
            }
            mapaTemas[nomeTema] = tStats;
            grandTotal += tStats.totalTema;
            grandFeitos += tStats.feitosTema;
        }
    }

    // 1. DASHBOARD GLOBAL (PERFIL)
    ofstream global("README.md");
    global << "# 🚀 DASHBOARD DE EVOLUÇÃO C++\n\n";
    global << "### 👑 RANK GLOBAL: " << rankGeral(grandFeitos) << "\n";
    global << "🏆 **XP TOTAL:** " << grandFeitos << " / " << grandTotal << " concluídos\n\n";
    global << "## 📊 STATUS POR TEMA\n";
    global << "| Tema | Especialidade | Concluídos | Progresso |\n";
    global << "| :--- | :--- | :---: | :--- |\n";
    for (auto const &[nome, st] : mapaTemas)
    {
        int barras = (st.totalTema > 0) ? (st.feitosTema * 10 / st.totalTema) : 0;
        string progress = "";
        for (int i = 0; i < 10; i++)
            progress += (i < barras ? "█" : "░");
        global << "| [" << nome << "](./" << nome << ") | " << rankEspecialidade(st.feitosTema) << " | " << st.feitosTema << "/" << st.totalTema << " | `" << progress << "` |\n";
    }
    global.close();

    // 2. README POR TEMA (DETALHADO)
    for (auto const &[nome, st] : mapaTemas)
    {
        ofstream fTema("./" + nome + "/README.md");
        fTema << "# 📂 Especialidade: " << nome << "\n";
        fTema << "### 🏅 Rank no Tema: " << rankEspecialidade(st.feitosTema) << "\n\n";
        fTema << "## 📍 Detalhes por Nível\n| Nível | Status |\n| :--- | :---: |\n";
        for (auto const &lv : st.niveis)
            fTema << "| " << lv.nome << " | " << lv.feitos << "/" << lv.total << " |\n";
        fTema << "\n## 🧬 Competências Desbloqueadas\n";
        for (auto const &c : st.competencias)
            fTema << "- ✅ " << c << "\n";
        fTema.close();
    }
    return 0;
}
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master