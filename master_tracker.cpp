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
    map<string, pair<int, int>> skills;
};

// --- LOGICA DE RANK POR XP REAL ---
string calcularRankReal(int concluidos)
{
    if (concluidos == 0)
        return "DESEMPREGADO 😶";
    if (concluidos <= 2)
        return "ESTAGIÁRIO NOOB 👶";
    if (concluidos <= 5)
        return "JUNIOR EM EVOLUÇÃO 🛠️";
    if (concluidos <= 10)
        return "PLENO RESPEITADO 🛡️";
    if (concluidos <= 20)
        return "SENIOR BRABO 🧙‍♂️";
    return "ARQUITETO LENDÁRIO 🏛️";
}

string normalizar(string s)
{
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

int main()
{
    SetConsoleOutputCP(65001);
    vector<TopicoData> catalogo;
    int grandTotal = 0, grandFeitos = 0;

    for (const auto &entryTopico : fs::directory_iterator("."))
    {
        if (entryTopico.is_directory())
        {
            string nomeTopico = entryTopico.path().filename().string();
            if (nomeTopico[0] == '.' || nomeTopico == "progresso" || nomeTopico == "vscode")
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
                            while (getline(arq, linha))
                            {
                                string limpa = normalizar(linha);
                                if (limpa.find("STATUS:DONE") != string::npos)
                                    done = true;
                                if (linha.find("- ") != string::npos && linha.find("COMPETENCIAS") == string::npos)
                                {
                                    size_t pos = linha.find("- ");
                                    string c = linha.substr(pos + 2);
                                    c.erase(remove(c.begin(), c.end(), '*'), c.end());
                                    if (!c.empty() && c.length() < 30)
                                    {
                                        tData.skills[c].first++;
                                        if (done)
                                            tData.skills[c].second++;
                                    }
                                }
                            }
                            lData.total++;
                            if (done)
                                lData.feitos++;
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

                // --- README DO TEMA (DENTRO DA PASTA) ---
                ofstream rTema(tData.nomePasta + "/README.md");
                rTema << "# 📂 TEMA: " << tData.nomePasta << endl
                      << endl;
                rTema << "### 📊 STATUS NESTE TEMA: " << calcularRankReal(tData.feitosTopico) << endl;
                rTema << "- Concluídos: " << tData.feitosTopico << " de " << tData.totalTopico << endl
                      << endl;

                rTema << "## 🏆 ÁRVORE DE SKILLS" << endl;
                rTema << "| Skill | Status |" << endl
                      << "| :--- | :---: |" << endl;
                for (auto const &[name, data] : tData.skills)
                {
                    rTema << "| " << name << " | " << data.second << "/" << data.first << " |" << endl;
                }

                rTema << "\n## 🗺️ PROGRESSO POR LEVEL" << endl;
                for (auto const &lv : tData.niveis)
                {
                    rTema << "- " << lv.nome << " [" << lv.feitos << "/" << lv.total << "]" << endl;
                }
                rTema.close();
            }
        }
    }

    // --- README GLOBAL LIMPO E SEM LINKS ---
    ofstream readme("README.md");
    readme << "# 🚀 CENTRAL DE COMANDO" << endl
           << endl;
    readme << "### 👑 RANK GERAL: " << calcularRankReal(grandFeitos) << endl;
    readme << "XP TOTAL: " << grandFeitos << " exercícios concluídos." << endl
           << endl;

    readme << "| Tema | Concluídos | Progresso % |" << endl;
    readme << "| :--- | :---: | :---: |" << endl;
    for (auto &t : catalogo)
    {
        double p = (double)t.feitosTopico / t.totalTopico * 100.0;
        readme << "| " << t.nomePasta << " | " << t.feitosTopico << " | " << (int)p << "% |" << endl;
    }
    readme << endl
           << "---" << endl
           << "*Navegue pelas pastas para ver detalhes de cada tema.*" << endl;
    readme.close();

    return 0;
}

// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\atualizar_tudo.bat