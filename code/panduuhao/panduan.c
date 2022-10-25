#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#define N_CATEGORIES 7

typedef int(*myfp)(int);

int is_not_print(int ch)
{
    return !isprint(ch);
}

struct isting{
    int total;
    myfp test_func[N_CATEGORIES];
    char *label[N_CATEGORIES];
    int count[N_CATEGORIES];
    
} myhandler={
    .total=0,
    {
        iscntrl,
        isspace,
        isdigit,
        islower,
        isupper,
        ispunct,
        is_not_print
    },
    {
        "control",
        "whitespace",
        "digit",
        "low case",
        "upper case",
        "punctuation",
        "non-printable"
    },
    {
        0
    }

};

static int(*test_func[])(int) ={
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    is_not_print
};




char *label[]={
    "control",
    "whitespace",
    "digit",
    "low case",
    "upper case",
    "punctuation",
    "non-printable"
};

int main(void)
{
    struct isting *myptr;
    int ch;

    myptr =&myhandler;

   while((ch =getchar())!='z')
   {
        myptr->total+=1;
        for(int i =0; i<N_CATEGORIES;i++)
        {
            if(myptr->test_func[i](ch))
            {
                myptr->count[i] +=1;
            }
        }

   }

   printf("myptr total =%d\n",myptr->total);

   if(myptr->total ==0)
    printf("No characters in the input\n");

    else{
        for(int i =0; i < N_CATEGORIES;i++)
        {
            printf("%3.0f%% %s characters\n",
            ((myptr->count[i])*100.0)/(myptr->total),\
            myptr->label[i]);
        }
    }

    return 0;
 
}