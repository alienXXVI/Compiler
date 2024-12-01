%{
    #include <stdio.h>
    #include "arvore.h"
    #include "hash_table.h"
    
    extern int yylex();
    extern int yyparse();
    void yyerror(const char* msg);

    extern FILE *yyin; // Variável para o arquivo de entrada
    extern int yynerrs;

    TabelaSimbolo *T;
    TabelaReservada *R;
    PilhaFilhos* pilha = NULL;
    No* arvore = NULL;
    int linhasArq = 1;
    char str[200];

%}

%union {
    int inteiro;
    double real;
    char* string;
}

%token  <inteiro> INTEIRO
%token  <real> REAL
%token  <string> IDENTIFICADOR CADEIA FILE_NAME CARACTER

%token  IF ELSE WHILE FOR DO SWITCH CASE RETURN BREAK DEFAULT
%token  INT FLOAT CHAR VOID STRING
%token  STRUCT ENUM DEFINE INCLUDE
%token  SCAN PRINT
%token  SOMA MULTIPLICACAO DIVISAO SUBTRACAO RECEBE
%token  IGUAL DIFERENTE MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL
%token  E_LOGICO OU_LOGICO NOT_LOGICO
%token  ABRE_P FECHA_P ABRE_CH FECHA_CH VIRGULA DOIS_PONTOS PONTO_VIRGULA


%left OU_LOGICO
%left E_LOGICO
%left NOT_LOGICO
%left DIFERENTE IGUAL
%left MAIOR MAIOR_IGUAL MENOR_IGUAL MENOR
%left SUBTRACAO SOMA 
%left DIVISAO MULTIPLICACAO
%left FECHA_P ABRE_P

%%

programa:
    sentencas_include sentencas_define funcoes { 
        inserir(&pilha, "programa", 3);
        arvore = desempilharFilho(&pilha);
        associarFilhos(arvore, &pilha, 3);
    }
    ;

// -- Include --
sentencas_include:
      sentenca_include sentencas_include {
        inserir(&pilha, "sentencas_include", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "sentencas_include", 0);
    }
    ;
