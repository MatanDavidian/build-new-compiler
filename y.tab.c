/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "yacc.y"
	#include "c_func.c"
#line 5 "yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct tree_node* node;
    	char* chr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 35 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define RETURN 257
#define FUNC 258
#define VAR 259
#define DO 260
#define IF 261
#define FOR 262
#define WHILE 263
#define BOOL 264
#define CHAR 265
#define INT 266
#define REAL 267
#define STRING 268
#define ELSE 269
#define VOID 270
#define Null 271
#define IDENTIFIER 272
#define BOOL_LITERAL 273
#define CHAR_LITERAL 274
#define INT_LITERAL 275
#define REAL_LITERAL 276
#define STRING_LITERAL 277
#define P_CHAR 278
#define P_REAL 279
#define P_INT 280
#define OR 281
#define AND 282
#define EQUAL 283
#define DIFF 284
#define BIG_OR_EQUAL 285
#define SMALL_OR_EQUAL 286
#define COMMENT 287
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    2,   22,   22,    1,    1,    3,    3,
   20,   20,   20,   20,   20,   20,   20,   20,   20,    4,
    7,    7,    8,    8,    8,    9,   10,   10,   10,   10,
   11,   11,   11,   11,   14,   14,   23,   23,   23,   23,
   23,   15,   16,   16,   13,   13,   12,   12,   12,   12,
   24,   24,   24,   24,   17,   18,   19,   19,    5,    5,
    6,    6,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,
};
static const YYINT yylen[] = {                            2,
    2,    0,    1,    0,    4,    2,    3,    1,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    0,    4,    3,    1,    7,    3,    3,    1,    1,
    4,    6,    6,    8,    2,    0,    2,    2,    1,    2,
    1,    4,    4,    3,    1,    1,    5,    7,    5,    9,
    7,    1,    5,    9,    7,    2,    1,    1,    3,    4,
    6,    6,    2,    2,    3,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    1,
    2,    5,    2,    6,    6,    4,    1,    1,    1,    1,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   14,   15,   16,   17,   18,   19,   11,
   12,   13,    0,   20,    1,    0,    0,    0,    0,    3,
    0,    0,    0,    0,   26,    0,    0,    0,    0,    0,
    0,   25,    7,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   57,   58,   46,    0,    0,   39,
    0,   41,    0,    0,   52,   45,   21,    0,    0,    0,
    0,   24,   93,    0,   89,   91,   88,   90,   92,    0,
    0,    0,    0,    0,    0,    0,   80,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   35,   42,   38,   40,
   37,    0,    0,   23,    0,    0,    0,    0,    0,   83,
    0,   66,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   44,    0,    0,    0,   27,   28,    0,
    0,    0,    0,   65,   79,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   68,   70,    0,    0,    0,
    0,    0,   43,    0,    0,    0,    0,   86,    0,    0,
    0,    0,   47,    0,    0,   49,   53,    0,    9,   33,
    0,   82,    0,    0,    0,    0,    0,   62,   61,    0,
   85,   84,   55,   48,   51,    0,   34,    0,   50,   54,
};
static const YYINT yydgoto[] = {                          2,
   23,   18,  125,   13,   45,   46,   30,   31,    3,   60,
   37,   47,   48,   49,   50,   77,   52,   53,   54,   19,
  126,   20,   55,   56,
};
static const YYINT yysindex[] = {                      -244,
  267,    0, -244,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -255,    0,    0,    3,  267,   16, -211,    0,
  -17,   77,   67,  -90,    0, -211,  267,  267, -157,  281,
  -90,    0,    0,    0,   -6,   58,   75,  149,  -17,  121,
  125,  140,   -8,  -86,    0,    0,    0,  281,   63,    0,
  142,    0,  166,  169,    0,    0,    0,   43,  155,  171,
  149,    0,    0,   -7,    0,    0,    0,    0,    0,  -79,
  149,  149,  -35,  149,  149,  -64,    0,  426,  -37,  149,
    2,  149,  149,  149,  134,  170,    0,    0,    0,    0,
    0,   -6,   -6,    0,  153,  149,  141,   51,   51,    0,
  -39,    0,   13,  110,  149,  149,  149,  149,  149,  149,
  149,  149,  149,  149,  149,  149,  195,   35,  -27,  177,
   49,  426,  160,    0,  197,  167,  149,    0,    0,   56,
  370,  149,  117,    0,    0,  440,  447,  454,  454,  174,
  174,  174,  174,   51,   51,    0,    0,  149,  281,  149,
  281,  178,    0,  149,  426, -157,  149,    0,  412,  149,
  149,   60,    0,  -15,  419,    0,    0,  -89,    0,    0,
  356,    0,   71,   82,  196,  281,    2,    0,    0, -157,
    0,    0,    0,    0,    0,  215,    0,  281,    0,    0,
};
static const YYINT yyrindex[] = {                       257,
    0,    0,  257,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  218,    0,    0,    0,
    0,   22,  235,  306,    0,    0,    0,    0,    0,  152,
  306,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  152,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  220,  221,    0,
    0,    0,    0,  -41,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  222,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -34,  -21,  -14,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   95,    0,    0,    0,  241,    0,    0,    0,  224,
    0,    0,    0,    0,    0,  234,  467,  436,  462,   91,
   97,  104,  111,    6,   26,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   99,    0,    0,    0,    0,    0,
    0,    0,    0,  342,    0,    0,    0,    0,    0,    0,
  225,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                       282,
  260,    0,  146,    0,   54,    0,  270,    0,  106,  131,
 -140,   30,  154,  254,   89,  410,    0,    0,  -69,   14,
  689,  277,    0, -114,
};
#define YYTABLESIZE 850
static const YYINT yytable[] = {                         87,
   87,   87,   87,   87,  101,   87,   81,   81,   81,   81,
   81,  120,   81,    1,   14,  170,   16,   87,   87,   63,
   87,   63,   63,   63,   81,   81,   64,   81,   64,   64,
   64,   85,   85,   83,  164,   44,  167,   63,   63,  187,
   63,   35,   17,   44,   64,   64,   67,   64,   67,   67,
   67,   87,   83,  134,  115,  113,   21,  114,   81,  116,
   22,  185,    8,   84,   67,   67,   69,   67,   69,   69,
   69,   63,  111,  190,  109,  149,  115,  113,   64,  114,
    8,  116,   84,   96,   69,   69,   92,   69,   59,  151,
  115,  113,  115,  114,  111,  116,  109,  116,   67,  156,
  175,  115,  113,   83,  114,   24,  116,  186,  111,   25,
  109,  181,  115,  113,   36,  114,  157,  116,   69,  111,
   26,  109,  182,  115,  113,   27,  114,   79,  116,   32,
  111,   73,  109,   62,   73,   59,   32,   74,   59,   60,
   74,  111,   60,  109,   75,   59,   59,   75,   61,   73,
   73,   76,   73,   59,   76,   74,   74,   60,   74,  160,
   80,  161,   75,   75,   81,   75,   74,    1,   28,   76,
   76,   70,   76,   75,  124,   73,   71,   29,   72,   82,
  166,   74,  178,   73,  179,   86,   70,   88,   75,   74,
   73,   71,   97,   72,  115,  113,   75,  114,   93,  116,
   89,  115,  113,   76,  114,  184,  116,  104,  115,  113,
  154,  114,  111,  116,  109,  115,  113,  189,  114,  111,
  116,  109,  128,  129,   90,  117,  111,   91,  109,   94,
  127,  132,  133,  135,  148,  150,  100,  153,  168,   87,
   87,   87,   87,   87,   87,  130,   81,   81,   81,   81,
   81,   81,  152,  176,  183,  188,    2,   76,    4,   63,
   63,   63,   63,   63,   63,   58,   64,   64,   64,   64,
   64,   64,   76,  119,   72,    6,   36,   72,   29,   30,
   56,   10,   31,   32,   15,   33,   67,   67,   67,   67,
   67,   67,   72,  105,  106,  107,  108,  110,  112,  169,
   57,   87,  163,   34,    0,    0,   69,   69,   69,   69,
   69,   69,    0,    0,    0,  105,  106,  107,  108,  110,
  112,    0,   44,    0,    0,    0,   72,    0,    0,  105,
  106,  107,  108,  110,  112,    0,    0,    0,    0,    0,
  105,  106,  107,  108,  110,  112,    0,   22,    0,    0,
    0,  105,  106,  107,  108,  110,  112,    0,    0,    0,
    0,    0,  105,  106,  107,  108,  110,  112,    0,    0,
    0,   73,   73,   73,   73,   73,   73,   74,   74,   74,
   74,   74,   74,   45,   75,   75,   75,   75,   75,   75,
    0,   76,   76,   76,   76,   76,   76,  115,  113,  180,
  114,    0,  116,   24,   63,   64,   65,   66,   67,   68,
   69,  115,  113,    0,  114,  111,  116,  109,    0,   63,
   64,   65,   66,   67,   68,   69,    0,    0,   22,  111,
   22,  109,    0,  105,  106,  107,  108,  110,  112,   51,
  105,  106,  107,  108,  110,  112,    0,  105,  106,  107,
  108,  110,  112,  115,  113,    0,  114,   51,  116,    0,
  115,  113,  158,  114,   45,  116,   45,  115,  113,    0,
  114,  111,  116,  109,    0,    0,   77,  177,  111,   77,
  109,  115,  113,    0,  114,  111,  116,  109,  115,  113,
    0,  114,    0,  116,   77,  115,  113,    0,  114,  111,
  116,  109,   78,    0,  172,   78,  111,   71,  109,    0,
   71,    0,    0,  111,   72,  109,    0,    0,    0,    0,
   78,    0,    0,    0,    0,   71,    0,    0,   77,    0,
    4,    5,    6,    7,    8,    0,    9,   38,    0,    0,
   39,   40,   41,   42,   10,   11,   12,    0,    0,    0,
    0,    0,   43,    0,   78,    0,    0,    0,   51,   71,
   51,    0,   22,    0,    0,   22,   22,   22,   22,    0,
    0,    0,    0,    0,    0,    0,    0,   22,    0,    0,
    0,    0,    0,    0,    0,   51,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,   45,    0,
    0,   45,   45,   45,   45,    0,    0,    0,    0,    0,
    0,    0,    0,   45,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  105,  106,  107,  108,
  110,  112,    0,    0,    0,    0,    0,    0,    0,    0,
  105,  106,  107,  108,  110,  112,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  105,  106,  107,  108,  110,  112,    0,  105,
  106,  107,  108,  110,  112,    0,  105,  106,  107,  108,
  110,  112,    0,    0,    0,    0,   77,   77,   77,   77,
    0,  106,  107,  108,  110,  112,   78,    0,    0,  107,
  108,  110,  112,    0,    0,    0,    0,    0,  110,  112,
    0,    0,   78,   78,   78,   78,    0,   71,   71,   95,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   98,
   99,    0,  102,  103,    0,    0,    0,    0,  118,    0,
  121,  122,  123,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  131,    0,    0,    0,    0,    0,
    0,    0,    0,  136,  137,  138,  139,  140,  141,  142,
  143,  144,  145,  146,  147,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  155,    0,    0,    0,    0,
  159,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  162,    0,  165,    0,
    0,    0,    0,    0,    0,  171,    0,    0,  173,  174,
};
static const YYINT yycheck[] = {                         41,
   42,   43,   44,   45,   40,   47,   41,   42,   43,   44,
   45,   81,   47,  258,    1,  156,  272,   59,   60,   41,
   62,   43,   44,   45,   59,   60,   41,   62,   43,   44,
   45,   40,   40,   61,  149,   42,  151,   59,   60,  180,
   62,   28,   40,   42,   59,   60,   41,   62,   43,   44,
   45,   93,   61,   41,   42,   43,   41,   45,   93,   47,
  272,  176,   41,   91,   59,   60,   41,   62,   43,   44,
   45,   93,   60,  188,   62,   41,   42,   43,   93,   45,
   59,   47,   91,   91,   59,   60,   44,   62,   35,   41,
   42,   43,   42,   45,   60,   47,   62,   47,   93,   44,
   41,   42,   43,   61,   45,  123,   47,  177,   60,   21,
   62,   41,   42,   43,  272,   45,   61,   47,   93,   60,
   44,   62,   41,   42,   43,   59,   45,   39,   47,   24,
   60,   41,   62,   59,   44,   41,   31,   41,   44,   41,
   44,   60,   44,   62,   41,   92,   93,   44,   91,   59,
   60,   41,   62,   59,   44,   59,   60,   59,   62,   43,
   40,   45,   59,   60,   40,   62,   33,  258,  259,   59,
   60,   38,   62,   40,   41,   42,   43,  268,   45,   40,
  151,   33,  272,   93,  274,  272,   38,  125,   40,   93,
   42,   43,  272,   45,   42,   43,   93,   45,   44,   47,
   59,   42,   43,   93,   45,  176,   47,  272,   42,   43,
   44,   45,   60,   47,   62,   42,   43,  188,   45,   60,
   47,   62,   92,   93,   59,  263,   60,   59,   62,   59,
   61,   91,  272,  124,   40,   59,  272,   41,   61,  281,
  282,  283,  284,  285,  286,   93,  281,  282,  283,  284,
  285,  286,   93,  269,   59,   41,    0,  124,   41,  281,
  282,  283,  284,  285,  286,  272,  281,  282,  283,  284,
  285,  286,  124,  272,   41,   41,  125,   44,   59,   59,
   59,   41,   59,   59,    3,   26,  281,  282,  283,  284,
  285,  286,   59,  281,  282,  283,  284,  285,  286,  154,
   31,   48,  149,   27,   -1,   -1,  281,  282,  283,  284,
  285,  286,   -1,   -1,   -1,  281,  282,  283,  284,  285,
  286,   -1,   42,   -1,   -1,   -1,   93,   -1,   -1,  281,
  282,  283,  284,  285,  286,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,  285,  286,   -1,   42,   -1,   -1,
   -1,  281,  282,  283,  284,  285,  286,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,  285,  286,   -1,   -1,
   -1,  281,  282,  283,  284,  285,  286,  281,  282,  283,
  284,  285,  286,   42,  281,  282,  283,  284,  285,  286,
   -1,  281,  282,  283,  284,  285,  286,   42,   43,   44,
   45,   -1,   47,  123,  271,  272,  273,  274,  275,  276,
  277,   42,   43,   -1,   45,   60,   47,   62,   -1,  271,
  272,  273,  274,  275,  276,  277,   -1,   -1,  123,   60,
  125,   62,   -1,  281,  282,  283,  284,  285,  286,   30,
  281,  282,  283,  284,  285,  286,   -1,  281,  282,  283,
  284,  285,  286,   42,   43,   -1,   45,   48,   47,   -1,
   42,   43,   93,   45,  123,   47,  125,   42,   43,   -1,
   45,   60,   47,   62,   -1,   -1,   41,   59,   60,   44,
   62,   42,   43,   -1,   45,   60,   47,   62,   42,   43,
   -1,   45,   -1,   47,   59,   42,   43,   -1,   45,   60,
   47,   62,   41,   -1,   93,   44,   60,   41,   62,   -1,
   44,   -1,   -1,   60,  281,   62,   -1,   -1,   -1,   -1,
   59,   -1,   -1,   -1,   -1,   59,   -1,   -1,   93,   -1,
  264,  265,  266,  267,  268,   -1,  270,  257,   -1,   -1,
  260,  261,  262,  263,  278,  279,  280,   -1,   -1,   -1,
   -1,   -1,  272,   -1,   93,   -1,   -1,   -1,  149,   93,
  151,   -1,  257,   -1,   -1,  260,  261,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  176,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  188,  257,   -1,
   -1,  260,  261,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
  285,  286,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,  285,  286,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,  285,  286,   -1,  281,
  282,  283,  284,  285,  286,   -1,  281,  282,  283,  284,
  285,  286,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   -1,  282,  283,  284,  285,  286,   38,   -1,   -1,  283,
  284,  285,  286,   -1,   -1,   -1,   -1,   -1,  285,  286,
   -1,   -1,  281,  282,  283,  284,   -1,  281,  282,   61,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   71,
   72,   -1,   74,   75,   -1,   -1,   -1,   -1,   80,   -1,
   82,   83,   84,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   96,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,  116,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  127,   -1,   -1,   -1,   -1,
  132,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  148,   -1,  150,   -1,
   -1,   -1,   -1,   -1,   -1,  157,   -1,   -1,  160,  161,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 287
#define YYUNDFTOKEN 314
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"RETURN","FUNC","VAR","DO","IF","FOR",
"WHILE","BOOL","CHAR","INT","REAL","STRING","ELSE","VOID","Null","IDENTIFIER",
"BOOL_LITERAL","CHAR_LITERAL","INT_LITERAL","REAL_LITERAL","STRING_LITERAL",
"P_CHAR","P_REAL","P_INT","OR","AND","EQUAL","DIFF","BIG_OR_EQUAL",
"SMALL_OR_EQUAL","COMMENT",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : s",
"s : function s",
"s :",
"parameter_lists : parameter_list",
"parameter_lists :",
"parameter_list : type parameter_list_same_type ';' parameter_list",
"parameter_list : type parameter_list_same_type",
"parameter_list_same_type : IDENTIFIER ',' parameter_list_same_type",
"parameter_list_same_type : IDENTIFIER",
"argument_list : expression ',' argument_list",
"argument_list : expression",
"type : P_CHAR",
"type : P_REAL",
"type : P_INT",
"type : BOOL",
"type : CHAR",
"type : INT",
"type : REAL",
"type : STRING",
"type : VOID",
"func_type : type",
"declarations : declaration declarations",
"declarations :",
"declaration : VAR type variable_declaration ';'",
"declaration : STRING string_declaration ';'",
"declaration : function",
"function : FUNC func_type IDENTIFIER '(' parameter_lists ')' code_block_statement",
"variable_declaration : IDENTIFIER ',' variable_declaration",
"variable_declaration : variable_assignment_statement ',' variable_declaration",
"variable_declaration : IDENTIFIER",
"variable_declaration : variable_assignment_statement",
"string_declaration : IDENTIFIER '[' expression ']'",
"string_declaration : IDENTIFIER '[' expression ']' '=' expression",
"string_declaration : IDENTIFIER '[' expression ']' ',' string_declaration",
"string_declaration : IDENTIFIER '[' expression ']' '=' expression ',' string_declaration",
"statements : stmnt statements",
"statements :",
"simple_statement : assignment_statement ';'",
"simple_statement : function_call_statement ';'",
"simple_statement : code_block_statement",
"simple_statement : return_statement ';'",
"simple_statement : do_statement",
"code_block_statement : '{' declarations statements '}'",
"function_call_statement : IDENTIFIER '(' argument_list ')'",
"function_call_statement : IDENTIFIER '(' ')'",
"stmnt : matched_stmnt",
"stmnt : unmatched_stmnt",
"unmatched_stmnt : IF '(' expression ')' stmnt",
"unmatched_stmnt : IF '(' expression ')' matched_stmnt ELSE unmatched_stmnt",
"unmatched_stmnt : WHILE '(' expression ')' unmatched_stmnt",
"unmatched_stmnt : FOR '(' assignment_statement ';' expression ';' assignment_statement ')' unmatched_stmnt",
"matched_stmnt : IF '(' expression ')' matched_stmnt ELSE matched_stmnt",
"matched_stmnt : simple_statement",
"matched_stmnt : WHILE '(' expression ')' matched_stmnt",
"matched_stmnt : FOR '(' assignment_statement ';' expression ';' assignment_statement ')' matched_stmnt",
"do_statement : DO code_block_statement WHILE '(' expression ')' ';'",
"return_statement : RETURN expression",
"assignment_statement : variable_assignment_statement",
"assignment_statement : string_assignment_statement",
"variable_assignment_statement : IDENTIFIER '=' expression",
"variable_assignment_statement : '*' IDENTIFIER '=' expression",
"string_assignment_statement : IDENTIFIER '[' expression ']' '=' CHAR_LITERAL",
"string_assignment_statement : IDENTIFIER '[' expression ']' '=' IDENTIFIER",
"expression : '+' expression",
"expression : '-' expression",
"expression : '(' expression ')'",
"expression : '!' expression",
"expression : expression '+' expression",
"expression : expression '*' expression",
"expression : expression '-' expression",
"expression : expression '/' expression",
"expression : expression AND expression",
"expression : expression OR expression",
"expression : expression '>' expression",
"expression : expression BIG_OR_EQUAL expression",
"expression : expression '<' expression",
"expression : expression SMALL_OR_EQUAL expression",
"expression : expression EQUAL expression",
"expression : expression DIFF expression",
"expression : '|' IDENTIFIER '|'",
"expression : function_call_statement",
"expression : '&' IDENTIFIER",
"expression : '&' IDENTIFIER '[' expression ']'",
"expression : '*' IDENTIFIER",
"expression : '*' '(' IDENTIFIER '-' expression ')'",
"expression : '*' '(' IDENTIFIER '+' expression ')'",
"expression : IDENTIFIER '[' expression ']'",
"expression : IDENTIFIER",
"expression : INT_LITERAL",
"expression : BOOL_LITERAL",
"expression : REAL_LITERAL",
"expression : CHAR_LITERAL",
"expression : STRING_LITERAL",
"expression : Null",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 218 "yacc.y"
/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////C//////////////////////////////////////////////////////////
int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	exit(1);
	return 0;
}

