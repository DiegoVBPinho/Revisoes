/*
==================================================
📘 LEVEL 1 - POO - EXERCICIO 02/10: O OBJETO
==================================================

STATUS: TO DO

COMPETENCIAS:
- INSTANCIACAO
- ACESSO_MEMBRO

🧠 O QUE É UM OBJETO?
Se a Classe é a planta da casa, o Objeto é a casa construída.
Instanciar significa "criar um objeto a partir de uma classe".

Quando criamos um objeto, o computador reserva um espaço na
memória para guardar as informações daquele objeto específico.

--------------------------------------------------

🧠 COMO CRIAR UM OBJETO E ACESSAR SEUS DADOS?

Passo 1️⃣ — Declare a classe (como você fez no exercício anterior).
Passo 2️⃣ — No main, use o Nome da Classe como se fosse um "tipo".
Passo 3️⃣ — Use o operador ponto `.` para acessar os atributos.

Exemplo de Sintaxe:

MinhaClasse objeto;      // Criando o objeto
objeto.atributo = 10;    // Dando um valor para ele

--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Zumbi'.
2. Dentro dela, coloque `public:` e um atributo `int vida`.
3. No `main()`, crie um objeto da classe Zumbi chamado 'z1'.
4. Atribua o valor 100 para a `vida` do 'z1'.
5. Imprima o valor da vida do zumbi usando `std::cout`.

--------------------------------------------------

🔹 TESTES (Entrada e Saida Esperadas)
--------------------------------------------------
ENTRADA:
<Nenhuma>

SAIDA ESPERADA:
Vida do Zumbi: 100
--------------------------------------------------
*/

#include <iostream>

class Zumbi
{
public:
    int vida;
};

int main()
{
    Zumbi z1;
    z1.vida = 100;

    std::cout << "Vida do Zumbi: " << z1.vida << std::endl;

    return 0;
}