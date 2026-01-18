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
    int total = 0;
    int feitos = 0;
};

struct TemaStats
{
    int totalTema = 0;
    int feitosTema = 0;
    vector<LevelStats> niveis;
    set<string> competencias;
};

int main()
{
    SetConsoleOutputCP(65001);
    map<string, TemaStats> dashboard;

    // Varre os Temas (ex: 01 - POO)
    for (const auto &entryTema : fs::directory_iterator("."))
    {
        if (entryTema.is_directory())
        {
            string nomeTema = entryTema.path().filename().string();
            if (nomeTema[0] == '.' || nomeTema == "progresso")
                continue;

            TemaStats tStats;

            // Varre os Levels dentro do Tema
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
            dashboard[nomeTema] = tStats;
        }
    }

    // GERAÇÃO DO README DENTRO DE CADA TEMA (Ex: 01 - POO)
    for (auto const &[nome, st] : dashboard)
    {
        float porcTema = (st.totalTema > 0) ? (float)st.feitosTema / st.totalTema * 100.0f : 0.0f;

        ofstream fTema("./" + nome + "/README.md");
        fTema << "# 📂 Assunto: " << nome << "\n\n";
        fTema << "### 🏅 Rank no Tema: " << rankTema(porcTema) << " (" << fixed << setprecision(1) << porcTema << "%)\n\n";

        fTema << "## 📈 Progresso por Level\n";
        fTema << "| Level | Exercícios | Status | % |\n";
        fTema << "| :--- | :---: | :--- | :---: |\n";

        for (auto const &lv : st.niveis)
        {
            float porcLv = (lv.total > 0) ? (float)lv.feitos / lv.total * 100.0f : 0.0f;
            int barras = (int)(porcLv / 10);
            string progress = "";
            for (int i = 0; i < 10; i++)
                progress += (i < barras ? "█" : "░");

            fTema << "| " << lv.nome << " | " << lv.feitos << "/" << lv.total << " | `" << progress << "` | " << (int)porcLv << "% |\n";
        }

        fTema << "\n## 🧬 Competências do Tema\n";
        for (auto const &c : st.competencias)
            fTema << "- ✅ " << c << "\n";

        fTema.close();
    }

    cout << "✨ Dashboard de Níveis gerado dentro das pastas de Tema!" << endl;
    return 0;
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master