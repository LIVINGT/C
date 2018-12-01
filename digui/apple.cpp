#include<iostream>

using namespace std;

//i个苹果放进k个盘子有多少种放法

/**
 * 有盘子为空 + 没盘子为空
 **/

int f(int m,int n)
{
	if(n > m)
	{
		return f(m,m);
	}
	if(m == 0)
		return 1;
	if(n == 0)
		return 0;
	return f(m,n-1) + f(m-n,n);
}


int main()
{
	return 0;
}