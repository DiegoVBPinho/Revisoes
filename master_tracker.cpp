#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <iomanip>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

// --- FUNÇÕES DE APOIO ---
string toUpper(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

bool checkDone(string path)
{
    ifstream f(path);
    if (!f.is_open())
        return false;
    string l;
    while (getline(f, l))
    {
        string u = toUpper(l);
        if (u.find("STATUS") != string::npos && u.find("DONE") != string::npos)
            return true;
    }
    return false;
}

// --- NOVA FUNÇÃO: GERA O TRACKER LOCAL SE ELE NÃO EXISTIR ---
void garantirTrackerLocal(string pathLevel, const vector<string> &arquivos)
{
    string pathReadme = pathLevel + "/README.md";

    // Se o arquivo não existe, nós criamos o "esqueleto" dele
    if (!fs::exists(pathReadme))
    {
        ofstream f(pathReadme);
        f << "# 📋 TRACKER DE NÍVEL" << endl
          << endl;
        f << "| Status | Exercício |" << endl;
        f << "| :---: | :--- |" << endl;

        for (const auto &nome : arquivos)
        {
            f << "| [ ] | " << nome << " |" << endl;
        }
        f.close();
        cout << "   ✨ Criado tracker faltante em: " << pathLevel << endl;
    }
}

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

int main()
{
    SetConsoleOutputCP(65001); // UTF-8
    cout << "--- 👑 MASTER TRACKER: VARREDURA E AUTO-GERAÇÃO ---" << endl;

    vector<TopicoData> catalogo;
    int grandTotal = 0;
    int grandFeitos = 0;

    for (const auto &entryTopico : fs::directory_iterator("."))
    {
        if (entryTopico.is_directory())
        {
            string nomeTopico = entryTopico.path().filename().string();

            if (nomeTopico[0] == '.' || nomeTopico == "progresso" || nomeTopico.find("0x") != string::npos)
            {
                continue;
            }

            TopicoData tData;
            tData.nomePasta = nomeTopico;
            bool temConteudo = false;

            for (const auto &entryLevel : fs::directory_iterator(entryTopico.path()))
            {
                if (entryLevel.is_directory())
                {
                    string nomeLevel = entryLevel.path().filename().string();
                    string uLevel = toUpper(nomeLevel);

                    if (uLevel.find("LEVEL") != string::npos || uLevel.find("NIVEL") != string::npos)
                    {
                        LevelData lData;
                        lData.nome = nomeLevel;
                        vector<string> listaArquivosNoLevel;

                        for (const auto &entryFile : fs::directory_iterator(entryLevel.path()))
                        {
                            string fName = entryFile.path().filename().string();
                            if (fName.find(".cpp") != string::npos && isdigit(fName[0]))
                            {
                                listaArquivosNoLevel.push_back(fName);
                                lData.total++;
                                if (checkDone(entryFile.path().string()))
                                {
                                    lData.feitos++;
                                }
                            }
                        }

                        if (lData.total > 0)
                        {
                            // 🔥 A MÁGICA ACONTECE AQUI:
                            sort(listaArquivosNoLevel.begin(), listaArquivosNoLevel.end());
                            garantirTrackerLocal(entryLevel.path().string(), listaArquivosNoLevel);

                            tData.niveis.push_back(lData);
                            tData.totalTopico += lData.total;
                            tData.feitosTopico += lData.feitos;
                            temConteudo = true;
                        }
                    }
                }
            }

            if (temConteudo)
            {
                catalogo.push_back(tData);
                grandTotal += tData.totalTopico;
                grandFeitos += tData.feitosTopico;
            }
        }
    }

    // ... (O resto do seu código que gera o README global continua igual abaixo)
    sort(catalogo.begin(), catalogo.end(), [](const TopicoData &a, const TopicoData &b)
         { return a.nomePasta < b.nomePasta; });
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
    for (auto &topico : catalogo)
    {
        sort(topico.niveis.begin(), topico.niveis.end(), [](const LevelData &a, const LevelData &b)
             { return a.nome < b.nome; });
        double porcTopico = (topico.totalTopico > 0) ? (double)topico.feitosTopico / topico.totalTopico * 100.0 : 0.0;
        string statusTopico = (porcTopico == 100.0) ? "🏆 DOMINADO" : (porcTopico > 0 ? "🔥 EM ANDAMENTO" : "💤 AGUARDANDO");
        readme << "## 📂 " << topico.nomePasta << " [" << (int)porcTopico << "%] - " << statusTopico << endl;
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
    cout << "\n✅ MASTER TRACKER CONCLUÍDO! Trackers locais criados/atualizados." << endl;
    return 0;
}