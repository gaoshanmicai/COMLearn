#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>s

typedef float  (*funhandler)(float ,float  ) ;

// void (*nextstate)(void) = initialize;
/* 状态函数 */
float add(float a,float b ),  decrease(float a,float b ),  plus(float a,float b ),  divide(float a, float b);

// funhandler myfun[5]={
//     add,
//     decrease,
//     plus,
//     divide,
//     NULL
// };

float add(float a,float b)
{
    return a+b;
}

float decrease(float a,float b)
{
    return a-b;
}
float plus(float a,float b)
{
    return a*b;
}
float divide(float a,float b)
{
    assert(b!=0);
    return a/b;
}

struct myhand {
    char name[32];
    funhandler myfun;
} Myfun[] =

{
    {"+",add},
    {"-",decrease},
    {"x",plus},
    {"/",divide},
    {NULL,NULL}
};



float main(float argc,char **argv)
{
    struct myhand *pfun;
    pfun = Myfun;
    float ret =0;

    while(pfun!=NULL)
    {
        ret=(pfun->myfun)(atof(argv[1]),atof(argv[2]));
       
        printf(" %lf %s %lf = %lf\n",atof(argv[1]),pfun->name,atof(argv[2]),ret);
        pfun++;
    } 
    
    return 0;

}
