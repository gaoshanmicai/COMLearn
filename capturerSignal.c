#include<signal.h>
#include<stdio.h>

void handler(int s)
{

    if(s == SIGSEGV) printf("now got a segmentation violation signal\n");
    if(s == SIGILL)  printf("now got an illegal instruction signal\n");
    if(s == SIGINT)  printf("now got an illegal interupt signal\n");


}

int main(void)
{
    int *p = NULL;

    // signal(SIGBUS,handler);
    signal(SIGSEGV,handler);
    signal(SIGILL,handler);
    signal(SIGINT,handler);

    while(1);
   // *p = 0;

}