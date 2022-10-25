#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<assert.h>


int main(int argc,char **argv)
{
    char **p;
    p = argv;

    while(*p!=NULL)
        printf("\n%s\n",*p++);
    
    assert(*argv[3]==NULL);
    int a=atoi(argv[3]);

    printf("a = %d\n",a);

    putchar("0123456789ABCDEF"[a%16]);

    return 0;

}