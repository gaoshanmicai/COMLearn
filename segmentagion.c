#include<stdio.h>
#include<assert.h>

int main(void)
{
    int *p =9;
    int *ptr;

    ptr = (char*)malloc(sizeof(int));

    *ptr = 10;

    free(ptr);
    ptr =NULL;


    printf("the ptr = %d\n",*ptr);

    

    //*p =18;
    // printf("this is a segmentation\n");


}