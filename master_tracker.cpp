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

int main()
{
    SetConsoleOutputCP(65001);
    map<string, TemaData> dashboard;

    for (const auto &entryTema : fs::directory_iterator("."))
    {
        if (entryTema.is_directory())
        {
            string nomeTema = entryTema.path().filename().string();
            if (nomeTema[0] == '.' || nomeTema == "progresso")
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
                            bool done = false, lendoComp = false;
                            set<string> compsDoArquivo;

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
                                        compsDoArquivo.insert(c);
                                }
                            }
                            lData.exercicios.push_back({arq.path().filename().string(), done});
                            if (done)
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
                        tData.feitosTema += lData.feitos; // Erro corrigido aqui: era lStats
                    }
                }
            }
            if (!tData.niveis.empty())
                dashboard[nomeTema] = tData;
        }
    }

    for (auto const &[nomeTema, tData] : dashboard)
    {
        for (auto const &lv : tData.niveis)
        {
            string pathLv = "./" + nomeTema + "/" + lv.nome + "/README.md";
            ofstream fLv(pathLv);
            float p = (lv.total > 0) ? (float)lv.feitos / lv.total * 100 : 0;

            fLv << "# 🎯 FOCO NO NÍVEL: " << lv.nome << "\n\n";
            fLv << "### 📊 PROGRESSO DO NÍVEL: " << lv.feitos << "/" << lv.total << " (" << fixed << setprecision(1) << p << "%)\n---\n\n";

            fLv << "### 📝 Exercícios\n| Status | Exercício |\n| :---: | :--- |\n";
            for (auto const &ex : lv.exercicios)
                fLv << "| " << (ex.second ? "✅" : "🔨") << " | " << ex.first << " |\n";

            fLv << "\n---\n### 🧬 Árvore de Competências do Nível\n";
            // Mostra o que já foi conquistado
            for (auto const &c : lv.competenciasAdquiridas)
                fLv << "- ✅ " << c << " (Concluída)\n";
            // Mostra o que falta, mas remove da lista de pendentes o que já foi adquirido em outro arquivo
            for (auto const &c : lv.competenciasPendentes)
            {
                if (lv.competenciasAdquiridas.find(c) == lv.competenciasAdquiridas.end())
                    fLv << "- ⏳ " << c << " (Pendente)\n";
            }
            fLv.close();
        }
    }

    cout << "✨ Master Tracker compilado e executado com sucesso!" << endl;
    return 0;
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master