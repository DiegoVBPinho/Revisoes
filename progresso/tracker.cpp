#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream arquivo(
        "../01 - Ponteiros/Level 1 - Conceitos Basicos/README.md");

    if (!arquivo.is_open())
    {
        cout << "ERRO: nao consegui abrir o README" << endl;
        return 0;
    }

    string linha;
    int concluidos = 0;
    int total = 0;

    while (getline(arquivo, linha))
    {
        if (linha.size() > 0 && linha[0] == '|' &&
            (linha.find("[") != string::npos))
        {
            total++;

            if (
                linha.find("[x]") != string::npos ||
                linha.find("[X]") != string::npos)
            {
                concluidos++;
            }
        }
    }

    cout << "Level 1: " << concluidos << "/" << total << endl;

    return 0;
}
