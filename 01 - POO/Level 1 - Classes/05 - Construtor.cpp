/*
==================================================
📘 LEVEL 1 - POO - EXERCICIO 05/10: CONSTRUTOR
==================================================

STATUS: TO DO

COMPETENCIAS:
- CONSTRUTOR_PADRAO
- INICIALIZACAO_OBJETO

🧠 O QUE É UM CONSTRUTOR?
O Construtor é um método especial que é executado AUTOMATICAMENTE
no momento em que o objeto é criado. Ele serve para garantir que
o objeto comece com valores válidos (ex: vida não começar vazia).

--------------------------------------------------

🧠 COMO DECLARAR UM CONSTRUTOR?

1. Ele deve ter exatamente o MESMO NOME da classe.
2. Ele NÃO tem tipo de retorno (nem mesmo void).
3. Ele deve ser público.

Exemplo de Sintaxe:

class Item {
public:
    Item() {
        // Código de inicialização aqui
        std::cout << "Item criado!" << std::endl;
    }
};

--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Zumbi'.
2. Adicione um atributo público: `int vida`.
3. Crie um Construtor `Zumbi()`.
4. Dentro do Construtor:
   - Defina `vida = 100`.
   - Imprima "Zumbi nasceu!" usando std::cout.
5. No 'main':
   - Apenas instancie um zumbi: `Zumbi z1;`.
   - Imprima a vida do zumbi para provar que o construtor funcionou.

--------------------------------------------------

🔹 TESTES (Entrada e Saida Esperadas)
--------------------------------------------------
ENTRADA:
Instanciar Zumbi z1

SAIDA ESPERADA:
Zumbi nasceu!
Vida inicial: 100
--------------------------------------------------
*/

#include <iostream>
