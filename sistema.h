#ifndef SISTEMA
#define SISTEMA

// ----------- ESTRUTURAS -----------

// Estrutura para transições de um único estado
struct no {
    int estado;
    char simbolo;
    struct no *prox;
};

// Ponteiro para a cabeça da lista de transições
typedef struct no *transicao;

// Estrutura para a especificação da gramática
typedef struct{
    char *alfabeto;
    int *estados;
    int *finais;
    transicao *transicoes; // vetor de cabeças
} GRAMATICA;

// ----------- SISTEMA -----------

// Constrói a especificação da gramática
// Entrada: ponteiro para alfabeto, estados e finais
// Saída: nenhuma
void criar_gramatica(char *alfabeto, int *estados, int *finais);

// Insere uma transição na gramática
// Entrada: ponteiro para a gramática, estado de onde sai a transição, estado para onde vai e o simbolo lido
// Saída: nenhuma
void inserir_transicao(GRAMATICA *gramatica, int estado_origem, int estado_destino, char simbolo);



#endif