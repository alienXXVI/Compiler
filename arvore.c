#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "arvore.h"

// Criar um novo nó com filhos
// Entrada: nome do nó (char*) seguido de número de filhos e seus nomes
// Saída: nó criado (NoArvore*)
NoArvore *criarNo(const char *valor, int numFilhos, ...) {
    NoArvore *no = (NoArvore *)malloc(sizeof(NoArvore));
    no->valor = strdup(valor);
    no->numFilhos = numFilhos;
    no->filhos = (NoArvore **)malloc(numFilhos * sizeof(NoArvore *));
    
    va_list args;
    va_start(args, numFilhos);
    for (int i = 0; i < numFilhos; i++) {
        const char *filhoValor = va_arg(args, const char *);
        no->filhos[i] = criarNo(filhoValor, 0); // Filhos sem filhos próprios inicialmente
    }
    va_end(args);
    return no;
}

// Adicionar vários filhos a um nó existente
// Entrada: nó pai, número de filhos e seus nomes
// Saída: nenhuma
void adicionarFilhos(NoArvore *pai, int numFilhos, ...) {
    pai->filhos = (NoArvore **)realloc(pai->filhos, (pai->numFilhos + numFilhos) * sizeof(NoArvore *));
    
    va_list args;
    va_start(args, numFilhos);
    for (int i = 0; i < numFilhos; i++) {
        const char *filhoValor = va_arg(args, const char *);
        pai->filhos[pai->numFilhos + i] = criarNo(filhoValor, 0); // Filhos sem filhos próprios inicialmente
    }
    va_end(args);
    pai->numFilhos += numFilhos;
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

    // Imprimir o nó atual no formato especificado
    for (int i = 0; i < nivel; i++) {
        printf("|  ");
    }
    printf("+- %s\n", no->valor);

    // Recursão para imprimir os filhos
    for (int i = 0; i < no->numFilhos; i++) {
        imprimirArvore(no->filhos[i], nivel + 1);
    }
}

// Escrever a árvore em níveis em um arquivo
// Entrada: ponteiro para a raíz (NoArvore*), profundidade (int) e o arquivo
// Saída: nenhuma
void imprimirArvoreArquivo(NoArvore *no, int nivel, FILE *arquivo) {
    if (no == NULL || arquivo == NULL) return;

    // Escrever o nó atual no arquivo com o mesmo formato da impressão
    for (int i = 0; i < nivel; i++) {
        fprintf(arquivo, "|  ");
    }
    fprintf(arquivo, "+- %s\n", no->valor);

    // Recursão para os filhos
    for (int i = 0; i < no->numFilhos; i++) {
        imprimirArvoreArquivo(no->filhos[i], nivel + 1, arquivo);
    }
}

// Liberar memória da árvore
// Entrada: nó raiz da árvore
// Saída: nenhuma
void liberarArvore(NoArvore *no) {
    if (no == NULL) return;

    for (int i = 0; i < no->numFilhos; i++) {
        liberarArvore(no->filhos[i]);
    }
    free(no->valor);
    free(no->filhos);
    free(no);
}