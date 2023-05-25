
#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
int main()
{
    int a[6]={3,4,-2,-9,10,8};
	int cumarr[6]; cumarr[-1]=0;
    int i,j;
    int sum=0;
    int maxsofar=0;
 
    for(i=0;i<6;++i)
    {
    	cumarr[i] = cumarr[i-1] + a[i];
    }
	for(i=0;i<6;++i)
	{
		sum=0;
		for(j=i;j<6;++j)
		{
					
		    sum = cumarr[j] - cumarr [i-1];
			maxsofar=max(maxsofar,sum);
		}
	}
	
	printf("max=%d\n",maxsofar);
	return 0;
}