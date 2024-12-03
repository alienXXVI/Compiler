# Análise Léxica

Em `analise_lexica.l` é feita a inserção de tokens lidos do arquivo nas tabelas de símbolos e de palavras reservadas.

<br>

## 1. Expressões Regulares

Expressões Regulares são criadas para reconhecer padrões ou a construção de padrões de tokens, como `STRING` ou `INT`.

```lex
LETRA               [a-zA-Z]
DIGITO              [0-9]
IDENTIFICADOR       (_|{LETRA})(_|{LETRA}|{DIGITO})*
```

### Tokens reconhecidos pela linguagem:
- **Palavras Reservadas de condição, repetição, etc.**
  - `IF`
  - `ELSE`
  - `WHILE`
  - `FOR`
  - `DO`
  - `RETURN`
  - `STRUCT`
  - `ENUM`
  - `DEFINE`
  - `INCLUDE`

- **Palavras Reservadas para declaração de tipo.**
  - `INT`
  - `FLOAT`
  - `CHAR`
  - `VOID`
  - `STRING`

- **Palavras Reservadas para operações.**
  - `SOMA`
  - `MULTIPLICAÇÃO`
  - `DIVISAO`
  - `SUBTRACAO`
  - `ATRIBUICAO`

- **Símbolos.**
  - `IDENTIFICADOR`
  - `INTEIRO`
  - `REAL`
  - `CARACTER`
  - `CADEIA`

### Erros reconhecidos pela linguagem:
- **Erro 1** - reconhecimento de palavras reservadas mal formadas (`if3`, `*while`)
- **Erro 2** - identificadores mal formados, não seguem o padrão solicitado (`90_aliana`)
- **Erro 3** - operadores mal formados, duplicados ou "compostos" (`++`, `+/`)

<br>

## 2. Inserção de Tokens

Ao detectar um token, ele é inserido na tabela de símbolos ou de palavras reservadas, dependendo da sua natureza.

```lex
{IF}                {inserirReservada(yytext, R);}
{IDENTIFICADOR}     {inserirSimbolo(yytext, 0, T);}
```

Comentários e espaços em branco são ignorados.

<br>

## 3. Inicialização e Impressão das Tabelas

No `main`, as tabelas são inicializadas e após a varredura do arquivo, são printadas.

---

<br>

## Estruturas de Dados e Métodos

Em `hash_table.c` e `.h` estão as estruturas de dados e métodos para tratar as tabelas hashing.

<br>

### 1. Estrutura de Símbolo

Um símbolo é armazenado em um "nó", que contém seu identificador, seu valor em string e sua categoria.

```c
typedef struct noS {
    int id;
    char *lexema;
    Categoria categoria;
} Simbolo;
```

Este nó faz parte de um total da tabela hashing para símbolos.

```c
typedef struct simbolos {
    Simbolo **tabela;
} TabelaSimbolo;
```

Um símbolo pode ter as seguintes categorias:
- `IDENTIFICADOR`
- `INTEIRO`
- `REAL`
- `CARACTER`
- `STRING`

<br>

### 2. Estrutura de Palavra Reservada

Uma palavra reservada é armazenada em um "nó", que contém seu identificador e seu valor em string.

```c
typedef struct noR {
    int id;
    char *lexema;
} Reservada;
```

Este nó faz parte de um total da tabela hashing para palavras reservadas.

```c
typedef struct reservadas {
    Reservada **tabela;
} TabelaReservada;
```

<br><br>

# Análise Sintática

Na fase de Análise Sintática (analise_sintatica.y) do compilador, em geral, é feita a verificação da relação entre tokens por meio das regras de uma gramática.

<br>

## Estruturas Sintáticas

Ao serem reconhecidas, um valor (nome) associado àquela estrutura é inserido na árvore de derivação, de baixo para cima.

### Programa

‘@’ = vazio; significa que aquela estrutura não precisa existir obrigatóriamente.

<br>

