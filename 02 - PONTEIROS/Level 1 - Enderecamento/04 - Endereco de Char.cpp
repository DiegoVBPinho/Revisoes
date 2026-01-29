/*
==================================================
📘 PONTEIROS - LEVEL 1 - EX 04: Endereço de Char
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Fácil (Level 1)

COMPETENCIAS:
- TRABALHO_COM_CHARS
- CASTING_DE_PONTEIRO (Opcional)

⚠️ CUIDADO: O 'cout' tenta imprimir a string quando vê um ponteiro de char.
Para ver o endereço, as vezes precisamos de um pequeno truque.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie 'char inicial = 'G''.
2. Crie um ponteiro para essa inicial.
3. Imprima o endereço de memória da inicial.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    char inicial = 'G';
    char *pInicial = &inicial; // ponteiro aponta para o endereço

    // imprimindo endereço

    cout << "Endereço da Inicial com (VOID*): " << (void *)pInicial << endl; //
    cout << "Endereço da Inicial usando &: " << &pInicial;                   //
    return 0;
}

// lembrar sempre que parenteses tem prioridade.
// void * faz: “Ei, cout, isso aqui é só um endereço cru.
// Não tenta imprimir como texto.