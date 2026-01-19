/*
==================================================
📘 01 - THREADS - EXERCICIO 01: Criação Básica
==================================================
[ORIGEM: Professor Christopher]

STATUS: TO DO

COMPETENCIAS:
- BIBLIOTECA_THREAD
- FUNCOES_ASSINCRONAS
- METODO_JOIN

🧠 O QUE SÃO THREADS? (Aula de Concorrência)
Uma thread é como uma "linha de execução". Normalmente o C++ roda uma por uma. 
Com threads, podemos disparar uma função e continuar fazendo outra coisa no main.

⚠️ REGRA DE OURO: 
Sempre use o método '.join()' no main para esperar a thread terminar antes 
do programa fechar, caso contrário o Windows forçará o encerramento com erro.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO:
1. Crie uma função chamada 'tarefaPesada()' que exibe "Trabalhando..." 5 vezes.
2. No main, dispare essa função usando 'std::thread t1(tarefaPesada)'.
3. Use 't1.join()' para garantir que o main espere a conclusão.
--------------------------------------------------
*/

#include <iostream>
#include <thread>

using namespace std;

int main()
{
    return 0;
}
