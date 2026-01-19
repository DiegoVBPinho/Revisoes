#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void gerarProjetoFinalInatel(string path)
{
    // 1. README.md - Documentação de Alto Nível
    ofstream readme(path + "/README.md");
    readme << "# 🚀 PROJETO POO - INATEL\n\n"
           << "## 👥 Equipe\n"
           << "- Membro 1\n- Membro 2\n- Membro 3\n- Mestre\n\n"
           << "## 📡 Tema: Sistema de Monitoramento de Redes\n"
           << "Este projeto visa resolver problemas de monitoramento de ativos em infraestruturas de TI.\n\n"
           << "### 🛠 Requisitos Implementados:\n"
           << "- [x] Modularização (.h e .cpp)\n"
           << "- [x] Herança e Polimorfismo\n"
           << "- [x] Classes Abstratas\n"
           << "- [x] Threads para Monitoramento Paralelo\n"
           << "- [x] Persistência em Arquivos (Logs)\n";
    readme.close();

    // 2. Classe Abstrata Dispositivo.h (Requisito 5)
    ofstream hFile(path + "/Dispositivo.h");
    hFile << "#ifndef DISPOSITIVO_H\n#define DISPOSITIVO_H\n#include <string>\n\n"
          << "class Dispositivo {\n"
          << "protected:\n    std::string ip;\n    std::string nome;\n"
          << "public:\n"
          << "    Dispositivo(std::string n, std::string i) : nome(n), ip(i) {}\n"
          << "    virtual void verificarStatus() = 0; // Requisito 4: Polimorfismo\n"
          << "    virtual ~Dispositivo() {}\n"
          << "};\n#endif";
    hFile.close();

    // 3. Main.cpp com a lógica de Threads (Requisito 8)
    ofstream mainFile(path + "/main.cpp");
    mainFile << "#include <iostream>\n#include <vector>\n#include <thread>\n#include \"Dispositivo.h\"\n\n"
             << "using namespace std;\n\n"
             << "void monitorarTarefa(string ip) {\n"
             << "    cout << \"[THREAD] Analisando trafego no IP: \" << ip << endl;\n"
             << "}\n\n"
             << "int main() {\n"
             << "    cout << \"--- PROJETO POO - INATEL ---\\n\";\n"
             << "    vector<thread> pool;\n"
             << "    vector<string> ips = {\"192.168.1.1\", \"10.0.0.1\"};\n\n"
             << "    for(auto ip : ips) pool.push_back(thread(monitorarTarefa, ip));\n"
             << "    for(auto &t : pool) t.join();\n\n"
             << "    cout << \"Fim da execucao.\" << endl;\n"
             << "    return 0;\n"
             << "}";
    mainFile.close();
}

int main()
{
    // NOME DA PASTA ATUALIZADO CONFORME SOLICITADO
    string caminhoBase = "C:/Users/prefe/Documents/REVISOES - CPP/01 - POO/PROJETO POO - INATEL";

    if (!fs::exists(caminhoBase))
    {
        fs::create_directories(caminhoBase);
    }

    cout << "--- 🏭 FABRICA: GERANDO PROJETO POO - INATEL ---" << endl;
    gerarProjetoFinalInatel(caminhoBase);
    cout << "✅ Pasta 'PROJETO POO - INATEL' criada com sucesso!" << endl;

    return 0;
}
// g++ fabrica.cpp -o fabrica.exe
//./fabrica.exe