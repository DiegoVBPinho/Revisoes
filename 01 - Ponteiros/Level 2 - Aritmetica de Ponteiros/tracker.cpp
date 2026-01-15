#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <map>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

string toUpper(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Verifica se o arquivo tem STATUS: DONE
bool verificarStatusDone(string caminhoArquivo)
{
    ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open())
        return false;
    string linha;
    while (getline(arquivo, linha))
    {
        string linhaUpper = toUpper(linha);
        if (linhaUpper.find("STATUS") != string::npos &&
            linhaUpper.find("DONE") != string::npos)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    SetConsoleOutputCP(65001); // UTF-8

    // --- NOVA FUNCIONALIDADE: PEGAR NOME DA PASTA ---
    string nomePasta = fs::current_path().filename().string();
    string tituloMissao = toUpper(nomePasta);
    // ------------------------------------------------

    cout << "--- 🚀 TRACKER SYSTEM: " << tituloMissao << " ---" << endl;
    cout << endl;

    // 1. ESCANEIA A PASTA
    map<string, bool> statusExercicios;
    string path = ".";
    bool encontrouArquivos = false;

    for (const auto &entry : fs::directory_iterator(path))
    {
        string nomeArquivo = entry.path().filename().string();
        if (nomeArquivo.find(".cpp") != string::npos && isdigit(nomeArquivo[0]))
        {
            encontrouArquivos = true;
            string id = nomeArquivo.substr(0, 2);
            bool isDone = verificarStatusDone(entry.path().string());

            if (statusExercicios.find(id) == statusExercicios.end())
            {
                statusExercicios[id] = isDone;
            }
            else
            {
                if (isDone)
                    statusExercicios[id] = true;
            }
        }
    }

    if (!encontrouArquivos)
    {
        cout << "⚠️ NENHUM ARQUIVO .cpp ENCONTRADO." << endl;
        return 0;
    }

    // 2. MOSTRA STATUS
    cout << "📂 Status da Missao:" << endl;
    for (auto const &[id, isDone] : statusExercicios)
    {
        cout << "   ID " << id << ": " << (isDone ? "✅ DONE" : "❌ TO DO") << endl;
    }

    // 3. ATUALIZA O README
    ifstream leitura("README.md");
    if (!leitura.is_open())
    {
        cout << "\n⚠️ README.md NAO ENCONTRADO." << endl;
        return 0;
    }

    vector<string> linhasReadme;
    string linha;
    int total = 0;
    int concluidos = 0;

    while (getline(leitura, linha))
    {

        bool temCaixa = (linha.find("[ ]") != string::npos ||
                         linha.find("[x]") != string::npos ||
                         linha.find("[X]") != string::npos);

        if (temCaixa)
        {
            for (auto const &[id, isDone] : statusExercicios)
            {

                string tagTabela = " " + id + " ";
                string tagTabela2 = "|" + id + "|";
                string tagComp1 = "[ID:" + id + "]";
                string tagComp2 = "(ID:" + id + ")";

                if (linha.find(tagTabela) != string::npos ||
                    linha.find(tagTabela2) != string::npos ||
                    linha.find(tagComp1) != string::npos ||
                    linha.find(tagComp2) != string::npos)
                {

                    if (isDone)
                    {
                        size_t posBox = linha.find("[ ]");
                        if (posBox != string::npos)
                            linha.replace(posBox, 3, "[x]");
                    }
                    else
                    {
                        size_t posBoxX = linha.find("[x]");
                        if (posBoxX != string::npos)
                            linha.replace(posBoxX, 3, "[ ]");

                        size_t posBoxXBig = linha.find("[X]");
                        if (posBoxXBig != string::npos)
                            linha.replace(posBoxXBig, 3, "[ ]");
                    }
                }
            }
        }

        if (linha.find("|") != string::npos && temCaixa)
        {
            total++;
            if (linha.find("[x]") != string::npos || linha.find("[X]") != string::npos)
            {
                concluidos++;
            }
        }

        linhasReadme.push_back(linha);
    }
    leitura.close();

    // 4. SALVAR
    ofstream escrita("README.md");
    for (const string &l : linhasReadme)
    {
        escrita << l << endl;
    }
    escrita.close();

    cout << "\n========================================" << endl;
    cout << "📊 PROGRESSO [" << tituloMissao << "]: " << concluidos << "/" << total << endl;
    cout << "========================================" << endl;

    return 0;
}