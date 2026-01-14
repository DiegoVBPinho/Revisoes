/*
==================================================
📘 EXERCÍCIO DE FIXAÇÃO – PONTEIROS E ARRAYS
==================================================

🎯 OBJETIVO:
Usar um ponteiro para percorrer um array (vetor)
manualmente, pulando de casa em casa na memória.

--------------------------------------------------
⚙️ FLUXO DE EXECUÇÃO
--------------------------------------------------
1. Temos um array 'danos' com 3 valores: {15, 30, 50}
2. Você vai apontar para o início dele.
3. Vai imprimir o primeiro.
4. Vai fazer o ponteiro andar (++) para o segundo.
5. Vai fazer o ponteiro andar (++) para o terceiro e alterar o valor.
==================================================
*/

#include <iostream>

using namespace std;

int main()
{
    // 1. LISTA DE DANOS (Vetor fixo)
    int danos[3] = {15, 30, 50};

    cout << "--- Inicio do Combate ---" << endl;

    // 2. DECLARAR E VINCULAR
    // TODO: Declare um ponteiro de int chamado 'ptrDano'
    // TODO: Aponte ele para 'danos'.
    // Dica: Em arrays, o nome 'danos' JÁ É o endereço. Não use &.
    // Ex: int *p = nomeDoVetor;
    int *ptrDano;
    ptrDano = danos;

    // 3. PRIMEIRO GOLPE
    // TODO: Imprima o valor apontado por ptrDano (deve ser 15)
    cout << "Primeiro golpe: " << *ptrDano << endl;

    // 4. AVANÇANDO A MEMÓRIA
    // TODO: Incremente o ponteiro para ele pular para o próximo numero
    // Dica: use o operador ++ no nome do ponteiro
    ptrDano++; // "Andar sem espiar" Vetor[1]

    // 5. SEGUNDO GOLPE
    // TODO: Imprima o valor apontado por ptrDano AGORA (deve ser 30)
    cout << "Segundo golpe: " << *ptrDano << endl;

    // 6. MODIFICANDO O ÚLTIMO
    // TODO: Avance o ponteiro mais uma vez (para chegar no 50)
    ptrDano++; // Andar sem espiar Vetor[2]

    // TODO: Agora mude o valor desse terceiro item para 999 (Crítico!) usando o ponteiro (*ptr...)
    *ptrDano = 999;

    // VERIFICAÇÃO FINAL
    cout << "Terceiro golpe (Critico 999): " << danos[2] << endl;

    return 0;
}