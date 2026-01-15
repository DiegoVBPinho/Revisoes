#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

// ==========================================
// 🏗️ ESTRUTURAS DE DADOS (NÃO MEXA AQUI)
// ==========================================
struct Exercicio
{
    string id;
    string icon;
    string nome;
    string foco;
    string objetivo;  // Vai para o cabeçalho do CPP
    string checklist; // Vai para o README
    string teste;     // Input/Output esperado
};

struct Level
{
    string pasta;  // Nome da pasta (ex: Level 1 - Basico)
    string titulo; // Titulo no README
    vector<Exercicio> exercicios;
};

struct Tema
{
    string nomePastaRaiz; // Ex: 03 - Listas
    vector<Level> niveis;
};

// ==========================================
// ⚙️ MOTOR GERADOR (NÃO MEXA AQUI)
// ==========================================

string gerarCPP(string nivelTitulo, Exercicio ex)
{
    string s = "/*\n";
    s += "==================================================\n";
    s += "📘 " + nivelTitulo + " - EXERCÍCIO " + ex.id + "/10: " + ex.nome + " " + ex.icon + "\n";
    s += "==================================================\n\n";
    s += "🎯 OBJETIVO:\n" + ex.objetivo + "\n\n";
    s += "🔹 TESTES (Entrada e Saída Esperadas)\n";
    s += "--------------------------------------------------\n";
    s += ex.teste + "\n";
    s += "--------------------------------------------------\n";
    s += "*/\n\n";
    s += "#include <iostream>\n";
    s += "#include <string>\n";
    s += "#include <vector>\n";
    s += "using namespace std;\n\n";
    s += "int main() {\n";
    s += "    // SEU CODIGO AQUI\n\n";
    s += "    // STATUS: TO DO\n";
    s += "    return 0;\n";
    s += "}\n";
    return s;
}

string gerarREADME(string nivelTitulo, vector<Exercicio> &lista)
{
    string s = "/*\n";
    s += "================================================================================\n";
    s += "# 📝 TRACKER " + nivelTitulo + "\n";
    s += "================================================================================\n\n";
    s += "| Status | ID | Ícone | Nome | Foco |\n";
    s += "| :----: | :- | :---: | :--- | :--- |\n";
    for (auto &ex : lista)
    {
        s += "|  [ ]   | " + ex.id + " |  " + ex.icon + "   | " + ex.nome + " | " + ex.foco + " |\n";
    }
    s += "\n\n================================================================================\n";
    s += "🧠 CHECKLIST DE COMPETÊNCIAS: " + nivelTitulo + "\n";
    s += "================================================================================\n\n";
    for (auto &ex : lista)
    {
        s += "[ ] [ID:" + ex.id + "] " + ex.checklist + "\n";
    }
    s += "*/";
    return s;
}

// ==========================================
// 💾 CARTUCHO DE DADOS (AQUI VOCÊ EDITA!)
// ==========================================
// Quando quiser um novo tema, peça pro Gemini:
// "Gere o void carregarDados(Tema& t) para o assunto X"
// ==========================================

