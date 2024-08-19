#ifndef HASH_TABLE
#define HASH_TABLE
#include <stdio.h>
#include <stdlib.h>

// Categoria de simbolos
typedef enum categoria {
    IDENTIFICADOR,
    INTEIRO,
    REAL,
    CARACTER,
    STRING,
} Categoria;

typedef struct noS{
    int id;
    char *lexema;
    Categoria categoria;
} Simbolo;

// Tabela Hash de Simbolos (identificadores, const, num)
// Ex: x, fun1, Pessoa, 5.12
typedef struct simbolos {
    Simbolo **tabela;
} TabelaSimbolo;


typedef struct noR{
    int id;
    char *lexema;
} Reservada;

// Tabela Hash de Palavras Reservadas
// Ex: if, else, for, ;, {, }...
typedef struct reservadas {
    Reservada **tabela;
} TabelaReservada;

// -------------------------------------------------------------------------

// Imprime todas os símbolos e suas informações
// Entrada: ponteiro para uma TabelaSimbolo
// Saída: nenhuma
void imprimirTabelaSimbolo(TabelaSimbolo *T);

// Inicia a tabela de simbolo com seus valores iguais a NULL
// Entrada: nenhuma
// Saída: ponteiro para uma TabelaSimbolo
TabelaSimbolo* iniciarTabelaSimbolo();

// Busca um lexema na tabela de simbolos
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaSimbolo
// Saída: posição (inteiro) na tabela de simbolos (id hash)
int buscarSimbolo(char *lexema, TabelaSimbolo *T);

// Insere um lexema na tabela de simbolos
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaSimbolo
// Saída: nenhuma
void inserirSimbolo(char *lexema, int categoria, TabelaSimbolo *T);



// Imprime todas as palavras reservadas e suas informações
// Entrada: ponteiro para uma TabelaReservada
// Saída: nenhuma
void imprimirTabelaReservada(TabelaReservada *T);

// Inicia a tabela de palavras reservadas com seus valores iguais a NULL
// Entrada: nenhuma
// Saída: ponteiro para uma TabelaReservada
TabelaReservada* iniciarTabelaReservada();

// Busca um lexema na tabela de palavras reservadas
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaReservada
// Saída: posição (inteiro) na tabela de palavras reservadas (id hash)
int buscarReservada(char *lexema, TabelaReservada *T);

// Insere um lexema na tabela de palavras reservadas
// Entrada: ponteiro para string do lexema, ponteiro para uma TabelaReservada
// Saída: nenhuma
void inserirReservada(char *lexema, TabelaReservada *T);

#endif