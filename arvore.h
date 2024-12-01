#ifndef ARVORE
#define ARVORE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore
typedef struct No {
    char valor[50];
    int num_filhos;
    struct No** filhos;
} No;

// Estrutura da pilha de filhos
typedef struct PilhaFilhos {
    No* no;
    struct PilhaFilhos* prox;
} PilhaFilhos;

No* criarNo(char* valor, int num_filhos);
void empilharFilho(PilhaFilhos** pilha, No* no);
No* desempilharFilho(PilhaFilhos** pilha);
void imprimirPilha(PilhaFilhos* pilha);
void associarFilhos(No* pai, PilhaFilhos** pilha, int num_filhos);
void inserir(PilhaFilhos** pilha, char* valor, int num_filhos);
void imprimirArvore(No* arvore, int nivel);
void liberarArvore(No* arvore);

#endif