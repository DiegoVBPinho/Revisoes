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

// FUNÇÃO NOVA: Limpa espaços e converte para maiúsculo para não errar a leitura
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
    map<string, map<string, CompData>> skillsPorCategoria;
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
            string categoriaAtual = nomeTopico;

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
                                string limpa = normalizar(linha);
                                // Agora ele ignora espaços: "STATUS:DONE" ou "STATUS:   DONE" funcionam
                                if (limpa.find("STATUS:DONE") != string::npos)
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
                                skillsPorCategoria[categoriaAtual][c].total++;
                                if (done)
                                    skillsPorCategoria[categoriaAtual][c].feitos++;
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

    ofstream readme("README.md");
    double porcGlobal = (grandTotal > 0) ? (double)grandFeitos / grandTotal * 100.0 : 0.0;

    // Gerar Ranking
    string rank, emoji;
    if (porcGlobal < 10)
    {
        rank = "NOOB 👶";
    }
    else if (porcGlobal < 30)
    {
        rank = "ASPIRANTE 🛠️";
    }
    else
    {
        rank = "GUERREIRO 🛡️";
    }

    readme << "# 🚀 CENTRAL DE COMANDO: ESTUDOS C++" << endl
           << endl;
    readme << "### 🎮 STATUS: " << rank << " (" << grandFeitos << "/" << grandTotal << ")" << endl
           << endl;
    readme << "## 🌍 PROGRESSO: " << fixed << setprecision(1) << porcGlobal << "%" << endl;
    readme << "`[";
    int barras = (int)(porcGlobal / 5);
    for (int i = 0; i < 20; i++)
        readme << (i < barras ? "█" : "░");
    readme << "]`" << endl
           << endl
           << "---" << endl;

    for (auto const &[cat, listaSkills] : skillsPorCategoria)
    {
        readme << "### 📂 " << cat << endl;
        readme << "| Habilidade | Status | Nível |" << endl;
        readme << "| :--- | :---: | :---: |" << endl;
        for (auto const &[nome, data] : listaSkills)
        {
            double p = (data.total > 0) ? (double)data.feitos / data.total * 100.0 : 0.0;
            string med = (p == 100.0) ? "🥇" : "🥈";
            readme << "| " << nome << " | " << data.feitos << "/" << data.total << " | " << med << " " << (int)p << "% |" << endl;
        }
    }

    readme.close();
    return 0;
}