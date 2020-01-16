%{
	#define _GNU_SOURCE
 	#include "lex.yy.c"
	#include "part3.c"
	#include "c_func.c"
	#include "func.h"
%}

%union {
	struct tree_node* node;
    	char* chr;
}

%start s

%token <node>  RETURN  FUNC VAR DO IF FOR WHILE BOOL CHAR INT REAL STRING 
%token <node> ELSE VOID Null
%token <chr> IDENTIFIER
%token <node> BOOL_LITERAL CHAR_LITERAL INT_LITERAL REAL_LITERAL STRING_LITERAL 
%token <node> P_CHAR P_REAL P_INT

%token <chr> ';'
%left <chr> ','
%right <chr> '='
%left <chr> OR
%left <chr> AND
%right <chr> '&'
%left <chr>  EQUAL DIFF
%left <chr> '>' BIG_OR_EQUAL '<' SMALL_OR_EQUAL
%left <chr> '+' '-'
%left <chr> '*' '/'
%left <chr> '!'
%left <chr> '{' '}' '[' ']' '(' ')' 
%token <chr> COMMENT
%type <chr>  parameter_list_same_type
%type <node> s parameter_lists argument_list func_type variable_assignment_statement string_assignment_statement  
%type <node> declarations declaration function variable_declaration string_declaration unmatched_stmnt  stmnt  
%type <node> statements  code_block_statement function_call_statement  do_statement  return_statement assignment_statement type   
%type <node> expression parameter_list simple_statement  matched_stmnt  
%%
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////START////////////////////////////////////////////////////////////////
s: 	function s
	{
		add_node(first_func,$1);
	}|{$$=NULL;};
parameter_lists: parameter_list
		{
			$$=mknode("PARAMS", $1, NULL, NULL, NULL);
		}|
		{$$=make_empty_node("NONE PARAMS");};

parameter_list:	type parameter_list_same_type ';' parameter_list
		{
			$$=mknode("empty", $1, make_empty_node($2), $4, NULL);
		}|
		type parameter_list_same_type
		{
			$$=mknode("empty", $1, make_empty_node($2) , NULL, NULL);
		};
parameter_list_same_type: 
	IDENTIFIER ',' parameter_list_same_type 
	{
		char* str=strdup($1);
		strcat(str," ");
		strcat(str,$3);
		$$=str;
	}|
	IDENTIFIER{$$=$1;};
argument_list:	expression ',' argument_list {$$=mknode("ARGS", $1, $3, NULL, NULL);}	|
		expression{$$=mknode("ARGS", $1, NULL, NULL, NULL);};
type: 
	P_CHAR{$$=make_empty_node("P_CHAR");} | 
	P_REAL{$$=make_empty_node("P_REAL");} | 
	P_INT{$$=make_empty_node("P_INT");}|
	BOOL{$$=make_empty_node("BOOL");} |
	CHAR{$$=make_empty_node("CHAR");} | 
	INT{$$=make_empty_node("INT");} | 
	REAL{$$=make_empty_node("REAL");} | 
	STRING{$$=make_empty_node("STRING");} | 
	VOID{$$=make_empty_node("VOID");};

func_type: type
{
	$$=mknode("TYPE ", $1, NULL, NULL, NULL);
};
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////DECLARATIONS/////////////////////////////////////////////////////////

declarations: 	declaration declarations{$$=mknode("DECS", $1, $2, NULL, NULL);} |
				{$$=NULL;};

declaration:	VAR type variable_declaration ';' {$$=mknode("VAR_DEC", $2, $3, NULL, NULL);}|
		STRING string_declaration ';' {$$=mknode("STR_DEC", $2, NULL, NULL, NULL);}|
		function {$$=mknode("FUNC_DEC", $1, NULL, NULL, NULL);}; 

/////////////////////function declaration//////////////////////////////////////////


function: FUNC func_type IDENTIFIER '(' parameter_lists ')'  code_block_statement  
{
	$$=mknode("FUNC", make_empty_node($3), $5, $2, $7);
};

//////////////////////////////////////////////////////////////////////////////////

variable_declaration:	IDENTIFIER ',' variable_declaration
			{		
				$$=mknode("VAR",make_empty_node($1), $3, NULL, NULL);
			} |
			variable_assignment_statement ',' variable_declaration{$$=mknode("ASS_STMT", $1, $3, NULL, NULL);} |
			IDENTIFIER {$$=mknode("VAR",make_empty_node($1),NULL,NULL,NULL);} |
			variable_assignment_statement {$$=mknode("ASS_STMT",$1,NULL,NULL,NULL);};

