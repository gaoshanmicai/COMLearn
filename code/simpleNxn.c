#include <stdio.h>
#define min(a, b) ((a)>(b)?(b):(a))
#define obs(a) a>0?a:-a
int main()
{
    int a[6]={3,4,-2,-9,10,8}; 
    int i,j,k;
    int sum=0;
    int maxsofar=65535;//这个很关键 
 
    
	for(i=0;i<6;++i)
	{
		for(j=i;j<6;++j)
		{
			sum=0;
			for(k=i;k<=j;++k)
			{
				sum+=a[k];
			}
			maxsofar=min(maxsofar,obs(sum));
		}
	}
	
	printf("max=%d\n",maxsofar);
	return 0;
}