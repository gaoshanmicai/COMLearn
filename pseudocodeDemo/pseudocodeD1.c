
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/* pseudocode
product a radom Set in the range[0,maxval] in order.
every set element must'nt duplicate
*/


/*
initialize set S to empty
size =0
while size < m do
     t= bigrand()%maxval
     if t is not in s
        insert t into S
        size++
print the elements of S in sorted order
*/

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


// step1 :initialize set S to empty
/*  How to def a set class 
    and how to initialize set to empty
    
*/

// step2 : bigrand() How to impletement this function
 int main()
{
    int m =5;
    const int maxval =10;

    size_t size;
    srand(time(NULL));

    for(size=0;size < maxval;++size)
    {
       if(rand()%(maxval-size)<m){

        printf("%d ",size);
        m--;
       }

    }

    return 0;



}


// step3 : how to insert . you must search a method to add this code


//step 4:
/* how to print the S
   how to traverse  the s */