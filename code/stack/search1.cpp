
#include <iostream>
#include <stdio.h>
 
using namespace std;
/*
问题:使用数组，生成[0 ,maxval]范围内m各随机整数的有序序列
分析：这是典型的插入排序。每次将一个带插入的元素插入到前面已经排好序的结果中。
      1】先查找到待插入位置，2】强待插入位置及其后面元素同一向后移动，然后在待插入位置上插入元素
输入: 
100(元素最大值) 10(输出的元素个数) 
输出; 
输出10个0~100且有序的元素 
*/
 
int randRange(int min ,int max)  
{  
    if(min > max)  
    {  
        int temp = min;  
        min = max;  
        max = min;  
    }  
    return ( rand() % (max - min + 1) + min );  
}  
 
template<class T>
class IntSetArray
{
public:
	IntSetArray(int maxSize , T maxVal)
	{
		_maxSize = maxSize;
		_maxVal = maxVal;
		_x = new T[_maxSize + 1];//多一个元素用于哨兵(查找)
		_n = 0;//数组起始下标必须初始化
		_x[0] = maxVal;//哨兵
	}
	~IntSetArray()
	{
		delete[] _x;
	}
 
	//由于采用的是插入排序来做的，必须要先找到待插入元素的位置:该位置是： x[i] > value >= x[i-1]
	void insert(T value)
	{
		if(value > _maxVal || _n >= _maxSize)
		{
			return;
		}
		if(_n <= 0)
		{
			_x[++_n] = value;
			return ;
		}
		//插入元素,插入的元素必须是不存在的(确保不重复，且能确定位置)
		int pos = upperBound(_x , 1 , _n , value);
		if(pos - 1 < 0 || pos - 1 > _n)
		{
			cout << "index is wrong" << endl;
			return;
		}
		//判断是否重复(前一个元素)，重复就不插入
		if(_x[pos - 1] == value)
		{
			return;
		}
		//不重复，就将A[n]~A[pos]依次先往后移动一个位置，然后插入A[pos]
		else
		{
			++_n;
			for(int j = _n ; j >= pos + 1 ; j--)
			{
				_x[j] = _x[j-1];
			}
			_x[pos] = value;
		}
	}
 
	void report(int* v)
	{
		if(NULL == v)
		{
			return;
		}
		for(int i = 0 ; i < _n; i++)
		{
			v[i] = _x[i + 1];// _x是从1开始计算的
		}
	}
 
	int size()
	{
		return _n;
	}
 
	/*查找是一个upperbound函数，寻找某个元素后面第一个元素
	A[mid] < value,元素在后半区间,low = mid + 1
	A[mid] > value,元素在前半区间，high = mid - 1
	A[mid] = value,元素在后半区间,low = mid + 1
	*/
	int upperBound(T* x , int low , int high , T value)
	{
		int middle;
		while(low <= high)//如果只有一个元素,low=high，也需要判定
		{
			middle = low + (high - low)/2;
			if( x[middle] <= value )
			{
				low = middle + 1;
			}
			else
			{
				high = middle - 1;
			}
		}
		return low;
	}
 
private:
	int _maxSize;//数组最大长度
	int _maxVal;
	int _n;//记录数组实际长度
	T* _x;
};
 
void print(int* array , int size)  
{  
    if(NULL == array || size <= 0)  
    {  
        cout << "no result" << endl;  
        return;  
    }  
    for(int i = 0 ; i < size ; i++)  
    {  
        cout << array[i] << " ";  
    }  
    cout << endl;  
}
 
void process()
{
	int maxSize;
	int maxVal;
	while(cin >> maxVal >> maxSize)
	{
        cout<<"maxVal =";
        cout<<maxVal<<endl;
        cout<<"maxSize =";
        cout<<maxSize<<endl;

		IntSetArray<int> intSetArray(maxSize , maxVal);
		int* pArray = new int[maxSize + 1];
		//接下来就计数
		while(intSetArray.size() < maxSize)
		{
			int value = randRange(0 , maxVal);
           // cout<<value<<endl;

			intSetArray.insert(value);
		}
		intSetArray.report(pArray);
		print(pArray , maxSize);
		delete[] pArray;
	}
}
 
int main(int argc , char* argv[])
{
	process();
	getchar();
	return 0;
}