/*
==================================================
📘 LEVEL 1 - POO - EXERCICIO 04/10: ATRIBUTOS
==================================================

STATUS: TO DO

COMPETENCIAS:
- MULTIPLOS_ATRIBUTOS
- TIPAGEM_NA_CLASSE

🧠 O QUE SÃO ATRIBUTOS?
Atributos são as características do seu objeto.
Em um jogo, um personagem não tem apenas "vida".
Ele tem força, nome, agilidade, etc.

Todos esses dados ficam agrupados dentro do mesmo "molde" (Classe).

--------------------------------------------------

🧠 COMO DECLARAR MÚLTIPLOS ATRIBUTOS?

Basta listá-los dentro do bloco public:, definindo o tipo e o nome.

Exemplo de Sintaxe:

class Item {
public:
    int id;
    double preco;
    bool emEstoque;
};

--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Zumbi'.
2. Adicione três atributos públicos:
   - 'int vida'
   - 'int forca'
   - 'char tipo' (para indicar se é tipo 'A', 'B', etc)
3. No 'main':
   - Instancie o zumbi 'z1'.
   - Atribua: vida = 80, forca = 15, tipo = 'Z'.
   - Imprima os três valores usando std::cout, um em cada linha.

--------------------------------------------------

🔹 TESTES (Entrada e Saida Esperadas)
--------------------------------------------------
ENTRADA:
vida=80, forca=15, tipo='Z'

SAIDA ESPERADA:
Vida: 80
Força: 15
Tipo: Z
--------------------------------------------------
*/

#include <iostream>