string_declaration: 
	IDENTIFIER '[' expression ']' {$$=mknode("STRING", make_empty_node($1), $3, NULL, NULL);} |
	IDENTIFIER '[' expression ']' '=' expression{$$=mknode("=", make_empty_node($1), $3, $6, NULL);} | 
	IDENTIFIER '[' expression ']' ',' string_declaration{$$=mknode("STRING",make_empty_node($1),$3,NULL,$6);} |
	IDENTIFIER '[' expression ']' '=' expression ',' string_declaration {$$=mknode("=",make_empty_node($1),$3,$6,$8);};

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////STATEMENTS///////////////////////////////////////////////////////////

statements: 	
	stmnt statements {$$=mknode("STMNT",$1,$2,NULL,NULL);}|
	{$$ = NULL;};

simple_statement: 	assignment_statement ';' {$$=$1;}|
			function_call_statement ';' {$$=mknode("FUNC_CALL",$1,NULL,NULL,NULL);}|
			code_block_statement {$$=$1;}|
			return_statement ';' {$$=mknode("RET",$1,NULL,NULL,NULL);}|
			do_statement{$$=mknode("DO_WHILE",$1,NULL,NULL,NULL);};

/////////////////////

code_block_statement: '{' declarations statements '}' {$$=mknode("BLOCK",$2,$3,NULL,NULL);};

function_call_statement: 	IDENTIFIER '(' argument_list ')' 
				{
					$$=mknode("FUNC_CALL",make_empty_node($1),$3,NULL,NULL);
				}
				|
				IDENTIFIER '(' ')'{
					$$=mknode("FUNC_CALL",make_empty_node($1),NULL,NULL,NULL);
				};

stmnt: matched_stmnt {$$=$1;}| unmatched_stmnt{$$=$1;};

unmatched_stmnt: IF '(' expression ')' stmnt {$$=mknode("IF",$3,$5,NULL,NULL);}|
		 IF '(' expression ')' matched_stmnt ELSE unmatched_stmnt {$$=mknode("IF-ELSE",$3,$5,$7,NULL);}|
		 WHILE '(' expression ')' unmatched_stmnt {$$=mknode("WHILE",$3,$5,NULL,NULL);}|
		 FOR '(' assignment_statement ';' expression ';' assignment_statement ')' unmatched_stmnt {$$=mknode("FOR",$3,$5,$7,$9);};
		 
matched_stmnt: 	IF '(' expression ')' matched_stmnt ELSE  matched_stmnt {$$=mknode("IF-ELSE",$3,$5,$7,NULL);}|
		simple_statement {$$=$1;}|
		WHILE '(' expression ')' matched_stmnt {$$=mknode("WHILE",$3,$5,NULL,NULL);}|
		FOR '(' assignment_statement ';' expression ';' assignment_statement ')' matched_stmnt {$$=mknode("FOR",$3,$5,$7,$9);};

do_statement: DO code_block_statement WHILE '(' expression ')' ';'  {$$=mknode("empty",$2,$5,NULL,NULL);};

return_statement: 	RETURN expression{$$=$2;};

/////////////////////assignment statements//////////////////////////////////////////

assignment_statement: variable_assignment_statement{$$=$1;} |
					string_assignment_statement{$$=$1;};

variable_assignment_statement:	
				IDENTIFIER '=' expression {$$=mknode("REGULAR_ASS", make_one_child_node("ID",make_empty_node($1)), $3, NULL, NULL);}|
				'*'IDENTIFIER '=' expression {$$=mknode("PTR_ASS", make_one_child_node("ID",make_empty_node($2)), $4, NULL, NULL);};

string_assignment_statement: 
					IDENTIFIER '[' expression ']' '=' CHAR_LITERAL {$$=mknode("STR_ASS", make_one_child_node("ID",make_empty_node($1)), $3, make_one_child_node("CHAR",make_empty_node($6)), NULL);}|
					IDENTIFIER '[' expression ']' '=' IDENTIFIER {$$=mknode("STR_ASS", make_one_child_node("ID",make_empty_node($1)), $3, make_one_child_node("ID",make_empty_node($6)), NULL);};
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////EXPRESSIONS/////////////////////////////////////////////////////////

