# Análise Léxica

Em `analise_lexica.l` é feita a inserção de tokens lidos do arquivo nas tabelas de símbolos e de palavras reservadas.

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
- **Erro 4** - reconhecimento de caracteres inválidos pela linguagem (`$` ou `~`)

## 2. Inserção de Tokens

Ao detectar um token, ele é inserido na tabela de símbolos ou de palavras reservadas, dependendo da sua natureza.

```lex
{IF}                {inserirReservada(yytext, R);}
{IDENTIFICADOR}     {inserirSimbolo(yytext, 0, T);}
```

Comentários e espaços em branco são ignorados.

## 3. Inicialização e Impressão das Tabelas

No `main`, as tabelas são inicializadas e após a varredura do arquivo, são printadas.

---

# Estruturas de Dados e Métodos

Em `hash_table.c` e `.h` estão as estruturas de dados e métodos para tratar as tabelas hashing.

## 1. Estrutura de Símbolo

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

## 2. Estrutura de Palavra Reservada

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
```
