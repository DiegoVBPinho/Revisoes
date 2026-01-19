/*
==================================================
📘 01 - ARQUITETURA - EXERCICIO 01: Namespaces
==================================================

STATUS: TO DO

COMPETENCIAS:
- NAMESPACE_CONCEITO
- ORGANIZACAO_LOGICA
- OPERADOR_DE_ESCOPO (::)

🧠 O QUE É UM NAMESPACE? (Aula 06)
Imagine que o Namespace é uma "pasta" ou "caixa" dentro do código. 
No Java, usamos 'package'. No C++, usamos 'namespace'.
Sua função é evitar que nomes iguais se batam.

--------------------------------------------------
SINTAXE BÁSICA C++:

namespace MeuGrupo {
    class MinhaClasse { ... };
}

Uso: MeuGrupo::MinhaClasse objeto;
--------------------------------------------------

🎯 OBJETIVO DO EXERCICIO:
1. Crie um namespace chamado 'Inatel'.
2. Dentro dele, crie a classe 'Matematica' com um atributo: string versao.
3. Na função main:
   - Instancie a classe usando o caminho completo (Inatel::Matematica).
   - Atribua uma versão (ex: "1.0") e exiba no console.

--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

// Desenvolva seu namespace e classe aqui:

int main()
{
    // Instancie e exiba aqui:

    return 0;
}
