/*
==================================================
📘 LEVEL 1 - POO - EXERCICIO 03/10: O MÉTODO
==================================================

STATUS: TO DO

COMPETENCIAS:
- METODOS_CONCEITO
- COMPORTAMENTO_OBJETO

🧠 O QUE É UM MÉTODO?
Um método é uma função que vive dentro de uma classe.
Enquanto os Atributos dizem o que o objeto É (características),
os Métodos dizem o que o objeto FAZ (comportamentos).

Pense assim:
- Atributo: vida, cor, nome.
- Método: andar(), atacar(), rugir().

--------------------------------------------------

🧠 COMO SE CRIA E CHAMA UM MÉTODO EM C++?

Passo 1️⃣ — Dentro da classe (na área public:), declare como uma função.
Passo 2️⃣ — No main, chame o método usando o operador ponto `.` seguido de parênteses.

Exemplo de Sintaxe:

class Pessoa {
public:
    void saudar() {
        std::cout << "Olá!" << std::endl;
    }
};

// No main:
Pessoa p;
p.saudar();

--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie uma classe chamada 'Zumbi'.
2. Adicione o atributo `public: int vida`.
3. Crie um método chamado `void rugir()` dentro da classe.
4. O método `rugir()` deve imprimir "WRRRRRRAGGGHHH!" usando std::cout.
5. No `main`, instancie o zumbi 'z1', atribua 100 de vida e chame o método `z1.rugir()`.

--------------------------------------------------

🔹 TESTES (Entrada e Saida Esperadas)
--------------------------------------------------
ENTRADA:
<Nenhuma>

SAIDA ESPERADA:
WRRRRRRAGGGHHH!
--------------------------------------------------
*/

#include <iostream>

// ESCREVA SEU CODIGO ABAIXO:
Manda o código quando terminar para eu validar e a gente pular para o próximo !