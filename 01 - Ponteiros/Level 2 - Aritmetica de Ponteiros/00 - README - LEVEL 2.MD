/*
================================================================================
# 📝 TRACKER LEVEL 2 - ARITMÉTICA DE PONTEIROS
================================================================================

| Status | ID | Ícone | Nome                | Foco                             |
| :----: | :- | :---: | :------------------ | :------------------------------- |
|  [x]   | 01 |  🔭   | O Salto Dimensional | Acesso via Deslocamento *(p+n)   |
|  [x]   | 02 |  🧭   | O Navegador         | Iteração Incremental p++         |
|  [ ]   | 03 |  🔙   | A Marcha Ré         | Iteração Decremental p--         |
|  [ ]   | 04 |  🦘   | O Canguru           | Incremento Não-Unitário p+=2     |
|  [ ]   | 05 |  📏   | A Régua             | Diferença de Ponteiros           |
|  [ ]   | 06 |  🧱   | O Preenchimento     | Atribuição em Massa              |
|  [ ]   | 07 |  📠   | O Copiador          | Cópia entre Buffers              |
|  [ ]   | 08 |  🚨   | O Sentinela         | Busca com Parada                 |
|  [ ]   | 09 |  🎯   | O Rastreador        | Rastrear Endereço vs Valor       |
|  [ ]   | 10 |  🤐   | A Palavra Secreta   | String C-Style \0                |


================================================================================
🧠 CHECKLIST DE COMPETÊNCIAS: LEVEL 2
O que eu preciso dominar para zerar os 10 exercícios de Aritmética.
================================================================================

📌 1. NAVEGAÇÃO BÁSICA (Caminhando na Memória)
   Necessário para os Exercícios 1, 2, 3 e 4.

[x] Deslocamento: Sei acessar um valor à frente sem mover o ponteiro original,
    usando matemática: *(p + 2).
[x] Incremento: Sei usar p++ para mover o ponteiro para a próxima casa do array.
[ ] Decremento: Sei usar p-- para voltar casas na memória.
[ ] Salto: Sei usar p += 2 (ou mais) para pular casas e acessar índices específicos.


🎮 2. INTERAÇÃO ENTRE PONTEIROS (Relatividade)
   Necessário para os Exercícios 5 e 7.

[ ] Distância: Sei que subtrair dois ponteiros (p_fim - p_inicio) me dá a
    quantidade de elementos entre eles (não o número de bytes).
[ ] Sincronia: Sei manipular dois ponteiros ao mesmo tempo (um na origem,
    outro no destino) dentro do mesmo loop.


🔄 3. ARRAYS & BUFFERS (Manipulação em Massa)
   Necessário para os Exercícios 6 e 9.

[ ] Preenchimento: Sei usar um loop e um ponteiro para escrever valores em
    todas as posições de um array vazio.
[ ] Rastreio: Sei a diferença entre guardar o maior valor e guardar o
    endereço do maior valor (p_maior = p_atual).


🛡️ 4. LIMITES & STRINGS (Onde Parar)
   Necessário para os Exercícios 8 e 10.

[ ] Sentinela Numérico: Sei criar loops que param quando o ponteiro encontra
    um número específico (ex: -1).
[ ] Sentinela de Texto: Sei que toda string estilo C termina com '\0' (null)
    e sei usar isso como condição de parada no while ou for.
*/