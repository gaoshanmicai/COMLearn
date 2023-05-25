
#include <iostream>  
#include <vector>  
#include <assert.h>  
#include <algorithm>  
using namespace std; 

/**
 * 问题：输入是具有 n个浮点数 的向量 x，输出是 输入向量的任何连续子向量中的最大和
*/

/**
 * 方法一：简单算法
 * 
 * 对所有满足 0 < ij<n的（i，j）整数对进行迭代，对每个整数对，程序都要计算x[i,..j]
 * 的总和，并检验总和是否大于此时的最大总和
 * 
 * 代码简洁，直观并且好理解，运行速度比较慢
*/

int MaxSum1(vector<int> datas)
{
    int i,j,k;
    int sum = 0;
    int maxsofar = 0;

    for(i =0; i < datas.size();++i)
    {
        for(j =i; j <datas.size();++j)
        {
            sum =0;
            for(k = i; k <= j; ++k)
            {
                sum +=datas[k];
            }
            maxsofar = max(maxsofar,sum);
        }
    }

    return maxsofar;
}

/**
 * 方法二：两个平方算法
 * 
 * 通过在固定的步数而不是方法一的 j -i +1步内完成对x[i,...j]的求和
 * x[i,...j]的总和与前面已经计算出的总和 x[i,...j-1]的总和密切相关
 * 
 * 时间复杂度是 O(n*n)
*/

int MaxSum2(vector<int> datas)
{
    int i,j;
    int sum = 0;
    int maxsofar = 0;

    for(i =0 ; i <datas.size();++i)
    {
        sum =0;
        for(j = i; j <datas.size();++j)
        {
            sum += datas[j];
            maxsofar = max(maxsofar,sum);
        }
    }

    return maxsofar;
}

/**
 * 通过访问在外循环执行之前就已经构建的数据结构的方式在内循环中计算总和
 * 
 * cumarr中的第 i 个元素包含 x[0...i]中各个数的累加和，所以x[i,...j]
 * 中各个数的总和可以通过计算 cumarr[j] - cumarr[i-1]得到
*/

int MaxSum2(vector<int> datas)
{
    int cumarr[datas.size()];
    cumarr[-1] =0;
    int i,j;
    int sum = 0;
    int maxsofar =0;

    for(i =0; i <datas.size();++i)
    {
        cumarr[i] = cumarr[i-1] + datas[i];
    }

    for(i =0 ; i <datas.size();++i)
    {
        sum =0;
        for(j =0; j <datas.size();++j)
        {
            sum = cumarr[j] - cumarr[i-1];
            maxsofar = max(maxsofar,sum);
        }
    }

    return maxsofar;
}

/**
 * 以上：
 * 
 *    所有算法考虑了所有可能的子向量，并计算了每个子向量中所有数的总和。
 * 因为存在 O(n*n)个子向量，所以这些算法至少需要平方的时间。你能想办法
 * 避免检测所有可能的子向量，从而获得运行时间更短的算法吗？
*/

/**
 * 分治算法
 * 
 * 解决规模为n的问题，可递归解决两个规模近似为 n/2的子问题，然后对他们的答案进行合并得到整个问题的答案
 * 
 * 思想：以m为分界线，最大值有三种情况

    一：在m左侧

    二：在m右侧

    三：跨越m

    关键：最初求解左右最大值时候，一定要从中间向两侧递增。
*/


int max2(int a,int b,int c)
{
	if(a>b&&a>c)
		return a;
	else if(b>a&&b>c)
		return b;
	else return c;	
} 

int MaxSum3(vector<int> datas,int l,int u)
{
    int i,m,sum,lmax,rmax;
	if(l>u)
		return 0;
	if(l==u)
		return max(0,datas[l]);
    m=(l+u)/2;
	
	lmax = sum =0;
	for(i=m;i>=l;--i)
   	{
		sum += datas[i];
		lmax =max(lmax,sum);
	}
	
	printf("m=:%d\n",m);
	rmax =sum =0;
	for(i=m+1;i<=u;++i)
	{
		sum += datas[i];
		rmax =max(rmax,sum);
	}
	return max2(lmax + rmax , MaxSum3(datas,l,m) , MaxSum3(datas,m+1,u) );
}

/**
 * 扫描算法
 * 
 * 
*/

int MaxSum3(vector<int> datas)
{
    int i,sum=0;
	for(i=0;i<6;++i)
	{
		sum+=datas[i];
		if(sum<0)
			sum=0;
	}
	
	printf("max=%d",sum);
    
    return sum;
}