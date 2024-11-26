%{
    #include <stdio.h>
    #include <string.h>
    #include "hash_table.h"
    #include "analise_sintatica.tab.h"

    TabelaSimbolo *T;
    TabelaReservada *R;

    extern int linhasArq = 1;
%}

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

{IF}                {inserirReservada(yytext, R);   return IF;}
{ELSE}              {inserirReservada(yytext, R);   return ELSE;}
{WHILE}             {inserirReservada(yytext, R);   return WHILE;}
{FOR}               {inserirReservada(yytext, R);   return FOR;}
{DO}                {inserirReservada(yytext, R);   return DO;}
{SWITCH}            {inserirReservada(yytext, R);   return SWITCH;}
{CASE}              {inserirReservada(yytext, R);   return CASE;}
{BREAK}             {inserirReservada(yytext, R);   return BREAK;}
{RETURN}            {inserirReservada(yytext, R);   return RETURN;}
{DEFAULT}           {inserirReservada(yytext, R);   return DEFAULT;}

{INT}               {inserirReservada(yytext, R);   return INT;}
{FLOAT}             {inserirReservada(yytext, R);   return FLOAT;}
{CHAR}              {inserirReservada(yytext, R);   return CHAR;}
{VOID}              {inserirReservada(yytext, R);   return VOID;}
{STRING}            {inserirReservada(yytext, R);   return STRING;}

{STRUCT}            {inserirReservada(yytext, R);   return STRUCT;}
{ENUM}              {inserirReservada(yytext, R);   return ENUM;}
{DEFINE}            {inserirReservada(yytext, R);   return DEFINE;}
{INCLUDE}           {inserirReservada(yytext, R);   return INCLUDE;}

{SCAN}              {inserirReservada(yytext, R);   return SCAN;}
{PRINT}             {inserirReservada(yytext, R);   return PRINT;}

{IDENTIFICADOR}     {inserirSimbolo(yytext, 0, T);  yylval.string = (char*) strdup(yytext); return IDENTIFICADOR;}
{INTEIRO}           {inserirSimbolo(yytext, 1, T);  yylval.inteiro = atoi(yytext); return INTEIRO;}
{REAL}              {inserirSimbolo(yytext, 2, T);  yylval.real = atof(yytext); return REAL;}
{CARACTER}          {inserirSimbolo(yytext, 3, T);  yylval.caractere = (char*) strdup(yytext); return CARACTER;}
{CADEIA}            {inserirSimbolo(yytext, 4, T);  yylval.string = (char*) strdup(yytext); return CADEIA;}
{FILE_NAME}         {inserirSimbolo(yytext, 4, T);  yylval.string = (char*) strdup(yytext); return FILE_NAME;}

{COMENTARIO}        {;}
{SOMA}              {inserirReservada(yytext, R);   return SOMA;}
{MULTIPLICACAO}     {inserirReservada(yytext, R);   return MULTIPLICACAO;}
{DIVISAO}           {inserirReservada(yytext, R);   return DIVISAO;}
{SUBTRACAO}         {inserirReservada(yytext, R);   return SUBTRACAO;}
{RECEBE}            {inserirReservada(yytext, R);   return RECEBE;}

{IGUAL}             {inserirReservada(yytext, R);   return IGUAL;}
{DIFERENTE}         {inserirReservada(yytext, R);   return DIFERENTE;}
{MAIOR}             {inserirReservada(yytext, R);   return MAIOR;}
{MENOR}             {inserirReservada(yytext, R);   return MENOR;}
{MAIOR_IGUAL}       {inserirReservada(yytext, R);   return MAIOR_IGUAL;}
{MENOR_IGUAL}       {inserirReservada(yytext, R);   return MENOR_IGUAL;}

{E_LOGICO}          {inserirReservada(yytext, R);   return E_LOGICO;}
{OU_LOGICO}         {inserirReservada(yytext, R);   return OU_LOGICO;}
{NOT_LOGICO}        {inserirReservada(yytext, R);   return NOT_LOGICO;}

{ERRO2_ID}          {printf("(%d) Erro 2 - identificador mal formado: %s\n", linhasArq, yytext);}

{ABRE_P}            {inserirReservada(yytext, R);   return ABRE_P;}
{FECHA_P}           {inserirReservada(yytext, R);   return FECHA_P;}
{ABRE_CH}           {inserirReservada(yytext, R);   return ABRE_CH;}
{FECHA_CH}          {inserirReservada(yytext, R);   return FECHA_CH;}
{ABRE_COL}          {inserirReservada(yytext, R);   return ABRE_COL;}
{FECHA_COL}         {inserirReservada(yytext, R);   return FECHA_COL;}
{VIRGULA}           {inserirReservada(yytext, R);   return VIRGULA;}
{ASPAS_DUPLAS}      {inserirReservada(yytext, R);   return ASPAS_DUPLAS;}
{PONTO_VIRGULA}     {inserirReservada(yytext, R);   return PONTO_VIRGULA;}
{DOIS_PONTOS}       {inserirReservada(yytext, R);   return DOIS_PONTOS;}

%%

int yywrap(){
    return 1;
}

// int main(int argc, char *argv[]) {
//     T = iniciarTabelaSimbolo();
//     R = iniciarTabelaReservada();

//     yyin = fopen(argv[1], "r");
//     if(yyin == NULL) {
//         printf("Erro ao abrir o arquivo.\n");
//         exit(1);
//     } 

//     yylex();
//     printf("\n");
//     imprimirTabelaReservada(R);
//     imprimirTabelaSimbolo(T);

//     return 0;
// }

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