<details>
<summary>Sentenças Include</summary>
    
```c
#include <nome_arquivo>
#include “nome_arquivo”
@
```
- Nome Arquivo:
        
```c
arquivo.extensao
```
</details>
        
<br>

<details>
<summary>Sentenças Define</summary>

- Sentenças Define
    
    ```c
    #define identificador expressao
    @
    ```
    
    - Expressão
        - Operação
            
            ```c
            operando op operando
            !operando
            ```
            
            - Op Aritmético
                
                ```c
                +
                -
                *
                /
                ```
                
            - Op Relacional
                
                ```c
                ==
                !=
                >
                <
                >=
                <=
                ```
                
            - Op Lógico
                
                ```c
                &&
                ||
                !
                ```
                
        - Operando
            
            ```c
            (operacao)
            literal
            ```
            
            - Literal
                
                ```c
                inteiro, real, caractere, cadeia, identificador
                ```

</details>

<br>

<details>
<summary>Funções</summary>

- Funções
    
    ```c
    tipo_dado identificador ( parametros ) {
    	comandos
    }
    ```
    
    <details>
    <summary>Tipo Dado</summary>
    
    ```c
    int
    float
    char
    void
    string
    ```
    
    </details>
    
    <details>
    <summary>Parâmetros</summary>
    
    ```c
    tipo_dado identificador
    tipo_dado identificador, ...
    @
    ```
    
    </details>
    
    <details>
    <summary>Comandos</summary>
    
    ```c
    decl_var
    atribuicao
    sentenca_if
    sentenca_while
    sentenca_for
    sentenca_do
    sentenca_scan
    sentenca_print
    chamada_funcao
    sentenca_return
    sentenca_switch
    @
    ```
    
    <details>
    <summary>Declaração Variável</summary>
    
    ```c
    tipo_dado identificador
    tipo_dado atribuicao
    tipo_dado identificador, ...
    tipo_dado atribuicao, ...
    ```
    
    <details>
    <summary>Tipo Dado</summary>
    
    ```c
    int
    float
    char
    void
    string
    ```
    
    </details>
    
    <details>
    <summary>Atribuição</summary>
    
    ```c
    identificador = expressao
    identificador = atribuicao
    ```
    
    <details>
    <summary>Expressão</summary>
    
    - Operação
        
        ```c
        operando op operando
        !operando
        ```
        
        - Op Aritmético
            
            ```c
            +
            -
            *
            /
            ```
            
        - Op Relacional
            
            ```c
            ==
            !=
            >
            <
            >=
            <=
            ```
            
        - Op Lógico
            
            ```c
            &&
            ||
            !
            ```
            
    - Operando
        
        ```c
        (operacao)
        literal
        ```
        
        - Literal
            
            ```c
            inteiro, real, caractere, cadeia, identificador
            ```
    
    </details>
    
    </details>
    
    </details>
    
    <details>
    <summary>Atribuição</summary>
    
    ```c
    identificador = expressao
    identificador = atribuicao
    ```
    
    <details>
    <summary>Expressão</summary>
    
    - Operação
        
        ```c
        operando op operando
        !operando
        ```
        
        - Op Aritmético
            
            ```c
            +
            -
            *
            /
            ```
            
        - Op Relacional
            
            ```c
            ==
            !=
            >
            <
            >=
            <=
            ```
            
        - Op Lógico
            
            ```c
            &&
            ||
            !
            ```
            
    - Operando
        
        ```c
        (operacao)
        literal
        ```
        
        - Literal
            
            ```c
            inteiro, real, caractere, cadeia, identificador
            ```
    
    </details>
    
    </details>
    
    <details>
    <summary>Sentença If</summary>
    
    ```c
    if ( expressao ) {
    	comandos
    }
    
    if ( expressao ) {
    	comandos
    } else {
    	comandos
    }
    ```
    
    <details>
    <summary>Expressão</summary>
    
    - Operação
        
        ```c
        operando op operando
        !operando
        ```
        
        - Op Aritmético
            
            ```c
            +
            -
            *
            /
            ```
            
        - Op Relacional
            
            ```c
            ==
            !=
            >
            <
            >=
            <=
            ```
            
        - Op Lógico
            
            ```c
            &&
            ||
            !
            ```
            
    - Operando
        
        ```c
        (operacao)
        literal
        ```
        
        - Literal
            
            ```c
            inteiro, real, caractere, cadeia, identificador
            ```
    
    </details>
    
    </details>
    
    <details>
    <summary>Sentença While</summary>
    
    ```c
    while ( expressao ) {
    	comandos
    }
    ```
    
    <details>
    <summary>Expressão</summary>
    
    - Operação
        
        ```c
        operando op operando
        !operando
        ```
        
        - Op Aritmético
            
            ```c
            +
            -
            *
            /
            ```
            
        - Op Relacional
            
            ```c
            ==
            !=
            >
            <
            >=
            <=
            ```
            
        - Op Lógico
            
            ```c
            &&
            ||
            !
            ```
            
    - Operando
        
        ```c
        (operacao)
        literal
        ```
        
        - Literal
            
            ```c
            inteiro, real, caractere, cadeia, identificador
            ```
    
    </details>
    
    </details>
    
    <details>
    <summary>Sentença For</summary>
    
    ```c
    for ( parametros ) {
    	comandos
    }
    ```
    
    <details>
    <summary>Parâmetros</summary>
    
    - Declaração Variável
        
        ```c
        tipo_dado identificador
        tipo_dado atribuicao
        tipo_dado identificador, ...
        tipo_dado atribuicao, ...
        ```
        
        <details>
        <summary>Tipo Dado</summary>
        
        ```c
        int
        float
        char
        void
        string
        ```
        
        </details>
        
        <details>
        <summary>Atribuição</summary>
        
        ```c
        identificador = expressao
        identificador = atribuicao
        ```
        
        <details>
        <summary>Expressão</summary>
        
        - Operação
            
            ```c
            operando op operando
            ```
            
            - Op Aritmético
                
                ```c
                +
                -
                *
                /
                ```
                
            - Op Relacional
                
                ```c
                ==
                !=
                >
                <
                >=
                <=
                ```
                
            - Op Lógico
                
                ```c
                &&
                ||
                !
                ```
                
        - Operando
            
            ```c
            (operacao)
            literal
            ```
            
            - Literal
                
                ```c
                inteiro, real, caractere, cadeia, identificador
                ```
                
        
        </details>
        
        </details>
        
    - Expressão
        - Operação
            
            ```c
            operando op operando
            !operando
            ```
            
            - Op Aritmético
                
                ```c
                +
                -
                *
                /
                ```
                
            - Op Relacional
                
                ```c
                ==
                !=
                >
                <
                >=
                <=
                ```
                
            - Op Lógico
                
                ```c
                &&
                ||
                !
                ```
                
        - Operando
            
            ```c
            (operacao)
            literal
            ```
            
            - Literal
                
                ```c
                inteiro, real, caractere, cadeia, identificador
                ```
                
        
    </details>
    
    </details>
    
    <details>
    <summary>Sentença Do</summary>
    
    ```c
    do {
    	comandos
    } while ( expressao )
    ```
    
    <details>
    <summary>Expressão</summary>
    
    - Operação
        
        ```c
        operando op operando
        !operando
        ```
        
        - Op Aritmético
            
            ```c
            +
            -
            *
            /
            ```
            
        - Op Relacional
            
            ```c
            ==
            !=
            >
            <
            >=
            <=
            ```
            
        - Op Lógico
            
            ```c
            &&
            ||
            !
            ```
            
    - Operando
        
        ```c
        (operacao)
        literal
        ```
        
        - Literal
            
            ```c
            inteiro, real, caractere, cadeia, identificador
            ```
    
    </details>
    
    </details>
    
    <details>
    <summary>Sentença Scan</summary>
    
    ```c
    scan ( parametros )
    ```
    
    <details>
    <summary>Parâmetros</summary>
    
    ```c
    identificador
    identificador,...
    ```
    
    </details>
    
    </details>
    
    <details>
    <summary>Sentença Print</summary>
    
    ```c
    print ( parametros )
    ```
    
    <details>
    <summary>Parâmetros</summary>
    
    ```c
    "string"
    identificador
    "string";...
    identificador;...
    ```
    
    </details>
    
    </details>
    
    <details>
    <summary>Chamada Função</summary>
    
    ```c
    identificador ( argumentos )
    ```
    
    <details>
    <summary>Argumentos</summary>
    
    ```c
    expressao
    expressao,...
    @
    ```
    
    <details>
    <summary>Expressão</summary>
    
    - Operação
        
        ```c
        operando op operando
        !operando
        ```
        
        - Op Aritmético
            
            ```c
            +
            -
            *
            /
            ```
            
        - Op Relacional
            
            ```c
            ==
            !=
            >
            <
            >=
            <=
            ```
            
        - Op Lógico
            
            ```c
            &&
            ||
            !
            ```
            
    - Operando
        
        ```c
        (operacao)
        literal
        ```
        
        - Literal
            
            ```c
            inteiro, real, caractere, cadeia, identificador
            ```
    
    </details>
    
    </details>

    </details>
    
    <details>
    <summary>Sentença Return</summary>
    
    ```c
    return ( valor )
    ```
    
    <details>
    <summary>Valor</summary>
    
    ```c
    expressão
    ```
    

    
    </details>

    </details>
    
    <details>
    <summary>Sentença Switch</summary>
    
    ```c
    switch ( valor ) {
    	case x:
    	break
    }
    ```
    
    <details>
    <summary>Valor</summary>
    
    ```c
    expressão
    ```
    
    </details>
    
