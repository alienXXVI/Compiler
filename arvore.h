#ifndef ARVORE
#define ARVORE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore
typedef struct NoArvore {
    char *valor;               // Valor associado ao nó
    int numFilhos;             // Número atual de filhos
    struct NoArvore **filhos;  // Ponteiro para os filhos
} NoArvore;

// Criar um novo nó com filhos
// Entrada: nome do nó (char*) seguido de número de filhos e seus nomes
// Saída: nó criado (NoArvore*)
NoArvore *criarNo(const char *valor, int numFilhos, ...);

// Adicionar vários filhos a um nó existente
// Entrada: nó pai, número de filhos e seus nomes
// Saída: nenhuma
void adicionarFilhos(NoArvore *pai, int numFilhos, ...);

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
void imprimirArvore(NoArvore *no, int nivel);

// Escrever a árvore em níveis em um arquivo
// Entrada: ponteiro para a raíz (NoArvore*), profundidade (int) e o arquivo
// Saída: nenhuma
void imprimirArvoreArquivo(NoArvore *no, int nivel, FILE *arquivo);

// Liberar memória da árvore
// Entrada: nó raiz da árvore
// Saída: nenhuma
void liberarArvore(NoArvore *no);


#endif