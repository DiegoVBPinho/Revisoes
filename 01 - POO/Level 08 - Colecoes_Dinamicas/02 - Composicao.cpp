/*
==================================================
📘 02 - RELAÇÕES - EXERCICIO 02: Composição
==================================================
[ORIGEM: Professor Christopher]

STATUS: TO DO

COMPETENCIAS:
- RELACIONAMENTO_FORTE
- CICLO_DE_VIDA_DEPENDENTE
- INSTANCIACAO_INTERNA

🧠 O QUE É COMPOSIÇÃO? (Aula 11)
É uma relação "forte". O objeto contido (ex: Motor) pertence EXCLUSIVAMENTE 
ao objeto dono (ex: Carro). Se o Carro for destruído, o Motor morre com ele.

⚠️ DIFERENÇA CHAVE: 
Na Composição, o objeto dependente costuma ser instanciado DENTRO 
do construtor da classe dona.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie a classe 'Motor' (potencia).
2. Crie a classe 'Carro' que possui um objeto 'Motor' (não ponteiro, o objeto direto).
3. No construtor de 'Carro', inicialize o 'Motor'.
4. Mostre que ao acessar o carro, você acessa as propriedades do motor.
--------------------------------------------------
*/

#include <iostream>

using namespace std;

// Desenvolva as classes aqui:

int main()
{
    return 0;
}
