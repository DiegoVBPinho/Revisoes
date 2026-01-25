/*
==================================================
📘 ESTRUTURA DE DADOS - 15: Destruição Total
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Difícil (O Mestre da Limpeza)

COMPETENCIAS:
- PREVENÇÃO_DE_MEMORY_LEAK
- RECURSIVIDADE_OU_LOOP_DE_DELEÇÃO

⚠️ REGRA DE OURO:
Nunca feche o programa sem deletar a lista nó por nó. Se você
apenas deletar o head, todos os outros nós ficarão "órfãos" na RAM.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma função 'void limparLista(No* &head)'.
2. Use um loop para percorrer a lista, salvando o próximo antes de deletar o atual.
3. No final, garanta que o head seja 'nullptr'.
4. Adicione um 'cout' dentro do loop para ver cada nó sendo destruído.

📥 ENTRADA: Lista com [1, 2, 3, 4, 5].
📤 SAIDA ESPERADA:
"Deletando no com valor 1..."
"Deletando no com valor 2..."
...
"Memoria totalmente limpa!"
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    return 0;
}