int main()
{
	first_func = (linked_list_node*)malloc(sizeof(linked_list_node));
	first_func->next = NULL;	//important end condition
	int x =yyparse();
	//print_list(first_func);
	//printf("start\n");
	make_symbol_table(first_func);
	
	return x;
}

#line 554 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 40 "yacc.y"
	{
		add_node(first_func,yystack.l_mark[-1].node);
	}
break;
case 2:
#line 42 "yacc.y"
	{yyval.node=NULL;}
break;
case 3:
#line 44 "yacc.y"
	{
			yyval.node=mknode("PARAMS", yystack.l_mark[0].node, NULL, NULL, NULL);
		}
break;
case 4:
#line 47 "yacc.y"
	{yyval.node=make_empty_node("NONE PARAMS");}
break;
case 5:
#line 50 "yacc.y"
	{
			yyval.node=mknode("empty", yystack.l_mark[-3].node, make_empty_node(yystack.l_mark[-2].chr), yystack.l_mark[0].node, NULL);
		}
break;
case 6:
#line 54 "yacc.y"
	{
			yyval.node=mknode("empty", yystack.l_mark[-1].node, make_empty_node(yystack.l_mark[0].chr) , NULL, NULL);
		}
break;
case 7:
#line 61 "yacc.y"
	{
		char* str=strdup(yystack.l_mark[-2].chr);
		strcat(str," ");
		strcat(str,yystack.l_mark[0].chr);
		yyval.chr=str;
	}
