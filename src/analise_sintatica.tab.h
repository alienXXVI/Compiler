/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ANALISE_SINTATICA_TAB_H_INCLUDED
# define YY_YY_ANALISE_SINTATICA_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEIRO = 258,
     REAL = 259,
     IDENTIFICADOR = 260,
     CADEIA = 261,
     FILE_NAME = 262,
     CARACTER = 263,
     IF = 264,
     ELSE = 265,
     WHILE = 266,
     FOR = 267,
     DO = 268,
     SWITCH = 269,
     CASE = 270,
     RETURN = 271,
     BREAK = 272,
     DEFAULT = 273,
     INT = 274,
     FLOAT = 275,
     CHAR = 276,
     VOID = 277,
     STRING = 278,
     DEFINE = 279,
     INCLUDE = 280,
     SCAN = 281,
     PRINT = 282,
     SOMA = 283,
     MULTIPLICACAO = 284,
     DIVISAO = 285,
     SUBTRACAO = 286,
     RECEBE = 287,
     IGUAL = 288,
     DIFERENTE = 289,
     MAIOR = 290,
     MENOR = 291,
     MAIOR_IGUAL = 292,
     MENOR_IGUAL = 293,
     E_LOGICO = 294,
     OU_LOGICO = 295,
     NOT_LOGICO = 296,
     ABRE_P = 297,
     FECHA_P = 298,
     ABRE_CH = 299,
     FECHA_CH = 300,
     VIRGULA = 301,
     DOIS_PONTOS = 302,
     PONTO_VIRGULA = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 26 "analise_sintatica.y"

    int inteiro;
    double real;
    char* string;


/* Line 2058 of yacc.c  */
#line 112 "analise_sintatica.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_ANALISE_SINTATICA_TAB_H_INCLUDED  */
