#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "arvore.h"

// Função para criar um novo nó
No* criarNo(char* valor, int num_filhos) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->valor, valor);  // Copia o valor do nó
    novoNo->num_filhos = num_filhos;
    novoNo->filhos = (No**)malloc(num_filhos * sizeof(No*));
    for (int i = 0; i < num_filhos; i++) {
        novoNo->filhos[i] = NULL;
    }
    return novoNo;
}

// Função para empilhar um nó na pilha de filhos
void empilharFilho(PilhaFilhos** pilha, No* no) {
    PilhaFilhos* novoElemento = (PilhaFilhos*)malloc(sizeof(PilhaFilhos));
    novoElemento->no = no;
    novoElemento->prox = *pilha;
    *pilha = novoElemento;
}

// Função para desempilhar um nó da pilha de filhos
No* desempilharFilho(PilhaFilhos** pilha) {
    if (*pilha == NULL) {
        return NULL;
    }
    PilhaFilhos* topo = *pilha;
    No* no = topo->no;
    *pilha = topo->prox;
    free(topo);
    return no;
}

// Função para imprimir a pilha
void imprimirPilha(PilhaFilhos* pilha) {
    printf("Pilha:\n");
    while (pilha != NULL) {
        printf("No: %s\n", pilha->no->valor);
        pilha = pilha->prox;
    }
    printf("Fim da Pilha\n");
}

// Função para associar filhos a um nó pai
void associarFilhos(No* pai, PilhaFilhos** pilha, int num_filhos) {
    for (int i = num_filhos - 1; i >= 0; i--) {
        pai->filhos[i] = desempilharFilho(pilha);
    }
}

// Função para inserir um nó na árvore
void inserir(PilhaFilhos** pilha, char* valor, int num_filhos) {
    No* novoNo = criarNo(valor, num_filhos);
    empilharFilho(pilha, novoNo);
}

// // Função para imprimir a árvore
// void imprimirArvore(No* arvore, int nivel) {
//     for (int i = 0; i < nivel; i++) {
//         printf("|  ");
//     }
//     printf("+- %s\n", arvore->valor);
//     for (int i = 0; i < arvore->num_filhos; i++) {
//         if (arvore->filhos[i] != NULL) {
//             imprimirArvore(arvore->filhos[i], nivel + 1);
//         }
//     }
// }

// Função para imprimir a árvore
void imprimirArvore(No* arvore, int nivel) {
    if (arvore == NULL) {
        return;
    }

    // Indentação de acordo com o nível atual
    for (int i = 0; i < nivel; i++) {
        printf("|  ");
    }

    // Verifica se o nó é folha ou vazio
    if (arvore->num_filhos == 0) {
        printf("-- %s\n", arvore->valor); // Sem filhos
    } else {
        printf("+- %s\n", arvore->valor); // Com filhos
    }

    // Recursivamente imprime os filhos
    for (int i = 0; i < arvore->num_filhos; i++) {
        if (arvore->filhos[i] != NULL) {
            imprimirArvore(arvore->filhos[i], nivel + 1);
        }
    }
}


// Função para liberar a memória da árvore
void liberarArvore(No* arvore) {
    for (int i = 0; i < arvore->num_filhos; i++) {
        if (arvore->filhos[i] != NULL) {
            liberarArvore(arvore->filhos[i]);
        }
    }
    free(arvore->filhos);
    free(arvore);
}