break;
case 8:
#line 67 "yacc.y"
	{yyval.chr=yystack.l_mark[0].chr;}
break;
case 9:
#line 69 "yacc.y"
	{yyval.node=mknode("ARGS", yystack.l_mark[-2].node, yystack.l_mark[0].node, NULL, NULL);}
break;
case 10:
#line 70 "yacc.y"
	{yyval.node=mknode("empty", yystack.l_mark[0].node, NULL, NULL, NULL);}
break;
case 11:
#line 73 "yacc.y"
	{yyval.node=make_empty_node("P_CHAR");}
break;
case 12:
#line 74 "yacc.y"
	{yyval.node=make_empty_node("P_REAL");}
break;
case 13:
#line 75 "yacc.y"
	{yyval.node=make_empty_node("P_INT");}
break;
case 14:
#line 76 "yacc.y"
	{yyval.node=make_empty_node("BOOL");}
break;
case 15:
#line 77 "yacc.y"
	{yyval.node=make_empty_node("CHAR");}
break;
case 16:
#line 78 "yacc.y"
	{yyval.node=make_empty_node("INT");}
break;
case 17:
#line 79 "yacc.y"
	{yyval.node=make_empty_node("REAL");}
break;
case 18:
#line 80 "yacc.y"
	{yyval.node=make_empty_node("STRING");}
