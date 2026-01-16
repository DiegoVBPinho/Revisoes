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
    map<string, pair<int, int>> skills; // Skills específicas deste tema
};

string normalizar(string s)
{
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

string calcularRank(double p)
{
    if (p < 20)
        return "NOOB 👶";
    if (p < 50)
        return "ASPIRANTE 🛠️";
    if (p < 80)
        return "GUERREIRO 🛡️";
    return "MESTRE 🧙‍♂️";
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

                    for (const auto &entryFile : fs::recursive_directory_iterator(entryLevel.path()))
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

                // --- CRIA O README DENTRO DA PASTA DO TEMA ---
                ofstream rTema(tData.nomePasta + "/README.md");
                double pT = (double)tData.feitosTopico / tData.totalTopico * 100.0;
                rTema << "# 📂 TEMA: " << tData.nomePasta << endl
                      << endl;
                rTema << "### 📊 STATUS: " << calcularRank(pT) << " (" << (int)pT << "%)" << endl
                      << endl;

                rTema << "## 🏆 COMPETÊNCIAS DO TEMA" << endl;
                rTema << "| Skill | Progresso |" << endl
                      << "| :--- | :---: |" << endl;
                for (auto const &[name, data] : tData.skills)
                {
                    double pS = (double)data.second / data.first * 100.0;
                    rTema << "| " << name << " | " << data.second << "/" << data.first << " (" << (int)pS << "%) |" << endl;
                }

                rTema << "\n## 🗺️ PROGRESSO POR NÍVEL" << endl;
                rTema << "| Nível | Status |" << endl
                      << "| :--- | :---: |" << endl;
                for (auto const &lv : tData.niveis)
                {
                    rTema << "| " << lv.nome << " | " << lv.feitos << "/" << lv.total << " |" << endl;
                }
                rTema.close();
            }
        }
    }

    // --- GERA O README GLOBAL LIMPO ---
    ofstream readme("README.md");
    double pG = (grandTotal > 0) ? (double)grandFeitos / grandTotal * 100.0 : 0.0;
    readme << "# 🚀 CENTRAL DE COMANDO: C++" << endl
           << endl;
    readme << "## 🌍 PROGRESSO GERAL: " << (int)pG << "%" << endl
           << endl;

    readme << "| Tema de Estudo | Progresso | Rank |" << endl;
    readme << "| :--- | :---: | :---: |" << endl;
    for (auto &t : catalogo)
    {
        double p = (double)t.feitosTopico / t.totalTopico * 100.0;
        readme << "| [" << t.nomePasta << "](./" << t.nomePasta << ") | " << (int)p << "% | " << calcularRank(p) << " |" << endl;
    }
    readme.close();
    return 0;
}