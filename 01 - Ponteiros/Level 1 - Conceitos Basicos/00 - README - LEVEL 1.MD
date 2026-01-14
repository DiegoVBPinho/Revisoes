# 📝 TRACKER LEVEL 1

| Status | ID | Ícone | Nome | Foco |

| [X] | 01 | 🪞 | O Espelho | Valor vs Endereço |
| [x] | 02 | 🤫 | A Soma Silenciosa | Somar via função |
| [ ] | 03 | 🏠 | O Vizinho | Comparar Endereços |
| [ ] | 04 | 👻 | Calc. Fantasma | Lógica só com ponteiro |
| [ ] | 05 | 🛡️ | O Guardião | Segurança (nullptr) |
| [ ] | 06 | 🆙 | O Upgrade | Precedência (*p)++ |
| [ ] | 07 | 🔄 | O Trocador | Swap (Troca) |
| [ ] | 08 | 🎁 | Cálculo Duplo | Retorno duplo |
| [ ] | 09 | 💡 | O Interruptor | Inverter Boolean |
| [ ] | 10 | 🔐 | A Criptografia | Aritmética Char |


🧠 CHECKLIST DE COMPETÊNCIAS: LEVEL 1
O que eu preciso dominar para zerar os 10 exercícios.

📌 1. FUNDAMENTOS (O Básico) - Necessário para os Exercícios  1 e 3.

[ ] Declarar: Sei criar um ponteiro (int *ptr;).
[ ] Endereçar: Sei usar o & para pegar o endereço de uma variável (ptr = &numero;).
[ ] Diferenciar: Sei que o ponteiro guarda o endereço (onde mora) e a variável guarda o valor (o que tem dentro).
[ ] Comparar: Sei comparar endereços (ptrA > ptrB) para ver a ordem na memória.

🎮 2. CONTROLE REMOTO (Manipulação) - Necessário para os Exercícios 2, 4 e 10.

[ ] Acessar (Dereferenciar): Sei usar o * para ler o valor apontado (cout << *ptr).
[ ] Alterar: Sei mudar o valor da variável original usando só o ponteiro (*ptr = 20;).
[ ] Matemática: Sei fazer contas no valor apontado (*ptr = *ptr + 10;).
[ ] ASCII: Sei que somar +1 num ponteiro de char muda a letra ('A' vira 'B').

🔄 3. FUNÇÕES & PODERES (O Pulo do Gato) - Necessário para os Exercícios 7, 8 e 9.

[ ] Passar Endereço: Sei enviar o endereço na chamada da função (funcao(&x)).
[ ] Receber Ponteiro: Sei declarar o parâmetro da função como ponteiro (void funcao(int* p)).
[ ] Retorno Múltiplo: Sei usar ponteiros para fazer uma função "devolver" 2 ou mais resultados (modificando as variáveis originais).
[ ] Swap (Troca): Sei usar uma variável auxiliar temp para trocar valores entre dois ponteiros.

🛡️ 4. SEGURANÇA & SINTAXE (Para não travar) - Necessário para os Exercícios 5 e 6.

[ ] Nullptr: Sei que ponteiro sem dono deve ser igual a nullptr.
[ ] Validação: Sei fazer o if (ptr != nullptr) antes de mexer no valor.
[ ] Parênteses Sagrados: Entendo a diferença vital entre (*p)++ (soma valor) e *p++ (move endereço). Sei que os parênteses são obrigatórios para somar.