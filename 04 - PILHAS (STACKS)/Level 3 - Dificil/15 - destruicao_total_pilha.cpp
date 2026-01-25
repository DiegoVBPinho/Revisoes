/*
==================================================
📘 PILHAS - 15: Gestão Crítica de Memória
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Difícil (O Mestre da Pilha)

COMPETENCIAS:
- PREVENÇÃO_DE_MEMORY_LEAK
- DESTRUTOR_DINÂMICO

⚠️ REGRA DE OURO:
Para pilhas dinâmicas (com ponteiros), o programa não pode fechar sem
limpar o Heap. O Destrutor deve ser implacável.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma Pilha Dinâmica (Nós).
2. Implemente o Destrutor `~Pilha()`.
3. O destrutor deve rodar um loop dando `delete` em cada Nó até o topo ser NULL.
4. Imprima "Endereço [0x...] liberado" para cada nó.

📥 ENTRADA: Criar pilha com 1000 elementos e fechar o escopo.
📤 SAIDA ESPERADA: Lista de endereços liberados e "Memoria Limpa".
--------------------------------------------------
*/

#include <iostream>

using namespace std;

int main()
{
    return 0;
}