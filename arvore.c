#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Criar um novo nó
// Entrada: nome do token (char*)
// Saída: nó criado (NoArvore*)
NoArvore *criarNo(const char *valor) {
    NoArvore *no = (NoArvore *)malloc(sizeof(NoArvore));
    no->valor = strdup(valor); // Aloca memória e copia o valor
    no->numFilhos = 0;         // Inicialmente, sem filhos
    no->filhos = NULL;         // Lista de filhos vazia
    return no;
}

// Adicionar um filho à árvore
// Entrada: ponteiro para o pai e ponteiro para o filho (NoArvore*)
// Saída: nenhuma
void adicionarFilho(NoArvore *pai, NoArvore *filho) {
    pai->numFilhos++;
    pai->filhos = (NoArvore **)realloc(pai->filhos, pai->numFilhos * sizeof(NoArvore *));
    pai->filhos[pai->numFilhos - 1] = filho;
}

// Imprimir a árvore em níveis
// Entrada: ponteiro para a raíz (NoArvore*) e a profundidade (int)
// Pré-condição: a profundidade deve começar com 0
/*
Árvore de Derivação:
+- Programa
|  +- Comando
|  |  +- TIPO_INT
|  |  +- SIMB_ATRIBUICAO
|  |  +- Expressao
|  |     +- Valor
*/
void imprimirArvore(NoArvore *no, int nivel) {
    if (no == NULL) return;
    
    // Imprime o nó atual
    for (int i = 0; i < nivel; i++) {
        printf("|  ");
    }

    // Caractere para mostrar as ramificações
    printf("+- %s\n", no->valor);

    // Recursão para imprimir os filhos
    for (int i = 0; i < no->numFilhos; i++) {
        imprimirArvore(no->filhos[i], nivel + 1);
    }
}


// Escrever a árvore em um arquivo
// Entrada: ponteiro para a raíz (NoArvore*) e o nome do arquivo
// Saída: nenhuma
void imprimirArvoreArquivo(NoArvore *no, int nivel, FILE *arquivo) {
    if (no == NULL) return;
    
    // Imprime o nó atual no arquivo
    for (int i = 0; i < nivel; i++) {
        fprintf(arquivo, "|  ");
    }

    // Caractere para mostrar as ramificações
    fprintf(arquivo, "+- %s\n", no->valor);

    // Recursão para imprimir os filhos no arquivo
    for (int i = 0; i < no->numFilhos; i++) {
        imprimirArvoreArquivo(no->filhos[i], nivel + 1, arquivo);
    }
}

// Liberar memória da árvore
// Entrada: ponteiro para a raíz (NoArvore)
// Saída: nenhuma
void liberarArvore(NoArvore *no) {
    if (no == NULL) return;

    // Libera memória dos filhos
    for (int i = 0; i < no->numFilhos; i++) {
        liberarArvore(no->filhos[i]);
    }

    // Libera o valor do nó e o próprio nó
    free(no->valor);
    free(no->filhos);
    free(no);
}