#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

// ==========================================
// 🏗️ ESTRUTURAS DE DADOS
// ==========================================
struct Exercicio
{
    string id;
    string icon;
    string nome;
    string foco;
    string tags_tecnicas;
    string objetivo;
    string checklist;
    string teste;
};

struct Level
{
    string pasta;
    string titulo;
    vector<Exercicio> exercicios;
};

struct Tema
{
    string nomePastaRaiz;
    vector<Level> niveis;
};

// ==========================================
// ⚙️ MOTOR GERADOR (TEMPLATE ATUALIZADO)
// ==========================================

string gerarCPP(string nivelTitulo, Exercicio ex)
{
    string s = "/*\n";
    s += "==================================================\n";
    s += "📘 " + nivelTitulo + " - EXERCICIO " + ex.id + "/10: " + ex.nome + "\n";
    s += "==================================================\n\n";

    s += "STATUS: TO DO\n\n";

    s += "COMPETENCIAS:\n";
    s += ex.tags_tecnicas + "\n\n";

    s += "🎯 OBJETIVO:\n" + ex.objetivo + "\n\n";

    s += "🔹 TESTES (Entrada e Saida Esperadas)\n";
    s += "--------------------------------------------------\n";
    s += ex.teste + "\n";
    s += "--------------------------------------------------\n";
    s += "*/\n\n";

    // --- TEMPLATE LIMPO SOLICITADO ---
    s += "#include <iostream>\n\n\n";
    s += "int main() \n";
    s += "{\n";
    s += "   \n\n";
    s += "   return 0;\n";
    s += "}\n";
    return s;
}

string gerarREADME(string nivelTitulo, vector<Exercicio> &lista)
{
    string s = "/*\n";
    s += "================================================================================\n";
    s += "# 📝 TRACKER " + nivelTitulo + "\n";
    s += "================================================================================\n\n";
    s += "| Status | ID | Icone | Nome | Foco |\n";
    s += "| :----: | :- | :---: | :--- | :--- |\n";
    for (auto &ex : lista)
    {
        s += "|  [ ]   | " + ex.id + " |  " + ex.icon + "   | " + ex.nome + " | " + ex.foco + " |\n";
    }
    s += "\n\n================================================================================\n";
    s += "🧠 CHECKLIST DE COMPETENCIAS: " + nivelTitulo + "\n";
    s += "================================================================================\n\n";
    for (auto &ex : lista)
    {
        s += "[ ] [ID:" + ex.id + "] " + ex.checklist + "\n";
    }
    s += "*/";
    return s;
}

// ==========================================
// 💾 CARTUCHO DE DADOS: PONTEIROS
// ==========================================

