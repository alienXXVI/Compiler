#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <libgen.h>

#include "arvore.h"

// Cria um novo nó
// Entrada: valor do nó e número de filhos
// Saída: nó criado
No* criarNo(char* valor, int num_filhos) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->valor, valor);
    novoNo->num_filhos = num_filhos;
    novoNo->filhos = (No**)malloc(num_filhos * sizeof(No*));
    for (int i = 0; i < num_filhos; i++) {
        novoNo->filhos[i] = NULL;
    }
    return novoNo;
}

// Empilha um nó na pilha de filhos
// Entrada: pilha em questão e nó a ser empilhado
// Saída: nenhuma
void empilharFilho(PilhaFilhos** pilha, No* no) {
    PilhaFilhos* novoElemento = (PilhaFilhos*)malloc(sizeof(PilhaFilhos));
    novoElemento->no = no;
    novoElemento->prox = *pilha;
    *pilha = novoElemento;
}

// Desempilha um nó da pilha de filhos
// Entrada: pilha em questão
// Saída: nó desempilhado
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

// Imprimir a pilha
// Entrada: pilha a ser impressa
// Saída: nenhuma
void imprimirPilha(PilhaFilhos* pilha) {
    printf("Pilha:\n");
    while (pilha != NULL) {
        printf("No: %s\n", pilha->no->valor);
        pilha = pilha->prox;
    }
    printf("Fim da Pilha\n");
}

// Associa filhos a um nó pai
// Entrada: ponteiro ao nó pai, pilha de nós e número de filhos
// Saída: nenhuma
void associarFilhos(No* pai, PilhaFilhos** pilha, int num_filhos) {
    for (int i = num_filhos - 1; i >= 0; i--) {
        pai->filhos[i] = desempilharFilho(pilha);
    }
}

// Insere um nó na árvore
// Entrada: pilha de nós, valor do nó e seu número de filhos
// Saída: nenhuma
void inserir(PilhaFilhos** pilha, char* valor, int num_filhos) {
    No* novoNo = criarNo(valor, num_filhos);
    empilharFilho(pilha, novoNo);
}

// Imprime a árvore na tela
// Entrada: ponteiro para a árvore e seu nível (começa com 0)
// Saída: nenhuma
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

// Imprime a árvore no arquivo dado
// Entrada: ponteiro para a árvore, seu nível (começa com 0) e ponteiro para o arquivo
// Saída: nenhuma
void imprimirArvoreArquivo(No* arvore, int nivel, FILE* arquivo) {
    if (arvore == NULL) {
        return;
    }

    // Indentação de acordo com o nível atual
    for (int i = 0; i < nivel; i++) {
        fprintf(arquivo, "|  ");
    }

    // Verifica se o nó é folha ou vazio
    if (arvore->num_filhos == 0) {
        fprintf(arquivo, "-- %s\n", arvore->valor); // Sem filhos
    } else {
        fprintf(arquivo, "+- %s\n", arvore->valor); // Com filhos
    }

    // Recursivamente imprime os filhos
    for (int i = 0; i < arvore->num_filhos; i++) {
        if (arvore->filhos[i] != NULL) {
            imprimirArvoreArquivo(arvore->filhos[i], nivel + 1, arquivo);
        }
    }
}

// Salva arvore em arquivi dado
// Entrada: ponteiro para a árvore, caminho para o diretório do arquivo e o nome do arquivo
// Saída: nenhuma
// Pós-condição: o arquivo será salvo no caminho dado, com o nome "arvore_NOME.txt"
void salvarArvoreEmArquivo(No* arvore, const char* caminhoDiretorio, const char* nomeArquivoOriginal) {
    // Extrai o nome do arquivo sem o caminho
    char nomeArquivo[256];
    char* nomeBase = basename((char*)nomeArquivoOriginal); // Extrai o nome do arquivo do caminho
    snprintf(nomeArquivo, sizeof(nomeArquivo), "arvore_%s", nomeBase);

    // Cria o caminho completo para salvar o arquivo
    char caminhoCompleto[512];
    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", caminhoDiretorio, nomeArquivo);

    // Abre o arquivo para escrita
    FILE* arquivo = fopen(caminhoCompleto, "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s para escrita.\n", caminhoCompleto);
        return;
    }

    // Imprime a árvore no arquivo
    fprintf(arquivo, "Árvore de Derivação:\n");
    imprimirArvoreArquivo(arvore, 0, arquivo);

    fclose(arquivo);
    printf("Arvore salva no arquivo: %s\n", caminhoCompleto);
}

// Libera a memória da árvore
// Entrada: ponteiro para a árvore
// Saída: nenhuma
void liberarArvore(No* arvore) {
    for (int i = 0; i < arvore->num_filhos; i++) {
        if (arvore->filhos[i] != NULL) {
            liberarArvore(arvore->filhos[i]);
        }
    }
    free(arvore->filhos);
    free(arvore);
}