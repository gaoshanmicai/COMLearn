#include<ctype.h>
#include<stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag
{
    IDENTIFIER,QUALIFIER,TYPE
};

struct token {
    char type;
    char string[MAXTOKENLEN];
                
};

int top =-1;
struct token stack[MAXTOKENLEN];
struct token this;

void initialize(), get_array(), get_params(), get_lparen(),get_ptr_part(), get_type();


#define pop stack[top--]
#define push(s)  stack[++top]=s
enum type_tag classify_string(void)
{
    char *s = this.string;
    if(strcmp(s,"const")==0){
        strcpy(s,"readonly");
        return QUALIFIER;

    }
    if (strcmp(s,"volatile")==0)
    {
        return QUALIFIER;   
    }
    if (strcmp(s,"void")==0)
    {
        return TYPE;
        
    }
    if(strcmp(s,"char")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"signed")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"unsigned")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"short")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"int")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"long")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"float")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"double")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"struct")==0)
    {
        return TYPE;
    }
    if(strcmp(s,"union")==0)
    {
        return TYPE;
    }
    return IDENTIFIER;
}

void gettoken(void)
{
    char *p = this.string;

    while((*p = getchar())==' ')
    ;
    if(isalnum(*p)){
        while (isalnum(*++p = getchar()))    
        ;
        ungetc(*p,stdin);
        *p = '\0';
        this.type = classify_string();
        return ;
      
    }
      
    this.string[1] ='\0';
    this.type=*p;
    return ;
        
}

/* state function */


void (*nextstate)(void) = initialize;


int main(){
    printf("the process start\n");
    while(nextstate !=NULL)
        (*nextstate)();
    return 0;
}


void initialize(){
    gettoken();
    while(this.type != IDENTIFIER){
        push(this);
        gettoken();
    }

    printf("%s is ",this.string);

    gettoken();
    nextstate= get_array;
}

void get_array(){
    nextstate = get_params;
    while (this.type =='[')
    {
        printf("array ");
        gettoken();/* a number or ']'  */
        if(isdigit(this.string[0])){
            printf("0..%d ",atoi(this.string)-1);
            gettoken();
        }
        gettoken();
        printf("of ");
        nextstate = get_lparen;
    }
    
}

void get_params(){
    nextstate = get_lparen;
    if(this.type =='('){
        while (this.type !=')')
        {
            gettoken();
        }
        gettoken();
        printf("function returning ");
        
    }
}

/* 左小括号 */
void get_lparen() {
    nextstate = get_ptr_part;
    if (top >= 0) {
        if (stack[top].type == '(') {
            pop;
            gettoken(); /* read past ')' */
            nextstate = get_array;
        }
    }
}



void get_ptr_part(){
    nextstate = get_type;

    if(stack[top].type =='*'){
        printf(" pointer to ");
        pop;
        nextstate = get_lparen;
    }else if (stack[top].type == QUALIFIER)
    {
        printf("%s ",pop.string);
        nextstate = get_lparen;   
    }
}



void get_type(){
    nextstate = NULL;

    while(top >=0){
        printf("%s ", pop.string);
    
    }
    printf("\n");
}



