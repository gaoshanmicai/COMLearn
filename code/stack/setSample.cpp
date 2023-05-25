
#include <iostream>
#include <set>
#include<time.h>
using namespace std;
 
void getSet(int m,int n)//在0 -- n-1 中挑选m个 随机数 
{
	srand(time(NULL));//这个很关键 
	set<int> S;
	while(S.size()<m)  //直到填满 
		S.insert(rand()%n);
	set<int>::iterator i;
	for(i=S.begin();i!=S.end();++i)
		cout<<*i<<" "; 
}
int main()
{
    getSet(5,10);
	return 0;
}