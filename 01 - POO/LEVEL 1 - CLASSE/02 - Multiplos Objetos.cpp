/*
==================================================
📘 01 - POO - EXERCICIO 02/05: Múltiplos Objetos
==================================================

STATUS: DONE

COMPETENCIAS:
- INSTANCIACAO
- ATRIBUTOS
- LOGICA_POO

🧠 INSTANCIANDO VÁRIOS OBJETOS
Uma classe é apenas o molde. Você pode criar quantos objetos quiser
a partir do mesmo molde. Cada objeto terá seus próprios valores nos atributos.

Exemplo:
Guerreiro g1; // Objeto 1
Guerreiro g2; // Objeto 2

g1.nome = "Arthur";
g2.nome = "Lancelot";

--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Use a mesma classe 'Guerreiro' do exercício anterior.
2. Na main, instancie DOIS guerreiros diferentes.
3. Atribua nomes diferentes para cada um.
4. Adicione um atributo 'vida' (int) na classe.
5. Exiba o nome e a vida de ambos no console.

--------------------------------------------------

🔹 TESTES (Entrada e Saida Esperadas)
--------------------------------------------------
Entrada: <Nenhuma>
Saida:
Guerreiro 1: Arthur (100 HP)
Guerreiro 2: Lancelot (80 HP)
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

class Guerreiro
{
public:
    string nome;
    int vida;

    void status()
    {
        cout << "Guerreiro: " << nome << " (" << vida << " HP)" << endl;
    }
};

int main()
{
    // Instancie dois objetos e atribua valores aqui

    return 0;
}