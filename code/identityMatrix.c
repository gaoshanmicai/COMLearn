#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool identity_matrix(int (*arg)[10])
{
    int count1=0,count2=0;
    for(int i=0; i<10;i++)
        for(int j=0;j<10;j++)
        {
            if(i==j)
            {
                if(arg[i][j]==1)
                    count1++;
            }
            else{
                if(arg[i][j]==0)
                    count2++;
            }

        }
    

    if(count1==10&&count2==90)
        return true;

    else
        return false;

}


bool identity_matrix2(int **arg,int len)
{
    
}

int myArr[10][10]=
{
    {1,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
   { 0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,1,0,0},
   { 0,0,0,0,0,0,0,0,1,0},
   { 0,0,0,0,0,0,0,0,0,1}
   
};

// *ptr[10]=myArr[10];

int main(void)
{
    bool ret;

    ret =identity_matrix(myArr);

    if(ret)
    printf("Yes it is\n");
    else
        printf("No it is\n");
 
 
 return 0;
}