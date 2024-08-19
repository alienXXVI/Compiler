#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

// Tamanho da tabela hash de simbolos
#define TAM 1000
// Tamanho da tabela hash de palavras reservadas
#define TAM_R 1000

// -------------------------------------------------------------------------

int somaCaracteres(char *str) {
    int soma = 0;

    while (*str) {
        soma += (int)(*str);
        str++;
    }
    return soma;
}

// Cálculo hash para posição na tabela
// Entrada: chave (inteiro)
// Saída: posição na tabela (inteiro)
int funcaoHash(int chave) {
    return chave % TAM;
}

// -------------------------------------------------------------------------

const char* getCategoriaNome(Categoria cat) {
    switch (cat) {
        case IDENTIFICADOR: return "identificador";
        case INTEIRO:       return "inteiro";
        case REAL:          return "real";
        case CARACTER:      return "caracter";
        case STRING:        return "string";
        default:            return "desconhecido";
    }
}

// Imprime todas os símbolos e suas informações
// Entrada: ponteiro para uma TabelaSimbolo
// Saída: nenhuma
void imprimirTabelaSimbolo(TabelaSimbolo *T) {
    if(T != NULL) {
        printf("--- TABELA DE SIMBOLOS ---\n");
        for(int i = 0; i < TAM; i++) {
            if(T->tabela[i] != NULL) {
                printf("Tabela[%d]\n", i);
                printf("id = %d\n", T->tabela[i]->id);
                printf("lexema = %s\n", T->tabela[i]->lexema);
                printf("categoria = %s\n\n", getCategoriaNome(T->tabela[i]->categoria));
            }
        }
    }
}

// Inicia a tabela de simbolo com seus valores iguais a NULL
// Entrada: nenhuma
// Saída: ponteiro para uma TabelaSimbolo
TabelaSimbolo* iniciarTabelaSimbolo() {
    TabelaSimbolo* novaTabela = (TabelaSimbolo*) malloc(sizeof(TabelaSimbolo));

    novaTabela->tabela = (Simbolo**) malloc(TAM * sizeof(Simbolo*));
    for(int i = 0; i < TAM; i++) 
        novaTabela->tabela[i] = NULL;

    return novaTabela;
}

// Busca um lexema na tabela de simbolos, se 1, encontrou, se 0, não encontrou
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaSimbolo
// Saída: posição (inteiro) na tabela de simbolos (id hash)
int buscarSimbolo(char *lexema, TabelaSimbolo *T) {
    int id = funcaoHash(somaCaracteres(lexema));

    while(T->tabela[id] != NULL) {
        if(strcmp(T->tabela[id]->lexema, lexema) == 0)
            return 1;
        else
            id = funcaoHash(id + 1);
    }
    return 0;
}

// Insere um lexema na tabela de simbolos (sem repetições)
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaSimbolo
// Saída: nenhuma
void inserirSimbolo(char *lexema, int categoria, TabelaSimbolo *T) {
    int chave = somaCaracteres(lexema);
    int id = funcaoHash(chave);

    if(buscarSimbolo(lexema, T)) {
        // printf("simbolo ja presente\n");
        return;
    }

    while(T->tabela[id] != NULL) 
        id = funcaoHash(chave + 1);

    T->tabela[id] = malloc(sizeof(Simbolo));
    T->tabela[id]->lexema = malloc(sizeof(char) * 50);

    strcpy(T->tabela[id]->lexema, lexema);
    T->tabela[id]->id = chave;
    T->tabela[id]->categoria = categoria;
}

// -------------------------------------------------------------------------

// Imprime todas as palavras reservadas e suas informações
// Entrada: ponteiro para uma TabelaReservada
// Saída: nenhuma
void imprimirTabelaReservada(TabelaReservada *T) {
    if(T != NULL) {
        printf("--- TABELA DE PALAVRAS RESERVADAS ---\n");
        for(int i = 0; i < TAM; i++) {
            if(T->tabela[i] != NULL) {
                printf("Tabela[%d]\n", i);
                printf("id = %d\n", T->tabela[i]->id);
                printf("lexema = %s\n\n", T->tabela[i]->lexema);
            }
        }
    }
}

// Inicia a tabela de palavras reservadas com seus valores iguais a NULL
// Entrada: nenhuma
// Saída: ponteiro para uma TabelaReservada
TabelaReservada* iniciarTabelaReservada() {
    TabelaReservada* novaTabela = (TabelaReservada*) malloc(sizeof(TabelaReservada));

    novaTabela->tabela = (Reservada**) malloc(TAM * sizeof(Reservada*));
    for(int i = 0; i < TAM; i++) 
        novaTabela->tabela[i] = NULL;

    return novaTabela;
}

// Busca um lexema na tabela de palavras reservadas, se 1, encontrou, se 0, não encontrou
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaReservada
// Saída: posição (inteiro) na tabela de palavras reservadas (id hash)
int buscarReservada(char *lexema, TabelaReservada *T) {
    int id = funcaoHash(somaCaracteres(lexema));

    while((T->tabela[id]) != NULL) {
        if(strcmp(T->tabela[id]->lexema, lexema) == 0)
            return 1;
        else
            id = funcaoHash(id + 1);
    }
    return 0;
}

// Insere um lexema na tabela de palavras reservadas (sem repetições)
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaReservada
// Saída: nenhuma
void inserirReservada(char *lexema, TabelaReservada *T) {
    int chave = somaCaracteres(lexema);
    int id = funcaoHash(chave);

    if(buscarReservada(lexema, T)) {
        // printf("palavra reservada ja presente\n");
        return;
    }

    while(T->tabela[id] != NULL) 
        id = funcaoHash(chave + 1);

    T->tabela[id] = malloc(sizeof(Reservada));
    T->tabela[id]->lexema = malloc(sizeof(char) * 50);

    strcpy(T->tabela[id]->lexema, lexema);
    T->tabela[id]->id = chave;
}