#include "stdio.h"
#define max(a,b)  a>b?a:b
 
int a[6]={3,4,-2,-9,10,8};
int max2(int a,int b,int c)
{
	if(a>b&&a>c)
		return a;
	else if(b>a&&b>c)
		return b;
	else return c;	
}  
int maxsum(int l,int u)
{
	int i,m,sum,lmax,rmax;
	if(l>u)
		return 0;
	if(l==u)
		return max(0,a[l]);
        m=(l+u)/2;
	
	lmax = sum =0;
	for(i=m;i>=l;--i)
   	{
		sum += a[i];
		lmax =max(lmax,sum);
	}
	
	printf("m=:%d\n",m);
	rmax =sum =0;
	for(i=m+1;i<=u;++i)
	{
		sum += a[i];
		rmax =max(rmax,sum);
	}
	return max2(lmax + rmax , maxsum(l,m) , maxsum(m+1,u) );
}
int main()
{	
	int maxsofar=maxsum(0,5);
	printf("max=%d",maxsofar);
	return 0;
}