sentenca_include:
      include menor nome_arquivo maior {
        inserir(&pilha, "sentenca_include", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
      }
    | include cadeia {
        inserir(&pilha, "sentenca_include", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    ;

// -- Define --
sentencas_define:
      sentenca_define sentencas_define {
        inserir(&pilha, "sentencas_define", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    | /*vazio*/ {
        inserir(&pilha, "sentencas_define", 0);
    }
    ;
sentenca_define:
    define identificador valor_define {
        inserir(&pilha, "sentenca_define", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    ;
valor_define:
        expressao {
        inserir(&pilha, "valor_define", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    ;

// -- Funções --
funcoes:
      funcao funcoes { 
        inserir(&pilha, "funcoes", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    | /*vazio*/ {
        inserir(&pilha, "funcoes", 0);
    }
    ;
funcao:
    tipo_dado identificador abre_p parametros_funcao fecha_p corpo { 
        inserir(&pilha, "funcao", 6);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 6);
        empilharFilho(&pilha, no); 
    }
    ;
parametros_funcao:
      parametro_funcao {
        inserir(&pilha, "parametros_funcao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | parametro_funcao virgula parametros_funcao {
        inserir(&pilha, "parametros_funcao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "parametros_funcao", 0);
    }
    ;
parametro_funcao:
    tipo_dado identificador {
        inserir(&pilha, "parametro_funcao", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    ;

// -- Comandos --
corpo:
      abre_ch comandos fecha_ch {
        inserir(&pilha, "corpo", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "corpo", 0);
    }
    ;
comandos:
      comando comandos {
        inserir(&pilha, "comandos", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    | comando {
        inserir(&pilha, "comandos", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    ;
comando:
      decl_var {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | atribuicao {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_if {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_while {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_for {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_do {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_scan {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_print {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | chamada_funcao {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_return {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | sentenca_switch {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "comando", 0);
    } 
    ;

// -- Declaração --
decl_var:
      tipo_dado identificador decl_vars{
        inserir(&pilha, "decl_var", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
      }
    | tipo_dado atribuicao decl_vars{
        inserir(&pilha, "decl_var", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    ;
decl_vars:
      virgula identificador decl_vars {
        inserir(&pilha, "decl_vars", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
      }
    | virgula atribuicao decl_vars {
        inserir(&pilha, "decl_vars", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "decl_vars", 0);
    }
    ;

// -- Atribuição --
atribuicao:
      identificador recebe expressao {
        inserir(&pilha, "atribuicao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
      }
    | identificador recebe atribuicao {
        inserir(&pilha, "atribuicao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    ;
expressao: 
      operacao {
        inserir(&pilha, "expressao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | operando {
        inserir(&pilha, "expressao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    ;
operacao: 
      operando op operando {
        inserir(&pilha, "operacao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    | not_logico operando {
        inserir(&pilha, "operacao", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    ;
operando: 
      literal {
        inserir(&pilha, "operando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | abre_p operacao fecha_p {
        inserir(&pilha, "operando", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    | operacao {
        inserir(&pilha, "operando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    ;
op: 
      op_aritmetico {
        inserir(&pilha, "op", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | op_relacional {
        inserir(&pilha, "op", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | op_logico {
        inserir(&pilha, "op", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    ;

// Condição
sentenca_if: 
      if abre_p expressao fecha_p corpo {
        inserir(&pilha, "sentenca_if", 5);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 5);
        empilharFilho(&pilha, no);
      }
    | if abre_p expressao fecha_p corpo else corpo {
        inserir(&pilha, "sentenca_if", 7);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 7);
        empilharFilho(&pilha, no);
    }
    ;

// Repetição
sentenca_while: 
    while abre_p expressao fecha_p corpo {
        inserir(&pilha, "sentenca_while", 5);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 5);
        empilharFilho(&pilha, no);
    }
    ;
sentenca_for: 
    for abre_p decl_var ponto_virgula expressao ponto_virgula atribuicao fecha_p corpo {
        inserir(&pilha, "sentenca_for", 9);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 9);
        empilharFilho(&pilha, no);
    }
    ;
sentenca_do:
    do corpo while abre_p expressao fecha_p {
        inserir(&pilha, "sentenca_do", 6);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 6);
        empilharFilho(&pilha, no);
    }
    ;

// Leitura e Escrita de Dados
sentenca_scan:
    scan abre_p parametros_scan fecha_p {
        inserir(&pilha, "sentenca_scan", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
    }
    ;
parametros_scan:
      identificador {
        inserir(&pilha, "parametros_scan", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | identificador virgula parametros_scan {
        inserir(&pilha, "parametros_scan", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    ;
sentenca_print:
    print abre_p parametros_print fecha_p {
        inserir(&pilha, "sentenca_print", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
    }
    ;
parametros_print:
      string parametros_print {
        inserir(&pilha, "parametros_print", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    | identificador parametros_print {
        inserir(&pilha, "parametros_print", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    | ponto_virgula parametros_print {
        inserir(&pilha, "parametros_print", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "parametros_print", 0);
    }
    ;
    
// Retorno de Função
sentenca_return:
    return expressao {
        inserir(&pilha, "sentenca_return", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    ;

// Switch-Case
sentenca_switch:
    switch abre_p identificador fecha_p abre_ch cases fecha_ch {
        inserir(&pilha, "sentenca_switch", 7);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 7);
        empilharFilho(&pilha, no);
    }
    ;
cases:
      sentenca_case cases {
        inserir(&pilha, "cases", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    | default {
        inserir(&pilha, "cases", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "cases", 0);
    }
    ;
sentenca_case:
    case literal dois_pontos comandos {
        inserir(&pilha, "sentenca_case", 5);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 5);
        empilharFilho(&pilha, no);
    }
    ;

// Chamada de Função
chamada_funcao:
    identificador abre_p argumentos fecha_p {
        inserir(&pilha, "chamada_funcao", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
    }
    ;
argumentos: 
      expressao {
        inserir(&pilha, "argumentos", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | expressao virgula argumentos {
        inserir(&pilha, "argumentos", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | /*vazio*/ {
        inserir(&pilha, "argumentos", 0);
    }
    ;

include: INCLUDE { inserir(&pilha, "#include", 0); };
define: DEFINE { inserir(&pilha, "#define", 0); };
nome_arquivo: FILE_NAME { inserir(&pilha, $1, 0); };

tipo_dado:
      int { inserir(&pilha, "int", 0); } 
    | float { inserir(&pilha, "float", 0); }
    | char { inserir(&pilha, "char", 0); }
    | void { inserir(&pilha, "void", 0); }
    | string { inserir(&pilha, "string", 0); };
int: INT;
float: FLOAT;
char: CHAR;
void: VOID;
string: STRING;

literal: 
      inteiro {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    | real {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | caracter {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | cadeia {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    | identificador {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    };
inteiro: INTEIRO { sprintf(str, "%d", $1); inserir(&pilha, str, 0); };
real: REAL { sprintf(str, "%f", $1); inserir(&pilha, str, 0); };
caracter: CARACTER { inserir(&pilha, $1, 0); };
cadeia: CADEIA { inserir(&pilha, $1, 0); };
identificador: IDENTIFICADOR { inserir(&pilha, $1, 0);} ;

op_aritmetico: 
      soma { inserir(&pilha, "+", 0); }
    | subtracao { inserir(&pilha, "-", 0); }
    | multiplicacao { inserir(&pilha, "*", 0); }
    | divisao { inserir(&pilha, "/", 0); };
soma: SOMA;
subtracao: SUBTRACAO;
multiplicacao: MULTIPLICACAO;
divisao: DIVISAO;
recebe: RECEBE { inserir(&pilha, "=", 0); };;

op_relacional: 
      igual { inserir(&pilha, "==", 0); }
    | diferente { inserir(&pilha, "!=", 0); }
    | maior { inserir(&pilha, ">", 0); }
    | menor { inserir(&pilha, "<", 0); }
    | maior_igual { inserir(&pilha, ">=", 0); }
    | menor_igual { inserir(&pilha, "<=", 0); };
igual: IGUAL;
diferente: DIFERENTE;
maior: MAIOR;
menor: MENOR;
maior_igual: MAIOR_IGUAL;
menor_igual: MENOR_IGUAL;

op_logico:
      e_logico { inserir(&pilha, "&&", 0); }
    | ou_logico { inserir(&pilha, "||", 0); };
e_logico: E_LOGICO;
ou_logico: OU_LOGICO;
not_logico: NOT_LOGICO { inserir(&pilha, "!", 0); };

if: IF { inserir(&pilha, "if", 0); };
else: ELSE { inserir(&pilha, "else", 0); };
switch: SWITCH { inserir(&pilha, "switch", 0); };
case: CASE { inserir(&pilha, "case", 0); };
break: BREAK { inserir(&pilha, "break", 0); };
default: DEFAULT { inserir(&pilha, "default", 0); };

while: WHILE { inserir(&pilha, "while", 0); };
for: FOR { inserir(&pilha, "for", 0); };
do: DO { inserir(&pilha, "do", 0); };

scan: SCAN { inserir(&pilha, "scan", 0); };
print: PRINT { inserir(&pilha, "print", 0); };
return: RETURN { inserir(&pilha, "return", 0); };

virgula: VIRGULA { inserir(&pilha, ",", 0); };
ponto_virgula: PONTO_VIRGULA { inserir(&pilha, ";", 0); };
dois_pontos: DOIS_PONTOS { inserir(&pilha, ":", 0); };
abre_p: ABRE_P { inserir(&pilha, "(", 0); };
fecha_p: FECHA_P { inserir(&pilha, ")", 0); };
abre_ch: ABRE_CH { inserir(&pilha, "{", 0); };
fecha_ch: FECHA_CH { inserir(&pilha, "}", 0); };

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
    // printf("Tabelas de Tokens:\n");
    // imprimirTabelaSimbolo(T);
    // imprimirTabelaReservada(R);

    printf("\nArvore de Derivacao:\n");
    imprimirArvore(arvore, 0);  // Imprime a árvore gerada
    liberarArvore(arvore);
    

    // // Verifica se houve erro de sintaxe
    // if (yynerrs == 0) {
    //     FILE *arquivo = fopen("arvore_derivacao.txt", "w");
    //     if (arquivo == NULL) {
    //         fprintf(stderr, "Erro ao abrir o arquivo.\n");
    //         return 1;
    //     }

    //     // Imprime a árvore no arquivo
    //     // fprintf(arquivo, "Árvore de Derivação:\n");
    //     // imprimirArvoreArquivo(raiz, 0, arquivo);
    //     fclose(arquivo);
    // } else {
    //     printf("Erro na análise sintática. Não foi gerado o arquivo.\n");
    // }

    // liberarArvore(raiz);
    fclose(yyin);
    return 0;
}