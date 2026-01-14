# 📝 TRACKER LEVEL 1

| Status | ID | Ícone | Nome | Foco |

| [X] | 01 | 🪞 | O Espelho | Valor vs Endereço |
| [x] | 02 | 🤫 | A Soma Silenciosa | Somar via função |
| [x] | 03 | 🏠 | O Vizinho | Comparar Endereços |
| [x] | 04 | 👻 | Calc. Fantasma | Lógica só com ponteiro |
| [x] | 05 | 🛡️ | O Guardião | Segurança (nullptr) |
| [x] | 06 | 🆙 | O Upgrade | Precedência (*p)++ |
| [x] | 07 | 🔄 | O Trocador | Swap (Troca) |
| [x] | 08 | 🎁 | Cálculo Duplo | Retorno duplo |
| [] | 09 | 💡 | O Interruptor | Inverter Boolean |
| [] | 10 | 🔐 | A Criptografia | Aritmética Char |


🧠 CHECKLIST DE COMPETÊNCIAS: LEVEL 1
O que eu preciso dominar para zerar os 10 exercícios.

📌 1. FUNDAMENTOS (O Básico) - Necessário para os Exercícios  1 e 3.

[x] Declarar: Sei criar um ponteiro (int *ptr;).
[x] Endereçar: Sei usar o & para pegar o endereço de uma variável (ptr = &numero;).
[x] Diferenciar: Sei que o ponteiro guarda o endereço (onde mora) e a variável guarda o valor (o que tem dentro).
[x] Comparar: Sei comparar endereços (ptrA > ptrB) para ver a ordem na memória.

🎮 2. CONTROLE REMOTO (Manipulação) - Necessário para os Exercícios 2, 4 e 10.

[x] Acessar (Dereferenciar): Sei usar o * para ler o valor apontado (cout << *ptr).
[x] Alterar: Sei mudar o valor da variável original usando só o ponteiro (*ptr = 20;).
[x] Matemática: Sei fazer contas no valor apontado (*ptr = *ptr + 10;).
[x] ASCII: Sei que somar +1 num ponteiro de char muda a letra ('A' vira 'B').

🔄 3. FUNÇÕES & PODERES (O Pulo do Gato) - Necessário para os Exercícios 7, 8 e 9.

[x] Passar Endereço: Sei enviar o endereço na chamada da função (funcao(&x)).
[x] Receber Ponteiro: Sei declarar o parâmetro da função como ponteiro (void funcao(int* p)).
[x] Retorno Múltiplo: Sei usar ponteiros para fazer uma função "devolver" 2 ou mais resultados (modificando as variáveis originais).
[x] Swap (Troca): Sei usar uma variável auxiliar temp para trocar valores entre dois ponteiros.
[x] Lógica Booleana: Sei usar o operador ! (NOT) para alterar estados (true/false) em ponteiros.

🛡️ 4. SEGURANÇA & SINTAXE (Para não travar) - Necessário para os Exercícios 5 e 6.

[x] Nullptr: Sei que ponteiro sem dono deve ser igual a nullptr.
[x] Validação: Sei fazer o if (ptr != nullptr) antes de mexer no valor.
[x] Parênteses Sagrados: Entendo a diferença vital entre (*p)++ (soma valor) e *p++ (move endereço). Sei que os parênteses são obrigatórios para somar.