/*
==================================================
📘 01 - ACESSO - EXERCICIO 01: Modificadores
==================================================

STATUS: TO DO

COMPETENCIAS:
- PUBLIC_VS_PRIVATE
- ENCAPSULAMENTO_BASICO
- SEGURANCA_DE_DADOS

🧠 MODIFICADORES DE ACESSO (Aula 07)
Um expert não deixa tudo público. 
1. PUBLIC: Qualquer um acessa (a vitrine da loja).
2. PRIVATE: Só a própria classe acessa (o cofre da loja).

Esconder os atributos e mostrar apenas métodos é a base do Encapsulamento.

--------------------------------------------------
SINTAXE BÁSICA C++:

class Conta {
private:
    double saldo; // Ninguém fora da classe altera isso direto
public:
    void depositar(double valor) { saldo += valor; }
};
--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie a classe 'ContaBancaria'.
2. Coloque o atributo 'saldo' como PRIVATE.
3. Crie métodos PUBLIC para 'depositar' e 'verSaldo'.
4. No main, tente alterar o saldo diretamente e veja o erro de compilação.
5. Corrija usando os métodos.
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

// Desenvolva sua classe aqui:

int main()
{
    return 0;
}
