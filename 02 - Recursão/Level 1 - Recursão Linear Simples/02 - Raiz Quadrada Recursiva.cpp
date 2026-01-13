/*
==================================================
📘 EXERCÍCIO DA IMAGEM: RAIZ QUADRADA RECURSIVA
==================================================

🎯 OBJETIVO:
Calcular a raiz quadrada de um número 'x' usando
um algoritmo de aproximação recursiva.

Parâmetros:
   x  = número que queremos a raiz
   x0 = estimativa inicial
   e  = margem de erro (epsilon)

Fórmula dada:
   - Caso Base: Se |x0*x0 - x| <= e, retorna x0.
   - Recursão:  Se não, chama a função novamente atualizando
                o x0 para: (x0*x0 + x) / (2*x0).

OBS: O resultado deve ter 4 casas decimais.

📥 ENTRADA ESPERADA (Testes):
   125 1 0.001
   5 1 0.0001

📤 SAÍDA ESPERADA:
   11.1803
   2.2361
==================================================
*/
