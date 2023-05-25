#include<stdio.h>
 
#define ARRSIZE(a) sizeof(a)/sizeof(a[0])

void Printarr(int *arr,int sz)
{
	int i =0;
	for (i =0; i < sz ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

}

void swap( int *arr,int i,int j)
{
    int temp;

    temp = arr[i];
    arr[i] =arr[j];
    arr[j]= temp;


}

int sort1(int *arr,int arrsize)
{
    if(arr == NULL||arrsize ==0)
        return -1;
    
    int i,j;

    for(i =0; i < arrsize;i++)
        for(j = i; j> 0 && arr[j-1]> arr[j];j--)
            swap(arr,j-1,j);
  

    return 0;
}

void selectSort(int *intStorage,int kout)
{
    int i,j,k,intTemp,intmin;
    for(i =0 ; i < kout-1;i++){
        intmin = intStorage[i];
        k = i ;//what the k meaning

        // inter loop 
        for(j = i+1; j < kout;j++)
        {
            if(intmin > intStorage[j]){
                intmin = intStorage[j];
                k =j;
            }
        }

        intTemp = intStorage[i];
        intStorage[i] = intStorage[k];
        intStorage[k]= intTemp;

    }
}


void bubbleSort(int *intStorage ,int kout)
{

}


void merge(int m1,int n1,int m2,int n2);


int intStorage[40] ;
void mergeSort(int m,int n)
{
    int intMid;
    if(m < n)
    {
        intMid = (m + n)/2;
        mergeSort(m,intMid);
        mergeSort(intMid+1,n);
        nerge(m,intMid,intMid+1,n);



    }
    
}

void merge(int m1,int n1,int m2,int n2)
{
    int tmpStorage[40];
    int m,n,k;
    m = m1;
    n = m2;
    k = 0;

    while( m <= n1 && n <= n2)
    {
        if(intStorage[m] < intStorage[n])
            tmpStorage[k++]= intStorage[m++];
        else
            tmpStorage[k++]= intStorage[n++];

    }

    while(m <= n1)
        tmpStorage[k++]= intStorage[m++];
    while(m <= n2)
        tmpStorage[k++]= intStorage[n++];

    for(m = m1,n =0; m <= n2;m++,n++)
        intStorage[m] =tmpStorage[n];
    
}


int main()
{
    int da[6] ={8,9,2,0,1,3};
    printf("Before sort\n");
    Printarr(da,ARRSIZE(da));
    selectSort(da,ARRSIZE(da));
    //sort1(da,ARRSIZE(da));
    printf("after sort\n");
    Printarr(da,ARRSIZE(da));
    return 0;



}