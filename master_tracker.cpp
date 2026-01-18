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

    // 1. VARREDURA COMPLETA
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
                xpTotal += (tData.feitosTema * 10); // Cada exercício DONE vale 10 XP
            }
        }
    }

    // 2. GERAÇÃO DO README PRINCIPAL (RAIZ)
    ofstream fMain("README.md");
    fMain << "# 🚀 CENTRAL DE COMANDO C++\n\n";
    fMain << "### 👑 XP TOTAL: " << xpTotal << "\n\n";
    fMain << "## 📊 DASHBOARD DE TEMAS\n";
    fMain << "| Tema | Status | Rank |\n| :--- | :---: | :--- |\n";

    for (auto const &[nome, tData] : dashboard)
    {
        float p = (float)tData.feitosTema / tData.totalTema * 100;
        fMain << "| [" << nome << "](./" << nome << ") | " << tData.feitosTema << "/" << tData.totalTema << " | " << getRank(p) << " |\n";
    }

    fMain << "\n## 🧬 ÁRVORE DE COMPETÊNCIAS (POR ASSUNTO)\n";
    for (auto const &[nome, tData] : dashboard)
    {
        fMain << "### 📂 " << nome << "\n";
        set<string> todasAdq, todasPend;
        for (auto const &lv : tData.niveis)
        {
            todasAdq.insert(lv.competenciasAdquiridas.begin(), lv.competenciasAdquiridas.end());
            todasPend.insert(lv.competenciasPendentes.begin(), lv.competenciasPendentes.end());
        }

        // Listar Dominadas
        for (auto const &c : todasAdq)
            fMain << "- [x] ✅ " << c << "\n";
        // Listar Pendentes (que não foram adquiridas em outro lugar)
        for (auto const &c : todasPend)
        {
            if (todasAdq.find(c) == todasAdq.end())
                fMain << "- [ ] 💡 " << c << "\n";
        }
        fMain << "\n";
    }
    fMain.close();

    // 3. GERAÇÃO DOS READMES DE TEMA E LEVEL (Mesma lógica do anterior)
    for (auto const &[nomeTema, tData] : dashboard)
    {
        string pathTema = "./" + nomeTema + "/README.md";
        ofstream fTema(pathTema);
        fTema << "# 📂 Assunto: " << nomeTema << "\n\n## 📈 Níveis\n| Level | Progresso | % |\n| :--- | :---: | :---: |\n";

        set<string> tAdq, tPend;
        for (auto const &lv : tData.niveis)
        {
            float p = (float)lv.feitos / lv.total * 100;
            fTema << "| [" << lv.nome << "](./" << lv.nome << ") | " << lv.feitos << "/" << lv.total << " | " << (int)p << "% |\n";
            tAdq.insert(lv.competenciasAdquiridas.begin(), lv.competenciasAdquiridas.end());
            tPend.insert(lv.competenciasPendentes.begin(), lv.competenciasPendentes.end());
        }

        fTema << "\n## 🧬 Competências Adquiridas\n";
        if (tAdq.empty())
            fTema << "> Nenhuma dominada ainda.\n";
        for (auto const &c : tAdq)
            fTema << "- ✅ " << c << "\n";

        fTema << "\n## ⏳ Em Desenvolvimento\n";
        for (auto const &c : tPend)
            if (tAdq.find(c) == tAdq.end())
                fTema << "- 💡 " << c << "\n";
        fTema.close();

        for (auto const &lv : tData.niveis)
        {
            string pathLv = "./" + nomeTema + "/" + lv.nome + "/README.md";
            ofstream fLv(pathLv);
            fLv << "# 🎯 FOCO NO NÍVEL: " << lv.nome << "\n\n### 📊 PROGRESSO: " << lv.feitos << "/" << lv.total << "\n---\n";
            fLv << "### 📝 Exercícios\n| Status | Exercício |\n| :---: | :--- |\n";
            for (auto const &ex : lv.exercicios)
                fLv << "| " << (ex.second ? "✅" : "🔨") << " | " << ex.first << " |\n";
            fLv << "\n### 🧬 Competências\n";
            for (auto const &c : lv.competenciasAdquiridas)
                fLv << "- ✅ " << c << "\n";
            for (auto const &c : lv.competenciasPendentes)
                if (lv.competenciasAdquiridas.find(c) == lv.competenciasAdquiridas.end())
                    fLv << "- ⏳ " << c << "\n";
            fLv.close();
        }
    }

    cout << "Central de Comando e Árvores de Competência atualizadas!" << endl;
    return 0;
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master