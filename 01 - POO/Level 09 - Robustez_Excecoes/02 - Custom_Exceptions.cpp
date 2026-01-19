/*
==================================================
📘 02 - EXCEÇÕES - EXERCICIO 02: Classes de Erro
==================================================
[ORIGEM: Professor Christopher]

STATUS: TO DO

COMPETENCIAS:
- STD_EXCEPTION
- OVERRIDE_WHAT
- CUSTOM_EXCEPTIONS

🧠 CLASSES DE EXCEÇÃO (Aula 12)
Profissionais criam classes que herdam de 'std::exception'. 
Isso permite organizar erros por categorias (Erro de Banco, Erro de Rede, etc).

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie a classe 'SaldoInsuficienteException' que herda de 'std::exception'.
2. Sobrescreva o método 'virtual const char* what() const throw()'.
3. Crie uma classe 'Conta' com saldo e um método 'sacar'.
4. Se o saque for maior que o saldo, lance a sua exceção personalizada.
--------------------------------------------------
*/

#include <iostream>
#include <exception>

using namespace std;

int main()
{
    return 0;
}
