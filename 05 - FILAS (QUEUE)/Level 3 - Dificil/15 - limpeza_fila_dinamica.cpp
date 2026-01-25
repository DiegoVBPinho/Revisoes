/*
==================================================
📘 FILAS - 15: O Destruidor de Fila
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Difícil (O Mestre da Fila)

COMPETENCIAS:
- GESTÃO_DE_MEMÓRIA (Heap)
- DESTRUTORES_C++

⚠️ REGRA DE OURO:
Em filas dinâmicas, o destrutor deve percorrer do 'frente' ao 'tras',
deletando cada nó individualmente para não deixar lixo na RAM.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Implemente o destrutor `~Fila()`.
2. O destrutor deve chamar `desenfileirar()` até que a fila esteja vazia.
3. Cada vez que um nó for deletado, imprima seu endereço de memória.

📥 ENTRADA: Criar fila dinâmica, enfileirar 5 itens e encerrar programa.
📤 SAIDA ESPERADA: "Limpando... [0x...] deletado. Fila destruida."
--------------------------------------------------
*/

#include <iostream>

using namespace std;

int main()
{
    return 0;
}