void carregarDados(Tema &t)
{

    // 1. NOME DA PASTA RAIZ DO TEMA
    t.nomePastaRaiz = "03 - Lista";

    // ---------------------------------------------------------
    // LEVEL 1
    // ---------------------------------------------------------
    Level l1;
    l1.pasta = "Level 1 - Listas Sequenciais";
    l1.titulo = "LEVEL 1 - LISTAS SEQUENCIAIS (ARRAYS)";
    l1.exercicios = {
        {"01", "🆕", "A Criação", "Inicialização", "Crie um array estático de 5 inteiros preenchido manualmente.", "Inicialização: Sei declarar e iniciar array.", "Entrada: N/A\nSaida: 1, 2, 3, 4, 5"},
        {"02", "🔍", "O Buscador", "Busca Linear", "Percorra array buscando valor X.", "Busca: Sei iterar para achar valor.", "Entrada: 10\nSaida: Achei"},
        {"03", "✏️", "A Edição", "Update Indice", "Atualize o valor do índice informado.", "Acesso: Sei alterar valor por indice.", "Entrada: Indice 2, Val 99\nSaida: Ok"},
        {"04", "➕", "Push Back Manual", "Inserir Fim", "Controle o tamanho lógico para inserir no fim.", "Controle: Diferencio capacidade de tamanho.", "Entrada: Insere 5\nSaida: Tam 1"},
        {"05", "➖", "Pop Back Manual", "Remover Fim", "Diminua o contador de tamanho.", "Logica: Remover é diminuir contador.", "Entrada: Remove\nSaida: Tam diminuiu"},
        {"06", "🚚", "Shift Right", "Inserir Inicio", "Mova elementos para direita para inserir no zero.", "Algoritmo: Sei fazer shift right.", "Entrada: Insere 9\nSaida: 9, 1, 2..."},
        {"07", "🗑️", "Shift Left", "Remover Inicio", "Mova elementos para esquerda para tapar buraco.", "Algoritmo: Sei fazer shift left.", "Entrada: Remove 0\nSaida: 2 virou 1"},
        {"08", "🔄", "Inversão", "Swap In-Place", "Inverta o array usando ponteiros inicio/fim.", "Swap: Sei inverter array in-place.", "Entrada: 1,2,3\nSaida: 3,2,1"},
        {"09", "🔗", "Merge", "Juntar Arrays", "Crie array C juntando A e B.", "Merge: Sei copiar de duas fontes.", "Entrada: A+B\nSaida: C"},
        {"10", "🧹", "Clear", "Limpeza Logica", "Resete o contador de tamanho para zero.", "Reset: Sei zerar a lista logicamente.", "Entrada: Clear\nSaida: Tam 0"}};
    t.niveis.push_back(l1);

    // ---------------------------------------------------------
    // LEVEL 2
    // ---------------------------------------------------------
    Level l2;
    l2.pasta = "Level 2 - Estruturas Restritas";
    l2.titulo = "LEVEL 2 - PILHAS E FILAS";
    l2.exercicios = {
        {"01", "📚", "Stack Push/Pop", "LIFO", "Implemente pilha (ultimo entra, primeiro sai).", "LIFO: Entendo o conceito de Pilha.", "Entrada: Push 1, Pop\nSaida: 1"},
        {"02", "👀", "Stack Top", "Peek", "Olhe o topo sem remover.", "Peek: Sei consultar sem deletar.", "Entrada: Top\nSaida: Valor"},
        {"03", "🚶", "Queue Enqueue", "FIFO", "Implemente fila (primeiro entra, primeiro sai).", "FIFO: Entendo o conceito de Fila.", "Entrada: Fila\nSaida: Ok"},
        {"04", "🔄", "Fila Circular", "Mod", "Use % para fila circular.", "Math: Sei usar resto de divisao.", "Entrada: Loop\nSaida: Circular"},
        {"05", "🃏", "Hanoi Simples", "Logic", "Ordene usando duas pilhas.", "Logica: Manipular pilhas.", "Entrada: 3,1,2\nSaida: 1,2,3"},
        {"06", "📉", "Overflow", "Check", "Valide pilha cheia.", "Erro: Tratar limites.", "Entrada: Cheia\nSaida: Erro"},
        {"07", "↔️", "Palindromo", "String", "Use pilha para checar palindromo.", "App: Inverter string.", "Entrada: ARARA\nSaida: Sim"},
        {"08", "🌡️", "Priority Q", "Ordenado", "Insira na ordem certa na fila.", "Sort: Inserção ordenada.", "Entrada: 5, 1\nSaida: 1, 5"},
        {"09", "🥞", "Resize", "Dinâmico", "Dobre array se encher.", "Memoria: Realocação.", "Entrada: Full\nSaida: Dobrou"},
        {"10", "🔚", "Destructor", "Limpeza", "Libere memória no fim.", "Memoria: Delete.", "Entrada: Fim\nSaida: Limpo"}};
    t.niveis.push_back(l2);

    // ---------------------------------------------------------
    // LEVEL 3
    // ---------------------------------------------------------
    Level l3;
    l3.pasta = "Level 3 - Bibliotecas STL";
    l3.titulo = "LEVEL 3 - VECTOR E LIST (STL)";
    l3.exercicios = {
        {"01", "📦", "Vector Basic", "std::vector", "Use vector em vez de array.", "STL: Sei usar vector basico.", "Entrada: push\nSaida: ok"},
        {"02", "📏", "Capacity", "Memoria", "Analise size vs capacity.", "STL: Entendo alocação vector.", "Entrada: loop\nSaida: info"},
        {"03", "🔗", "List Basic", "std::list", "Use lista duplamente encadeada da STL.", "STL: Sei usar list.", "Entrada: push\nSaida: ok"},
        {"04", "🗺️", "Map Basic", "std::map", "Crie dicionario chave-valor.", "STL: Sei usar map.", "Entrada: chave\nSaida: valor"},
        {"05", "🥞", "Stack Adapter", "std::stack", "Use adaptador stack.", "STL: Sei usar stack pronta.", "Entrada: push\nSaida: ok"},
        {"06", "🚶", "Queue Adapter", "std::queue", "Use adaptador queue.", "STL: Sei usar queue pronta.", "Entrada: push\nSaida: ok"},
        {"07", "🔢", "Iterator", "Navegação", "Use iteradores para loop.", "STL: Sei usar iterators.", "Entrada: it\nSaida: valor"},
        {"08", "🔍", "Find", "Algoritmo", "Use std::find.", "Algo: Busca pronta.", "Entrada: find\nSaida: it"},
        {"09", "📶", "Sort", "Algoritmo", "Use std::sort.", "Algo: Ordenação pronta.", "Entrada: sort\nSaida: ordenado"},
        {"10", "🐑", "Lambda", "Modern C++", "Use for_each com lambda.", "Modern: Sintaxe lambda.", "Entrada: []\nSaida: print"}};
    t.niveis.push_back(l3);

    // ---------------------------------------------------------
    // LEVEL 4
    // ---------------------------------------------------------
    Level l4;
    l4.pasta = "Level 4 - Lista Encadeada Simples";
    l4.titulo = "LEVEL 4 - LISTAS ENCADEADAS (PONTEIROS)";
    l4.exercicios = {
        {"01", "📦", "Node Struct", "Estrutura", "Crie struct Node {val, prox}.", "Struct: Sei criar Nó.", "Entrada: N/A\nSaida: Ok"},
        {"02", "🔗", "Manual Link", "Ligação", "Ligue 3 nós na mão.", "Link: Entendo ponteiros.", "Entrada: n1->prox\nSaida: n2"},
        {"03", "➕", "Head Insert", "Inicio", "Insira atualizando head.", "Head: Mudar inicio.", "Entrada: Insere\nSaida: Novo head"},
        {"04", "🔚", "Tail Insert", "Fim", "Percorra até null e insira.", "Travessia: Ir até o fim.", "Entrada: Insere\nSaida: Novo fim"},
        {"05", "📠", "Print List", "Loop", "Imprima while != nullptr.", "Loop: Iterar lista.", "Entrada: Print\nSaida: Lista"},
        {"06", "🔍", "Search Node", "Busca", "Retorne endereço do nó.", "Busca: Achar ponteiro.", "Entrada: Valor\nSaida: Endereço"},
        {"07", "❌", "Delete Head", "Remover", "Delete head e avance.", "Delete: Liberar memoria.", "Entrada: Del\nSaida: Novo head"},
        {"08", "🗑️", "Delete Middle", "Remover", "Delete nó do meio.", "Relink: Pular nó.", "Entrada: Del\nSaida: Lista -1"},
        {"09", "🧹", "Clear All", "Destruir", "Delete tudo loop.", "Memoria: Limpeza total.", "Entrada: Clear\nSaida: Nullptr"},
        {"10", "📏", "Size Count", "Contar", "Conte nós.", "Algoritmo: Contagem.", "Entrada: Count\nSaida: N"}};
    t.niveis.push_back(l4);

    // ---------------------------------------------------------
    // LEVEL 5
    // ---------------------------------------------------------
    Level l5;
    l5.pasta = "Level 5 - Listas Complexas";
    l5.titulo = "LEVEL 5 - LISTAS DUPLAS E CIRCULARES";
    l5.exercicios = {
        {"01", "↔️", "Double Node", "Struct", "Node {ant, prox}.", "Dupla: Nó bidirecional.", "Entrada: N/A\nSaida: Ok"},
        {"02", "⬅️", "Reverse Print", "Loop", "Imprima de tras pra frente.", "Nav: Usar prev.", "Entrada: Print\nSaida: Reverso"},
        {"03", "➕", "Double Insert", "Inserção", "Ajuste 4 ponteiros.", "Link: Inserção complexa.", "Entrada: Insere\nSaida: Ok"},
        {"04", "❌", "Double Delete", "Remoção", "Ajuste vizinhos.", "Unlink: Remoção complexa.", "Entrada: Del\nSaida: Ok"},
        {"05", "🔄", "Circular Link", "Ciclo", "Fim aponta inicio.", "Ciclo: Fechar anel.", "Entrada: Link\nSaida: Loop"},
        {"06", "♾️", "Circular Print", "Loop", "Imprima sem loop infinito.", "Logica: Condição parada.", "Entrada: Print\nSaida: Uma volta"},
        {"07", "🕵️", "Floyd Cycle", "Detect", "Ache ciclo em lista.", "Algo: Tartaruga/Lebre.", "Entrada: Check\nSaida: True"},
        {"08", "🃏", "Deque Impl", "Deque", "Fila duas pontas.", "Estrutura: Deque.", "Entrada: Push\nSaida: Ok"},
        {"09", "🧩", "Sorted Insert", "Ordem", "Insira ordenado.", "Algo: Achar posição.", "Entrada: 3 em 1-5\nSaida: 1-3-5"},
        {"10", "🎁", "Template List", "Generic", "Lista<T>.", "Template: Genérico.", "Entrada: String\nSaida: Ok"}};
    t.niveis.push_back(l5);
}

