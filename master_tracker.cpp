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
    cout << "--- 👑 MASTER TRACKER: Árvore de Talentos Universal ---" << endl;

    vector<TopicoData> catalogo;
    // Mapa: [Nome da Pasta do Tema] -> [Mapa de Competências]
    map<string, map<string, CompData>> skillsPorCategoria;
    int grandTotal = 0, grandFeitos = 0;

    for (const auto &entryTopico : fs::directory_iterator("."))
    {
        if (entryTopico.is_directory())
        {
            string nomeTopico = entryTopico.path().filename().string();

            // Ignora pastas de configuração ou ocultas
            if (nomeTopico[0] == '.' || nomeTopico == "progresso" || nomeTopico == "vscode")
                continue;

            TopicoData tData;
            tData.nomePasta = nomeTopico;

            // --- A MÁGICA UNIVERSAL ---
            // A categoria agora é EXATAMENTE o nome da pasta que você criou
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
                                if (linha.find("STATUS: DONE") != string::npos)
                                    done = true;
                                if (linha.find("- ") != string::npos && linha.find("COMPETENCIAS") == string::npos)
                                {
                                    size_t pos = linha.find("- ");
                                    string c = linha.substr(pos + 2);

                                    // Limpeza de caracteres de comentário
                                    c.erase(remove(c.begin(), c.end(), '*'), c.end());
                                    c.erase(remove(c.begin(), c.end(), '/'), c.end());

                                    // Remove espaços em branco no fim da string
                                    c.erase(c.find_last_not_of(" \n\r\t") + 1);

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
    readme << "# 🚀 CENTRAL DE COMANDO: ESTUDOS C++" << endl
           << endl;

    // --- STATUS DO JOGADOR ---
    double porcGlobal = (grandTotal > 0) ? (double)grandFeitos / grandTotal * 100.0 : 0.0;
    string rank, emoji;
    if (porcGlobal < 10)
    {
        rank = "NOOB (Fraldinha de Código)";
        emoji = "👶";
    }
    else if (porcGlobal < 30)
    {
        rank = "ASPIRANTE";
        emoji = "🛠️";
    }
    else if (porcGlobal < 50)
    {
        rank = "GUERREIRO";
        emoji = "🛡️";
    }
    else if (porcGlobal < 75)
    {
        rank = "MESTRE";
        emoji = "🧙‍♂️";
    }
    else
    {
        rank = "LENDÁRIO";
        emoji = "🏛️";
    }

    readme << "### 🎮 STATUS DO JOGADOR" << endl;
    readme << "- **Nível Atual:** " << rank << " " << emoji << endl;
    readme << "- **XP Total:** " << grandFeitos << " de " << grandTotal << " concluídos" << endl
           << endl;

    readme << "## 🌍 PROGRESSO GLOBAL: " << fixed << setprecision(1) << porcGlobal << "%" << endl;
    readme << "`[";
    int barras = (int)(porcGlobal / 5);
    for (int i = 0; i < 20; i++)
        readme << (i < barras ? "█" : "░");
    readme << "]`" << endl
           << endl
           << "---" << endl
           << endl;

    // --- ÁRVORE DE TALENTOS UNIVERSAL ---
    readme << "## 🏆 ÁRVORE DE TALENTOS" << endl;
    for (auto const &[cat, listaSkills] : skillsPorCategoria)
    {
        readme << "### 📂 Categoria: " << cat << endl;
        readme << "| Habilidade | Progresso | Nível |" << endl;
        readme << "| :--- | :---: | :---: |" << endl;
        for (auto const &[nome, data] : listaSkills)
        {
            double p = (data.total > 0) ? (double)data.feitos / data.total * 100.0 : 0.0;
            string medalha = (p == 100.0) ? "🥇" : (p > 0 ? "🥈" : "🥉");
            readme << "| " << nome << " | " << data.feitos << "/" << data.total << " | " << medalha << " " << (int)p << "% |" << endl;
        }
        readme << endl;
    }

    readme << "---" << endl
           << endl;

    // Listagem por Níveis
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

    readme << "*Atualizado automaticamente pelo Master Tracker Evolutivo.*" << endl;
    readme.close();
    return 0;
}