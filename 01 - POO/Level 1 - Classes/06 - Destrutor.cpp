/*
==================================================
📘 LEVEL 1 - POO - EXERCICIO 05/10: DESTRUTOR
==================================================

STATUS: TO DO

COMPETENCIAS:
- DESTRUTOR_CONCEITO
- CICLO_DE_VIDA_OBJETO

🧠 O QUE É UM DESTRUTOR?
O Destrutor é um método especial que é executado automaticamente
quando um objeto é destruído (quando a função main termina ou
o objeto sai do escopo).

Ele é usado para liberar memória ou avisar que o objeto sumiu.

--------------------------------------------------

🧠 COMO DECLARAR UM DESTRUTOR?

1. Use o símbolo til `~` seguido do nome da classe.
2. Ele NÃO tem tipo de retorno (nem void).
3. Ele NÃO recebe parâmetros.

Exemplo de Sintaxe:

class Item {
public:
    ~Item() {
        std::cout << "Item destruído!" << std::endl;
    }
};

--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Zumbi'.
2. No 'public:', crie um Destrutor `~Zumbi()`.
3. Dentro do Destrutor, imprima: "Zumbi removido da memoria!" usando std::cout.
4. No 'main':
   - Apenas instancie um zumbi: `Zumbi z1;`.
   - Não precisa chamar o destrutor manualmente.
   - Ao rodar, você verá a mensagem aparecer no final da execução.

--------------------------------------------------

🔹 TESTES (Entrada e Saida Esperadas)
--------------------------------------------------
ENTRADA:
Execução do programa

SAIDA ESPERADA:
Zumbi removido da memoria!
--------------------------------------------------
*/

#include <iostream>

