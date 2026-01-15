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

string toUpper(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Verifica se arquivo tem STATUS: DONE
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

    cout << "--- 👑 MASTER TRACKER: INICIANDO VARREDURA GERAL ---" << endl;

    vector<TopicoData> catalogo;
    int grandTotal = 0;
    int grandFeitos = 0;

    // 1. Loop nas pastas da Raiz (01 - Ponteiros, 02 - Recursao...)
    for (const auto &entryTopico : fs::directory_iterator("."))
    {
        if (entryTopico.is_directory())
        {
            string nomeTopico = entryTopico.path().filename().string();

            // --- 🚫 FILTRO DE EXCLUSÃO (BLACKLIST) ---
            // Ignora:
            // 1. Pastas do sistema (começam com .)
            // 2. Pasta "progresso" (antiga)
            // 3. Pasta "0x" (Templates) <--- AQUI ESTÁ A CORREÇÃO
            if (nomeTopico[0] == '.' ||
                nomeTopico == "progresso" ||
                nomeTopico.find("0x") != string::npos)
            {
                continue; // Pula essa pasta e vai para a próxima
            }

            // Criamos o objeto do Tópico
            TopicoData tData;
            tData.nomePasta = nomeTopico;
            bool temConteudo = false;

            // 2. Entra na pasta do Tópico e procura os Levels
            for (const auto &entryLevel : fs::directory_iterator(entryTopico.path()))
            {
                if (entryLevel.is_directory())
                {
                    string nomeLevel = entryLevel.path().filename().string();
                    string uLevel = toUpper(nomeLevel);

                    // Só processa pastas que tenham "LEVEL" ou "NIVEL" no nome
                    if (uLevel.find("LEVEL") != string::npos || uLevel.find("NIVEL") != string::npos)
                    {

                        LevelData lData;
                        lData.nome = nomeLevel;

                        // 3. Conta os arquivos .cpp dentro do Level
                        for (const auto &entryFile : fs::directory_iterator(entryLevel.path()))
                        {
                            string fName = entryFile.path().filename().string();
                            if (fName.find(".cpp") != string::npos && isdigit(fName[0]))
                            {
                                lData.total++;
                                if (checkDone(entryFile.path().string()))
                                {
                                    lData.feitos++;
                                }
                            }
                        }

                        if (lData.total > 0)
                        {
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
                cout << "   📦 Tópico Detectado: " << nomeTopico << " (" << tData.feitosTopico << "/" << tData.totalTopico << ")" << endl;
            }
        }
    }

    // Ordenar tópicos (01 antes de 02...)
    sort(catalogo.begin(), catalogo.end(), [](const TopicoData &a, const TopicoData &b)
         { return a.nomePasta < b.nomePasta; });

    // ---------------------------------------------
    // GERAR O README GLOBAL (DASHBOARD SUPREMO)
    // ---------------------------------------------
    ofstream readme("README.md");
    readme << "# 🚀 CENTRAL DE COMANDO: ESTUDOS C++" << endl
           << endl;

    // BARRA GERAL
    double porcGlobal = (grandTotal > 0) ? (double)grandFeitos / grandTotal * 100.0 : 0.0;
    readme << "## 🌍 PROGRESSO GLOBAL: " << grandFeitos << "/" << grandTotal << " (" << fixed << setprecision(1) << porcGlobal << "%)" << endl;

    readme << "`[";
    int barras = (int)(porcGlobal / 5);
    for (int i = 0; i < 20; i++)
        readme << (i < barras ? "█" : "░");
    readme << "]`" << endl
           << endl;
    readme << "---" << endl
           << endl;

    // LOOP POR TÓPICOS
    for (auto &topico : catalogo)
    {
        // Ordena os levels dentro do tópico
        sort(topico.niveis.begin(), topico.niveis.end(), [](const LevelData &a, const LevelData &b)
             { return a.nome < b.nome; });

        double porcTopico = (topico.totalTopico > 0) ? (double)topico.feitosTopico / topico.totalTopico * 100.0 : 0.0;
        string statusTopico = (porcTopico == 100.0) ? "🏆 DOMINADO" : (porcTopico > 0 ? "🔥 EM ANDAMENTO" : "💤 AGUARDANDO");

        readme << "## 📂 " << topico.nomePasta << " [" << (int)porcTopico << "%] - " << statusTopico << endl;

        // Tabela do Tópico
        readme << "| Nível | Progresso | Status |" << endl;
        readme << "| :--- | :---: | :---: |" << endl;

        for (const auto &lv : topico.niveis)
        {
            string icon = (lv.feitos == lv.total) ? "✅" : (lv.feitos > 0 ? "🔨" : "❌");
            readme << "| " << lv.nome << " | " << lv.feitos << "/" << lv.total << " | " << icon << " |" << endl;
        }
        readme << endl;
    }

    readme << "---" << endl;
    readme << "*Atualizado automaticamente pelo Master Tracker.*" << endl;
    readme.close();

    cout << "\n✅ README GERAL ATUALIZADO (Templates ignorados)!" << endl;
    return 0;
}