%{
    #include <stdio.h>
    #include "arvore.h"
    #include "hash_table.h"
    
    extern int yylex();
    extern int yyparse();
    void yyerror();

    extern FILE *yyin; // Variável para o arquivo de entrada
    extern int yynerrs;
    int linhasArq = 1;

    TabelaSimbolo *T;
    TabelaReservada *R;
%}

%union {
    int inteiro;
    double real;
    char* string;
    char caractere;
}

%token  <inteiro> INTEIRO
%token  <real> REAL
%token  <string> IDENTIFICADOR CADEIA FILE_NAME
%token  <caractere> CARACTER

%token  IF ELSE WHILE FOR DO SWITCH CASE RETURN BREAK DEFAULT
%token  INT FLOAT CHAR VOID STRING
%token  STRUCT ENUM DEFINE INCLUDE
%token  SCAN PRINT
%token  SOMA MULTIPLICACAO DIVISAO SUBTRACAO RECEBE
%token  IGUAL DIFERENTE MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL
%token  E_LOGICO OU_LOGICO NOT_LOGICO
%token  ABRE_P FECHA_P ABRE_CH FECHA_CH ABRE_COL FECHA_COL VIRGULA ASPAS_DUPLAS DOIS_PONTOS PONTO_VIRGULA

%%

programa:
    sentencas_include sentencas_define funcoes
    ;

// Include
sentencas_include:
    sentenca_include sentencas_include | 
    // vazio
    ;
sentenca_include:
    include menor nome_arquivo maior |
    include aspas_duplas nome_arquivo aspas_duplas
    ;

// Define
sentencas_define:
    sentenca_define sentencas_define |
    // vazio
    ;
sentenca_define:
    define identificador valor_define
    ;
valor_define:
    real |
    identificador |
    string
    ;

// Funções
funcoes:
    funcao funcoes |
    // vazio
    ;
funcao:
    tipo_dado identificador abre_p parametros_funcao fecha_p corpo
    ;
parametros_funcao:
    parametro_funcao |
    parametro_funcao virgula parametros_funcao |
    // vazio
    ;
parametro_funcao:
    tipo_dado identificador
    ;

// Comandos
corpo:
    abre_ch comandos fecha_ch
    ;
comandos:
    comando comandos |
    comando
    ;
comando:
    decl_var |
    atribuicao |
    sentenca_if |
    sentenca_while |
    sentenca_for |
    sentenca_do |
    sentenca_scan |
    sentenca_print |
    chamada_funcao |
    sentenca_return |
    sentenca_switch |
    // vazio
    ;

// Declaração
decl_var:
    tipo_dado identificador |
    tipo_dado atribuicao |
    tipo_dado identificador virgula decl_var |
    tipo_dado atribuicao virgula decl_var
    ;

// Atribuição
atribuicao:
    identificador recebe expressao |
    identificador recebe atribuicao
    ;
expressao: 
    operacao |
    operando
    ;
operacao: 
    operando op operando
    ;
operando: 
    literal |
    abre_p operacao fecha_p
    ;
op: 
    op_aritmetico |
    op_relacional |
    op_logico
    ;

// Condição
sentenca_if: 
    if abre_p expressao fecha_p corpo |
	if abre_p expressao fecha_p corpo else corpo
    ;

// Repetição
sentenca_while: 
    while abre_p expressao fecha_p corpo
    ;
sentenca_for: 
    for abre_p decl_var ponto_virgula expressao ponto_virgula atribuicao fecha_p corpo
    ;
sentenca_do:
    do corpo while abre_p expressao fecha_p
    ;

// Leitura e Escrita de Dados
sentenca_scan:
    scan abre_p parametros_scan fecha_p
    ;
parametros_scan:
    identificador |
    identificador virgula parametros_scan
    ;
sentenca_print:
    print abre_p parametros_print fecha_p
    ;
parametros_print:
    string parametros_print |
    identificador parametros_print |
    ponto_virgula parametros_print |
    // vazio
    ;
    
// Retorno de Função
sentenca_return:
    return expressao
    ;

// Switch-Case
sentenca_switch:
    switch abre_p expressao fecha_p abre_ch cases fecha_ch
    ;
cases:
    sentenca_case cases |
    default |
    // vazio
    ;
sentenca_case:
    case inteiro dois_pontos comandos break
    ;

// Chamada de Função
chamada_funcao:
    identificador abre_p argumentos fecha_p
    ;
argumentos: 
    expressao |
    expressao virgula argumentos |
    // vazio
    ;


include: INCLUDE;
define: DEFINE
nome_arquivo: FILE_NAME;

tipo_dado: int | float | char | void | string;
int: INT;
float: FLOAT;
char: CHAR;
void: VOID;
string: STRING;

literal: inteiro | real | caracter | cadeia | identificador;
inteiro: INTEIRO;
real: REAL;
caracter: CARACTER;
cadeia: CADEIA;
identificador: IDENTIFICADOR;

op_aritmetico: soma | subtracao | multiplicacao | divisao;
soma: SOMA;
subtracao: SUBTRACAO;
multiplicacao: MULTIPLICACAO;
divisao: DIVISAO;
recebe: RECEBE;

op_relacional: igual | diferente | maior | menor | maior_igual | menor_igual;
igual: IGUAL;
diferente: DIFERENTE;
maior: MAIOR;
menor: MENOR;
maior_igual: MAIOR_IGUAL;
menor_igual: MENOR_IGUAL;

op_logico: e_logico | ou_logico | not_logico;
e_logico: E_LOGICO;
ou_logico: OU_LOGICO;
not_logico: NOT_LOGICO;

if: IF;
else: ELSE;
switch: SWITCH;
case: CASE;
break: BREAK;
default: DEFAULT;

while: WHILE;
for: FOR;
do: DO;

scan: SCAN;
print: PRINT;
return: RETURN;

virgula: VIRGULA;
ponto_virgula: PONTO_VIRGULA;
aspas_duplas: ASPAS_DUPLAS;
dois_pontos: DOIS_PONTOS;
abre_p: ABRE_P;
fecha_p: FECHA_P;
abre_ch: ABRE_CH;
fecha_ch: FECHA_CH;
abre_col: ABRE_COL;
fecha_col: FECHA_COL;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Erro: %s\n", msg);
    exit(1);
}

int main(int argc, char **argv) {
    T = iniciarTabelaSimbolo();
    R = iniciarTabelaReservada();

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    // Abrindo o arquivo de entrada
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    yyparse();

    // Verifica se houve erro de sintaxe
    if (yynerrs == 0) {
        FILE *arquivo = fopen("arvore_derivacao.txt", "w");
        if (arquivo == NULL) {
            fprintf(stderr, "Erro ao abrir o arquivo.\n");
            return 1;
        }

        // Imprime a árvore no arquivo
        // fprintf(arquivo, "Árvore de Derivação:\n");
        // imprimirArvoreArquivo(raiz, 0, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro na análise sintática. Não foi gerado o arquivo.\n");
    }

    // liberarArvore(raiz);
    fclose(yyin);
    return 0;
}