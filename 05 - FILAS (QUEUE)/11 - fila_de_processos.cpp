/*
==================================================
📘 FILAS - 11: Simulação de Escalonador (Round Robin)
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Difícil

COMPETENCIAS:
- SIMULAÇÃO_SISTEMA_OPERACIONAL
- LÓGICA_DE_CICLOS

🧠 CONCEITO:
Sistemas Operacionais usam filas para decidir qual processo usa a CPU.
Se um processo não termina no tempo dele, ele volta para o fim da fila.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma struct 'Processo' (ID, tempoRestante).
2. Coloque 3 processos na fila.
3. Em um loop, retire o da frente, diminua 2 segundos do seu tempo.
4. Se tempoRestante > 0, coloque-o de volta no fim (tras).

📥 ENTRADA: P1(5s), P2(2s), P3(4s).
📤 SAIDA ESPERADA: "Executando P1... P1 voltou para a fila. Executando P2... P2 finalizado!"
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    return 0;
}