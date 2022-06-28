#include<stdio.h>
#include <string.h>
char const *keyword[]={
    "do",
    "for",
    "if",
    "register",
    "return",
    "switch",
    "while",
    NULL
};
#define N_KEYWORD \
    (sizeof(keyword)/sizeof(keyword[0]))


int lookup_keyword(char const *const desired_world,
                char const *keyword_table[],int const size){


    char const **kwp;
    /*  kwp no initial is a fault */
    /* for(*kwp =keyword[0];*kwp !=NULL;*kwp++) */
    /* for(kwp = keyword_table;kwp <keyword_table+size;kwp++) */
    /* another methon to read */
    for(kwp = keyword_table;*kwp !=NULL;*kwp++)
    {
        if(strcmp(desired_world,*kwp)==0)
            return kwp-keyword_table;
    
    }
    return -1;
}
int main(void)
{

    int three_dim[2][3][5]={
        {
            {000,001,002,003,004,005},
            {010,001,002,003,004,005},
            {000,001,002,003,004,005}
        },
        {
            {100,101,102,103,104,105},        
            {100,101,102,103,104,105},        
            {100,101,102,103,104,105}        

        }
    };

    char *kname ="while";
    int index ;
    char name[] ={'x','m','s','s'};
    char *name2="xmss";
    puts(name);
    // name2[0]='w';
    puts(name);
    puts(name2);
    index =lookup_keyword(kname,keyword,N_KEYWORD);
    printf("the index =%d\n",index);
   
    return 0;
}