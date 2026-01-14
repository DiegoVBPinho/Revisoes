#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int contarExerciciosConcluidos(const string &caminhoReadme)
{
    ifstream arquivo(caminhoReadme);
    string linha;
    int concluidos = 0;

    if (!arquivo.is_open())
        return 0;

    while (getline(arquivo, linha))
    {
        if (linha.find("|  [x]") != string::npos)
            concluidos++;
    }

    return concluidos;
}

int main()
{
    string caminho =
        "01 - Ponteiros/Level 2 - Aritmetica de Ponteiros/00 - README - LEVEL 2.md";

    int feitos = contarExerciciosConcluidos(caminho);

    cout << "Level 2: " << feitos << "/10" << endl;

    return 0;
}
