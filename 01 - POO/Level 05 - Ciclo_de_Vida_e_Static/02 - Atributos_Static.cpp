/*
==================================================
📘 02 - CICLO DE VIDA - EXERCICIO 02: Atributos Static
==================================================

STATUS: TO DO

COMPETENCIAS:
- ATRIBUTOS_STATIC
- ESCOPO_DE_CLASSE
- MEMORIA_COMPARTILHADA

🧠 O QUE É STATIC? (Aula 08)
Atributos 'static' não pertencem ao objeto, mas sim à CLASSE.
Imagine um contador de alunos: ele não pode zerar cada vez que um 
novo aluno nasce. Ele deve ser um só para todos.

⚠️ REGRA DE OURO DO C++ (Diferente do Java):
Atributos estáticos DEVEM ser inicializados fora da classe, 
usando o operador de escopo ::. 
Ex: int Aluno::contador = 0;

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie a classe 'Estudante'.
2. Adicione um atributo static privado: 'totalEstudantes'.
3. No construtor da classe, incremente (++) esse contador.
4. Crie um método static 'getTotal()' para retornar o valor.
5. No main, crie 3 estudantes e exiba o total através da classe.
--------------------------------------------------
*/

#include <iostream>

using namespace std;

// Desenvolva sua classe aqui:

// IMPORTANTE: Inicialize o static aqui fora!

int main()
{
    return 0;
}
