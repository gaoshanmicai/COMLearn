#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
int main()
{
    int a[6]={3,4,-2,-9,10,8}; 
    int i,j,k;
    int sum=0;
    int maxsofar=0;
 
    
	for(i=0;i<6;++i)
	{
		for(j=i;j<6;++j)
		{
			sum=0;
			for(k=i;k<=j;++k)
			{
				sum+=a[k];
			}
			maxsofar=max(maxsofar,sum);
		}
	}
	
	printf("max=%d\n",maxsofar);
	return 0;
}
