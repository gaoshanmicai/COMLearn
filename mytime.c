#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int array[]={23,24,25,26};
#define TOTAL_ELEMENTS (sizeof(array)/sizeof(array[0]))

 int main(void)
{
    time_t biggest_time =0x7fffffff;
    time_t tm;
    struct tm *p;
    int d =-1,x;
    char const *mydata ="yuan";
    const char arr[4]="yua";


    //arr[1]='k';


    


    if(d <(int)TOTAL_ELEMENTS -2)
      {
         x =array[d+1];

      } 






    printf("the biggerst = %s\n",ctime(&biggest_time));

    printf("the local biggest = %s\n",asctime(gmtime(&biggest_time)));

    time(&tm);
    
     printf("ctime  = %s\n",ctime(&tm));
    p =localtime(&tm);

    printf(" the current time =%s\n",asctime(gmtime(&biggest_time)));

    printf(" %d:%d:%d\n",p->tm_hour,p->tm_min,p->tm_sec);

    return 0;
}