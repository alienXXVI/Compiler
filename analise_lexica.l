%{
    #include <stdio.h>
    #include "hash_table.h"

    TabelaSimbolo *T;
    TabelaReservada *R;

    int linhasArq = 1;
%}

%option noyywrap

LETRA               [a-zA-Z]
DIGITO              [0-9]
IDENTIFICADOR       (_|{LETRA})(_|{LETRA}|{DIGITO})*
NATURAL_SEM_ZERO    [1-9]
NATURAL             (({NATURAL_SEM_ZERO}{DIGITO}*)|0)
INTEIRO             [-+]?{NATURAL}
REAL                {INTEIRO}([.,]{DIGITO}*)?
CARACTER            ('.')|''
CADEIA              \"[^\"\n]*\"

IF                  if
ELSE                else
WHILE               while
FOR                 for
DO                  do
RETURN              return

INT                 int
FLOAT               float
CHAR                char
VOID                void
STRING              string

COMENTARIO          "//"(.*)
SOMA                "+"
MULTIPLICACAO       "*"
DIVISAO             "/"
SUBTRACAO           "-"
ATRIBUICAO          "="

STRUCT              struct
ENUM                enum
DEFINE              #define
INCLUDE             #include

BRANCO              [ \t]+
EOL                 [\n\r]
DELIMITADORES       ("(")|(")")|("{")|("}")|("[")|("]"|,)
ERRO1_1             [!#@$%&*,.;<>:^~0-9=|]+({IF}|{ELSE}|{WHILE}|{FOR}|{DO}|{RETURN}|{INT}|{FLOAT}|{CHAR}|{VOID}|{STRUCT}|{ENUM})
ERRO1_2             ({IF}|{ELSE}|{WHILE}|{FOR}|{DO}|{RETURN}|{INT}|{FLOAT}|{CHAR}|{VOID}|{STRUCT}|{ENUM})[!#@$%&*,.;<>:^~0-9=|]+
ERRO1_3             [!#@$%&*,.;<>:^~0-9=|]+({IF}|{ELSE}|{WHILE}|{FOR}|{DO}|{RETURN}|{INT}|{FLOAT}|{CHAR}|{VOID}|{STRUCT}|{ENUM})[!#@$%&*,.;<>:^~0-9=|]+
ERRO1_4_1           ([!#@$%&*,.;<>:^~0-9=|]+({DEFINE}|{INCLUDE}))
ERRO1_4_2           (({DEFINE}|{INCLUDE})[!#@$%&*,.;<>:^~0-9=|]+)
ERRO1_4_3           ([!#@$%&*,.;<>:^~0-9=|]+({DEFINE}|{INCLUDE})[!#@$%&*,.;<>:^~0-9=|]+)
ERRO1_4             {ERRO1_4_1}|{ERRO1_4_2}|{ERRO1_4_3}
ERRO1_PALAVRA       {ERRO1_1}|{ERRO1_2}|{ERRO1_3}|{ERRO1_4}

ERRO2_1             [!#@$%&*,.;<>:^~0-9]+{IDENTIFICADOR}
ERRO2_2             {IDENTIFICADOR}[!#@$%&*,.;<>:^~]+
ERRO2_3             [!#@$%&*,.;<>:^~0-9]+{IDENTIFICADOR}[!#@$%&*,.;<>:^~]+
ERRO2_ID            {ERRO2_1}|{ERRO2_2}|{ERRO2_3}

ERRO3_SOMA          ({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})+{SOMA}({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})*
ERRO3_MULTIPLICAO   ({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})+{MULTIPLICACAO}({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})*
ERRO3_DIVISAO       ({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})+{DIVISAO}({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})*
ERRO3_SUBTRACAO     ({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})+{SUBTRACAO}({SOMA}|{MULTIPLICACAO}|{DIVISAO}|{SUBTRACAO})*
ERRO3_OP            ({ERRO3_SOMA}|{ERRO3_DIVISAO}|{ERRO3_SUBTRACAO}|{ERRO3_MULTIPLICAO})

%%
{BRANCO}            {;}
{EOL}               {linhasArq++;}

{ERRO1_PALAVRA}     {printf("(%d) Erro 1 - palavra reservada mal formada: %s\n", linhasArq, yytext);}
{ERRO3_OP}          {printf("(%d) Erro 3 - operador mal formado: %s\n", linhasArq, yytext);}

{IF}                {inserirReservada(yytext, R);}
{ELSE}              {inserirReservada(yytext, R);}
{WHILE}             {inserirReservada(yytext, R);}
{FOR}               {inserirReservada(yytext, R);}
{DO}                {inserirReservada(yytext, R);}
{RETURN}            {inserirReservada(yytext, R);}

{INT}               {inserirReservada(yytext, R);}
{FLOAT}             {inserirReservada(yytext, R);}
{CHAR}              {inserirReservada(yytext, R);}
{VOID}              {inserirReservada(yytext, R);}
{STRING}            {inserirReservada(yytext, R);}

{STRUCT}            {inserirReservada(yytext, R);}
{ENUM}              {inserirReservada(yytext, R);}
{DEFINE}            {inserirReservada(yytext, R);}
{INCLUDE}           {inserirReservada(yytext, R);}

{IDENTIFICADOR}     {inserirSimbolo(yytext, 0, T);}
{INTEIRO}           {inserirSimbolo(yytext, 1, T);}
{REAL}              {inserirSimbolo(yytext, 2, T);}
{CARACTER}          {inserirSimbolo(yytext, 3, T);}
{CADEIA}            {inserirSimbolo(yytext, 4, T);}

{COMENTARIO}        {;}
{SOMA}              {inserirReservada(yytext, R);}
{MULTIPLICACAO}     {inserirReservada(yytext, R);}
{DIVISAO}           {inserirReservada(yytext, R);}
{SUBTRACAO}         {inserirReservada(yytext, R);}
{ATRIBUICAO}        {inserirReservada(yytext, R);}

{ERRO2_ID}          {printf("(%d) Erro 2 - identificador mal formado: %s\n", linhasArq, yytext);}

{DELIMITADORES}     {;}

%%

int main(int argc, char *argv[]) {
    T = iniciarTabelaSimbolo();
    R = iniciarTabelaReservada();

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    } 

    yylex();
    printf("\n");
    imprimirTabelaReservada(R);
    imprimirTabelaSimbolo(T);

    return 0;
}