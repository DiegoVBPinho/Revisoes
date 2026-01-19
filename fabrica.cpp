#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

string obterConteudoProjeto(int id)
{
    if (id == 1)
        return R"(/*
==================================================
🚀 PROJETO FINAL - FASE 1: Arquitetura Core
==================================================
[ORIGEM: Aulas 14-15 - Modelagem]

COMPETENCIAS:
- HERANCA_E_POLIMORFISMO
- CLASSES_ABSTRATAS
- ENCAPSULAMENTO

🧠 O DESAFIO:
Criar a base do sistema de frota. 
- Classe Abstrata 'Veiculo' (modelo, placa).
- Classes Filhas 'Carro' e 'Caminhao' com cálculos de manutenção diferentes.
- Uso de Vector para armazenar a frota.
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << "--- Fase 1: Sistema de Frota Iniciado ---" << endl;
    return 0;
}
)";

    if (id == 2)
        return R"(/*
==================================================
🚀 PROJETO FINAL - FASE 2: Persistência e Segurança
==================================================
[ORIGEM: Aulas 16-17 - Implementação]

COMPETENCIAS:
- MANIPULACAO_DE_ARQUIVOS (TXT/CSV)
- TRATAMENTO_DE_EXCECOES
- ROBUSTEZ

🧠 O DESAFIO:
O sistema agora deve salvar a frota em um arquivo ao fechar e carregar ao abrir.
- Implementar 'salvarEmArquivo()'.
- Tratar erros de leitura caso o arquivo esteja corrompido ou ausente.
--------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

using namespace std;

int main() {
    cout << "--- Fase 2: Persistencia Implementada ---" << endl;
    return 0;
}
)";

    if (id == 3)
        return R"(/*
==================================================
🚀 PROJETO FINAL - FASE 3: Otimização e Padrões
==================================================
[ORIGEM: Aulas 18-19 - Entrega Final]

COMPETENCIAS:
- SINGLETON (Gerenciador de Sistema)
- TEMPLATES (Relatórios Genéricos)
- QUALIDADE_DE_CODIGO

🧠 O DESAFIO FINAL:
Refatorar o sistema usando o padrão Singleton para o Gerenciador da Frota e 
Templates para criar uma função de busca que funcione por Placa ou por Modelo.
--------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "--- Fase 3: Sistema Finalizado (Nivel Expert) ---" << endl;
    return 0;
}
)";
    return "";
}

int main()
{
    string caminhoBase = "C:/Users/prefe/Documents/REVISOES - CPP/01 - POO/99 - PROJETO_FINAL_INTEGRADO";

    struct Dado
    {
        string arquivo;
        int id;
    };
    vector<Dado> roteiro = {
        {"Fase_01_Arquitetura.cpp", 1},
        {"Fase_02_Persistencia.cpp", 2},
        {"Fase_03_Sistema_Completo.cpp", 3}};

    if (!fs::exists(caminhoBase))
    {
        fs::create_directories(caminhoBase);
    }

    cout << "--- 🏭 FABRICA - PROJETO FINAL: CONSOLIDANDO AULAS 14 A 19 ---" << endl;

    for (const auto &item : roteiro)
    {
        fs::path caminhoFinal = fs::path(caminhoBase) / item.arquivo;
        ofstream arquivo(caminhoFinal);
        if (arquivo.is_open())
        {
            arquivo << obterConteudoProjeto(item.id);
            arquivo.close();
            cout << "✅ GERADO: " << item.arquivo << endl;
        }
    }

    return 0;
}
// g++ fabrica.cpp -o fabrica.exe
//./fabrica.exe