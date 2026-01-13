/*
==================================================
📘 EXERCÍCIO DE FIXAÇÃO – ARRAYS DINÂMICOS
==================================================

🎯 OBJETIVO:
Criar um array cujo tamanho é definido pelo usuário
durante a execução (Runtime), e não no código fixo.

--------------------------------------------------
⚙️ FLUXO DE EXECUÇÃO
--------------------------------------------------
1. Perguntar ao usuário: "Quantos soldados você quer?"
2. Ler esse número numa variável inteira.
3. Usar 'new int[quantidade]' para criar o array.
4. Preencher o array usando um loop (for).
5. IMPORTANTE: Usar 'delete[]' para limpar tudo.
==================================================
*/

#include <iostream>

using namespace std;

int main()
{
    int tamanho;

    cout << "--- Criacao de Exercito Dinamico ---" << endl;
    cout << "Quantos soldados voce quer criar? ";
    cin >> tamanho;

    // 1. ALOCAÇÃO DE ARRAY (O PEDIDO EM MASSA)
    // TODO: Declare um ponteiro 'ptrSoldados'.
    // TODO: Faça ele receber 'new int[tamanho]' (Use colchetes!)
    // Ex: int *p = new int[variavelTamanho];
    int *ptrSoldados = nullptr;
    ptrSoldados = new int[tamanho];

    // 2. PREENCHENDO O ARRAY
    // Vamos dar 100 de vida para cada um.
    for (int i = 0; i < tamanho; i++)
    {
        // TODO: Acessar a posição i do ponteiro e colocar 100
        // Dica: Ponteiros funcionam igual arrays aqui: ptrSoldados[i] = ...
        ptrSoldados[i] = 100;
    }

    // 3. MOSTRANDO (Só para conferir o último)
    cout << "Ultimo soldado (posicao " << tamanho - 1 << ") tem vida: ";
    cout << ptrSoldados[tamanho - 1] << endl;

    // 4. DESALOCAÇÃO DE ARRAY (ATENÇÃO AQUI!)
    // TODO: Use 'delete[]' (com colchetes vazios) para apagar o array todo.
    // Ex: delete[] nomeDoPonteiro;
    // Se esquecer os [], apaga só o primeiro soldado e vaza memória!

    delete[] ptrSoldados;

    // 5. SEGURANÇA
    ptrSoldados = nullptr;

    cout << "Exercito dispensado. Memoria limpa." << endl;

    return 0;
}