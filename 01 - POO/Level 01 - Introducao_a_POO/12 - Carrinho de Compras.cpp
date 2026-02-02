/*
==================================================
📘 01 - POO - EXERCICIO 12: Carrinho de Compras
==================================================

STATUS: TODO

COMPETENCIAS:
- ARRAYS_DE_OBJETOS
- LOGICA_OPERACIONAL
- SIMULACAO_AVANCADA

🧠 CONCEITO: COLEÇÕES DE OBJETOS (Aula 04)
Ao final do material, vemos que objetos podem ser armazenados em arrays.
Isso permite processar grandes volumes de dados de uma só vez.

--------------------------------------------------
🎯 OBJETIVO DO EXERCICIO (Baseado no Slide 17):
1. Crie uma classe 'Produto' com: std::string nome e float preco.
2. Na função main:
   - Crie um array de 'Produto' com 3 posições.
   - Atribua valores para cada produto no array.
   - Use um loop 'for' para percorrer o array e somar todos os preços.
   - Exiba o valor total da fatura no final.
--------------------------------------------------
*/

#include <iostream>
#include <string>
#include <iomanip>

// Desenvolva sua classe aqui:

class Produto
{
public:
    std::string nome;
    float preco;
};

int main()
{
    // criando array
    Produto produtos[3];

    // instancias

    produtos[0].nome = "Abacate";
    produtos[0].preco = 5.00;

    produtos[1].nome = "Laranja";
    produtos[1].preco = 6.00;

    produtos[2].nome = "Maca";
    produtos[2].preco = 7.00;

    float resultado = 0;

    for (int i = 0; i < 3; i++)
    {
        resultado += produtos[i].preco;
    }

    std::cout << std::fixed << std::setprecision(2) << "a soma total eh: " << resultado;

    return 0;
}