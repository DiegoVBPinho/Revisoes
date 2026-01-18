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

int main()
{
    SetConsoleOutputCP(65001);
    map<string, TemaData> dashboard;

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
                            bool isDone = false;
                            bool lendoComp = false;
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
                                {
                                    lendoComp = false;
                                }

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
                dashboard[nomeTema] = tData;
        }
    }

    for (auto const &[nomeTema, tData] : dashboard)
    {
        string pathTema = "./" + nomeTema + "/README.md";
        ofstream fTema(pathTema);

        fTema << "# 📂 Assunto: " << nomeTema << "\n\n";
        fTema << "## 📈 Níveis\n| Level | Progresso | % |\n| :--- | :---: | :---: |\n";

        set<string> totalAdquiridas, totalPendentes;
        for (auto const &lv : tData.niveis)
        {
            float pLv = (float)lv.feitos / lv.total * 100;
            fTema << "| [" << lv.nome << "](./" << lv.nome << ") | " << lv.feitos << "/" << lv.total << " | " << (int)pLv << "% |\n";
            totalAdquiridas.insert(lv.competenciasAdquiridas.begin(), lv.competenciasAdquiridas.end());
            totalPendentes.insert(lv.competenciasPendentes.begin(), lv.competenciasPendentes.end());
        }

        fTema << "\n## 🧬 Competências Adquiridas\n";
        if (totalAdquiridas.empty())
        {
            fTema << "> Nenhuma competência dominada ainda.\n";
        }
        else
        {
            for (auto const &c : totalAdquiridas)
                fTema << "- ✅ " << c << "\n";
        }

        fTema << "\n## ⏳ Competências em Desenvolvimento\n";
        bool temPendente = false;
        for (auto const &c : totalPendentes)
        {
            if (totalAdquiridas.find(c) == totalAdquiridas.end())
            {
                fTema << "- 💡 " << c << "\n";
                temPendente = true;
            }
        }
        if (!temPendente && !totalAdquiridas.empty())
            fTema << "> Todas as competências atuais foram concluídas!\n";
        fTema.close();

        for (auto const &lv : tData.niveis)
        {
            string pathLv = "./" + nomeTema + "/" + lv.nome + "/README.md";
            ofstream fLv(pathLv);
            float pLv = (float)lv.feitos / lv.total * 100;
            fLv << "# 🎯 FOCO NO NÍVEL: " << lv.nome << "\n\n";
            fLv << "### 📊 PROGRESSO DO NÍVEL: " << lv.feitos << "/" << lv.total << " (" << fixed << setprecision(1) << pLv << "%)\n---\n\n";
            fLv << "### 📝 Exercícios\n| Status | Exercício |\n| :---: | :--- |\n";
            for (auto const &ex : lv.exercicios)
                fLv << "| " << (ex.second ? "✅" : "🔨") << " | " << ex.first << " |\n";
            fLv << "\n---\n### 🧬 Árvore de Competências do Nível\n";
            for (auto const &c : lv.competenciasAdquiridas)
                fLv << "- ✅ " << c << " (Concluída)\n";
            for (auto const &c : lv.competenciasPendentes)
            {
                if (lv.competenciasAdquiridas.find(c) == lv.competenciasAdquiridas.end())
                    fLv << "- ⏳ " << c << " (Pendente)\n";
            }
            fLv.close();
        }
    }

    cout << "Dashboard atualizado com sucesso!" << endl;
    return 0;
}

// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master