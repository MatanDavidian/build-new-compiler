#include "func.h"
int n_label=0;
int n_var=0;
char* freshLabel()
{
    char *l = (char*)malloc(4);
    if(n_label<10)
    {
        n_label++;
        l[0]='L';
        l[1]=(char)n_label + 48;
        l[2]='\0';
    }
    else if(n_label<100)
    {
        l[0]='l';
        l[1]=(char)( (n_label/10) + 48);
        l[2]=(char)( (n_label%10) + 48);
        l[3]='\0';
    }
    return l;
}
char* freshVar()
{
    char* v= (char*)malloc(4);
    n_var++;
    if(n_var<10)
    {
        v[0]='t';
        v[1]=(char)(n_var + 48);
        v[2]='\0';
    }
    else if(n_var<100)
    {
        v[0]='t';
        v[1]=(char)( (n_var/10) + 48);
        v[2]=(char)( (n_var%10) + 48);
        v[3]='\0';
    }
    return v;
}
void scan_all_func(linked_list_node* head)
{
    linked_list_node * current = head;
    while (current->next != NULL) {
        //printf("NEW FUNC SCAN\n");
        n_label=0;
        n_var=0;
        set_new_labels_to_stmnts(current->data->d->b);
        set_labels_to_stmnts_and_add_code(current->data);
        printf("\n%s",current->data->code);
        current = current->next;
    }

}
//post order scan
void set_new_labels_to_stmnts(tree_node* node)
{
    if(node == Null)
        return; 
    //recursive call 
    if(node->a != NULL)
        set_new_labels_to_stmnts(node->a);
    if(node->b != NULL)
        set_new_labels_to_stmnts(node->b);
    if(node->c != NULL)
        set_new_labels_to_stmnts(node->c);
    if(node->d != NULL)
        set_new_labels_to_stmnts(node->d);
    if(!strcmp(node->token,"FUNC"))
        node->d->nextLabel=freshLabel();
    else if(node->b != NULL && !strcmp(node->token,"BLOCK"))
        node->b->nextLabel=freshLabel();   
    else if(node->a != NULL && !strcmp(node->token,"STMNT"))
        node->a->nextLabel=freshLabel();
    else if(!strcmp(node->token,"IF"))
        node->a->trueLabel=freshLabel();
    else if(!strcmp(node->token,"WHILE"))
        node->a->trueLabel=freshLabel();
    else if(!strcmp(node->token,"DO_WHILE"))
        node->a->b->trueLabel=freshLabel();
    else if(!strcmp(node->token,"FOR"))
        node->b->trueLabel=freshLabel();
    else if(!strcmp(node->token,"IF-ELSE"))
    {
        node->a->trueLabel = freshLabel();
        node->a->falseLabel = freshLabel();
    }
    else if(!strcmp(node->token,"&&"))
    {
        node->a->trueLabel = freshLabel();
    }
    else if(!strcmp(node->token,"||"))
    {
        node->a->falseLabel = freshLabel();
    }
}
//pre order and post order scan
void set_labels_to_stmnts_and_add_code(tree_node* node)
{
    char* code;
    if(node == Null)
        return; 
    set_next_label(node);
    //recursive call 
    if(node->a != NULL)
        set_labels_to_stmnts_and_add_code(node->a);
    if(node->b != NULL)
        set_labels_to_stmnts_and_add_code(node->b);
    if(node->c != NULL)
        set_labels_to_stmnts_and_add_code(node->c);
    if(node->d != NULL)
        set_labels_to_stmnts_and_add_code(node->d);
    write_code(node);
}
void write_code(tree_node* node)
{
    char* code;
    if(!strcmp(node->token,"FUNC")){
        printf("start func\n");
        asprintf(&node->code,"%s:\n\tBeginFunc‬‬\n%s\tEndFunc\n",node->a->token,node->d->code); 
    }
    else if(!strcmp(node->token,"BLOCK")){

        if(node->a!=NULL && node->b!=NULL)
        {
            printf("a\n");
            asprintf(&node->code,"%s\n%s\n",node->a->code,node->b->code); 
        }
        else if(node->a==NULL && node->b!=NULL)
        {
            printf("b\n");
            asprintf(&node->code,"%s\n",node->b->code); 
        }
        else if(strcmp(node->a->code,"") && !strcmp(node->b->code,""))
        {
            printf("c\n");
            asprintf(&node->code,"%s\n",node->a->code);
        }
        else
        {
            printf("d\n");
            node->code = strdup("");
        }
    }
    else if(node->b != NULL && node->a != NULL && !strcmp(node->token,"STMNT"))
            asprintf(&node->code,"%s\n%s\n",node->a->code,node->b->code); 
    
    else if(node->b == NULL && node->a != NULL && !strcmp(node->token,"STMNT"))
            asprintf(&node->code,"%s\n",node->a->code); 

    else if(!strcmp(node->token,"DO_WHILE"))
        asprintf(&node->code,"%s:\n%s%s\n\tgoto %s\n%s:",node->a->b->trueLabel,node->a->a->code,node->a->b->code,node->a->b->trueLabel,node->a->b->falseLabel); 
    else if(!strcmp(node->token,"WHILE"))
        asprintf(&node->code,"%s:\n%s\n %s\n\tgoto %s\n%s:",node->a->trueLabel,node->a->code,node->b->code,node->a->trueLabel,node->nextLabel); 
    else if(!strcmp(node->token,"FOR"))
        asprintf(&node->code,"%s%s:%s%s%s\n\tgoto %s\n%s:", node->a->code, node->b->trueLabel, node->c->code, node->d->code, node->b->code, node->b->trueLabel, node->nextLabel); 
    else if(!strcmp(node->token,"IF"))
        asprintf(&node->code,"%s\n%s\n%s:\n",node->a->code,node->b->code,node->nextLabel); 
    else if(!strcmp(node->token,"IF-ELSE"))
        asprintf(&node->code,"%s\n%s\n\tgoto %s\n %s:\n%s\n%s:\n",node->a->code,node->b->code,node->nextLabel,node->a->falseLabel,node->c->code,node->nextLabel);
    else if(!strcmp(node->token,"&&"))
        asprintf(&node->code,"%s\n%s\n%s\n",node->a->code, node->a->trueLabel, node->b->code);
    else if(!strcmp(node->token,"||"))
        asprintf(&node->code,"%s\n%s\n%s\n",node->a->code, node->a->falseLabel, node->b->code);
    else if(!strcmp(node->token,"!"))
        node->code = (node->a->code);
    else if( !strcmp(node->token,"<") || !strcmp(node->token,"<=") || !strcmp(node->token,">") || !strcmp(node->token,">=") || !strcmp(node->token,"==") || !strcmp(node->token,"!="))
        asprintf(&node->code,"%s\n%s\n\tifz %s %s %s goto %s\n",node->a->code,node->b->code,node->a->var,node->token,node->b->var,node->falseLabel); 
    else if(!strcmp(node->token,"BOOL")){
        if(!strcmp(node->a->token,"true"))
            asprintf(&node->code,"\tgoto %s\n",node->trueLabel); 
        else if(!strcmp(node->a->token,"false"))
            asprintf(&node->code,"\tgoto %s\n",node->falseLabel); 
    }
    else if(!strcmp(node->token,"ID"))
    {
        asprintf(&node->var,"%s",node->a->token); 
        node->code = strdup("");
    }
    else if(node->a !=NULL && (!strcmp(node->token,"INT")||!strcmp(node->token,"REAL")||!strcmp(node->token,"CHAR")||!strcmp(node->token,"STRING"))){
        node->var=freshVar();

        asprintf(&node->code,"\t%s=%s\n\t",node->var,node->a->token);
    }
    else if(!strcmp(node->token,"ARGS") && node->b==NULL)
    {
        node->var=freshVar();
        asprintf(&node->code,"%s%s=%s\n\tPushParam %s\n\t",node->a->code, node->var, node->a->var, node->var);
    }
    else if(!strcmp(node->token,"ARGS"))
    {
        node->var=freshVar();
        asprintf(&node->code,"\n\t%s%s%s=%s\n\tPushParam %s\n\t", node->b->code, node->a->code, node->var, node->a->var, node->var);
    }
    else if(!strcmp(node->token,"FUNC_CALL") && node->b!=NULL)
    {

        node->var=freshVar();
        asprintf(&node->code,"%sLCALL %s\n\tPopParams %s", node->b->code, node->a->token,param_as_bytes(node));
    }
    else if(!strcmp(node->token,"FUNC_CALL") && strcmp(node->a->token,"FUNC_CALL"))
    {
        node->var=freshVar();
        asprintf(&node->code,"LCALL %s\n", node->a->token);
    }
    else if(!strcmp(node->token,"FUNC_CALL"))
    {
        asprintf(&node->code,"%s", node->a->code);
    }
    else if(!strcmp(node->token,"RET")){
        node->var=freshVar();
        asprintf(&node->code,"\n\t%s=%s\n\tReturn %s",node->var,node->a->var,node->var);
    }
    else if(!strcmp(node->token,"*")){
        node->var=freshVar();
        asprintf(&node->code,"%s%s\n\t%s=%s*%s\n\t",node->a->code,node->b->code,node->var,node->a->var,node->b->var);
    }
    else if(!strcmp(node->token,"/")){
        node->var=freshVar();
        asprintf(&node->code,"%s%s\n\t%s=%s/%s\n\t",node->a->code,node->b->code,node->var,node->a->var,node->b->var);
    }
    else if(!strcmp(node->token,"+")){
        node->var=freshVar();
        asprintf(&node->code,"%s%s\n\t%s=%s+%s\n\t",node->a->code,node->b->code,node->var,node->a->var,node->b->var);
    }
    else if(!strcmp(node->token,"-")){
        node->var=freshVar();
        asprintf(&node->code,"%s%s\n\t%s=%s-%s\n\t",node->a->code,node->b->code,node->var,node->a->var,node->b->var);
    }
    else if(!strcmp(node->token,"(")){
        asprintf(&node->var,"%s",node->a->var);
        asprintf(&node->code,"\n%s",node->a->code);
    }
    else if(!strcmp(node->token,"ASS_STMT") && node->b !=NULL)
    {
        asprintf(&node->code,"%s%s",node->a->code,node->b->code);
    }
    else if(!strcmp(node->token,"ASS_STMT"))
    {
        asprintf(&node->code,"%s",node->a->code);
    }
    else if(!strcmp(node->token,"REGULAR_ASS"))
        asprintf(&node->code,"%s%s=%s\n",node->b->code,node->a->var,node->b->var);
    else if(!strcmp(node->token,"STR_ASS"))
    {
            node->var=freshVar();
            asprintf(&node->code,"%s%s%s=%s*1\n\t%s[%s]=%s",node->b->code,node->c->code,node->var,node->b->var,node->a->var,node->var,node->c->var);
    }
    else if(node->b != NULL && node->a != NULL && !strcmp(node->token,"DECS"))
    {
        if(!strcmp(node->a->token,"VAR_DEC"))
            asprintf(&node->code,"%s%s",node->a->code,node->b->code); 
        else
            asprintf(&node->code,"%s",node->b->code); 
    }
    else if(node->b == NULL && node->a != NULL && !strcmp(node->token,"DECS"))
    {
        if(!strcmp(node->a->token,"VAR_DEC"))
            asprintf(&node->code,"%s",node->a->code); 
        else
            node->code=strdup("");
    }
    else if(!strcmp(node->token,"VAR_DEC"))
    {
        if(!strcmp(node->b->token,"ASS_STMT") && node->b->b==NULL)
            asprintf(&node->code,"%s",node->b->code); 
        else if(!strcmp(node->b->token,"ASS_STMT"))
            asprintf(&node->code,"%s%s",node->a->code,node->b->code); 
        else
            node->code=strdup("");
    }

}
void set_next_label(tree_node* node)
{
    if(node->b != NULL && !strcmp(node->token,"STMNT"))
        node->b->nextLabel= node->nextLabel;
    else if(!strcmp(node->token,"FOR"))
    {
        node->d->falseLabel=node->nextLabel;
        node->b->falseLabel=node->nextLabel;
        node->b->nextLabel=node->nextLabel;
    }
    else if(!strcmp(node->token,"WHILE"))
    {
        node->a->falseLabel=node->nextLabel;
        node->b->nextLabel=node->nextLabel;
    }
    
    else if(!strcmp(node->token,"DO_WHILE"))
    {
        node->a->b->falseLabel=node->nextLabel;
        node->a->a->nextLabel=node->nextLabel;
    }
    else if(!strcmp(node->token,"IF"))
    {
        node->a->falseLabel=node->nextLabel;
        node->b->nextLabel=node->nextLabel;
    }
    else if(!strcmp(node->token,"IF-ELSE"))
    {
        node->b->nextLabel = node->nextLabel;
        node->c->nextLabel = node->nextLabel;
    }
    else if(!strcmp(node->token,"&&"))
    {
        node->a->falseLabel = node->falseLabel;
        node->b->trueLabel = node->trueLabel;
        node->b->falseLabel = node->falseLabel;
    }
    else if(!strcmp(node->token,"||"))
    {
        node->a->trueLabel = node->trueLabel;
        node->b->trueLabel = node->trueLabel;
        node->b->falseLabel = node->falseLabel;
    }
    else if(!strcmp(node->token,"!"))
    {
        node->a->trueLabel = node->falseLabel;
        node->a->falseLabel = node->trueLabel;
    }
    else if(!strcmp(node->token,"("))
    {
        node->a->trueLabel = node->trueLabel;
        node->a->falseLabel = node->falseLabel;
    }

}
char* param_as_bytes(tree_node* node)
{
    char *buffer=(char*)malloc(10);
    int size=0;
    int num = num_of_args(node) -1;
    for(int i=0;i<num;i++)
    {
        if(!strcmp(node->args_type[i],"CHAR"))
         {   size++;}
        else if( (!strcmp(node->args_type[i],"REAL"))||(!strcmp(node->args_type[i],"INT"))|| !strcmp(node->args_type[i],"P_INT")|| !strcmp(node->args_type[i],"P_CHAR")|| !strcmp(node->args_type[i],"P_REAL") ) 
           { size+=4;}
    }
    if(size<10){
        buffer[0]=(char)(size+48);
        buffer[1]='\0';
    }
    if(size>=10){
        buffer[0]=(char)(size/10+48);
        buffer[1]=(char)(size%10+48);
        buffer[2]='\0';
    }
    //printf("buffer %s",buffer);
    return buffer;
}
