#include <stdlib.h>
#include "sistema.h"

// Constrói a especificação da gramática
// Entrada: ponteiro para alfabeto, estados e finais
// Saída: nenhuma
void criar_gramatica(char *alfabeto, int *estados, int *finais) {
    GRAMATICA *gramatica = (GRAMATICA*) malloc (sizeof(GRAMATICA));

    gramatica->alfabeto = alfabeto;
    gramatica->estados = estados;
    gramatica->finais = finais;

    int tamanho = sizeof(estados);
    gramatica->transicoes = (transicao *) malloc(tamanho);
    for(int i = 0; i < tamanho; i++)
        gramatica->transicoes[i] = NULL;
}

// Faz inserção na cauda da lista
// Entrada: ponteiro para a lista, estado para onde vai e simbolo lido
// Saída: ponteiro para a lista
struct no* inserir_cauda(struct no* l, int estado_destino, char simbolo) {
    if(l == NULL) {
        l = (struct no*) malloc(sizeof(struct no));

        l->estado = estado_destino;
        l->simbolo = simbolo;
        l->prox = NULL;
        return l;
    }
    l->prox = inserir_cauda(l->prox, estado_destino, simbolo);
    return l;
}

// Insere uma transição na gramática
// Entrada: ponteiro para a gramática, estado de onde sai a transição, estado para onde vai e o simbolo lido
// Saída: nenhuma
void inserir_transicao(GRAMATICA *gramatica, int estado_origem, int estado_destino, char simbolo) {
    gramatica->transicoes[estado_origem] = inserir_cauda(gramatica->transicoes[estado_origem], estado_destino, simbolo);
}

void imprimir_lista(struct no* l) {
    if(l == NULL)
        return;
    printf("q%d | %c -> ", l->estado, l->simbolo);
    imprimir_lista(l->prox);
}

void imprimir_gramatica(GRAMATICA *gramatica) {
    printf("\nAlfabeto: ");
    for(int i = 0; i < sizeof(gramatica->alfabeto); i++)
        printf("%c ", gramatica->alfabeto[i]);

    printf("\nEstados: ");
    for(int i = 0; i < sizeof(gramatica->estados); i++)
        printf("q%d ", gramatica->estados[i]);

    printf("\nFinais: ");
    for(int i = 0; i < sizeof(gramatica->finais); i++)
        printf("q%d ", gramatica->finais[i]);

    printf("\nTransicoes: ");
    for(int i = 0; i < sizeof(gramatica->estados); i++) {
        printf("q%d -> ", gramatica->alfabeto[i]);
        imprimir_lista(gramatica->transicoes[i]);
    }
}

// Simula o processamento da palavra no AFD especificado
// Entrada: ponteiro para a gramatica não nula e palavra
// Saída: nenhuma
void testar_palavra(GRAMATICA *gramatica, char *palavra) {

}