void carregarDados(Tema &t)
{

    t.nomePastaRaiz = "01 - Ponteiros";

    // --- LEVEL 1 ---
    Level l1;
    l1.pasta = "Level 1 - Conceitos Basicos";
    l1.titulo = "LEVEL 1 - CONCEITOS BASICOS";
    l1.exercicios = {
        {"01", "🪞", "O Espelho", "Valor vs Endereco", "- PTR_DECLARACAO\n- PTR_ENDERECO (&)",
         "1. Declare uma variavel inteira 'numero' = 10.\n2. Declare um ponteiro 'pNum' apontando para ela.\n3. Imprima o VALOR de 'numero' usando o ponteiro.\n4. Imprima o ENDERECO de 'numero' usando o ponteiro.\n5. Mude o valor para 20 usando apenas o ponteiro.",
         "Fundamentos: Sei criar ponteiro e pegar endereco com &.", "Entrada: <Nenhuma>\nSaida: 10\n0x7ffd1a... (Endereco muda)\n20"},

        {"02", "🤫", "A Soma Silenciosa", "Somar via funcao", "- PTR_DEREFERENCIA (*)\n- PTR_MODIFICACAO",
         "1. Crie uma funcao que recebe ponteiro.\n2. Some +10 ao valor original dentro da funcao.",
         "Manipulacao: Sei alterar valor original via *ptr.", "Entrada: 10\nSaida: 20"},

        {"03", "🏠", "O Vizinho", "Comparar Enderecos", "- PTR_COMPARACAO\n- MEMORIA_STACK",
         "1. Declare duas variaveis int a, b.\n2. Compare seus enderecos para ver quem vem primeiro.",
         "Fundamentos: Sei comparar enderecos memoria.", "Entrada: &a, &b\nSaida: a < b"},

        {"04", "👻", "Calc. Fantasma", "Logica so com ponteiro", "- PTR_ARITMETICA_VALOR\n- VARIAVEL_OCULTA",
         "1. Declare dois numeros.\n2. Faca a soma usando APENAS os ponteiros (*p1 + *p2).",
         "Manipulacao: Matematica com dereferencia (*p).", "Entrada: 5, 5\nSaida: 10"},

        {"05", "🛡️", "O Guardiao", "Seguranca (nullptr)", "- PTR_NULLPTR\n- PTR_VALIDACAO",
         "1. Inicialize ponteiro com nullptr.\n2. Faca if(p != nullptr) antes de usar.",
         "Seguranca: Sei evitar crash com nullptr.", "Entrada: null\nSaida: Seguro"},

        {"06", "🆙", "O Upgrade", "Precedencia (*p)++", "- PTR_PRECEDENCIA\n- PTR_INCREMENTO_VALOR",
         "1. Mostre a diferenca entre (*p)++ e *p++ na pratica.",
         "Sintaxe: Entendo precedencia de operadores.", "Entrada: 10\nSaida: 11"},

        {"07", "🔄", "O Trocador", "Swap (Troca)", "- PTR_SWAP\n- PTR_AUXILIAR",
         "1. Crie funcao void troca(int* a, int* b).\n2. Troque os valores originais.",
         "Funcoes: Sei fazer Swap com ponteiros.", "Entrada: 1, 2\nSaida: 2, 1"},

        {"08", "🎁", "Calculo Duplo", "Retorno duplo", "- PTR_RETORNO_MULTIPLO\n- FUNC_PARAM_PTR",
         "1. Funcao que retorna void mas 'devolve' soma e dobro via ponteiros.",
         "Funcoes: Retorno multiplo via ponteiro.", "Entrada: 10\nSaida: 10, 20"},

        {"09", "💡", "O Interruptor", "Inverter Boolean", "- PTR_BOOL\n- PTR_LOGICA",
         "1. Funcao que inverte estado de bool via ponteiro.",
         "Logica: Manipular flags booleanas.", "Entrada: true\nSaida: false"},

        {"10", "🔐", "A Criptografia", "Aritmetica Char", "- PTR_CHAR\n- ASCII_MATH",
         "1. Some +1 ao valor de um char via ponteiro para mudar a letra.",
         "ASCII: Manipular char como numero.", "Entrada: 'A'\nSaida: 'B'"}};
    t.niveis.push_back(l1);

    // --- LEVEL 2 ---
    Level l2;
    l2.pasta = "Level 2 - Aritmetica de Ponteiros";
    l2.titulo = "LEVEL 2 - ARITMETICA DE PONTEIROS";
    l2.exercicios = {
        {"01", "🔭", "O Salto", "Acesso *(p+n)", "- PTR_OFFSET\n- ARRAY_ACCESS", "Acesse indices do array usando soma no ponteiro.", "Offset: Sei acessar *(p+i).", "Entrada: array[2]\nSaida: Valor"},
        {"02", "🧭", "O Navegador", "Loop p++", "- PTR_ITERACAO\n- LOOP_WHILE", "Percorra um array incrementando o ponteiro.", "Iteracao: Sei usar p++ em loop.", "Entrada: Loop\nSaida: Todos elementos"},
        {"03", "🔙", "A Marcha Re", "Loop p--", "- PTR_DECREMENTO\n- LOOP_REVERSE", "Percorra de tras para frente decrementando.", "Iteracao: Sei usar p--.", "Entrada: Loop\nSaida: Reverso"},
        {"04", "🦘", "O Canguru", "Salto p+=2", "- PTR_ARITMETICA_AVANCADA\n- STEP_ITERATION", "Percorra pulando de 2 em 2.", "Passo: Sei usar p+=n.", "Entrada: Loop\nSaida: 0, 2, 4..."},
        {"05", "📏", "A Regua", "Subtracao P-P", "- PTR_DIFERENCA\n- ARRAY_SIZE_CALC", "Calcule a distancia entre dois ponteiros.", "Distancia: Sei que p2-p1 da numero de elementos.", "Entrada: &arr[5]-&arr[0]\nSaida: 5"},
        {"06", "🧱", "O Preenchimento", "Fill", "- PTR_WRITE\n- BULK_OPERATION", "Preencha um array usando ponteiros.", "Write: Sei escrever em massa.", "Entrada: Loop\nSaida: Array cheio"},
        {"07", "📠", "O Copiador", "Copy", "- PTR_COPY\n- DUAL_POINTER_LOOP", "Copie dados de um array para outro via ponteiros.", "Copy: Sei clonar arrays.", "Entrada: A->B\nSaida: Iguais"},
        {"08", "🚨", "O Sentinela", "Busca", "- PTR_SENTINEL\n- SEARCH_LOOP", "Pare o loop ao encontrar valor especifico.", "Stop: Sei usar condicao de parada.", "Entrada: Ate -1\nSaida: Parou"},
        {"09", "🎯", "O Rastreador", "Max Pointer", "- PTR_TRACKING\n- CONDITIONAL_ASSIGN", "Guarde o ENDERECO do maior valor, nao so o valor.", "Rastreio: Sei guardar referencia do alvo.", "Entrada: 1, 5, 2\nSaida: Endereco do 5"},
        {"10", "🤐", "A String", "Char*", "- C_STRING\n- NULL_TERMINATOR", "Percorra char* ate achar '\\0'.", "C-String: Sei iterar texto cru.", "Entrada: 'Oi'\nSaida: O, i"}};
    t.niveis.push_back(l2);

    // --- LEVEL 3 ---
    Level l3;
    l3.pasta = "Level 3 - Memoria Dinamica";
    l3.titulo = "LEVEL 3 - ARRAYS E SEGMENTOS DE MEMORIA";
    l3.exercicios = {
        {"01", "📊", "Matriz Linear", "Indexacao 2D", "- MEM_MAPPING\n- MATH_INDEX", "Trate array 1D como 2D (linha*coluna).", "Mapping: Sei linearizar matrizes.", "Entrada: 2x2\nSaida: Flat"},
        {"02", "🔪", "O Fatiador", "Slice", "- PTR_SLICE\n- SUB_ARRAY", "Crie um ponteiro que aponta para o meio do array.", "Sub-array: Sei criar 'views' de memoria.", "Entrada: &arr[5]\nSaida: Sub-lista"},
        {"03", "🧵", "String Copy", "Implementacao", "- C_STR_MANIP\n- PTR_COPY", "Recrie a funcao strcpy usando ponteiros.", "Algoritmo: Sei manipular char*.", "Entrada: 'Ola'\nSaida: Copia feita"},
        {"04", "📏", "String Len", "Implementacao", "- C_STR_COUNT\n- PTR_WHILE", "Recrie strlen usando while e ponteiro.", "Algoritmo: Contar ate \\0.", "Entrada: 'Test'\nSaida: 4"},
        {"05", "🔄", "String Rev", "In-Place", "- TWO_POINTERS\n- SWAP_CHAR", "Inverta string usando dois ponteiros (begin/end).", "Algoritmo: Dois ponteiros convergentes.", "Entrada: 'Roma'\nSaida: 'amor'"},
        {"06", "🥞", "A Pilha (Stack)", "Variaveis Locais", "- STACK_ADDR\n- MEM_GROWTH", "Mostre que enderecos locais crescem/decrescem na Stack.", "Memoria: Entendo regiao de Stack.", "Entrada: &a, &b\nSaida: Enderecos"},
        {"07", "📦", "O Heap (Intro)", "Intro New", "- HEAP_ALLOC\n- NEW_DELETE", "Apenas declare um 'new int' e delete.", "Heap: Primeiro contato com memoria dinamica.", "Entrada: new\nSaida: Ok"},
        {"08", "👻", "Dangling Ptr", "Perigo", "- DANGLING_PTR\n- MEM_ERROR", "Simule o erro de acessar memoria deletada (com cuidado!).", "Erro: Entendo o risco de ponteiro solto.", "Entrada: delete, usa\nSaida: Lixo/Crash"},
        {"09", "🧟", "Memory Leak", "Perigo", "- MEM_LEAK\n- BAD_PRACTICE", "Aloque num loop sem deletar (conceitual).", "Erro: Entendo vazamento de memoria.", "Entrada: Loop new\nSaida: RAM sobe"},
        {"10", "🛡️", "Safe Delete", "Padrao", "- SAFE_DELETE\n- MACRO_FUNC", "Crie macro/funcao que deleta e seta nullptr.", "Seguranca: Padrao de limpeza segura.", "Entrada: SafeDel(p)\nSaida: p e null"}};
    t.niveis.push_back(l3);

    // --- LEVEL 4 ---
    Level l4;
    l4.pasta = "Level 4 - Ponteiro de Ponteiro";
    l4.titulo = "LEVEL 4 - HEAP E GESTAO DE RECURSOS";
    l4.exercicios = {
        {"01", "✨", "Array Dinamico", "New []", "- HEAP_ARRAY\n- DYNAMIC_SIZE", "Aloque um array de tamanho N definido pelo usuario.", "Heap: Alocacao de arrays em tempo de execucao.", "Entrada: N=10\nSaida: Array criado"},
        {"02", "🧹", "Delete []", "Limpeza Array", "- DELETE_ARRAY\n- MEM_CLEAN", "Delete corretamente array dinamico.", "Heap: Liberacao correta de arrays.", "Entrada: delete[]\nSaida: Limpo"},
        {"03", "📈", "Resize Manual", "Realloc", "- REALLOC_LOGIC\n- DATA_MIGRATION", "Crie novo maior, copie, delete antigo.", "Algoritmo: Logica de redimensionar vetor.", "Entrada: Aumentar\nSaida: Array maior"},
        {"04", "🏭", "Fabrica Struct", "Return Ptr", "- FACTORY_PATTERN\n- STRUCT_PTR", "Funcao que cria Struct no heap e retorna ponteiro.", "Padrao: Factory function.", "Entrada: Cria()\nSaida: Ponteiro valido"},
        {"05", "🔢", "Matriz Dinamica", "Ponteiro p/ Ponteiro", "- DOUBLE_PTR\n- 2D_ALLOC", "Aloque matriz NxM usando int**.", "Complexidade: Alocacao bidimensional.", "Entrada: 3x3\nSaida: Matriz"},
        {"06", "🗑️", "Free Matriz", "Delete Loop", "- CASCADE_DELETE\n- MEM_FREE", "Libere a matriz NxM na ordem certa (linhas depois array).", "Complexidade: Liberacao em cascata.", "Entrada: Free\nSaida: Ok"},
        {"07", "📝", "Buffer de Texto", "Input Dinamico", "- DYNAMIC_BUFFER\n- CHAR_READ", "Leia texto de tamanho desconhecido char a char.", "Input: Buffer elastico.", "Entrada: Texto longo\nSaida: Lido ok"},
        {"08", "👥", "Array de Objetos", "Structs Dinamicas", "- OBJ_ARRAY\n- HEAP_STRUCTS", "Aloque array de structs Pessoa.", "Estrutura: Dados complexos no heap.", "Entrada: N Pessoas\nSaida: Lista"},
        {"09", "🚫", "Fora de Limite", "Valgrind", "- OUT_OF_BOUNDS\n- DEBUG", "Acesse indice N (erro) e veja comportamento.", "Debug: Entender acesso invalido no heap.", "Entrada: arr[N]\nSaida: Erro/Lixo"},
        {"10", "🧠", "Smart Ptr (Intro)", "Unique_ptr", "- SMART_PTR\n- STD_UNIQUE", "Use std::unique_ptr para nao precisar de delete.", "Modern C++: Gestao automatica basica.", "Entrada: make_unique\nSaida: Auto delete"}};
    t.niveis.push_back(l4);

    // --- LEVEL 5 ---
    Level l5;
    l5.pasta = "Level 5 - Juncao de tudo";
    l5.titulo = "LEVEL 5 - PONTEIROS MASTER CLASS";
    l5.exercicios = {
        {"01", "🌌", "Void*", "Generico", "- VOID_PTR\n- TYPE_CAST", "Use void* para apontar para int e float.", "Tipagem: Ponteiro generico cru.", "Entrada: (int*)voidp\nSaida: Valor"},
        {"02", "🎭", "Polimorfismo C", "Cast", "- REINTERPRET_CAST\n- BYTE_MANIP", "Trate bytes de um int como char*.", "Memoria: Reinterpretacao de dados.", "Entrada: int 65\nSaida: char 'A'"},
        {"03", "📞", "Func Pointer", "Callback", "- FUNC_PTR\n- DELEGATE", "Crie ponteiro para funcao e chame-a.", "Sintaxe: Ponteiro de funcao basico.", "Entrada: (*p)(10)\nSaida: Executa func"},
        {"04", "🧮", "Operacao Flex", "Callback Param", "- STRATEGY_PATTERN\n- INJECTION", "Funcao 'Calcular' que recebe ponteiro de Soma ou Subtracao.", "Design: Injecao de dependencia via ponteiro.", "Entrada: Calc(Soma)\nSaida: Resultado"},
        {"05", "📜", "Menu Array", "Array de Func", "- DISPATCH_TABLE\n- MENU_SYSTEM", "Array de ponteiros de funcao para menu.", "Design: Tabela de despacho.", "Entrada: Opcao 1\nSaida: Func 1"},
        {"06", "🕵️", "Reference vs Ptr", "Diferenca", "- REF_VS_PTR\n- CPP_CONCEPTS", "Faca a mesma funcao com & e com *.", "Teoria: Referencia C++ vs Ponteiro C.", "Entrada: Troca\nSaida: Igual"},
        {"07", "📦", "Ponteiro p/ Ponteiro", "Modificar Ptr", "- PTR_TO_PTR\n- INDIRECT_MOD", "Funcao que recebe int** para mudar para onde o ponteiro aponta.", "Indirecao: Alterar endereco remotamente.", "Entrada: Aloca(&p)\nSaida: p mudou"},
        {"08", "⚡", "Volatile", "Hardware", "- VOLATILE\n- COMPILER_OPT", "Conceito de ponteiro volatile (teorico).", "Keyword: Evitar otimizacao de compilador.", "Entrada: N/A\nSaida: Leitura real"},
        {"09", "🧬", "Iterator Custom", "Ponteiro Smart", "- OP_OVERLOAD\n- CLASS_IMPL", "Crie uma classe que imita comportamento de ponteiro.", "OOP: Sobrecarga de operadores * e ->.", "Entrada: *obj\nSaida: Valor"},
        {"10", "🎓", "Desafio Final", "Linked List", "- LINKED_LIST\n- FULL_IMPL", "Implemente uma lista encadeada simples manual.", "Capstone: Juntar tudo (struct, heap, ponteiros).", "Entrada: Add/Rem\nSaida: Lista"}};
    t.niveis.push_back(l5);
}

