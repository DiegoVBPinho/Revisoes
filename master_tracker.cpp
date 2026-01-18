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

struct LevelData
{
    string nome;
    int total = 0, feitos = 0;
    vector<pair<string, bool>> exercicios;
    set<string> competenciasAdquiridas;
    set<string> competenciasPendentes;
};

struct TemaData
{
    int totalTema = 0, feitosTema = 0;
    vector<LevelData> niveis;
};

string trim(string s)
{
    size_t first = s.find_first_not_of(" \t\r\n");
    if (string::npos == first)
        return s;
    size_t last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, (last - first + 1));
}

string getRank(float p)
{
    if (p <= 0)
        return "DESEMPREGADO 😶";
    if (p < 30)
        return "ESTAGIÁRIO 📋";
    if (p < 60)
        return "JUNIOR 🛠️";
    if (p < 90)
        return "PLENO 🛡️";
    return "SENIOR 👑";
}

int main()
{
    SetConsoleOutputCP(65001);
    map<string, TemaData> dashboard;
    int xpTotal = 0;

    for (const auto &entryTema : fs::directory_iterator("."))
    {
        if (entryTema.is_directory())
        {
            string nomeTema = entryTema.path().filename().string();
            if (nomeTema[0] == '.' || nomeTema == "progresso" || nomeTema == "bin")
                continue;

            TemaData tData;
            for (const auto &entryLevel : fs::directory_iterator(entryTema.path()))
            {
                if (entryLevel.is_directory())
                {
                    LevelData lData;
                    lData.nome = entryLevel.path().filename().string();

                    for (const auto &arq : fs::directory_iterator(entryLevel.path()))
                    {
                        if (arq.path().extension() == ".cpp")
                        {
                            lData.total++;
                            ifstream f(arq.path());
                            string linha;
                            bool isDone = false, lendoComp = false;
                            set<string> compsDoArquivo;

                            while (getline(f, linha))
                            {
                                string up = linha;
                                transform(up.begin(), up.end(), up.begin(), ::toupper);
                                if (up.find("STATUS: DONE") != string::npos)
                                    isDone = true;
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
                                    c = trim(c);
                                    if (!c.empty() && c[0] != '=')
                                        compsDoArquivo.insert(c);
                                }
                            }
                            lData.exercicios.push_back({arq.path().filename().string(), isDone});
                            if (isDone)
                            {
                                lData.feitos++;
                                lData.competenciasAdquiridas.insert(compsDoArquivo.begin(), compsDoArquivo.end());
                            }
                            else
                            {
                                lData.competenciasPendentes.insert(compsDoArquivo.begin(), compsDoArquivo.end());
                            }
                        }
                    }
                    if (lData.total > 0)
                    {
                        tData.niveis.push_back(lData);
                        tData.totalTema += lData.total;
                        tData.feitosTema += lData.feitos;
                    }
                }
            }
            if (!tData.niveis.empty())
            {
                dashboard[nomeTema] = tData;
                xpTotal += (tData.feitosTema * 10);
            }
        }
    }

    // --- README GLOBAL ---
    ofstream fMain("README.md");
    fMain << "# 🚀 CENTRAL DE COMANDO C++\n\n### 👑 XP TOTAL: " << xpTotal << "\n\n## 📊 DASHBOARD DE TEMAS\n| Tema | Status | Rank |\n| :--- | :---: | :--- |\n";
    for (auto const &[nome, tData] : dashboard)
    {
        float p = (float)tData.feitosTema / tData.totalTema * 100;
        fMain << "| [" << nome << "](./" << nome << ") | " << tData.feitosTema << "/" << tData.totalTema << " | " << getRank(p) << " |\n";
    }
    fMain << "\n## 🧬 ÁRVORE DE COMPETÊNCIAS (CONSOLIDADO)\n";
    for (auto const &[nome, tData] : dashboard)
    {
        fMain << "### 📂 " << nome << "\n";
        set<string> tAdq, tPend;
        for (auto const &lv : tData.niveis)
        {
            tAdq.insert(lv.competenciasAdquiridas.begin(), lv.competenciasAdquiridas.end());
            tPend.insert(lv.competenciasPendentes.begin(), lv.competenciasPendentes.end());
        }
        for (auto const &c : tAdq)
            fMain << "- [x] ✅ **" << c << "**\n";
        for (auto const &c : tPend)
            if (tAdq.find(c) == tAdq.end())
                fMain << "- [ ] ⏳ " << c << "\n";
    }
    fMain.close();

    // --- READMES DE TEMA E LEVEL ---
    for (auto const &[nomeTema, tData] : dashboard)
    {
        ofstream fTema("./" + nomeTema + "/README.md");
        fTema << "# 📂 Assunto: " << nomeTema << "\n\n## 📈 Níveis\n| Level | Progresso | % |\n| :--- | :---: | :---: |\n";
        set<string> tAdq, tPend;
        for (auto const &lv : tData.niveis)
        {
            fTema << "| [" << lv.nome << "](./" << lv.nome << ") | " << lv.feitos << "/" << lv.total << " | " << (int)((float)lv.feitos / lv.total * 100) << "% |\n";
            tAdq.insert(lv.competenciasAdquiridas.begin(), lv.competenciasAdquiridas.end());
            tPend.insert(lv.competenciasPendentes.begin(), lv.competenciasPendentes.end());
        }
        fTema << "\n## 🧬 Clusters de Domínio\n";
        for (auto const &c : tAdq)
            fTema << "- ✅ **" << c << "** (Concluído)\n";
        for (auto const &c : tPend)
            if (tAdq.find(c) == tAdq.end())
                fTema << "- 💡 " << c << " (Pendente)\n";
        fTema.close();

        for (auto const &lv : tData.niveis)
        {
            ofstream fLv("./" + nomeTema + "/" + lv.nome + "/README.md");
            fLv << "# 🎯 FOCO: " << lv.nome << "\n\n### 📊 STATUS: " << lv.feitos << "/" << lv.total << "\n---\n";
            fLv << "### 📝 Exercícios\n| Status | Arquivo |\n| :---: | :--- |\n";
            for (auto const &ex : lv.exercicios)
                fLv << "| " << (ex.second ? "✅" : "🔨") << " | " << ex.first << " |\n";
            fLv << "\n### 🧬 Competências do Nível\n";
            for (auto const &c : lv.competenciasAdquiridas)
                fLv << "- ✅ " << c << "\n";
            for (auto const &c : lv.competenciasPendentes)
                if (lv.competenciasAdquiridas.find(c) == lv.competenciasAdquiridas.end())
                    fLv << "- ⏳ " << c << "\n";
            fLv.close();
        }
    }
    cout << "Clusters aplicados em todos os READMES!" << endl;
    return 0;
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master