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

// Dicionário de Agrupamento (Mapeia a skill solta para o Cluster)
map<string, string> mapearCluster = {
    {"CLASSE_CONCEITO", "📦 MODELAGEM_BASE"}, {"DEFINICAO_ATRIBUTOS", "📦 MODELAGEM_BASE"}, {"DEFINICAO_METODOS", "📦 MODELAGEM_BASE"}, {"TIPAGEM_EM_CLASSES", "📦 MODELAGEM_BASE"}, {"PADRONIZACAO_DE_NOMES", "📦 MODELAGEM_BASE"}, {"INSTANCIACAO", "🏗️ INSTANCIACAO_E_MEMORIA"}, {"CRIACAO_DE_OBJETOS", "🏗️ INSTANCIACAO_E_MEMORIA"}, {"MULTIPLAS_INSTANCIAS", "🏗️ INSTANCIACAO_E_MEMORIA"}, {"MEMORIA_INDEPENDENTE", "🏗️ INSTANCIACAO_E_MEMORIA"}, {"ACESSO_A_MEMBROS", "🏗️ INSTANCIACAO_E_MEMORIA"}, {"LOGICA_DE_METODOS", "⚙️ LOGICA_OPERACIONAL"}, {"ALTERACAO_DE_ESTADO", "⚙️ LOGICA_OPERACIONAL"}, {"MANIPULACAO_DE_ATRIBUTOS", "⚙️ LOGICA_OPERACIONAL"}, {"ATRIBUTOS_CALCULADOS", "⚙️ LOGICA_OPERACIONAL"}, {"CONDICIONAIS_EM_METODOS", "⚙️ LOGICA_OPERACIONAL"}, {"CALCULOS_EM_METODOS", "⚙️ LOGICA_OPERACIONAL"}, {"ESCOPO_DE_CLASSE", "⚙️ LOGICA_OPERACIONAL"}, {"INTERACAO_METODOS", "⚔️ SISTEMAS_DE_INTERACAO"}, {"INTERACAO_OBJETO_VARIAVEL", "⚔️ SISTEMAS_DE_INTERACAO"}, {"OBJETOS_COMO_PARAMETROS", "⚔️ SISTEMAS_DE_INTERACAO"}, {"REFERENCIA_DE_INSTANCIAS", "⚔️ SISTEMAS_DE_INTERACAO"}, {"PASSAGEM_POR_REFERENCIA", "⚔️ SISTEMAS_DE_INTERACAO"}, {"LOGICA_DE_COMBATE", "⚔️ SISTEMAS_DE_INTERACAO"}, {"INTERPRETACAO_UML", "📐 ARQUITETURA_UML"}, {"REPRESENTACAO_UML", "📐 ARQUITETURA_UML"}, {"VISIBILIDADE_MÉTODOS", "📐 ARQUITETURA_UML"}, {"MODIFICADORES_ACESSO (PUBLIC)", "📐 ARQUITETURA_UML"}, {"LOGICA_DE_SISTEMAS_COOPERATIVOS", "🎮 SIMULACAO_AVANCADA"}, {"SIMULACAO_SISTEMAS", "🎮 SIMULACAO_AVANCADA"}, {"ARRAYS_DE_OBJETOS", "🎮 SIMULACAO_AVANCADA"}, {"MODELAGEM_COMPLEXA", "🎮 SIMULACAO_AVANCADA"}};

struct LevelData
{
    string nome;
    int total = 0, feitos = 0;
    vector<pair<string, bool>> exercicios;
    set<string> clustersAdquiridos;
    set<string> clustersPendentes;
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
                            bool isDone = false, lendoComp = false;

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
                                    string cluster = (mapearCluster.count(c)) ? mapearCluster[c] : c;
                                    if (!c.empty() && c[0] != '=')
                                    {
                                        if (isDone)
                                            lData.clustersAdquiridos.insert(cluster);
                                        else
                                            lData.clustersPendentes.insert(cluster);
                                    }
                                }
                            }
                            lData.exercicios.push_back({arq.path().filename().string(), isDone});
                            if (isDone)
                                lData.feitos++;
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
        // --- README TEMA (POO) ---
        ofstream fTema("./" + nomeTema + "/README.md");
        fTema << "# 📂 Assunto: " << nomeTema << "\n\n## 🧬 Domínio por Clusters\n";
        set<string> tAdq, tPend;
        for (auto const &lv : tData.niveis)
        {
            tAdq.insert(lv.clustersAdquiridos.begin(), lv.clustersAdquiridos.end());
            tPend.insert(lv.clustersPendentes.begin(), lv.clustersPendentes.end());
        }
        for (auto const &c : tAdq)
            fTema << "- ✅ " << c << " (Dominado)\n";
        for (auto const &c : tPend)
            if (tAdq.find(c) == tAdq.end())
                fTema << "- 💡 " << c << " (Em progresso)\n";
        fTema.close();

        // --- README GLOBAL ---
        ofstream fGlobal("README.md");
        fGlobal << "# 🚀 CENTRAL DE COMANDO\n\n## 🧬 ÁRVORE DE COMPETÊNCIAS\n";
        for (auto const &[nT, tD] : dashboard)
        {
            fGlobal << "### 📂 " << nT << "\n";
            set<string> gAdq, gPend;
            for (auto const &lv : tD.niveis)
            {
                gAdq.insert(lv.clustersAdquiridos.begin(), lv.clustersAdquiridos.end());
                gPend.insert(lv.clustersPendentes.begin(), lv.clustersPendentes.end());
            }
            for (auto const &c : gAdq)
                fGlobal << "- [x] ✅ " << c << "\n";
            for (auto const &c : gPend)
                if (gAdq.find(c) == gAdq.end())
                    fGlobal << "- [ ] ⏳ " << c << "\n";
        }
    }
    cout << "Agrupamento automático concluído!" << endl;
    return 0;
}
// g++ -std=c++17 master_tracker.cpp -o master.exe
//.\master