// ==========================================
// 🚀 MAIN - EXECUCAO
// ==========================================
int main()
{
    SetConsoleOutputCP(65001);

    Tema tema;
    carregarDados(tema);

    cout << "--- 🏭 FABRICA DE EXERCICIOS: " << tema.nomePastaRaiz << " ---" << endl;

    // Verifica se tracker.exe existe na raiz antes de começar
    bool temTracker = fs::exists("tracker.exe");
    if (!temTracker)
    {
        cout << "⚠️  AVISO: 'tracker.exe' NAO ENCONTRADO na raiz!" << endl;
        cout << "⚠️  Os arquivos serao criados, mas o tracker nao sera copiado." << endl;
        cout << "⚠️  Voce tera que copiar manualmente depois.\n"
             << endl;
    }

    if (!fs::exists(tema.nomePastaRaiz))
    {
        fs::create_directory(tema.nomePastaRaiz);
        cout << "📁 Criada pasta raiz: " << tema.nomePastaRaiz << endl;
    }
    else
    {
        cout << "📁 Pasta raiz ja existe: " << tema.nomePastaRaiz << endl;
    }

    for (auto &nivel : tema.niveis)
    {
        string pathLevel = tema.nomePastaRaiz + "/" + nivel.pasta;

        if (!fs::exists(pathLevel))
        {
            fs::create_directory(pathLevel);
            cout << "   📂 Criando Nivel: " << nivel.pasta << endl;
        }

        // 1. Gera os arquivos .cpp
        for (auto &ex : nivel.exercicios)
        {
            string nomeArquivo = ex.id + " - " + ex.nome + ".cpp";
            string pathArquivo = pathLevel + "/" + nomeArquivo;

            if (!fs::exists(pathArquivo))
            {
                ofstream arquivo(pathArquivo);
                arquivo << gerarCPP(nivel.titulo, ex);
                arquivo.close();
            }
        }

        // 2. Gera README dentro da pasta
        string pathReadme = pathLevel + "/README.md";
        ofstream readme(pathReadme);
        readme << gerarREADME(nivel.titulo, nivel.exercicios);
        readme.close();

        // 3. 🚀 AUTO-DEPLOY DO TRACKER 🚀
        if (temTracker)
        {
            string destinoTracker = pathLevel + "/tracker.exe";
            try
            {
                fs::copy_file("tracker.exe", destinoTracker, fs::copy_options::overwrite_existing);
            }
            catch (fs::filesystem_error &e)
            {
                cout << "      [ERRO] Falha ao copiar tracker: " << e.what() << endl;
            }
        }
    }

    cout << "\n✅ PROCESSO CONCLUIDO!" << endl;
    if (temTracker)
    {
        cout << "🤖 Tracker instalado em todas as pastas automaticamente." << endl;
    }
    cout << "👉 Execute 'atualizar_tudo.bat' para sincronizar o progresso." << endl;
    return 0;
}