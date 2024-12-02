#ifndef ARVORE
#define ARVORE
#define MAX 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore
typedef struct No {
    char valor[MAX];
    int num_filhos;
    struct No** filhos;
} No;

// Estrutura da pilha de filhos
typedef struct PilhaFilhos {
    No* no;
    struct PilhaFilhos* prox;
} PilhaFilhos;

// Cria um novo nó
// Entrada: valor do nó e número de filhos
// Saída: nó criado
No* criarNo(char* valor, int num_filhos);

// Empilha um nó na pilha de filhos
// Entrada: pilha em questão e nó a ser empilhado
// Saída: nenhuma
void empilharFilho(PilhaFilhos** pilha, No* no);

// Desempilha um nó da pilha de filhos
// Entrada: pilha em questão
// Saída: nó desempilhado
No* desempilharFilho(PilhaFilhos** pilha);

// Imprimir a pilha
// Entrada: pilha a ser impressa
// Saída: nenhuma
void imprimirPilha(PilhaFilhos* pilha);

// Associa filhos a um nó pai
// Entrada: ponteiro ao nó pai, pilha de nós e número de filhos
// Saída: nenhuma
void associarFilhos(No* pai, PilhaFilhos** pilha, int num_filhos);

// Insere um nó na árvore
// Entrada: pilha de nós, valor do nó e seu número de filhos
// Saída: nenhuma
void inserir(PilhaFilhos** pilha, char* valor, int num_filhos);

// Imprime a árvore na tela
// Entrada: ponteiro para a árvore e seu nível (começa com 0)
// Saída: nenhuma
void imprimirArvore(No* arvore, int nivel);

// Salva arvore em arquivi dado
// Entrada: ponteiro para a árvore, caminho para o diretório do arquivo e o nome do arquivo
// Saída: nenhuma
// Pós-condição: o arquivo será salvo no caminho dado, com o nome "arvore_NOME.txt"
void salvarArvoreEmArquivo(No* arvore, const char* caminhoDiretorio, const char* nomeArquivoOriginal);

// Libera a memória da árvore
// Entrada: ponteiro para a árvore
// Saída: nenhuma
void liberarArvore(No* arvore);

#endif