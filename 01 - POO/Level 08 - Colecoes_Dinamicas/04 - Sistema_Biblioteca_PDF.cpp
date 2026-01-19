/*
==================================================
📘 04 - SISTEMA BIBLIOTECA (UML DO PDF)
==================================================
[ORIGEM: Professor Christopher - Arquivo Biblioteca.pdf]

STATUS: TO DO

COMPETENCIAS:
- IMPLEMENTACAO_DE_DIAGRAMA_UML
- COMPOSICAO (Livro tem Autor)
- AGREGACAO (Biblioteca tem lista de Livros)
- ASSOCIACAO_DE_METODOS (Pessoa interage com Livro)

🧠 ANALISE DO DIAGRAMA:
Este exercício é a prova final de que entendeste como os objetos conversam.
1. Classe 'Autor': Atributos nome e nacionalidade.
2. Classe 'Livro': Atributo titulo e o objeto Autor (Composição).
3. Classe 'Biblioteca': Deve gerenciar um vector de ponteiros para Livros.
4. Classe 'Pessoa': Métodos para emprestar e devolver que alteram o status do Livro.
--------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Implementa a estrutura baseada no Biblioteca.pdf aqui:

int main() {
    cout << "--- Desafio Biblioteca.pdf Iniciado ---" << endl;
    return 0;
}
