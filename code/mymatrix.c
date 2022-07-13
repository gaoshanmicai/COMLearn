#include<stdio.h>
#include<string.h>


void matrix_multiply(int *m1[y],int *m2[z],int *r[z],\
                    int x,int y,int z)
{
    int i,j,k;

    for(i =0; i< x; i++)
        for(k =0; k < z; k++)
        {
            for(j =0; j<y;j++)
            {
               // r[i][k]=m1[i][j] * m2[j][k];
              (*(*(r+i)[k]))=(*(*(m1+i)[j])) * (*(*(m2+j)[k]));
            }
        }

    
}


int main(void)
{
    int mx1[3][2]={
        {2,-6},
        {3,5},
        {1,-1}
    
    };

    int mx2[2][4]={
        {4,-2,-4,-5},
        {-7,-3,6,7}
    };

    int mr[3][4]={0};


    matrix_multiply(mx1,mx2,mr,3,2,4);

    return 0;
}