</details>
   
<br>

## Alguns Erros Sintáticos Comuns

Além de reconhecer os erros léxicos, na fase do parser, quando é encontrado um erro sintático, este é exibido na tela. Por exemplo:

1. **Falta de tipo de retorno em definição de funções**

```c
funcao(float a, float b)
```

2. **Falta de palavra-chave de fechamento**

```c
if (x > 5) {
    print(x)
else {
    print("Erro")
```

3. **Falta de parênteses em chamadas de função**

```c
print "Hello"
funcao a, b
```
<br>

## Árvore de Derivação

É gerado um arquivo de nome “arvore_nomeArquivo.txt” na pasta “arvores_geradas” com a árvore de derivação por onde o parser passou depois que uma “cadeia” (ou código fonte) é aceita.

Caso ocorra um erro, o arquivo não é criado e o erro é exibido.

A estrutura de um nó é dado por um valor (seu nome representativo), seu número de filhos e um ponteiro para a sua lista de filhos:

```c
typedef struct No {
    char valor[MAX];
    int num_filhos;
    struct No** filhos;
} No;
```

No main, as tabelas de símbolos e de palavras reservadas continuam sendo impressas.

<br>

## Compilação

Para compilar, é recomendado estar na pasta de caminho:

```c
cd C:\Users\...\Trabalho\src
```
<br>

Primeiro, é feita a compilação do parser em “analise_sintatica.y”.

Em seguida, do scanner em “analise_lexica.l”.

Por fim, os códigos em .c são compilados e o executável é gerado, em “.\gçç.exe”

```c
yacc -d analise_sintatica.y
lex analise_lexica.l
gcc (Get-ChildItem -Recurse -Path "C:\Users\...\Trabalho" -Filter "*.c").FullName -o gçç
```
<br>

Para testar um arquivo texto contendo um código fonte, basta chamar o executável “.\gçç” seguido do nome do arquivo (redirecionar para a pasta onde ele se encontra, se necessário).

```c
.\gçç ..\codigos_teste\teste_yacc.txt
```

<br>