expression:	 '+' expression  {$$=make_one_child_node("+",$2);}|	
			'-' expression  {$$=make_one_child_node("-",$2);}|
			'(' expression ')' {$$=make_two_childs_node("(",$2,make_empty_node(")"));}|
			'!' expression {$$=make_one_child_node("!",$2);}|
			expression '+' expression {$$=make_two_childs_node("+",$1,$3);}|
			expression '*' expression {$$=make_two_childs_node("*",$1,$3);}|
			expression '-' expression {$$=make_two_childs_node("-",$1,$3);}|
			expression '/' expression {$$=make_two_childs_node("/",$1,$3);}|
			expression AND expression {$$=make_two_childs_node("&&",$1,$3);}|
			expression OR expression {$$=make_two_childs_node("||",$1,$3);}|
			expression ">" expression {$$=make_two_childs_node(">",$1,$3);}|
			expression BIG_OR_EQUAL expression {$$=make_two_childs_node(">=",$1,$3);}|
			expression "<" expression {$$=make_two_childs_node("<",$1,$3);}|
			expression SMALL_OR_EQUAL expression {$$=make_two_childs_node("<=",$1,$3);}|
			expression EQUAL expression {$$=make_two_childs_node("==",$1,$3);}|
			expression DIFF expression {$$=make_two_childs_node("!=",$1,$3);}|

			'|' IDENTIFIER '|' { $$=make_one_child_node("STR_LEN", make_one_child_node("ID",make_empty_node($2)));}|

			function_call_statement{$$=$1;/**/}|

			'&'IDENTIFIER{$$=make_one_child_node("ADDRESS", make_one_child_node("ID",make_empty_node($2)));}|
			'&'IDENTIFIER '[' expression ']'{$$=make_two_childs_node("ADDRESS", make_one_child_node("ID",make_empty_node($2)), make_one_child_node("IN_PLACE",$4));}|

			'*'IDENTIFIER{$$=make_one_child_node("PTR",make_one_child_node("ID",make_empty_node($2)));}|
			'*' '(' IDENTIFIER '-' expression ')'{$$=make_two_childs_node("PTR",make_one_child_node("ID",make_empty_node($3)),$5);}|
			'*' '(' IDENTIFIER '+' expression ')'{$$=make_two_childs_node("PTR",make_one_child_node("ID",make_empty_node($3)),$5);}|
			IDENTIFIER '[' expression ']' {$$=make_two_childs_node("ID", make_one_child_node("ID",make_empty_node($1)), make_one_child_node("IN_PLACE",$3));}|
			IDENTIFIER {$$=make_one_child_node("ID",make_empty_node($1));}|

			INT_LITERAL  {$$=make_one_child_node("INT",make_empty_node($1));}|
			BOOL_LITERAL {$$=make_one_child_node("BOOL",make_empty_node($1));}|
			REAL_LITERAL {$$=make_one_child_node("REAL",make_empty_node($1));}|
			CHAR_LITERAL {$$=make_one_child_node("CHAR",make_empty_node($1));}|
			STRING_LITERAL {$$=make_one_child_node("STRING",make_empty_node($1));}|
			Null	{$$=make_empty_node("NULL");};
		
%%
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
	first_func->next = NULL;	//important - end condition
	int x =yyparse();
	//printf("start\n");
	//print_list(first_func);
	printf("PART 2\n");
	make_symbol_table(first_func);
	printf("PART 3\n");
	scan_all_func(first_func);
	
	return x;
}

//<---------------------------linked_list-------------------------------------------------------->//
void add_node(linked_list_node* old_head , tree_node* root){

    linked_list_node* new_head = (linked_list_node*)malloc(sizeof(linked_list_node));
    new_head->data = root;
	new_head ->next = old_head;
	first_func = new_head;
}

void print_list(linked_list_node* head) {
    printf("(CODE\n");
    linked_list_node * current = head;

    while (current != NULL) {
        print_tree(current->data,1);
        current = current->next;
    }
    printf(")\n");
}

tree_node *mknode(char* token,tree_node *a,tree_node *b,tree_node *c,tree_node *d)
{

	tree_node* new_tree_node=(tree_node*)malloc(sizeof(tree_node));
	char *newstr=strdup(token);
	new_tree_node->a=a;
	new_tree_node->b=b;
	new_tree_node->c=c;
	new_tree_node->d=d;
	new_tree_node->token=newstr;
	return new_tree_node;
}
tree_node *make_two_childs_node(char* token,tree_node *a,tree_node *b)
{
	return mknode(token,a,b,NULL,NULL);
}
tree_node *make_one_child_node(char* token,tree_node *a)
{
	return mknode(token,a,NULL,NULL,NULL);
}
tree_node *make_empty_node(char* token) 
{
	return mknode(token,NULL,NULL,NULL,NULL);
}
void tabs(int t){
	for(int i=0;i<t;i++)
		printf("\t");
}
void print_tree(tree_node* node,int n_tab){
	if(node == NULL)
		return;  

	if(is_leaf(node)){
		if(strcmp(node->token,"empty")){
			tabs(n_tab);
			printf("%s\n" , node->token);
			}
		return;
	}
	if(strcmp(node->token,"empty"))
	{
		tabs(n_tab);
		printf("(%s\n" , node->token);
		
		print_tree(node->a,n_tab+1);
		print_tree(node->b,n_tab+1);
		print_tree(node->c,n_tab+1);
		print_tree(node->d,n_tab+1);

		tabs(n_tab);
		if(strcmp(node->token,"empty"))
			printf(")\n");
	}
	else
	{
		print_tree(node->a,n_tab);
		print_tree(node->b,n_tab);
		print_tree(node->c,n_tab);
		print_tree(node->d,n_tab);
    }

}
bool is_leaf(tree_node* node){
    if(node->a == NULL && node->b == NULL && node->c == NULL && node->d == NULL)
	return true;
    return false;
}

