#include "func.h"

//<---------------------------tree_scan---------------------------------------------------------->//
void make_symbol_table(linked_list_node* head) {
    //printf("0.1\n");
	bool main_exist = false;
	int current_max_num_of_funcs = 2;
    int* num_of_func = (int*)malloc(sizeof(int));
	* num_of_func=0;
	int current_max_num_of_vars = 2;
    int* num_of_vars = (int*)malloc(sizeof(int));
	* num_of_vars=0;
	int* max_num_of_params=(int*)malloc(sizeof(int));
	* max_num_of_params=2;

	//global scope contain functions smbl
	scope *current_scope = (scope*)malloc(sizeof(scope));
	//create records for global func
	current_scope->FUNC_SYMB_TBL=(smb_func**)malloc(sizeof(smb_func*) * current_max_num_of_funcs);
	current_scope->num_of_funcs= num_of_func;
	current_scope->num_of_vars = (int*)malloc(sizeof(int));
	*(current_scope->num_of_vars) = 0;
	current_scope->VAR_SYMB_TBL=NULL;
	current_scope->func_name = strdup("global");
	current_scope->scope_lvl = 0;
	current_scope->pre =NULL;//scopes stop condition.
	current_scope->next=NULL;
	//first func in code
    linked_list_node * current = head;
	//printf("0.2\n");
    while (current->next != 0) {
		//printf("0.3\n");
		if(*num_of_func + 1 == current_max_num_of_funcs)
		{
			current_max_num_of_funcs *= 2;
			current_scope->FUNC_SYMB_TBL=(smb_func **)realloc(current_scope->FUNC_SYMB_TBL, sizeof(smb_func*) * current_max_num_of_funcs);
		}
		//printf("0.4\n");
		current_scope->FUNC_SYMB_TBL[*num_of_func] = (smb_func*)malloc(sizeof(smb_func));
		//printf("0.4.1\n");
		current_scope->FUNC_SYMB_TBL[*num_of_func]->name = strdup(current->data->a->token);
		//printf("0.4.1.1\n");
		if(find_func(current->data->a->token,current_scope->FUNC_SYMB_TBL,num_of_func))
		{
			printf("ERROR, func %s already exist in scope\n", current->data->a->token);
			exit(1);
		}
		//printf("0.4.2\n");
		current_scope->FUNC_SYMB_TBL[*num_of_func]->return_value = strdup(current->data->c->a->token);
		current_scope->FUNC_SYMB_TBL[(*num_of_func)]->num_of_params=(int*)malloc(sizeof(int));
		*(current_scope->FUNC_SYMB_TBL[(*num_of_func)]->num_of_params)=0;
		current_scope->FUNC_SYMB_TBL[(*num_of_func)]->params= (smb_var**)malloc(sizeof(int)*(* max_num_of_params));

		if(current->data->b->a!=NULL)
		{
			tree_scan_params_to_func_smb(current->data->b->a,&((current_scope->FUNC_SYMB_TBL)[(*num_of_func)]->params),max_num_of_params,(current_scope->FUNC_SYMB_TBL)[(*num_of_func)]->num_of_params);
		}
		if(current->data != NULL)
		{
			*num_of_func = *num_of_func +1;
			func_scan(current->data,current_scope);
		}
		if(current_scope->next !=NULL && !strcmp(current->data->a->token,"main"))
		{
			if(strcmp(current->data->b->token,"NONE PARAMS"))
			{
				printf("ERROR : main number of params have to be zero\n");
				exit(1);
			}
			if(strcmp(current->data->c->a->token,"VOID"))//not eqaul
			{
				printf("ERROR : main have to be void\n");
				exit(1);
			}
			main_exist= true;
		}
		//move to next func
		
        current = current->next;
    }
	if(main_exist==false)
		{
			printf("ERROR : no main func.\n");
			exit(1);
		}
	printf("-OK-\n");
	//print_scope(current_scope);
}
void func_scan(tree_node* node,scope *pre_scope)
{
	//create scope
	scope *current_scope = (scope*)malloc(sizeof(scope));
	//
	bool func=1;//if its a function have to be return at end
	int *current_max_num_of_funcs = (int*)malloc(sizeof(int));
    int *num_of_func = (int*)malloc(sizeof(int));
    int *current_max_num_of_vars = (int*)malloc(sizeof(int));
    int *num_of_var = (int*)malloc(sizeof(int));
	int *current_max_num_of_params = (int*)malloc(sizeof(int));
    int *num_of_param = (int*)malloc(sizeof(int));
	*current_max_num_of_funcs= 2;
	*num_of_func = 0;
	*current_max_num_of_vars=2;
    *num_of_var=0;
    *current_max_num_of_params=2;
    *num_of_param=0;
	//create var table in scope
    current_scope->VAR_SYMB_TBL = (smb_var**)malloc(sizeof(smb_var*) * (*current_max_num_of_vars));
	//create func table in scope
	current_scope->FUNC_SYMB_TBL=(smb_func**)malloc(sizeof(smb_func*) * (*current_max_num_of_funcs));
	current_scope->num_of_funcs=num_of_func;
    //printf("1.2\n");
	//get memory for first func table
	current_scope->FUNC_SYMB_TBL[*num_of_func]= (smb_func*)malloc(sizeof(smb_func));
	//get memory for params member in func table
	current_scope->FUNC_SYMB_TBL[*num_of_func]->params = (smb_var**)malloc(sizeof(smb_var*) * (*current_max_num_of_params));
	current_scope->FUNC_SYMB_TBL[*num_of_func]->num_of_params = num_of_param;
	//create link list of scopes
	current_scope->pre = pre_scope;
	pre_scope->next = current_scope;

	current_scope->scope_lvl = pre_scope->scope_lvl +1;
 
	//give name to scope
	
	current_scope->func_name = strdup(node->a->token);
	current_scope->num_of_vars = num_of_var;
	current_scope->return_value= strdup(node->c->a->token);
	if(!strcmp(current_scope->return_value,"STRING"))
	{
		printf("ERROR: function %s can not return string\n",current_scope->func_name);
		exit(1);
	}
	else if(!strcmp(current_scope->return_value,"VOID"))
	{
		func=0;
	}
	//add param var to var_smbl and to func_table->params
    if(node->b->a != NULL)
		tree_scan_params_to_var_smb(node->b->a,&(current_scope->VAR_SYMB_TBL),current_max_num_of_vars,num_of_var);
	//add vars to var_smbl and func to func table
    if(node->d->a != NULL)
		tree_scan_decs(node->d->a,&(current_scope->VAR_SYMB_TBL),current_max_num_of_vars,num_of_var,current_scope,&(current_scope->FUNC_SYMB_TBL),current_max_num_of_funcs,num_of_func);
	//scan for stms
	if(node->d->b != NULL)
	{
    	tree_scan_stms(node->d->b,current_scope,func);
	}
}
void tree_scan_params_to_var_smb(tree_node* node, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var) {
    //printf("------------tree_scan_params_to_var_smb\n");
    char type[10], ids_name[200],id_name[24];
    int start,end,k=0;;
    do
    {
		//printf("a\n");
		strcpy(type,node->a->token);
		//printf("a. type: %s\n",type);
		strcpy(ids_name,node->b->token);
		//printf("a. ids_name: %s\n",ids_name);
		start=0;
		for(int i=0; i<200; i++)
		{
			if(ids_name[i] == ' ' || ids_name[i] =='\0')
			{
				end = i;
				for(int j=start;j<end && k<24;j++)
				{
					id_name[k++] = ids_name[j];
				}

				id_name[k]='\0';
				add_row_to_symb_tbl(id_name, type, type, "???", 0, SYMB_TBL, current_max_num_of_vars, num_of_var);
				k=0;
				start=end+1;
			}
			if(ids_name[i] =='\0')
				break;
		}
		node= node->c;
    }while(node != NULL);
}
void tree_scan_params_to_func_smb(tree_node* node, smb_var*** func_params,int* current_max_num_of_params,int* num_of_param) {
    //printf("-----------------tree_scan_params_to_func_smb\n");
    char type[10], ids_name[200],id_name[24];
    int start,end,k=0;;
    do
    {
		//printf("a\n");
		strcpy(type,node->a->token);
		//printf("a. type: %s\n",type);
		strcpy(ids_name,node->b->token);
		//printf("a. ids_name: %s\n",ids_name);
		start=0;
		for(int i=0; i<200; i++)
		{
			if(ids_name[i] == ' ' || ids_name[i] =='\0')
			{
				end = i;
				for(int j=start;j<end && k<24;j++)
				{
					id_name[k++] = ids_name[j];
				}
				id_name[k]='\0';
				//printf("%s\n",id_name);		
				add_row_to_symb_tbl(id_name, type, type, "???", 0, func_params, current_max_num_of_params, num_of_param);
				k=0;
				start=end+1;
			}
			if(ids_name[i] =='\0')
				break;
		}
		node= node->c;
    }while(node != NULL);
}
void tree_scan_decs(tree_node* node, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope,smb_func ***func_table, int* current_max_num_of_funcs, int* num_of_func) {
	//printf("2.1\n");
    do
    {
	tree_scan_single_dec(node->a, SYMB_TBL, current_max_num_of_vars, num_of_var,current_scope,func_table, current_max_num_of_funcs, num_of_func);
	node= node->b;
    }while(node != NULL);
}
void tree_scan_single_dec(tree_node* node, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope,smb_func ***func_table, int* current_max_num_of_funcs, int* num_of_func) {
    char type[10];
    if(!strcmp(node->token,"VAR_DEC"))
    {
		//printf("3.1\n");
		strcpy(type,node->a->token);
		scan_var_dec(node->b,type,SYMB_TBL, current_max_num_of_vars, num_of_var,current_scope);
    }
    else if(!strcmp(node->token,"STR_DEC"))
    {
		//printf("3.2\n");
		strcpy(type,"STRING");
		scan_str_dec(node->a,type,SYMB_TBL, current_max_num_of_vars, num_of_var,current_scope);
    }
    else if(!strcmp(node->token,"FUNC_DEC"))
    {
		if(!(strcmp(node->a->a->token, "main"))) 
		{
		printf("Main function have to be at global scope\n"); 
		exit(1);
		}
		//printf("FUNC_DEC\n");
		if(find_func(node->a->a->token,current_scope->FUNC_SYMB_TBL,num_of_func))
		{
			printf("ERROR, func %s already exist in scope\n", node->a->a->token);
			exit(1);
		}
		if((*num_of_func) + 1 == (*current_max_num_of_funcs))
		{
			(*current_max_num_of_funcs) *= 2;
			(*func_table)=(smb_func **)realloc(*func_table, sizeof(smb_func*) * (*current_max_num_of_funcs));
			//current_scope->FUNC_SYMB_TBL = *func_table;
		}
		(*func_table)[*num_of_func]= (smb_func*)malloc(sizeof(smb_func));
		(*func_table)[(*num_of_func)]->name = strdup(node->a->a->token);
		(*func_table)[(*num_of_func)]->return_value = strdup(node->a->c->a->token);

		(*func_table)[(*num_of_func)]->num_of_params=(int*)malloc(sizeof(int));
		*((*func_table)[(*num_of_func)]->num_of_params)=0;
		int* max_num_of_params=(int*)malloc(sizeof(int));
		* max_num_of_params=2;

		(*func_table)[(*num_of_func)]->params= (smb_var**)malloc(sizeof(int)*(* max_num_of_params));
		if(node->a->b->a!=NULL)
		{
			tree_scan_params_to_func_smb(node->a->b->a,&((*func_table)[(*num_of_func)]->params),max_num_of_params,(*func_table)[(*num_of_func)]->num_of_params);
		}
		else
		{
			(*func_table)[(*num_of_func)]->params=NULL;
		}
		*num_of_func = *num_of_func +1;
		func_scan(node->a,current_scope);
		
		//print_func_smb_tbl(*num_of_func,*func_table);
    }
}
void scan_var_dec(tree_node* node,char type[10], smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope)
{
    char* value;
    int length;
    do{
		if(!strcmp(node->token,"VAR"))
		{
			add_row_to_symb_tbl(node->a->token,type,type,"???",0, SYMB_TBL, current_max_num_of_vars, num_of_var);
		}
		else if(!strcmp(node->token,"ASS_STMT"))
		{
			if(!strcmp("PTR_ASS",node->a->token))
			{
				printf("ERROR: cant do pointer assignment in declaration.\n");
				exit(1);
			}
			else if((!strcmp(check_exp_type(node->a->b,current_scope),"NULL")) && ( (!strcmp(type,"P_INT")) || (!strcmp(type,"P_CHAR")) || (!strcmp(type,"P_REAL")) ))
			{}
			else if(strcmp(type,check_exp_type(node->a->b,current_scope)))
			{
				printf("ERROR: cant assign %s type to %s type.\n",check_exp_type(node->a->b,current_scope),type);
				exit(1);
			}
			add_row_to_symb_tbl(node->a->a->a->token,type,type/*exp_type(node->a->b)*/,"???",0, SYMB_TBL, current_max_num_of_vars, num_of_var);
		}
		node = node->b;
    }while(node != NULL);
}
void scan_str_dec(tree_node* node,char type[10], smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var,scope *current_scope)
{
	//printf("scan_str_dec\n");
    do{
		if(strcmp(check_exp_type(node->b,current_scope),"INT"))
		{
			printf("ERROR: in operator [] can be only integer.\n");
			exit(1);
		}
		if(!strcmp(node->token,"STRING"))
		{
			add_row_to_symb_tbl(node->a->token,type,type,"???",10/*calc_exp(node->a->b)*/, SYMB_TBL, current_max_num_of_vars, num_of_var);
		}
		else if(!strcmp(node->token,"="))
		{
			if(strcmp(check_exp_type(node->c,current_scope),"STRING"))
			{
				printf("ERROR: string varibale can assign only to string.\n");
				exit(1);
			}
			add_row_to_symb_tbl(node->a->token,type,type,node->c->token,10/*calc_exp(node->a->b)*/, SYMB_TBL, current_max_num_of_vars, num_of_var);
		}
		node = node->d;
    }while(node != NULL);
}
bool find_func(char* id_name, smb_func **FUNC_SYMB_TBL, int* num_of_funcs)
{
    //printf("***find_func***\n");
    for(int i=0; i<(*num_of_funcs) ;i++)
    {
		if(!strcmp(id_name,FUNC_SYMB_TBL[i]->name))
			return true;
    }
    //printf("***********************************6.2\n");
    return false;
}
bool find_var(char* id_name, smb_var **SYMB_TBL, int* num_of_var)
{
    for(int i=0; i<(*num_of_var) ;i++)
    {
		if(!strcmp(id_name,SYMB_TBL[i]->name))
			return true;
    }
    return false;
}
void add_row_to_symb_tbl(char* id_name,char* id_type,char* id_ass_type, char* id_val, int id_len, smb_var ***SYMB_TBL, int* current_max_num_of_vars, int* num_of_var)
{
    if(! (find_var(id_name, *SYMB_TBL, num_of_var)) )
    {
		if(*num_of_var + 1 == *current_max_num_of_vars)
		{
			*current_max_num_of_vars *= 2;
			(*SYMB_TBL)=(smb_var **)realloc(*SYMB_TBL, sizeof(smb_var *) * (*current_max_num_of_vars));
		}
		(*SYMB_TBL)[*num_of_var]= (smb_var*)malloc(sizeof(smb_var));
		(*SYMB_TBL)[*num_of_var]->name = strdup(id_name);
		if(!strcmp(id_ass_type,"NONE") || !strcmp(id_ass_type,id_type))
			(*SYMB_TBL)[* num_of_var]->type = strdup(id_type);
		if(strcmp(id_val,"???"))
			(*SYMB_TBL)[* num_of_var]->initialized=true;
		else
			(*SYMB_TBL)[* num_of_var]->initialized=false;
		(*SYMB_TBL)[* num_of_var]->value = strdup(id_val);

		(*SYMB_TBL)[* num_of_var]->length = id_len;
		*num_of_var = *num_of_var + 1;
    }
	else
	{
		printf("ERROR: identifier %s alreary exist in current function.\n",id_name);
		exit(1);
	}
}
//<---------------------------scan stmnts------------------------------------------------------->//
void tree_scan_stms(tree_node* node,scope *current_scope, bool func)
{
	
	do
	{
		scan_stm(node->a,current_scope);
		if(node->b == NULL && func==1)// if it is function scope and we are on the last stmnts
		{
			if(strcmp(node->a->token,"RET"))//if last stmnt NOT EQUAL to return stmnt
			{
				printf("ERROR: last statement in function %s have to be return statement.\n",current_scope->func_name);
				exit(1);
			}
		}
		
		node = node->b;
	}while(node != NULL);
}
void scan_stm(tree_node* node,scope *current_scope)
{
	if(!strcmp(node->token,"IF"))
	{
		if(strcmp(check_exp_type(node->a,current_scope),"BOOL"))
		{
			printf("IF condition has to be bool type.\n");
			exit(1);
		}
		block_stmnt_scan(node->b, current_scope);
	}
	else if(!strcmp(node->token,"IF-ELSE"))
	{
		if(strcmp(check_exp_type(node->a,current_scope),"BOOL"))
		{
			printf("IF-ELSE condition has to be bool type.\n");
			exit(1);
		}
		block_stmnt_scan(node->b, current_scope);
		block_stmnt_scan(node->c, current_scope);
	}
	else if(!strcmp(node->token,"WHILE"))
	{
		if(strcmp(check_exp_type(node->a,current_scope),"BOOL"))
		{
			printf("WHILE condition has to be bool type.\n");
			exit(1);
		}
		block_stmnt_scan(node->b, current_scope);
	}
	else if(!strcmp(node->token,"FOR"))
	{
		if(strcmp(check_exp_type(node->b,current_scope),"BOOL"))
		{
			printf("FOR condition has to be bool type.\n");
			exit(1);
		}
		check_exp_type(node->a,current_scope);
		check_exp_type(node->c,current_scope);
		block_stmnt_scan(node->d, current_scope);
	}
	else if(!strcmp(node->token,"REGULAR_ASS"))
	{
		if((!strcmp(check_exp_type(node->b,current_scope),"NULL")) && ( (!strcmp(check_exp_type(node->a,current_scope),"P_INT")) || (!strcmp(check_exp_type(node->a,current_scope),"P_CHAR")) || (!strcmp(check_exp_type(node->a,current_scope),"P_REAL")) ))
		{}
		else if(strcmp(check_exp_type(node->a,current_scope),check_exp_type(node->b,current_scope)))
		{
			printf("ERROR: you can't to enter %s to %s type.\n",check_exp_type(node->b,current_scope),check_exp_type(node->a,current_scope));
			exit(1);
		}
	}
	else if(!strcmp(node->token,"PTR_ASS"))
	{
		if(!strcmp(check_exp_type(node->a,current_scope),"P_INT"))
		{
			if(strcmp(check_exp_type(node->b,current_scope),"INT"))
			{
				printf("ERROR: to int* can assign only int.\n");
				exit(1);
			}
		}
		else if(!strcmp(check_exp_type(node->a,current_scope),"P_REAL"))
		{
			if(strcmp(check_exp_type(node->b,current_scope),"REAL"))
			{
				printf("ERROR: to float* can assign only float.\n");
				exit(1);
			}
		}
		else if(!strcmp(check_exp_type(node->a,current_scope),"P_CHAR"))
		{
			if(strcmp(check_exp_type(node->b,current_scope),"CHAR"))
			{
				printf("ERROR: to char* can assign only char.\n");
				exit(1);
			}
		}
		else
		{
			printf("ERROR: %s type can not point to address.\n",check_exp_type(node->a,current_scope));
			exit(1);
		}
	}
	else if(!strcmp(node->token,"STR_ASS"))
	{
		if(strcmp(check_exp_type(node->a,current_scope),"STRING"))
		{
			printf("ERROR: operator [] can be used only on String type.\n");
			exit(1);
		}
		if(strcmp(check_exp_type(node->b,current_scope),"INT"))
		{
			printf("ERROR: in operator [] can be  only Int type.\n");
			exit(1);
		}
		if(strcmp(check_exp_type(node->c,current_scope),"CHAR"))
		{
			printf("check_exp_type(node->c,current_scope)%s\n",check_exp_type(node->c,current_scope));
			printf("ERROR: string[] can be assign only to char.\n");
			exit(1);
		}
	}
	else if(!strcmp(node->token,"FUNC_CALL"))
	{
		//if(node->b!=NULL && strcmp(node->b->token,"FUNC_CALL"))
		//{
			node->a->args_type= types_of_args(node->a->b ,current_scope);
			//printf("PART 2: -------- %s -------------\n",node->a->args_type[0]);
		//}
		check_exp_type(node->a,current_scope);
	}
	else if(!strcmp(node->token,"BLOCK"))
	{
		block_stmnt_scan(node, current_scope);
	}
	else if(!strcmp(node->token,"RET"))
	{
		if(strcmp(current_scope->return_value,check_exp_type(node->a,current_scope)))
		{
			printf("ERROR: function %s declare return %s but return %s.\n",current_scope->func_name,current_scope->return_value,check_exp_type(node->a,current_scope));
			exit(1);
		}
	}
	else if(!strcmp(node->token,"DO_WHILE"))
	{
		if(strcmp(check_exp_type(node->a->b,current_scope),"BOOL"))
		{
			printf("DO WHILE condition has to be bool type.\n");
			exit(1);
		}
		block_stmnt_scan(node->a->a, current_scope);
	}
}
void block_stmnt_scan(tree_node* node,scope *pre_scope)
{
	//create scope
	scope *current_scope = (scope*)malloc(sizeof(scope));
	//
	int *current_max_num_of_funcs = (int*)malloc(sizeof(int));
    int *num_of_func = (int*)malloc(sizeof(int));
    int *current_max_num_of_vars = (int*)malloc(sizeof(int));
    int *num_of_var = (int*)malloc(sizeof(int));
	int *current_max_num_of_params = (int*)malloc(sizeof(int));
    int *num_of_param = (int*)malloc(sizeof(int));
	*current_max_num_of_funcs= 2;
	*num_of_func = 0;
	*current_max_num_of_vars=2;
    *num_of_var=0;
    *current_max_num_of_params=2;
    *num_of_param=0;
	//return value of block is return value of func
	current_scope->return_value = pre_scope->return_value;
	//name of block is name of func
	current_scope->func_name = pre_scope->func_name;
	//create var table in scope
    current_scope->VAR_SYMB_TBL = (smb_var**)malloc(sizeof(smb_var*) * (*current_max_num_of_vars));
	//create func table in scope
	current_scope->FUNC_SYMB_TBL=(smb_func**)malloc(sizeof(smb_func*) * (*current_max_num_of_funcs));
	current_scope->num_of_funcs=num_of_func;
	//get memory for first func table
	current_scope->FUNC_SYMB_TBL[*num_of_func]= (smb_func*)malloc(sizeof(smb_func));
	//get memory for params member in func table
	current_scope->FUNC_SYMB_TBL[*num_of_func]->params = (smb_var**)malloc(sizeof(smb_var*) * (*current_max_num_of_params));
	current_scope->FUNC_SYMB_TBL[*num_of_func]->num_of_params = num_of_param;
	//create link list of scopes
	current_scope->pre = pre_scope;
	pre_scope->next = current_scope;
	current_scope->scope_lvl = pre_scope->scope_lvl +1;
	//give name to scope
	current_scope->num_of_vars = num_of_var;
	//add vars to var_smbl and func to func table
    if(node->a != NULL)
		tree_scan_decs(node->a,&(current_scope->VAR_SYMB_TBL),current_max_num_of_vars,num_of_var,current_scope,&(current_scope->FUNC_SYMB_TBL),current_max_num_of_funcs,num_of_func);
	//scan for stms
	if(node->b != NULL)
	{
    	tree_scan_stms(node->b,current_scope,0);
	}
}
//<---------------------------check exp------------------------------------------------------------------->//
char* check_exp_type(tree_node* node,scope *current_scope)
{ 
	bool flag1=false, flag2=false;
	if(!strcmp(node->token ,"INT")) return "INT";
	else if(!strcmp(node->token ,"REAL")) return "REAL";
	else if(!strcmp(node->token ,"P_CHAR")) return "P_CHAR";
	else if(!strcmp(node->token ,"CHAR")) return "CHAR";
	else if(!strcmp(node->token ,"BOOL")) return "BOOL";
	else if(!strcmp(node->token ,"STRING")) return "STRING";
	else if(!strcmp(node->token ,"P_INT")) return "P_INT";
	else if(!strcmp(node->token ,"P_REAL")) return "P_REAL";
	else if(!strcmp(node->token ,"NULL")) return "NULL";
	//UNARY PLUS
	else if(!strcmp(node->token ,"+") && node->b==NULL)
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT"))
			return "INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL"))
			return "REAL";
		else
		{
			printf("ERROR, invalid + to %s \n", check_exp_type(node->a, current_scope));
			exit(1);
		}
	}
	//UNARY MINUS
	else if(!strcmp(node->token ,"-")&& node->b==NULL)
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT"))
			return "INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL"))
			return "REAL";
		else
		{
			printf("ERROR, invalid - to %s \n", check_exp_type(node->a, current_scope)); exit(1);
		}
	}
	//(exp)
	else if(!strcmp(node->token ,"("))
	{ 
		return check_exp_type(node->a, current_scope);
	}
	// NOT 
	else if(!strcmp(node->token ,"!"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"BOOL"))
			return "BOOL";
		else
		{
			printf("ERROR, invalid ! to %s \n", check_exp_type(node->a, current_scope)); exit(1);
		}
	}
	// BINARY PLUS 
	else if(!strcmp(node->token ,"+"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"P_CHAR") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "P_CHAR";
		else
		{
			printf("ERROR, invalid + to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); 
			exit(1);
		}
	}
	// BINARY MINUS 
	else if(!strcmp(node->token ,"-"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"P_CHAR") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "P_CHAR";
		else
		{
			printf("ERROR, invalid - to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); 
			exit(1);
		}
	}
	// BINARY MUL 
	else if(!strcmp(node->token ,"*"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else
		{
			printf("ERROR, invalid * to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// BINARY DIVIED 
	else if(!strcmp(node->token ,"/"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "REAL";
		else
		{
			printf("ERROR, invalid / to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// LOGIC AND
	else if(!strcmp(node->token ,"&&"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"BOOL") && !strcmp(check_exp_type(node->b, current_scope),"BOOL"))
			return "BOOL";
		else
		{
			printf("ERROR, invalid &&(LOGIC AND) to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// LOGIC OR
	else if(!strcmp(node->token ,"||"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"BOOL") && !strcmp(check_exp_type(node->b, current_scope),"BOOL"))
			return "BOOL";
		else
		{
			printf("ERROR, invalid ||(LOGIC OR) to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// BIG
	else if(!strcmp(node->token ,">"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else
		{ 
			printf("ERROR, invalid > to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// BIG OR EQUAL
	else if(!strcmp(node->token ,">="))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else
		{
			printf("ERROR, invalid >= to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// SMALL
	else if(!strcmp(node->token ,"<"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else
		{
			printf("ERROR, invalid < to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// SMALL OR EQUAL
	else if(!strcmp(node->token ,"<="))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else
		{
			printf("ERROR, invalid <= to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// SMALL OR EQUAL
	else if(!strcmp(node->token ,"<="))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"INT") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"INT"))
			return "BOOL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL") && !strcmp(check_exp_type(node->b, current_scope),"REAL"))
			return "BOOL";
		else
		{
			printf("ERROR, invalid <= to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// EQUAL
	else if(!strcmp(node->token ,"=="))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),check_exp_type(node->b, current_scope)))
			return "BOOL";
		else
		{
			printf("ERROR, invalid == to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// DIFF
	else if(!strcmp(node->token ,"!="))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),check_exp_type(node->b, current_scope)))
			return "BOOL";
		else
		{
			printf("ERROR, invalid != to %s and %s\n", check_exp_type(node->a, current_scope), check_exp_type(node->b, current_scope)); exit(1);
		}
	}
	// STR_LEN
	else if(!strcmp(node->token ,"STR_LEN"))
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"STRING"))
			return "INT";
		else
		{
			printf("ERROR, invalid |%s|(STR LEN) work only on string.\n", check_exp_type(node->a, current_scope)); exit(1);
		}
	}
	// ADDRESS
	else if(!strcmp(node->token ,"ADDRESS") && node->b==NULL)
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"INT"))
			return "P_INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"REAL"))
			return "P_REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"CHAR"))
			return "P_CHAR";
		else
		{
			printf("ERROR, invalid &(addres) to %s.\n", check_exp_type(node->a, current_scope)); exit(1);
		}
	}
	// ADDRESS
	else if(!strcmp(node->token ,"ADDRESS"))
	{ 
		if(strcmp(check_exp_type(node->a, current_scope),"STRING"))//if not equal
		{
			printf("ERROR, invalid &(addres) to %s[].\n", check_exp_type(node->a, current_scope)); 
			exit(1);
		}
		if(strcmp(check_exp_type(node->b->a, current_scope),"INT"))//if not equal
		{
			printf("ERROR, invalid [%s], in [] operator can be only int type .\n", check_exp_type(node->b->a, current_scope)); 
			exit(1);
		}
		return "P_CHAR";
	}
	// POINTER
	else if(!strcmp(node->token ,"PTR") && node->b == NULL)
	{ 
		if(!strcmp(check_exp_type(node->a, current_scope),"P_INT"))
			return "INT";
		else if(!strcmp(check_exp_type(node->a, current_scope),"P_REAL"))
			return "REAL";
		else if(!strcmp(check_exp_type(node->a, current_scope),"P_CHAR"))
			return "CHAR";
		else
		{
			printf("ERROR, invalid *(pointer) to %s\n", check_exp_type(node->a, current_scope));
			 exit(1);
		}
	}
	// POINTER ARITHMETIC
	else if(!strcmp(node->token ,"PTR"))
	{ 
		if(strcmp(check_exp_type(node->b, current_scope),"INT"))
			{
				printf("ERROR, in pointer arithmetic you only can add or subtract from a pointer integer number.\n");
				exit(1);
			}
		if(!strcmp(check_exp_type(node->a, current_scope),"P_CHAR"))
			return "CHAR";
		else
		{
			printf("ERROR, Our language supports only pointer arithmetic for char pointers.\n");
			exit(1);
		}
	}
	// STRING IN PLACE
	else if(!strcmp(node->token ,"ID") && node->b != NULL)
	{ 
		if(strcmp(check_exp_type(node->a, current_scope),"STRING"))//if not equal
		{
			printf("ERROR, invalid [] to %s.\n", check_exp_type(node->a, current_scope));
			exit(1);
		}
		if(strcmp(check_exp_type(node->b->a, current_scope),"INT"))//if not equal
		{
			printf("ERROR, invalid [%s] .\n", check_exp_type(node->b->a, current_scope)); 
			exit(1);
		}
		return "CHAR";
	}
	// IDENTIFIER
	else if(!strcmp(node->token ,"ID"))
	{ 
		return identifier_type(node->a->token, current_scope);
	}
	// FUNC RETURN TYPE
	else if(!strcmp(node->token ,"FUNC_CALL"))
	{ 
		int number_of_args = num_of_args(node->b);
		//node->num_of_args=number_of_args;
		int num_of_params = num_of_params0(node->a->token, current_scope);
		if(node->b!=NULL)
		{
			if( number_of_args != num_of_params)
			{
				printf("func name: %s\n",node->a->token);
				printf("num of params: %d\n",num_of_params);
				printf("num of args: %d\n", number_of_args);
				printf("ERROR : num of params didnt match to num of args\n");
				exit(1);
			}
		}
		else
		{
			if(num_of_params != 0)
			{
				printf("func name: %s\n",node->a->token);
				printf("num of params: %d\n", 0);
				printf("num of args: %d\n", number_of_args);
				printf("ERROR : num of params didnt match to num of args\n");
				exit(1);
			}
		}
		smb_var** function_params;
		function_params= func_params(node->a->token,current_scope);
		char** args_type = types_of_args(node->b ,current_scope);
		//node->args_type=args_type;
		for(int i =0;i< number_of_args; i++)
		{
			if(strcmp(function_params[i]->type,args_type[i]))//not equals
			{
				printf("arg type(%s) didnt match to param type(%s).\n ",args_type[i],function_params[i]->type);
				exit(1);
			}
		}
		return func_type(node->a->token, current_scope);
	}
	return "ON WORKING";
}
char* identifier_type(char* id_name,scope* current_scope)
{
	scope* temp = current_scope;
	char *type;
	while(temp != NULL)
	{
		type = find_var_type(id_name,temp->VAR_SYMB_TBL,*(temp->num_of_vars));
		if(strcmp(type,"NONE"))//not equal
			return type;
		temp = temp->pre;
	}
	printf("ERROR :var %s dont exist in scope: %s\n",id_name,current_scope->func_name);
	exit(1);
}
char* find_var_type(char* id_name, smb_var **SYMB_TBL, int num_of_var)
{
    for(int i=0; i<num_of_var ;i++)
    {
		if(!strcmp(id_name,SYMB_TBL[i]->name))
		{
			return SYMB_TBL[i]->type;
		}
    }
    return "NONE";
}
char* func_type(char* func_name,scope* current_scope)
{
	//printf("------------------------------------------------func_type\n");
	scope* temp = current_scope;
	//printf("*10.ID: %s\n", func_name);
	char *type;
	while(temp != NULL)
	{

		type = find_func_type(func_name,temp->FUNC_SYMB_TBL,*(temp->num_of_funcs));
		if(strcmp(type,"NONE"))//not equal
			return type;
		//printf("------------not found func on scope lvl: %d --------------\n", temp->scope_lvl);
		temp = temp->pre;
			
	}
	printf("ERROR: at function: %s, function: %s didnt found.\n",current_scope->func_name,func_name);
	printf("you need to declare on function before you can use her.\n");
	exit(1);
}
char* find_func_type(char* func_name, smb_func **FUNC_TBL, int num_of_funcs)
{

    for(int i=0; i<num_of_funcs ;i++)
    {
		if(!strcmp(func_name,FUNC_TBL[i]->name))
		{

			return FUNC_TBL[i]->return_value;
		}
    }
    return "NONE";
}
//<---------------------------help func-------------------------------------------------------------->//
int num_of_params0(char* func_name,scope* current_scope)
{
	scope* temp = current_scope;
	int n_params = -1;
	while(temp != NULL)
	{

	
		n_params = num_of_params1(func_name,temp->FUNC_SYMB_TBL,*(temp->num_of_funcs));
		if(n_params != -1)//not equal
			return n_params;
		temp = temp->pre;
			
	}
	printf("ERROR: at function: %s, function: %s didnt found.\n",current_scope->func_name,func_name);
	printf("you need to declare on function before you can use her.\n");
	exit(1);
}
int num_of_params1(char* func_name , smb_func **FUNC_TBL, int num_of_funcs)
{
    for(int i=0; i<num_of_funcs ;i++)
    {
		if(!strcmp(func_name,FUNC_TBL[i]->name))
		{
			return *(FUNC_TBL[i]->num_of_params);
		}
    }
	return -1;
}
smb_var** func_params(char* func_name,scope* current_scope)
{
	scope* temp = current_scope;
	smb_var** params = NULL;
	while(temp != NULL)
	{
		for(int i=0; i<*(temp->num_of_funcs) ;i++)
		{

			if(!strcmp(func_name,temp->FUNC_SYMB_TBL[i]->name))
			{
			
				return temp->FUNC_SYMB_TBL[i]->params;
			}
		}
		temp = temp->pre;
	}
	printf("ERROR: at function: %s, function: %s didnt found.\n",current_scope->func_name,func_name);
	printf("you need to declare on function before you can use her.\n");
	exit(1);
}
int num_of_args(tree_node* node)
{
	int count=0;
	while(node!=NULL)
	{
		count++;
		node=node->b;
	}
	return count;
}
char** types_of_args(tree_node* node ,scope* current_scope)
{
	int num=0;
	char** types=(char**)malloc(sizeof(char*)*num_of_args(node));
	while(node!=NULL)
	{
		types[num++]=strdup(check_exp_type(node->a,current_scope));
		node=node->b;
	}
	return types;
}
//<---------------------------stack controll-------------------------------------------------------------->//
void print_scope(scope* s)
{
	print_var_smb_tbl(s->num_of_vars,s->VAR_SYMB_TBL,s->func_name);
	print_func_smb_tbl(s->num_of_funcs,s->FUNC_SYMB_TBL);
}
void print_var_smb_tbl(int num_of_var,smb_var **SYMB_TBL,char* func_name)
{
	printf("___________________\n");
    printf("SYMB_TBL for %s\n",func_name);
    printf("-------------------\n");
    printf("num_of_var : %d\n",num_of_var);
    for(int i=0;i<num_of_var;i++)
    {
	printf("%d name: %s\ttype: %s\tvalue: %s\tinitialized: %d\n",i,SYMB_TBL[i]->name,SYMB_TBL[i]->type,SYMB_TBL[i]->value,SYMB_TBL[i]->initialized);
    }
}
void print_func_smb_tbl(int num_of_func,smb_func** FUNC_SYMB_TBL)
{
	printf("\n_________________________\n");
	printf("FUNCTION SYMB_TBL\n");
    printf("-----------------------\n");
    printf("num_of_funcs : %d\n",num_of_func);
    for(int i=0;i<num_of_func;i++)
    {
		printf("%d func name: %s\t return_value: %s\n"
		, i+1, (FUNC_SYMB_TBL)[i]->name, (FUNC_SYMB_TBL)[i]->return_value);
    }
}
