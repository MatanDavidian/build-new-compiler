%{
#include "y.tab.h"
#include<stdio.h>
%}
DIGIT [0-9]
DIGIT_FROM_ONE [1-9]
LITTER [a-zA-Z]
SYM [1234567890'-'_=+[]{}\|"':;/.?><,~`]
comment_start (\*\/)
comment_end (\/\*)
%x comment
%%
"return"	return RETURN;
"function" 	return FUNC;
"void"		return VOID;
"var" 		return VAR;
"do"		return DO;
"if"		return IF;
"for"		return FOR;
"while"		return WHILE;
"bool"		return BOOL;
"char"		return CHAR;
"int"		return INT;
"real"		return REAL;
"string"	return STRING;
"int*"		return P_INT;
"char*"		return P_CHAR;
"real*"		return P_REAL;
"else"		return ELSE;
"null"		return Null;
"&&"	return AND;
"=="	return EQUAL;
">="	return BIG_OR_EQUAL;
"<="	return SMALL_OR_EQUAL;
"!="	return DIFF;
"||"	return OR;
[\n]    {yylineno++;}


 /*rule for comment*/
"/*" BEGIN comment;
<comment>[^\n] ;
 <comment>\n yylineno++;
<comment>"*/" BEGIN 0;


[ \t]	;



(false|true)	{yylval.chr = strdup(yytext);return BOOL_LITERAL;}
[a-zA-Z][a-zA-Z0-9_]* {yylval.chr = strdup(yytext);return IDENTIFIER;}

(0|{DIGIT_FROM_ONE}{DIGIT}*|0[xX][0-9A-Fa-f]+)	{yylval.chr = strdup(yytext);return INT_LITERAL;}


(0|{DIGIT_FROM_ONE}{DIGIT}*)?[.]?{DIGIT}*([eE][+-]?{DIGIT}*)?	{yylval.chr = strdup(yytext); return REAL_LITERAL;}


\"[^\"]*\" {/*he said \n is ok*/yylval.chr = strdup(yytext); return STRING_LITERAL;}

\'[^\']\'	{/*\n is a char*/yylval.chr = strdup(yytext);return CHAR_LITERAL; }
. 	{return yytext[0];}
%%