// ==========================================
// 🚀 MAIN - EXECUÇÃO
// ==========================================
int main()
{
    SetConsoleOutputCP(65001);

    Tema tema;
    carregarDados(tema); // <--- AQUI ELE PUXA O CARTUCHO QUE VOCÊ EDITOU

    cout << "--- 🏭 FÁBRICA DE EXERCÍCIOS: " << tema.nomePastaRaiz << " ---" << endl;

    // Cria pasta raiz do Tópico
    if (!fs::exists(tema.nomePastaRaiz))
    {
        fs::create_directory(tema.nomePastaRaiz);
        cout << "📁 Criada pasta raiz: " << tema.nomePastaRaiz << endl;
    }
    else
    {
        cout << "📁 Pasta raiz já existe: " << tema.nomePastaRaiz << endl;
    }

    for (auto &nivel : tema.niveis)
    {
        string pathLevel = tema.nomePastaRaiz + "/" + nivel.pasta;

        if (!fs::exists(pathLevel))
        {
            fs::create_directory(pathLevel);
            cout << "   📂 Criando Nível: " << nivel.pasta << endl;
        }

        // 1. Gera os arquivos .cpp
        for (auto &ex : nivel.exercicios)
        {
            string nomeArquivo = ex.id + " -.cpp"; // Nome simplificado
            string pathArquivo = pathLevel + "/" + nomeArquivo;

            // Só cria se não existir (pra não apagar seu código feito)
            if (!fs::exists(pathArquivo))
            {
                ofstream arquivo(pathArquivo);
                arquivo << gerarCPP(nivel.titulo, ex);
                arquivo.close();
            }
        }

        // 2. Gera/Sobrescreve o README.md (O README a gente sempre atualiza)
        string pathReadme = pathLevel + "/README.md";
        ofstream readme(pathReadme);
        readme << gerarREADME(nivel.titulo, nivel.exercicios);
        readme.close();
    }

    cout << "\n✅ PROCESSO CONCLUÍDO!" << endl;
    cout << "👉 Seus exercícios estão prontos em '" << tema.nomePastaRaiz << "'" << endl;
    return 0;
}