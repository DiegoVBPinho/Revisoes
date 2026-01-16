#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <iomanip>
#include <map>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

struct LevelData
{
    string nome;
    int total = 0;
    int feitos = 0;
};

struct TopicoData
{
    string nomePasta;
    vector<LevelData> niveis;
    int totalTopico = 0;
    int feitosTopico = 0;
};

struct CompData
{
    int total = 0;
    int feitos = 0;
};

int main()
{
    SetConsoleOutputCP(65001);
    cout << "--- 👑 MASTER TRACKER: Níveis + Competências ---" << endl;

    vector<TopicoData> catalogo;
    map<string, CompData> skills;
    int grandTotal = 0, grandFeitos = 0;

    // 1. Varredura para Níveis e Competências
    for (const auto &entryTopico : fs::directory_iterator("."))
    {
        if (entryTopico.is_directory())
        {
            string nomeTopico = entryTopico.path().filename().string();
            if (nomeTopico[0] == '.' || nomeTopico == "progresso")
                continue;

            TopicoData tData;
            tData.nomePasta = nomeTopico;

            for (const auto &entryLevel : fs::directory_iterator(entryTopico.path()))
            {
                if (entryLevel.is_directory())
                {
                    LevelData lData;
                    lData.nome = entryLevel.path().filename().string();

                    for (const auto &entryFile : fs::directory_iterator(entryLevel.path()))
                    {
                        if (entryFile.path().extension() == ".cpp")
                        {
                            ifstream arq(entryFile.path());
                            string linha;
                            bool done = false;
                            vector<string> compsNoArquivo;

                            while (getline(arq, linha))
                            {
                                if (linha.find("STATUS: DONE") != string::npos)
                                    done = true;
                                if (linha.find("- ") != string::npos && linha.find("COMPETENCIAS") == string::npos)
                                {
                                    size_t pos = linha.find("- ");
                                    string c = linha.substr(pos + 2);
                                    c.erase(remove(c.begin(), c.end(), '*'), c.end());
                                    c.erase(remove(c.begin(), c.end(), '/'), c.end());
                                    if (!c.empty() && c.length() < 30)
                                        compsNoArquivo.push_back(c);
                                }
                            }

                            lData.total++;
                            if (done)
                                lData.feitos++;

                            for (const string &c : compsNoArquivo)
                            {
                                skills[c].total++;
                                if (done)
                                    skills[c].feitos++;
                            }
                        }
                    }
                    if (lData.total > 0)
                    {
                        tData.niveis.push_back(lData);
                        tData.totalTopico += lData.total;
                        tData.feitosTopico += lData.feitos;
                    }
                }
            }
            if (!tData.niveis.empty())
            {
                catalogo.push_back(tData);
                grandTotal += tData.totalTopico;
                grandFeitos += tData.feitosTopico;
            }
        }
    }

    // 2. Geração do README.md
    ofstream readme("README.md");
    readme << "# 🚀 CENTRAL DE COMANDO: ESTUDOS C++" << endl
           << endl;

    double porcGlobal = (grandTotal > 0) ? (double)grandFeitos / grandTotal * 100.0 : 0.0;
    readme << "## 🌍 PROGRESSO GLOBAL: " << grandFeitos << "/" << grandTotal << " (" << fixed << setprecision(1) << porcGlobal << "%)" << endl;
    readme << "`[";
    int barras = (int)(porcGlobal / 5);
    for (int i = 0; i < 20; i++)
        readme << (i < barras ? "█" : "░");
    readme << "]`" << endl
           << endl
           << "---" << endl
           << endl;

    // Quadro de Competências (Nova Seção)
    if (!skills.empty())
    {
        readme << "## 🏆 ÁRVORE DE COMPETÊNCIAS" << endl;
        readme << "| Habilidade | Progresso | Nível |" << endl;
        readme << "| :--- | :---: | :---: |" << endl;
        for (auto const &[nome, data] : skills)
        {
            double p = (data.total > 0) ? (double)data.feitos / data.total * 100.0 : 0.0;
            string medalha = (p == 100.0) ? "🥇" : (p > 0 ? "🥈" : "🥉");
            readme << "| " << nome << " | " << data.feitos << "/" << data.total << " | " << medalha << " " << (int)p << "% |" << endl;
        }
        readme << endl
               << "---" << endl
               << endl;
    }

    // Listagem por Níveis (Sua estrutura original)
    for (auto &topico : catalogo)
    {
        double porcTopico = (topico.totalTopico > 0) ? (double)topico.feitosTopico / topico.totalTopico * 100.0 : 0.0;
        readme << "## 📂 " << topico.nomePasta << " [" << (int)porcTopico << "%]" << endl;
        readme << "| Nível | Progresso | Status |" << endl;
        readme << "| :--- | :---: | :---: |" << endl;
        for (const auto &lv : topico.niveis)
        {
            string icon = (lv.feitos == lv.total) ? "✅" : (lv.feitos > 0 ? "🔨" : "❌");
            readme << "| " << lv.nome << " | " << lv.feitos << "/" << lv.total << " | " << icon << " |" << endl;
        }
        readme << endl;
    }

    readme << "---" << endl
           << "*Atualizado automaticamente pelo Master Tracker.*" << endl;
    readme.close();

    cout << "✅ TUDO PRONTO! Níveis e Competências atualizados." << endl;
    return 0;
}