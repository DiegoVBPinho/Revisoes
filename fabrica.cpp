#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main()
{
    // Caminho da pasta que agora está protegida pela trava do seu .bat
    string caminhoBase = "C:/Users/prefe/Documents/REVISOES - CPP/01 - POO/PROJETO POO - INATEL";

    if (!fs::exists(caminhoBase))
    {
        fs::create_directories(caminhoBase);
    }

    ofstream readme(caminhoBase + "/README.md");

    if (readme.is_open())
    {
        readme << "# 🚀 PROJETO POO - INATEL\n\n";
        readme << "## 👥 Equipe de Desenvolvimento\n";
        readme << "- Membro 1\n";
        readme << "- Membro 2\n";
        readme << "- Membro 3\n";
        readme << "- Mestre\n\n";

        readme << "## 📡 Tema: Sistema de Monitoramento de Redes (Telecom/Software)\n";
        readme << "> **Objetivo:** Automatizar a verificação de integridade de ativos de rede via IP, utilizando processamento paralelo (Threads) e garantindo a persistência de logs de falhas.\n\n";

        readme << "## 🛠️ Checklist de Requisitos (Critérios Prof. Christopher Lima)\n";
        readme << "Abaixo estão os pontos obrigatórios conforme o documento de orientações (C06):\n\n";

        readme << "1.  **[ ] Boas Práticas:** Organização modular em arquivos `.h` e `.cpp`.\n";
        readme << "2.  **[ ] Classes:** Membros privados, métodos e construtores bem definidos.\n";
        readme << "3.  **[ ] Herança:** Hierarquia: `Dispositivo` -> `Roteador`, `Servidor`, `Switch`.\n";
        readme << "4.  **[ ] Polimorfismo:** Uso de funções virtuais para diferentes tipos de check-up.\n";
        readme << "5.  **[ ] Abstração:** Classe base `Dispositivo` como Classe Abstrata.\n";
        readme << "6.  **[ ] Tratamento de Erros:** Blocos `try-catch` para falhas de conexão ou leitura.\n";
        readme << "7.  **[ ] Persistência:** Escrita de logs de status em arquivos `.txt` ou `.csv`.\n";
        readme << "8.  **[ ] Threads:** Execução simultânea de pings em múltiplos dispositivos.\n";
        readme << "9.  **[ ] UML:** Diagrama de classes completo seguindo o padrão da disciplina.\n";
        readme << "10. **[ ] Repositório:** Versionamento constante via GitHub.\n";
        readme << "11. **[ ] Contexto de Engenharia:** Aplicação focada em infraestrutura de Redes.\n\n";

        readme << "--- \n";
        readme << "*Este README foi gerado para garantir o cumprimento integral da NP2.*";

        readme.close();
        cout << "✅ README.md gerado com sucesso respeitando todos os criterios do Professor Christopher!" << endl;
    }
    else
    {
        cout << "❌ Erro ao abrir o arquivo para escrita." << endl;
    }

    return 0;
}
// g++ fabrica.cpp -o fabrica.exe
//./fabrica.exe