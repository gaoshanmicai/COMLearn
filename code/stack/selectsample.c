#include "stdio.h"
#include "stdlib.h"
#include "time.h"
 
void getRandNumber(int m,int n)//在0 -- n-1 中挑选m个 随机数 
{
	srand(time(NULL));//这个很关键 
	
	int i,j;
	for(i=0;i<n;++i)
	{		
		if( rand()%(n-i) < m)
		{
			printf("%d  ",i);
			m--;
		}
	} 
	
}
int main()
{
	const int N=10;
	printf("the N is %d\n",N);
    getRandNumber(5,10);

	printf("change N to 11 or other serial\n");

	return 0;
}