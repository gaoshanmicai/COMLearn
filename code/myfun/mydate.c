#include<stdio.h>
#include<string.h>



int main()
{
    printf("\n%s,%d",__FILE__,__LINE__);

    printf("\n%s:%s",__DATE__,__TIME__);

    if(__STDC__)
        printf("\nANSI C");
    else
        printf("NOT ANSIC\n");

    return 0;
}