break;
case 19:
#line 81 "yacc.y"
	{yyval.node=make_empty_node("VOID");}
break;
case 20:
#line 84 "yacc.y"
	{
	yyval.node=mknode("TYPE ", yystack.l_mark[0].node, NULL, NULL, NULL);
}
break;
case 21:
#line 90 "yacc.y"
	{yyval.node=mknode("DECS", yystack.l_mark[-1].node, yystack.l_mark[0].node, NULL, NULL);}
break;
case 22:
#line 91 "yacc.y"
	{yyval.node=NULL;}
break;
case 23:
#line 93 "yacc.y"
	{yyval.node=mknode("VAR_DEC", yystack.l_mark[-2].node, yystack.l_mark[-1].node, NULL, NULL);}
break;
case 24:
#line 94 "yacc.y"
	{yyval.node=mknode("STR_DEC", yystack.l_mark[-1].node, NULL, NULL, NULL);}
break;
case 25:
#line 95 "yacc.y"
	{yyval.node=mknode("FUNC_DEC", yystack.l_mark[0].node, NULL, NULL, NULL);}
break;
case 26:
#line 101 "yacc.y"
	{
	yyval.node=mknode("FUNC", make_empty_node(yystack.l_mark[-4].chr), yystack.l_mark[-2].node, yystack.l_mark[-5].node, yystack.l_mark[0].node);
}
break;
case 27:
#line 108 "yacc.y"
	{		
				yyval.node=mknode("VAR",make_empty_node(yystack.l_mark[-2].chr), yystack.l_mark[0].node, NULL, NULL);
			}
