/*
==================================================
📘 EXERCÍCIO DE FIXAÇÃO – ALOCAÇÃO DINÂMICA
==================================================

🎯 OBJETIVO:
Aprender a alocar (criar) e desalocar (destruir)
memória manualmente usando 'new' e 'delete'.

--------------------------------------------------
⚙️ FLUXO DE EXECUÇÃO
--------------------------------------------------
1. Declarar um ponteiro nulo (para segurança).
2. Usar 'new' para pedir um espaço de inteiro ao sistema.
3. Guardar um valor lá dentro.
4. Usar 'delete' para devolver a memória.
==================================================
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "--- Gerenciamento Manual de Memoria ---" << endl;

    // 1. DECLARAR PONTEIRO SEGURO
    // TODO: Declare um ponteiro de int chamado 'ptrInimigo'
    // IMPORTANTE: Inicialize ele com 'nullptr'
    // Ex: int *p = nullptr;
    int *ptrInimigo = nullptr;

    // 2. ALOCAÇÃO (O PEDIDO)
    // TODO: Use o comando 'new' para criar um inteiro na memória
    // Ex: variavelPonteiro = new int;
    ptrInimigo = new int;

    // 3. USO DA MEMÓRIA
    // TODO: Agora que a memória existe, guarde o valor 500 nela
    // Lembre-se: Use *ptrInimigo para acessar o valor
    *ptrInimigo = 500;

    // Mostrando o resultado
    cout << "Inimigo criado na Heap com vida: " << *ptrInimigo << endl;

    // 4. DESALOCAÇÃO (A LIMPEZA)
    // TODO: Destrua a memória alocada usando 'delete'
    // Ex: delete nomeDoPonteiro;
    delete ptrInimigo;

    // 5. BOAS PRÁTICAS
    // TODO: Aponte 'ptrInimigo' para nullptr novamente
    // (Para garantir que ele não aponte para lixo de memória)

    ptrInimigo = nullptr;

    cout << "Memoria limpa. Fim do programa." << endl;

    return 0;
}