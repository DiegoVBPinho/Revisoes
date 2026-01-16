#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

struct ExercicioData
{
    std::string arquivo;
    std::string titulo;
    std::string tutor;
    std::string objetivo;
};

void gerarArquivo(const ExercicioData &ex)
{
    std::string pasta = "Level 01 - Introducao_a_POO";
    if (!fs::exists(pasta))
        fs::create_directories(pasta);

    std::string caminho = pasta + "/" + ex.arquivo;
    if (fs::exists(caminho))
        return;

    std::ofstream f(caminho);
    f << "/*\n"
      << "==================================================\n"
      << "📘 AULA 04 - " << ex.titulo << "\n"
      << "==================================================\n\n"
      << "STATUS: TO DO\n\n"
      << "🧠 TUTOR EXPLICA:\n"
      << ex.tutor << "\n\n"
      << "💻 SINTAXE (Sem namespace std):\n"
      << "std::cout << \"Texto\" << std::endl;\n"
      << "std::string variavel;\n\n"
      << "🎯 OBJETIVO:\n"
      << ex.objetivo << "\n"
      << "--------------------------------------------------\n"
      << "*/\n\n"
      << "#include <iostream>\n"
      << "#include <string>\n\n"
      << "int main() {\n"
      << "    // Desenvolva seu codigo aqui seguindo o objetivo\n"
      << "    return 0;\n"
      << "}\n";
    f.close();
}

int main()
{
    std::vector<ExercicioData> lista = {
        {"Ex 1 - Zumbis_Basico.cpp", "Exercicio 1: Zumbis",
         "Uma classe representa o que um objeto sabe sobre si (atributos) e o que sabe fazer (metodos).",
         "Crie uma classe Zumbi. Defina atributos e metodos. Na main, invoque as acoes."},

        {"Ex 2 - Zumbis_UML.cpp", "Exercicio 2: Modelagem UML",
         "O UML ajuda a visualizar a estrutura da classe antes de codar.",
         "Refine sua classe Zumbi baseada no diagrama UML do slide 51."},

        {"Ex 3 - Zumbis_Referencias.cpp", "Exercicio 3: Referencias",
         "Quando fazemos z1 = z2, as duas variaveis apontam para o mesmo objeto na memoria.",
         "Crie dois zumbis. Apos manipular a vida, faca z1 = z2 e verifique o resultado."},

        {"Ex 4 - Zumbis_Transferencia.cpp", "Exercicio 4: Validacao",
         "Metodos podem retornar valores (bool, int) para confirmar se uma acao deu certo.",
         "Crie um metodo que transfere vida entre zumbis e retorna true se der certo."},

        {"Ex 5 - Jogo_Dano.cpp", "Exercicio 5: Sistema de Jogo",
         "Objetos interagem entre si alterando seus estados internos (vida/resistencia).",
         "Personagem perde 5 de vida ao tomar dano e Arma perde 2 de resistencia ao usar."},

        {"Ex 6 - Mario_Kart.cpp", "Exercicio 6: Mario Kart",
         "Classes diferentes (Kart e Piloto) podem se relacionar para formar um sistema.",
         "Crie Kart e Piloto. Atribua cilindradas (50, 100, 150) e velocidades."}};

    std::cout << "--- 🏭 FABRICA DE EXERCICIOS: AULA 04 ---" << std::endl;
    for (const auto &ex : lista)
    {
        gerarArquivo(ex);
        std::cout << "✔ Arquivo gerado: " << ex.arquivo << std::endl;
    }
    std::cout << "\n✅ Pronto! Os 6 exercicios estao na pasta 'Level 01 - Introducao_a_POO'." << std::endl;

    return 0;
}