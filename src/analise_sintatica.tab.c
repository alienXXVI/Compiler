/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "analise_sintatica.y"

    #include <stdio.h>
    #include "..\estruturas\arvore.h"
    #include "..\estruturas\hash_table.h"
    
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
    char *filename = NULL;
    int errolex = 0;

    char str[200];
    


/* Line 371 of yacc.c  */
#line 93 "analise_sintatica.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "analise_sintatica.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 26 "analise_sintatica.y"

    int inteiro;
    double real;
    char* string;


/* Line 387 of yacc.c  */
#line 191 "analise_sintatica.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 219 "analise_sintatica.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNRULES -- Number of states.  */
#define YYNSTATES  222

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    11,    16,    19,    22,    23,
      27,    29,    32,    33,    40,    42,    46,    47,    50,    54,
      55,    58,    60,    62,    64,    66,    68,    70,    72,    74,
      76,    78,    80,    82,    84,    85,    89,    93,    97,   101,
     102,   106,   110,   114,   116,   118,   122,   125,   127,   131,
     133,   137,   139,   141,   143,   149,   157,   163,   169,   175,
     177,   178,   180,   181,   183,   184,   191,   196,   198,   202,
     207,   210,   213,   216,   217,   220,   228,   231,   232,   237,
     241,   246,   248,   252,   253,   255,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   293,   295,   297,   299,   301,   303,
     305,   307,   309,   311,   313,   315,   317,   319,   321,   323,
     325,   327,   329,   331,   333,   335,   337,   339,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   359,   361,   363,
     365,   367,   369,   371,   373,   375,   377,   379,   381,   383,
     385,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      50,     0,    -1,    51,    53,    56,    -1,    52,    51,    -1,
      -1,    88,   113,    90,   112,    -1,    88,   101,    -1,    54,
      53,    -1,    -1,    89,   102,    55,    -1,    66,    -1,    57,
      56,    -1,    -1,    91,   102,   135,    58,   136,    60,    -1,
      59,    -1,    59,   132,    58,    -1,    -1,    91,   102,    -1,
     137,    61,   138,    -1,    -1,    62,    61,    -1,    62,    -1,
      63,    -1,    65,    -1,    70,    -1,    71,    -1,    72,    -1,
      77,    -1,    78,    -1,    80,    -1,    86,    -1,    82,    -1,
      83,    -1,   124,    -1,    -1,    91,   102,    64,    -1,    91,
      65,    64,    -1,   132,   102,    64,    -1,   132,    65,    64,
      -1,    -1,   102,   108,    66,    -1,   102,   108,    65,    -1,
     102,   108,    86,    -1,    67,    -1,    68,    -1,    68,    69,
      68,    -1,   119,    68,    -1,    97,    -1,   135,    67,   136,
      -1,    67,    -1,   135,    68,   136,    -1,   103,    -1,   109,
      -1,   116,    -1,   120,   135,    66,   136,    60,    -1,   120,
     135,    66,   136,    60,   121,    60,    -1,   126,   135,    66,
     136,    60,    -1,   127,   135,    73,   136,    60,    -1,    74,
     133,    75,   133,    76,    -1,    63,    -1,    -1,    66,    -1,
      -1,    65,    -1,    -1,   128,    60,   126,   135,    66,   136,
      -1,   129,   135,    79,   136,    -1,   102,    -1,   102,   132,
      79,    -1,   130,   135,    81,   136,    -1,   101,    81,    -1,
     102,    81,    -1,   133,    81,    -1,    -1,   131,    66,    -1,
     122,   135,   102,   136,   137,    84,   138,    -1,    85,    84,
      -1,    -1,   123,    97,   134,    61,    -1,   125,   134,    61,
      -1,   102,   135,    87,   136,    -1,    66,    -1,    66,   132,
      87,    -1,    -1,    25,    -1,    24,    -1,     7,    -1,    92,
      -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,    19,
      -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,     3,
      -1,     4,    -1,     8,    -1,     6,    -1,     5,    -1,   104,
      -1,   105,    -1,   106,    -1,   107,    -1,    28,    -1,    31,
      -1,    29,    -1,    30,    -1,    32,    -1,   110,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,
      -1,   117,    -1,   118,    -1,    39,    -1,    40,    -1,    41,
      -1,     9,    -1,    10,    -1,    14,    -1,    15,    -1,    17,
      -1,    18,    -1,    11,    -1,    12,    -1,    13,    -1,    26,
      -1,    27,    -1,    16,    -1,    46,    -1,    48,    -1,    47,
      -1,    42,    -1,    43,    -1,    44,    -1,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    66,    72,    77,    83,    93,    99,   104,
     112,   122,   128,   133,   141,   147,   153,   158,   168,   174,
     179,   185,   193,   199,   205,   211,   217,   223,   229,   235,
     241,   247,   253,   259,   265,   272,   278,   286,   292,   298,
     305,   311,   317,   325,   331,   339,   345,   353,   359,   365,
     371,   379,   385,   391,   401,   407,   417,   425,   433,   441,
     447,   452,   458,   463,   469,   474,   484,   492,   498,   506,
     514,   520,   526,   532,   539,   549,   557,   563,   568,   574,
     584,   592,   598,   604,   609,   610,   611,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   626,   632,   638,
     644,   650,   656,   657,   658,   659,   660,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   688,   689,
     690,   691,   692,   694,   695,   696,   697,   698,   699,   701,
     702,   703,   705,   706,   707,   709,   710,   711,   712,   713,
     714,   715
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEIRO", "REAL", "IDENTIFICADOR",
  "CADEIA", "FILE_NAME", "CARACTER", "IF", "ELSE", "WHILE", "FOR", "DO",
  "SWITCH", "CASE", "RETURN", "BREAK", "DEFAULT", "INT", "FLOAT", "CHAR",
  "VOID", "STRING", "DEFINE", "INCLUDE", "SCAN", "PRINT", "SOMA",
  "MULTIPLICACAO", "DIVISAO", "SUBTRACAO", "RECEBE", "IGUAL", "DIFERENTE",
  "MAIOR", "MENOR", "MAIOR_IGUAL", "MENOR_IGUAL", "E_LOGICO", "OU_LOGICO",
  "NOT_LOGICO", "ABRE_P", "FECHA_P", "ABRE_CH", "FECHA_CH", "VIRGULA",
  "DOIS_PONTOS", "PONTO_VIRGULA", "$accept", "programa",
  "sentencas_include", "sentenca_include", "sentencas_define",
  "sentenca_define", "valor_define", "funcoes", "funcao",
  "parametros_funcao", "parametro_funcao", "corpo", "comandos", "comando",
  "decl_var", "decl_vars", "atribuicao", "expressao", "operacao",
  "operando", "op", "sentenca_if", "sentenca_while", "sentenca_for",
  "parametros_for", "parametro_decl_var", "parametro_expressao",
  "parametro_atribuicao", "sentenca_do", "sentenca_scan",
  "parametros_scan", "sentenca_print", "parametros_print",
  "sentenca_return", "sentenca_switch", "cases", "sentenca_case",
  "chamada_funcao", "argumentos", "include", "define", "nome_arquivo",
  "tipo_dado", "int", "float", "char", "void", "string", "literal",
  "inteiro", "real", "caracter", "cadeia", "identificador",
  "op_aritmetico", "soma", "subtracao", "multiplicacao", "divisao",
  "recebe", "op_relacional", "igual", "diferente", "maior", "menor",
  "maior_igual", "menor_igual", "op_logico", "e_logico", "ou_logico",
  "not_logico", "if", "else", "switch", "case", "break", "default",
  "while", "for", "do", "scan", "print", "return", "virgula",
  "ponto_virgula", "dois_pontos", "abre_p", "fecha_p", "abre_ch",
  "fecha_ch", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      55,    56,    56,    57,    58,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    69,    69,    69,    70,    70,    71,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    78,    79,    79,    80,
      81,    81,    81,    81,    82,    83,    84,    84,    85,    85,
      86,    87,    87,    87,    88,    89,    90,    91,    91,    91,
      91,    91,    92,    93,    94,    95,    96,    97,    97,    97,
      97,    97,    98,    99,   100,   101,   102,   103,   103,   103,
     103,   104,   105,   106,   107,   108,   109,   109,   109,   109,
     109,   109,   110,   111,   112,   113,   114,   115,   116,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     4,     2,     2,     0,     3,
       1,     2,     0,     6,     1,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     3,     3,     3,     0,
       3,     3,     3,     1,     1,     3,     2,     1,     3,     1,
       3,     1,     1,     1,     5,     7,     5,     5,     5,     1,
       0,     1,     0,     1,     0,     6,     4,     1,     3,     4,
       2,     2,     2,     0,     2,     7,     2,     0,     4,     3,
       4,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    84,     0,     8,     4,     0,     1,    85,    12,     8,
       0,     3,   105,   125,     6,     0,    92,    93,    94,    95,
      96,     2,    12,     0,    87,    88,    89,    90,    91,     7,
     106,     0,    86,     0,    11,     0,   102,   103,   104,   132,
     148,     9,    10,    43,    44,    47,    97,    98,    99,   100,
     101,     0,     0,   124,     5,    16,   111,   113,   114,   112,
     122,   123,   126,   127,   130,   131,     0,    51,   107,   108,
     109,   110,    52,   116,   117,   118,   119,   120,   121,    53,
     128,   129,    49,    46,    49,     0,     0,    14,     0,    45,
     149,    48,    50,    19,   145,    16,    17,   150,    13,    34,
      15,   133,   139,   140,   141,   135,   144,   137,   142,   143,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      31,    32,    30,     0,     0,     0,     0,    33,     0,     0,
      19,     0,     0,     0,   151,    18,    20,    39,    39,   115,
       0,    83,     0,     0,     0,    60,     0,     0,    73,    74,
      36,     0,    35,    41,    40,    42,   101,    81,     0,     0,
       0,     0,    59,     0,     0,     0,     0,    67,   146,     0,
      73,    73,    73,    39,    39,    83,    80,    19,     0,    19,
      19,    62,     0,    66,     0,    69,    70,    71,    72,    38,
      37,    82,    54,    77,    56,    57,    61,     0,     0,    68,
     134,    19,   136,   138,     0,    77,     0,     0,    64,    65,
      55,    75,    76,     0,   147,    34,    63,    58,     0,    34,
      79,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,     9,    41,    21,    22,    86,
      87,    98,   110,   111,   112,   150,   113,   157,    43,    44,
      66,   114,   115,   116,   163,   164,   197,   217,   117,   118,
     166,   119,   169,   120,   121,   204,   205,   122,   158,     5,
      10,    33,   123,    24,    25,    26,    27,    28,    45,    46,
      47,    48,    49,    50,    67,    68,    69,    70,    71,   140,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      51,   125,   201,   126,   206,   127,   207,   128,   129,   130,
     131,   132,   133,   151,   172,   215,    52,    91,    99,   135
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -157
static const yytype_int16 yypact[] =
{
       7,  -157,    35,    12,     7,    15,  -157,  -157,    44,    12,
      33,  -157,  -157,  -157,  -157,    36,  -157,  -157,  -157,  -157,
    -157,  -157,    44,    33,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,    14,  -157,    17,  -157,    11,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,   198,   211,  -157,  -157,  -157,  -157,  -157,
    -157,    14,    14,  -157,  -157,    44,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,    14,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,   211,     6,   182,     6,     8,    33,   211,
    -157,  -157,  -157,    27,  -157,    44,  -157,  -157,  -157,   164,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
      28,   164,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,    33,    -9,    11,    11,  -157,    11,    11,
      27,    11,    11,    14,  -157,  -157,  -157,     8,   -21,  -157,
      14,    14,    14,    33,    14,    44,    49,    33,    10,  -157,
    -157,    33,  -157,  -157,  -157,  -157,    -9,     8,     6,     6,
       6,     6,  -157,     6,    24,    11,     6,     8,  -157,     6,
      10,    10,    10,     8,   -21,    14,  -157,    27,    27,    27,
      27,    14,    14,  -157,    33,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,    64,    16,  -157,  -157,  -157,    24,     6,  -157,
    -157,    27,  -157,  -157,    28,    16,    42,    29,    33,  -157,
    -157,  -157,  -157,    29,  -157,   164,  -157,  -157,    45,   164,
    -157,  -157
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,    82,  -157,    79,  -157,  -157,    78,  -157,     9,
    -157,  -118,   -97,  -157,   -43,  -134,  -114,   -28,   -24,   -22,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
     -81,  -157,  -102,  -157,  -157,   -99,  -157,   -32,   -68,  -157,
    -157,  -157,     2,  -157,  -157,  -157,  -157,  -157,   -96,  -157,
    -157,  -157,    -4,   -10,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,    76,   106,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,   -31,  -157,  -157,
    -157,  -157,  -157,   -82,  -156,   -93,   -33,   -79,   -61,   -83
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      31,    14,    55,    42,   152,    95,    92,    93,   181,   137,
      23,   139,   146,    35,   136,    30,    12,    36,    37,    30,
      12,    12,    38,   139,    23,    94,   153,    82,    84,    83,
      85,   202,     1,    40,   203,     6,     7,   173,    30,   189,
     190,   208,    82,    32,    89,    36,    37,    30,    12,    90,
      38,    13,    53,    40,    94,    39,    40,    88,   168,   192,
     102,   194,   195,    16,    17,    18,    19,    20,   186,   187,
     188,    97,   168,   134,   200,   175,   214,   139,    96,   176,
     177,   178,   179,   210,   180,   184,    11,   183,    29,   124,
     185,   141,   142,   143,   216,   144,   145,    88,   147,   148,
      34,   124,   162,   199,   100,   149,   212,   191,   155,    54,
     213,    15,   154,   138,   159,   165,   161,   193,   220,   209,
     219,   211,   221,   141,     0,     0,     0,     0,     0,     0,
     156,     0,   182,   160,     0,     0,     0,   167,   171,     0,
       0,   174,     0,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,   196,   198,     0,     0,     0,     0,     0,
     171,   171,   171,     0,     0,     0,   170,   170,   170,    30,
       0,     0,     0,   101,   167,   102,   103,   104,   105,     0,
     106,   107,     0,    16,    17,    18,    19,    20,     0,     0,
     108,   109,     0,     0,     0,     0,     0,     0,   218,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,   124,
      56,    57,    58,    59,     0,    60,    61,    53,    13,    62,
      63,    64,    65,     0,     0,    90,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,    56,
      57,    58,    59,     0,    60,    61,    53,    13,    62,    63,
      64,    65
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      10,     5,    35,    31,   138,    87,    85,    86,   164,   123,
       8,    32,   130,    23,   111,     5,     6,     3,     4,     5,
       6,     6,     8,    32,    22,    46,   140,    51,    52,    51,
      52,    15,    25,    42,    18,     0,    24,   151,     5,   173,
     174,   197,    66,     7,    66,     3,     4,     5,     6,    43,
       8,    36,    35,    42,    46,    41,    42,    55,    48,   177,
      11,   179,   180,    19,    20,    21,    22,    23,   170,   171,
     172,    44,    48,    45,    10,   157,    47,    32,    88,   158,
     159,   160,   161,   201,   163,   167,     4,   166,     9,    99,
     169,   124,   125,   126,   208,   128,   129,    95,   131,   132,
      22,   111,   145,   184,    95,   133,   205,   175,   140,    33,
     206,     5,   140,   123,   142,   146,   144,   178,   215,   198,
     213,   204,   219,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,   165,   143,    -1,    -1,    -1,   147,   148,    -1,
      -1,   151,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,    -1,    -1,    -1,   170,   171,   172,     5,
      -1,    -1,    -1,     9,   184,    11,    12,    13,    14,    -1,
      16,    17,    -1,    19,    20,    21,    22,    23,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    50,    51,    52,    88,     0,    24,    53,    54,
      89,    51,     6,    36,   101,   113,    19,    20,    21,    22,
      23,    56,    57,    91,    92,    93,    94,    95,    96,    53,
       5,   102,     7,    90,    56,   102,     3,     4,     8,    41,
      42,    55,    66,    67,    68,    97,    98,    99,   100,   101,
     102,   119,   135,    35,   112,   135,    28,    29,    30,    31,
      33,    34,    37,    38,    39,    40,    69,   103,   104,   105,
     106,   107,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    67,    68,    67,    68,    58,    59,    91,    68,
      43,   136,   136,   136,    46,   132,   102,    44,    60,   137,
      58,     9,    11,    12,    13,    14,    16,    17,    26,    27,
      61,    62,    63,    65,    70,    71,    72,    77,    78,    80,
      82,    83,    86,    91,   102,   120,   122,   124,   126,   127,
     128,   129,   130,   131,    45,   138,    61,    65,   102,    32,
     108,   135,   135,   135,   135,   135,    60,   135,   135,    66,
      64,   132,    64,    65,    66,    86,   102,    66,    87,    66,
     102,    66,    63,    73,    74,   126,    79,   102,    48,    81,
     101,   102,   133,    65,   102,   132,   136,   136,   136,   136,
     136,   133,   135,   136,   132,   136,    81,    81,    81,    64,
      64,    87,    60,   137,    60,    60,    66,    75,    66,    79,
      10,   121,    15,    18,    84,    85,   123,   125,   133,   136,
      60,   138,    84,    97,    47,   134,    65,    76,   102,   134,
      61,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 57 "analise_sintatica.y"
    { 
        inserir(&pilha, "programa", 3);
        arvore = desempilharFilho(&pilha);
        associarFilhos(arvore, &pilha, 3);
    }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 66 "analise_sintatica.y"
    {
        inserir(&pilha, "sentencas_include", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 72 "analise_sintatica.y"
    {
        inserir(&pilha, "sentencas_include", 0);
    }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 77 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_include", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
      }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 83 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_include", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 93 "analise_sintatica.y"
    {
        inserir(&pilha, "sentencas_define", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 99 "analise_sintatica.y"
    {
        inserir(&pilha, "sentencas_define", 0);
    }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 104 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_define", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 112 "analise_sintatica.y"
    {
        inserir(&pilha, "valor_define", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 122 "analise_sintatica.y"
    { 
        inserir(&pilha, "funcoes", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 128 "analise_sintatica.y"
    {
        inserir(&pilha, "funcoes", 0);
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 133 "analise_sintatica.y"
    { 
        inserir(&pilha, "funcao", 6);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 6);
        empilharFilho(&pilha, no); 
    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 141 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_funcao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 147 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_funcao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 153 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_funcao", 0);
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 158 "analise_sintatica.y"
    {
        inserir(&pilha, "parametro_funcao", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 168 "analise_sintatica.y"
    {
        inserir(&pilha, "corpo", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 174 "analise_sintatica.y"
    {
        inserir(&pilha, "corpo", 0);
    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 179 "analise_sintatica.y"
    {
        inserir(&pilha, "comandos", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 185 "analise_sintatica.y"
    {
        inserir(&pilha, "comandos", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 193 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 199 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 205 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 211 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 217 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 223 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 229 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 235 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 241 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 247 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 253 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 259 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 265 "analise_sintatica.y"
    {
        inserir(&pilha, "comando", 0);
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 272 "analise_sintatica.y"
    {
        inserir(&pilha, "decl_var", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
      }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 278 "analise_sintatica.y"
    {
        inserir(&pilha, "decl_var", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 286 "analise_sintatica.y"
    {
        inserir(&pilha, "decl_vars", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
      }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 292 "analise_sintatica.y"
    {
        inserir(&pilha, "decl_vars", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 298 "analise_sintatica.y"
    {
        inserir(&pilha, "decl_vars", 0);
    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 305 "analise_sintatica.y"
    {
        inserir(&pilha, "atribuicao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
      }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 311 "analise_sintatica.y"
    {
        inserir(&pilha, "atribuicao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 317 "analise_sintatica.y"
    {
        inserir(&pilha, "atribuicao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 325 "analise_sintatica.y"
    {
        inserir(&pilha, "expressao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 331 "analise_sintatica.y"
    {
        inserir(&pilha, "expressao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 339 "analise_sintatica.y"
    {
        inserir(&pilha, "operacao", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 345 "analise_sintatica.y"
    {
        inserir(&pilha, "operacao", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 353 "analise_sintatica.y"
    {
        inserir(&pilha, "operando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 359 "analise_sintatica.y"
    {
        inserir(&pilha, "operando", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 365 "analise_sintatica.y"
    {
        inserir(&pilha, "operando", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 371 "analise_sintatica.y"
    {
        inserir(&pilha, "operando", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 379 "analise_sintatica.y"
    {
        inserir(&pilha, "op", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 385 "analise_sintatica.y"
    {
        inserir(&pilha, "op", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 391 "analise_sintatica.y"
    {
        inserir(&pilha, "op", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 401 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_if", 5);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 5);
        empilharFilho(&pilha, no);
      }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 407 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_if", 7);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 7);
        empilharFilho(&pilha, no);
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 417 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_while", 5);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 5);
        empilharFilho(&pilha, no);
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 425 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_for", 5);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 5);
        empilharFilho(&pilha, no);
    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 433 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_for", 5);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 5);
        empilharFilho(&pilha, no);
      }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 441 "analise_sintatica.y"
    {
        inserir(&pilha, "parametro_decl_var", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 447 "analise_sintatica.y"
    {
        inserir(&pilha, "parametro_decl_var", 0);
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 452 "analise_sintatica.y"
    {
        inserir(&pilha, "parametro_expressao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 458 "analise_sintatica.y"
    {
        inserir(&pilha, "parametro_expressao", 0);
    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 463 "analise_sintatica.y"
    {
        inserir(&pilha, "parametro_atribuicao", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 469 "analise_sintatica.y"
    {
        inserir(&pilha, "parametro_atribuicao", 0);
    }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 474 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_do", 6);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 6);
        empilharFilho(&pilha, no);
    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 484 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_scan", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 492 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_scan", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 498 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_scan", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 506 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_print", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
    }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 514 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_print", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 520 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_print", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 526 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_print", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 532 "analise_sintatica.y"
    {
        inserir(&pilha, "parametros_print", 0);
    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 539 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_return", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 549 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_switch", 7);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 7);
        empilharFilho(&pilha, no);
    }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 557 "analise_sintatica.y"
    {
        inserir(&pilha, "cases", 2);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 2);
        empilharFilho(&pilha, no);
      }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 563 "analise_sintatica.y"
    {
        inserir(&pilha, "cases", 0);
    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 568 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_case", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 574 "analise_sintatica.y"
    {
        inserir(&pilha, "sentenca_case", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 584 "analise_sintatica.y"
    {
        inserir(&pilha, "chamada_funcao", 4);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 4);
        empilharFilho(&pilha, no);
    }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 592 "analise_sintatica.y"
    {
        inserir(&pilha, "argumentos", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 598 "analise_sintatica.y"
    {
        inserir(&pilha, "argumentos", 3);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 3);
        empilharFilho(&pilha, no);
    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 604 "analise_sintatica.y"
    {
        inserir(&pilha, "argumentos", 0);
    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 609 "analise_sintatica.y"
    { inserir(&pilha, "#include", 0); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 610 "analise_sintatica.y"
    { inserir(&pilha, "#define", 0); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 611 "analise_sintatica.y"
    { inserir(&pilha, (yyvsp[(1) - (1)].string), 0); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 614 "analise_sintatica.y"
    { inserir(&pilha, "int", 0); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 615 "analise_sintatica.y"
    { inserir(&pilha, "float", 0); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 616 "analise_sintatica.y"
    { inserir(&pilha, "char", 0); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 617 "analise_sintatica.y"
    { inserir(&pilha, "void", 0); }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 618 "analise_sintatica.y"
    { inserir(&pilha, "string", 0); }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 626 "analise_sintatica.y"
    {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
      }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 632 "analise_sintatica.y"
    {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 638 "analise_sintatica.y"
    {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 644 "analise_sintatica.y"
    {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 650 "analise_sintatica.y"
    {
        inserir(&pilha, "literal", 1);
        No* no = desempilharFilho(&pilha);
        associarFilhos(no, &pilha, 1);
        empilharFilho(&pilha, no);
    }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 656 "analise_sintatica.y"
    { sprintf(str, "%d", (yyvsp[(1) - (1)].inteiro)); inserir(&pilha, str, 0); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 657 "analise_sintatica.y"
    { sprintf(str, "%f", (yyvsp[(1) - (1)].real)); inserir(&pilha, str, 0); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 658 "analise_sintatica.y"
    { inserir(&pilha, (yyvsp[(1) - (1)].string), 0); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 659 "analise_sintatica.y"
    { inserir(&pilha, (yyvsp[(1) - (1)].string), 0); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 660 "analise_sintatica.y"
    { inserir(&pilha, (yyvsp[(1) - (1)].string), 0);}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 663 "analise_sintatica.y"
    { inserir(&pilha, "+", 0); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 664 "analise_sintatica.y"
    { inserir(&pilha, "-", 0); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 665 "analise_sintatica.y"
    { inserir(&pilha, "*", 0); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 666 "analise_sintatica.y"
    { inserir(&pilha, "/", 0); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 671 "analise_sintatica.y"
    { inserir(&pilha, "=", 0); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 674 "analise_sintatica.y"
    { inserir(&pilha, "==", 0); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 675 "analise_sintatica.y"
    { inserir(&pilha, "!=", 0); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 676 "analise_sintatica.y"
    { inserir(&pilha, ">", 0); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 677 "analise_sintatica.y"
    { inserir(&pilha, "<", 0); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 678 "analise_sintatica.y"
    { inserir(&pilha, ">=", 0); }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 679 "analise_sintatica.y"
    { inserir(&pilha, "<=", 0); }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 688 "analise_sintatica.y"
    { inserir(&pilha, "&&", 0); }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 689 "analise_sintatica.y"
    { inserir(&pilha, "||", 0); }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 692 "analise_sintatica.y"
    { inserir(&pilha, "!", 0); }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 694 "analise_sintatica.y"
    { inserir(&pilha, "if", 0); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 695 "analise_sintatica.y"
    { inserir(&pilha, "else", 0); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 696 "analise_sintatica.y"
    { inserir(&pilha, "switch", 0); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 697 "analise_sintatica.y"
    { inserir(&pilha, "case", 0); }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 698 "analise_sintatica.y"
    { inserir(&pilha, "break", 0); }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 699 "analise_sintatica.y"
    { inserir(&pilha, "default", 0); }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 701 "analise_sintatica.y"
    { inserir(&pilha, "while", 0); }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 702 "analise_sintatica.y"
    { inserir(&pilha, "for", 0); }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 703 "analise_sintatica.y"
    { inserir(&pilha, "do", 0); }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 705 "analise_sintatica.y"
    { inserir(&pilha, "scan", 0); }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 706 "analise_sintatica.y"
    { inserir(&pilha, "print", 0); }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 707 "analise_sintatica.y"
    { inserir(&pilha, "return", 0); }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 709 "analise_sintatica.y"
    { inserir(&pilha, ",", 0); }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 710 "analise_sintatica.y"
    { inserir(&pilha, ";", 0); }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 711 "analise_sintatica.y"
    { inserir(&pilha, ":", 0); }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 712 "analise_sintatica.y"
    { inserir(&pilha, "(", 0); }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 713 "analise_sintatica.y"
    { inserir(&pilha, ")", 0); }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 714 "analise_sintatica.y"
    { inserir(&pilha, "{", 0); }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 715 "analise_sintatica.y"
    { inserir(&pilha, "}", 0); }
    break;


/* Line 1792 of yacc.c  */
#line 2851 "analise_sintatica.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 717 "analise_sintatica.y"


void yyerror(const char *msg) {
    fprintf(stderr, "%s:%d Erro: %s\n", filename, linhasArq, msg);
    exit(1);
}

int main(int argc, char **argv) {
    T = iniciarTabelaSimbolo();
    R = iniciarTabelaReservada();

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    yyin = fopen(filename, "r");
    if (yyin == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    yyparse();
    imprimirTabelaSimbolo(T);
    imprimirTabelaReservada(R); 

    if (!yynerrs && !errolex) {
        // salvarArvoreEmArquivo(arvore, filename);
        salvarArvoreEmArquivo(arvore, "../arvores_geradas", filename);
    } else {
        yyerror("Erro sintatico.");
    }

    liberarArvore(arvore);
    fclose(yyin);
    return 0;
}