#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include "lex.yy.c"


//---------------STRUCTS----------------------------------//
	typedef struct tree_node
	{
		char* token;
		struct tree_node* a;
		struct tree_node* b;
		struct tree_node* c;
		struct tree_node* d;
		
	} tree_node;
	typedef struct linked_list_node
	{
	    	struct tree_node* data;
	    	struct linked_list_node* next;
	}linked_list_node;
	typedef struct smb_var
	{
		char *name;
		char *value;
		char *type;
		int length;
		bool initialized;
	}smb_var;
	typedef struct smb_func
	{
		int* num_of_params;
		struct smb_var** params;
		char *name;
		char *return_value;	
	}smb_func;
	typedef struct scope
	{
		struct scope * next;
		struct scope * pre;
		struct smb_var ** VAR_SYMB_TBL;
		struct smb_func ** FUNC_SYMB_TBL;
		int scope_lvl;
		int* num_of_funcs;
		int* num_of_vars;
		char* func_name;
		char *return_value;
	}scope;
//global var
linked_list_node *first_func = NULL;

//---------------part one func----------------------------------//
	bool is_leaf(tree_node* node);
	bool one_child(tree_node* node);
	tree_node *mknode(char* token,tree_node *a,tree_node *b,tree_node *c,tree_node *d);
	tree_node *make_empty_node(char* token);
	tree_node *make_one_child_node(char* token,tree_node *a);
	tree_node *make_two_childs_node(char* token,tree_node *a,tree_node *b);
	void print_tree(tree_node* node, int n_tab);
	void tabs(int t);
	int yylex();
	int yyerror();
	int ***symb;
//---------------part two func build symbol table----------------------------------//
void add_row_to_symb_tbl(char* id_name,char* id_type,char* id_ass_type, char* id_val, int id_len, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var);
bool find_var(char* id_name, smb_var **SYMB_TBL, int* num_of_var);
bool find_func(char* id_name, smb_func **FUNC_SYMB_TBL, int* num_of_funcs);
void tree_scan_params_to_func_smb(tree_node* node, smb_var*** func_params,int* current_max_num_of_params,int* num_of_param);
void tree_scan_params_to_var_smb(tree_node* node, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var);
void scan_var_dec(tree_node* ,char*, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope);
void scan_str_dec(tree_node* node,char type[10], smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope);
void tree_scan_single_dec(tree_node* node, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope,smb_func ***func_table, int* current_max_num_of_funcs, int* num_of_func);
void tree_scan_decs(tree_node* node, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope,smb_func ***func_table, int* current_max_num_of_funcs, int* num_of_func);
void func_scan(tree_node* node,scope *current_scope);
void make_symbol_table(linked_list_node* head);
int num_of_args(tree_node* node);
char** types_of_args(tree_node* node ,scope* current_scope);
int num_of_params0(char* func_name,scope* current_scope);
int num_of_params1(char* func_name , smb_func **FUNC_TBL, int num_of_funcs);
smb_var** func_params(char* func_name,scope* current_scope);
//stmnts scan
void tree_scan_stms(tree_node* node,scope *current_scope, bool func);
void scan_stm(tree_node* node,scope *current_scope);
void block_stmnt_scan(tree_node* node,scope *pre_scope);
//<---------------------------check exp------------------------------------------------------------------->//
char* check_exp_type(tree_node* node,scope *current_scope);
char* identifier_type(char* id_name,scope* current_scope);
char* find_var_type(char* id_name, smb_var **SYMB_TBL, int num_of_var);
char* find_func_type(char* func_name, smb_func **FUNC_TBL, int num_of_funcs);
char* func_type(char* func_name,scope* current_scope);
int num_of_args(tree_node* node);
char** types_of_args(tree_node* node,scope* current_scope);
//---------------part two func manage scopes(inside stuck)----------------------------------//
scope* push_scope(scope* head_scope,scope* new_scope , smb_var* new_smb_var, smb_func* new_smb_func);
scope* pop_scope(scope* head_scope);
void check(scope*);
void print_var_smb_tbl(int num_of_var,smb_var **SYMB_TBL,char*);
void print_func_smb_tbl(int num_of_func,smb_func** FUNC_SYMB_TBL);
