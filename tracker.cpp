#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

// Função para verificar se o arquivo está DONE
bool verificarStatusDone(string caminhoArquivo)
{
    ifstream arquivo(caminhoArquivo);
    string linha;
    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            // Converte para maiúsculo para garantir
            string linhaUpper = linha;
            transform(linhaUpper.begin(), linhaUpper.end(), linhaUpper.begin(), ::toupper);
            if (linhaUpper.find("STATUS: DONE") != string::npos)
            {
                return true;
            }
        }
        arquivo.close();
    }
    return false;
}

int main()
{
    // 1. Identificar arquivos .cpp DONE na pasta atual
    vector<string> concluidos;
    for (const auto &entry : fs::directory_iterator("."))
    {
        if (entry.path().extension() == ".cpp")
        {
            // Pega o ID do nome do arquivo (ex: "01 - Nome.cpp" -> "01")
            string nome = entry.path().filename().string();
            if (verificarStatusDone(entry.path().string()))
            {
                string id = nome.substr(0, 2); // Pega os 2 primeiros chars
                concluidos.push_back(id);
            }
        }
    }

    // 2. Atualizar o README.md
    fstream readme("README.md");
    if (!readme.is_open())
    {
        cout << "Erro: README.md nao encontrado nesta pasta." << endl;
        return 1;
    }

    vector<string> linhas;
    string linha;
    while (getline(readme, linha))
    {
        linhas.push_back(linha);
    }
    readme.close();

    ofstream readmeOut("README.md");
    for (string &l : linhas)
    {
        // Procura linhas de tabela: "| [ ] | 01 |" ou "| [x] | 01 |"
        if (l.find("|") != string::npos && l.find("|") < 5)
        { // É uma linha de tabela
            for (const string &id : concluidos)
            {
                // Se a linha tem o ID do exercício (ex: " 01 ")
                if (l.find(" " + id + " ") != string::npos || l.find("| " + id + " |") != string::npos)
                {
                    // Substitui [ ] por [x]
                    size_t pos = l.find("[ ]");
                    if (pos != string::npos)
                    {
                        l.replace(pos, 3, "[x]");
                    }
                    // Se quisesse voltar para TODO (caso tenha removido o done), seria logica inversa aqui
                    // Mas o foco é marcar o DONE.
                }
            }
        }
        readmeOut << l << endl;
    }
    readmeOut.close();

    cout << "Tracker Local executado! README atualizado." << endl;
    return 0;
}