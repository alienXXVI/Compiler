%{
    #include <stdio.h>
    #include <string.h>
    #include "hash_table.h"
    // #include "analise_sintatica.tab.h"

    TabelaSimbolo *T;
    TabelaReservada *R;

    // extern 
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
SWITCH              switch
CASE                case
BREAK               break
RETURN              return
DEFAULT             default

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
RECEBE              "="

IGUAL               "=="
DIFERENTE           "!="
MAIOR               ">"
MENOR               "<"
MAIOR_IGUAL         ">="
MENOR_IGUAL         "<="

E_LOGICO            "&&"
OU_LOGICO           "||"
NOT_LOGICO          "!"

STRUCT              struct
ENUM                enum
DEFINE              #define
INCLUDE             #include

SCAN                scan
PRINT               print
FILE_NAME           [a-zA-Z0-9_/\.-]+(\.h|\.cpp|\.c|\.txt|\.js|\.py)

BRANCO              [ \t]+
EOL                 [\n\r]
ABRE_P              "("
FECHA_P             ")"
ABRE_CH             "{"
FECHA_CH            "}"
ABRE_COL            "["
FECHA_COL           "]"
VIRGULA             ","
ASPAS_DUPLAS        \"
PONTO_VIRGULA       ";"
DOIS_PONTOS         ":"

ERRO1_1             [!#@$%&*,.;<>:^~0-9=|]+({IF}|{ELSE}|{WHILE}|{FOR}|{DO}|{RETURN}|{INT}|{FLOAT}|{CHAR}|{VOID}|{STRUCT}|{ENUM}|{PRINT}|{SCAN}|{SWITCH}|{CASE})
ERRO1_2             ({IF}|{ELSE}|{WHILE}|{FOR}|{DO}|{RETURN}|{INT}|{FLOAT}|{CHAR}|{VOID}|{STRUCT}|{ENUM}|{PRINT}|{SCAN}|{SWITCH}|{CASE})[!#@$%&*,.;<>:^~=|]+
ERRO1_3             [!#@$%&*,.;<>:^~0-9=|]+({IF}|{ELSE}|{WHILE}|{FOR}|{DO}|{RETURN}|{INT}|{FLOAT}|{CHAR}|{VOID}|{STRUCT}|{ENUM}|{PRINT}|{SCAN}|{SWITCH}|{CASE})[!#@$%&*,.;<>:^~0-9=|]+
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
{SWITCH}            {inserirReservada(yytext, R);}
{CASE}              {inserirReservada(yytext, R);}
{BREAK}             {inserirReservada(yytext, R);}
{RETURN}            {inserirReservada(yytext, R);}
{DEFAULT}           {inserirReservada(yytext, R);}

{INT}               {inserirReservada(yytext, R);}
{FLOAT}             {inserirReservada(yytext, R);}
{CHAR}              {inserirReservada(yytext, R);}
{VOID}              {inserirReservada(yytext, R);}
{STRING}            {inserirReservada(yytext, R);}

{STRUCT}            {inserirReservada(yytext, R);}
{ENUM}              {inserirReservada(yytext, R);}
{DEFINE}            {inserirReservada(yytext, R);}
{INCLUDE}           {inserirReservada(yytext, R);}

{SCAN}              {inserirReservada(yytext, R);}
{PRINT}             {inserirReservada(yytext, R);}

{IDENTIFICADOR}     {inserirSimbolo(yytext, 0, T);}
{INTEIRO}           {inserirSimbolo(yytext, 1, T);}
{REAL}              {inserirSimbolo(yytext, 2, T);}
{CARACTER}          {inserirSimbolo(yytext, 3, T);}
{CADEIA}            {inserirSimbolo(yytext, 4, T);}
{FILE_NAME}         {inserirSimbolo(yytext, 4, T);}

{COMENTARIO}        {;}
{SOMA}              {inserirReservada(yytext, R);}
{MULTIPLICACAO}     {inserirReservada(yytext, R);}
{DIVISAO}           {inserirReservada(yytext, R);}
{SUBTRACAO}         {inserirReservada(yytext, R);}
{RECEBE}            {inserirReservada(yytext, R);}

{IGUAL}             {inserirReservada(yytext, R);}
{DIFERENTE}         {inserirReservada(yytext, R);}
{MAIOR}             {inserirReservada(yytext, R);}
{MENOR}             {inserirReservada(yytext, R);}
{MAIOR_IGUAL}       {inserirReservada(yytext, R);}
{MENOR_IGUAL}       {inserirReservada(yytext, R);}

{E_LOGICO}          {inserirReservada(yytext, R);}
{OU_LOGICO}         {inserirReservada(yytext, R);}
{NOT_LOGICO}        {inserirReservada(yytext, R);}

{ERRO2_ID}          {printf("(%d) Erro 2 - identificador mal formado: %s\n", linhasArq, yytext);}

{ABRE_P}            {inserirReservada(yytext, R);}
{FECHA_P}           {inserirReservada(yytext, R);}
{ABRE_CH}           {inserirReservada(yytext, R);}
{FECHA_CH}          {inserirReservada(yytext, R);}
{ABRE_COL}          {inserirReservada(yytext, R);}
{FECHA_COL}         {inserirReservada(yytext, R);}
{VIRGULA}           {inserirReservada(yytext, R);}
{ASPAS_DUPLAS}      {inserirReservada(yytext, R);}
{PONTO_VIRGULA}     {inserirReservada(yytext, R);}
{DOIS_PONTOS}       {inserirReservada(yytext, R);}

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

// int main() {
//     T = iniciarTabelaSimbolo();
//     R = iniciarTabelaReservada();

//     printf("Digite o codigo a ser analisado (finalize com Ctrl+D em Unix/Linux ou Ctrl+Z em Windows):\n");

//     // Definindo yyin como stdin para leitura da entrada padrão
//     yyin = stdin;

//     // Chama o analisador léxico
//     yylex();

//     imprimirTabelaReservada(R);
//     imprimirTabelaSimbolo(T);

//     return 0;
// }
