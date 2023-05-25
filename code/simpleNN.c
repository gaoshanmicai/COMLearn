
#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a)>(b)?(b):(a))
#define obs(a) a>0?a:-a
 
/*先将 轴 记录在temp 中 先从后面向前找小于轴的 放到第一个（即轴所在位置）
再从前向后找  大于轴的元素 存放到 上一步找到的小于轴的位置 
总之：要做的是将后面小于轴的 跟 前面大于轴的 做替换 】
当退出while 循环后 因为最后收场的是 i从低端加上来 所以 i 的位置对应 轴最后要存放的位置*/
   
int Partition(int a[],int i,int j)
{
	int temp=a[i];//记录下轴的位置 
	while(i<j)
	{
		while(i<j&&temp<=a[j])//将比轴小的  移动到低端 
		   j--;
     
          a[i]=a[j];//小的 等于后面的大的 (之后的i 会增加)【后面的大的 移动到前面来后 本趟不会再动】 
       
          
        while(i<j&&temp>=a[i])//将比轴大的 移动到高端 【从前往后找 ，找到 小的往后移动】 
           i++;
        
        a[j]=a[i]; // a[j] 存的 上面找到的小的 （在这里改变）小的等于 前面大的 【】 
        
 	  
	}
	a[i]=temp;//轴的位置 
	
	return i;		
}

void Printarr(int *arr,int sz)
{
	int i =0;
	for (i =0; i < sz ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

}

 
void Quicksort(int a[],int i,int j)
{
	int p;
	if(i<j)
	{
		 
	    p=Partition(a,i,j);	    
		Quicksort(a,i,p-1);
		Quicksort(a,p+1,j);
	}
}

int cmp_int(const void *e1,const void *e2)
{
	return *(int *)e1 -*(int *)e2;
}
 
int main()
{
    int a[6]={3,4,-2,-9,10,8};
	int cumarr[6]; cumarr[-1]=0;
	int cumarr1[6];
    int i,j;
    int minsofar=65535;
 
    for(i=0;i<6;++i)
    {
    	cumarr[i] = cumarr[i-1] + a[i];
    }
	

    Quicksort(cumarr,0,4);   
	
	for(i=0;i<5;++i)
	{
	    minsofar=min(minsofar,obs(cumarr[i+1] - cumarr [i]));	
	}
	
	printf("min=%d\n",minsofar);
	


	printf("before sort\n");
	Printarr(a,6);

	qsort(a,6,sizeof(a[0]),cmp_int);
	printf("after sort\n");


	Printarr(a,6);
	return 0;
}