break;
case 28:
#line 111 "yacc.y"
	{yyval.node=mknode("ASS_STMT", yystack.l_mark[-2].node, yystack.l_mark[0].node, NULL, NULL);}
break;
case 29:
#line 112 "yacc.y"
	{yyval.node=mknode("VAR",make_empty_node(yystack.l_mark[0].chr),NULL,NULL,NULL);}
break;
case 30:
#line 113 "yacc.y"
	{yyval.node=mknode("ASS_STMT",yystack.l_mark[0].node,NULL,NULL,NULL);}
break;
case 31:
#line 116 "yacc.y"
	{yyval.node=mknode("STRING", make_empty_node(yystack.l_mark[-3].chr), yystack.l_mark[-1].node, NULL, NULL);}
break;
case 32:
#line 117 "yacc.y"
	{yyval.node=mknode("=", make_empty_node(yystack.l_mark[-5].chr), yystack.l_mark[-3].node, yystack.l_mark[0].node, NULL);}
break;
case 33:
#line 118 "yacc.y"
	{yyval.node=mknode("STRING",make_empty_node(yystack.l_mark[-5].chr),yystack.l_mark[-3].node,NULL,yystack.l_mark[0].node);}
break;
case 34:
#line 119 "yacc.y"
	{yyval.node=mknode("=",make_empty_node(yystack.l_mark[-7].chr),yystack.l_mark[-5].node,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 35:
#line 125 "yacc.y"
	{yyval.node=mknode("empty",yystack.l_mark[-1].node,yystack.l_mark[0].node,NULL,NULL);}
break;
case 36:
#line 126 "yacc.y"
	{yyval.node = NULL;}
break;
case 37:
#line 129 "yacc.y"
	{yyval.node=yystack.l_mark[-1].node;}
break;
case 38:
#line 130 "yacc.y"
	{yyval.node=mknode("FUNC_CALL",yystack.l_mark[-1].node,NULL,NULL,NULL);}
break;
case 39:
#line 131 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;}
break;
case 40:
#line 132 "yacc.y"
	{yyval.node=mknode("RET",yystack.l_mark[-1].node,NULL,NULL,NULL);}
break;
case 41:
#line 133 "yacc.y"
	{yyval.node=mknode("DO_WHILE",yystack.l_mark[0].node,NULL,NULL,NULL);}
break;
case 42:
#line 137 "yacc.y"
	{yyval.node=mknode("BLOCK",yystack.l_mark[-2].node,yystack.l_mark[-1].node,NULL,NULL);}
break;
case 43:
#line 140 "yacc.y"
	{
					yyval.node=mknode("FUNC_CALL",make_empty_node(yystack.l_mark[-3].chr),yystack.l_mark[-1].node,NULL,NULL);
				}
break;
case 44:
#line 144 "yacc.y"
	{
					yyval.node=mknode("FUNC_CALL",make_empty_node(yystack.l_mark[-2].chr),NULL,NULL,NULL);
				}
break;
case 45:
#line 148 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;}
break;
case 46:
#line 148 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;}
break;
case 47:
#line 150 "yacc.y"
	{yyval.node=mknode("IF",yystack.l_mark[-2].node,yystack.l_mark[0].node,NULL,NULL);}
break;
case 48:
#line 151 "yacc.y"
	{yyval.node=mknode("IF-ELSE",yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node,NULL);}
break;
case 49:
#line 152 "yacc.y"
	{yyval.node=mknode("WHILE",yystack.l_mark[-2].node,yystack.l_mark[0].node,NULL,NULL);}
break;
case 50:
#line 153 "yacc.y"
	{yyval.node=mknode("FOR",yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 51:
#line 156 "yacc.y"
	{yyval.node=mknode("IF-ELSE",yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node,NULL);}
break;
case 52:
#line 157 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;}
break;
case 53:
#line 158 "yacc.y"
	{yyval.node=mknode("WHILE",yystack.l_mark[-2].node,yystack.l_mark[0].node,NULL,NULL);}
break;
case 54:
#line 159 "yacc.y"
	{yyval.node=mknode("FOR",yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 55:
#line 161 "yacc.y"
	{yyval.node=mknode("empty",yystack.l_mark[-5].node,yystack.l_mark[-2].node,NULL,NULL);}
break;
case 56:
#line 163 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;}
break;
case 57:
#line 167 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;}
break;
case 58:
#line 168 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;}
break;
case 59:
#line 171 "yacc.y"
	{yyval.node=mknode("REGULAR_ASS", make_one_child_node("ID",make_empty_node(yystack.l_mark[-2].chr)), yystack.l_mark[0].node, NULL, NULL);}
break;
case 60:
#line 172 "yacc.y"
	{yyval.node=mknode("PTR_ASS", make_one_child_node("ID",make_empty_node(yystack.l_mark[-2].chr)), yystack.l_mark[0].node, NULL, NULL);}
break;
case 61:
#line 175 "yacc.y"
	{yyval.node=mknode("STR_ASS", make_one_child_node("ID",make_empty_node(yystack.l_mark[-5].chr)), yystack.l_mark[-3].node, make_one_child_node("CHAR",make_empty_node(yystack.l_mark[0].node)), NULL);}
break;
case 62:
#line 176 "yacc.y"
	{yyval.node=mknode("STR_ASS", make_one_child_node("ID",make_empty_node(yystack.l_mark[-5].chr)), yystack.l_mark[-3].node, make_one_child_node("ID",make_empty_node(yystack.l_mark[0].chr)), NULL);}
break;
case 63:
#line 180 "yacc.y"
	{yyval.node=make_one_child_node("+",yystack.l_mark[0].node);}
break;
case 64:
#line 181 "yacc.y"
	{yyval.node=make_one_child_node("-",yystack.l_mark[0].node);}
break;
case 65:
#line 182 "yacc.y"
	{yyval.node=make_two_childs_node("(",yystack.l_mark[-1].node,make_empty_node(")"));}
break;
case 66:
#line 183 "yacc.y"
	{yyval.node=make_one_child_node("!",yystack.l_mark[0].node);}
break;
case 67:
#line 184 "yacc.y"
	{yyval.node=make_two_childs_node("+",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 68:
#line 185 "yacc.y"
	{yyval.node=make_two_childs_node("*",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 69:
#line 186 "yacc.y"
	{yyval.node=make_two_childs_node("-",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 70:
#line 187 "yacc.y"
	{yyval.node=make_two_childs_node("/",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 71:
#line 188 "yacc.y"
	{yyval.node=make_two_childs_node("&&",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 72:
#line 189 "yacc.y"
	{yyval.node=make_two_childs_node("||",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 73:
#line 190 "yacc.y"
	{yyval.node=make_two_childs_node(">",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 74:
#line 191 "yacc.y"
	{yyval.node=make_two_childs_node(">=",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 75:
#line 192 "yacc.y"
	{yyval.node=make_two_childs_node("<",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 76:
#line 193 "yacc.y"
	{yyval.node=make_two_childs_node("<=",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 77:
#line 194 "yacc.y"
	{yyval.node=make_two_childs_node("==",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 78:
#line 195 "yacc.y"
	{yyval.node=make_two_childs_node("!=",yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 79:
#line 197 "yacc.y"
	{ yyval.node=make_one_child_node("STR_LEN", make_one_child_node("ID",make_empty_node(yystack.l_mark[-1].chr)));}
break;
case 80:
#line 199 "yacc.y"
	{yyval.node=yystack.l_mark[0].node;/**/}
break;
case 81:
#line 201 "yacc.y"
	{yyval.node=make_one_child_node("ADDRESS", make_one_child_node("ID",make_empty_node(yystack.l_mark[0].chr)));}
break;
case 82:
#line 202 "yacc.y"
	{yyval.node=make_two_childs_node("ADDRESS", make_one_child_node("ID",make_empty_node(yystack.l_mark[-3].chr)), make_one_child_node("IN_PLACE",yystack.l_mark[-1].node));}
break;
case 83:
#line 204 "yacc.y"
	{yyval.node=make_one_child_node("PTR",make_one_child_node("ID",make_empty_node(yystack.l_mark[0].chr)));}
break;
case 84:
#line 205 "yacc.y"
	{yyval.node=make_two_childs_node("PTR",make_one_child_node("ID",make_empty_node(yystack.l_mark[-3].chr)),yystack.l_mark[-1].node);}
break;
case 85:
#line 206 "yacc.y"
	{yyval.node=make_two_childs_node("PTR",make_one_child_node("ID",make_empty_node(yystack.l_mark[-3].chr)),yystack.l_mark[-1].node);}
break;
case 86:
#line 207 "yacc.y"
	{yyval.node=make_two_childs_node("ID", make_one_child_node("ID",make_empty_node(yystack.l_mark[-3].chr)), make_one_child_node("IN_PLACE",yystack.l_mark[-1].node));}
break;
case 87:
#line 208 "yacc.y"
	{yyval.node=make_one_child_node("ID",make_empty_node(yystack.l_mark[0].chr));}
break;
case 88:
#line 210 "yacc.y"
	{yyval.node=make_one_child_node("INT",make_empty_node(yystack.l_mark[0].node));}
break;
case 89:
#line 211 "yacc.y"
	{yyval.node=make_one_child_node("BOOL",make_empty_node(yystack.l_mark[0].node));}
break;
case 90:
#line 212 "yacc.y"
	{yyval.node=make_one_child_node("REAL",make_empty_node(yystack.l_mark[0].node));}
break;
case 91:
#line 213 "yacc.y"
	{yyval.node=make_one_child_node("CHAR",make_empty_node(yystack.l_mark[0].node));}
break;
case 92:
#line 214 "yacc.y"
	{yyval.node=make_one_child_node("STRING",make_empty_node(yystack.l_mark[0].node));}
break;
case 93:
#line 215 "yacc.y"
	{yyval.node=make_empty_node("NULL");}
break;
#line 1151 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
