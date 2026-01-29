/*
==================================================
📘 PONTEIROS - LEVEL 1 - EX 05: Identidade
==================================================
[ORIGEM: Inteligência Artificial]

STATUS: TO DO
DIFICULDADE: Fácil (Level 1)

COMPETENCIAS:
- COMPARAÇÃO_DE_ENDEREÇOS
- COMPREENSÃO_DE_ALIAS (REFERÊNCIA)

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie um 'int original = 10'.
2. Crie uma referência 'int &ref = original'.
3. Imprima o endereço de '&original' e o endereço de '&ref'.
4. Verifique se os endereços são IDENTICOS.
--------------------------------------------------
*/

#include <iostream>

using namespace std;

int main()
{
    int original = 10;
    int &ref = original;

    cout << "Endereco de original: " << &original << endl;
    cout << "Endereco de ref:      " << &ref << endl;

    if (&original == &ref)
    {
        cout << "Os enderecos SAO IDENTICOS." << endl;
    }
    else
    {
        cout << "Os enderecos SAO DIFERENTES." << endl;
    }

    return 0;
}
