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
extern YYSTYPE yylval;
