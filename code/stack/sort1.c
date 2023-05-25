#include<stdio.h>
#include<string.h>



#define ARRSIZE(arr) sizeof(arr)/sizeof(arr[0])
static void shellSort(int *a,int length)
{
    int d = length;

    for(;;)
    {
         d = d/2;

         printf(" step %d\n",d);


        for(int x =0; x < d; x++){
            for(int i = x+d;i < length;i =i+d)
            {
                int temp=a[i];

                int j;

                for(j = i -d; j >=0&& a[j]>temp;j =j-d)
                {
                    a[j+d] =a[j];
                }
                a[j+d] =temp;
            }
        }

        if( d ==1)
        {
            break;

        }
    }
}

void printarr(int *a,int length)
{
    for(int i =0; i < length;i++)
    {
        printf("%d ",a[i]);

    }
    printf("\n");

}


int main(void)
{
    int arr[9] = {9,1,2,5,7,4,8,6,3,5};


    printf("befor sort :\n");
    printarr(arr,ARRSIZE(arr));

    shellSort(arr,ARRSIZE(arr));

    printf("after sort:\n");

    printarr(arr,ARRSIZE(arr));



    return 0;

}