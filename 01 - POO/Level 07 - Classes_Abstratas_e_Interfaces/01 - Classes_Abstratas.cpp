/*
==================================================
📘 01 - ABSTRAÇÃO - EXERCICIO 01: Classe Abstrata
==================================================
[ORIGEM: Professor Christopher]

STATUS: TO DO

COMPETENCIAS:
- PURE_VIRTUAL_FUNCTIONS
- CLASSES_ABSTRATAS
- IMPOSSIBILIDADE_DE_INSTANCIA

🧠 O QUE É UMA CLASSE ABSTRATA? (Aula 10)
É uma classe que serve apenas de modelo. Você NÃO pode dar 'new' nela.
Ela existe para garantir que todos os filhos tenham certos métodos.

No C++, uma função pura virtual é declarada assim:
virtual void metodo() = 0;

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie a classe abstrata 'Forma'.
2. Adicione o método puro virtual 'virtual float calcularArea() = 0;'.
3. Crie a classe 'Quadrado' que herda de Forma e implementa o cálculo.
4. No main, tente instanciar 'Forma' (deve dar erro) e depois instancie o Quadrado.
--------------------------------------------------
*/

#include <iostream>

using namespace std;

// Desenvolva a classe abstrata e o filho aqui:

int main()
{
    return 0;
}
