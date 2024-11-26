#ifndef ARVORE
#define ARVORE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore
typedef struct NoArvore {
    char *valor;               // Valor associado ao nó (nome da derivação)
    int numFilhos;             // Número atual de filhos
    struct NoArvore **filhos;  // Ponteiro para os filhos (lista dinâmica)
} NoArvore;

// Criar um novo nó
// Entrada: nome do token (char*)
// Saída: nó criado (NoArvore*)
NoArvore *criarNo(const char *valor);

// Adicionar um filho à árvore
// Entrada: ponteiro para o pai e ponteiro para o filho (NoArvore*)
// Saída: nenhuma
void adicionarFilho(NoArvore *pai, NoArvore *filho);

// Imprimir a árvore em níveis
// Entrada: ponteiro para a raíz (NoArvore*) e a profundidade (int)
// Pré-condição: a profundidade deve começar com 0
void imprimirArvore(NoArvore *no, int nivel);

// Escrever a árvore em um arquivo
// Entrada: ponteiro para a raíz (NoArvore*) e o nome do arquivo
// Saída: nenhuma
void imprimirArvoreArquivo(NoArvore *no, int nivel, FILE *arquivo);

// Liberar memória da árvore
// Entrada: ponteiro para a raíz (NoArvore)
// Saída: nenhuma
void liberarArvore(NoArvore *no);


#endif