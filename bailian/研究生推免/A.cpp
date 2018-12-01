#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

/**
 * 找出正整数 M 和 N 之间（N 不小于 M）的所有真素数。

真素数的定义：如果一个正整数 P 为素数，且其反序也为素数，那么 P 就为真素数。
例如，11，13 均为真素数，因为11的反序还是为11，13 的反序为 31 也为素数。
**/

int p[100009];

void initP()
{
	memset(p,1,sizeof(p));
	for(int i = 1;i <= 100000/2;i ++)
	{
		p[i << 1] = 0;
	}
	for(int i = 1;i <= (int)(100000 / 3)  + 1;i ++)
	{
		p[i * 3] = 0;
	}
	for(int i = 1;i <= 100000 / 5;i ++)
	{
		p[i * 5] = 0;
	}
}
//求反序
int inver(int m)
{
	int i = 0;
	int rs = 0;
	int c;
	int len = 0;
	if(m < 10) len = 1;
	else if(m < 100) len = 2;
	else if(m < 1000) len = 3;
	else if(m < 10000) len = 4;
	else if(m < 100000) len = 5;
	else len = 6;

	while(m != 0)
	{
		c = m % 10;
		m /= 10;
		i ++;
		rs += c * pow(10,len - i);
		
	}
	return rs;
}

int main()
{
	int m,n;
	cin>>m>>n;
	initP();
	int rs[100000 >> 3];
	int cnt = 0;
	for(int i = m;i <= n;i ++)
	{
		if(p[i] && p[inver(i)])
		{
			
			rs[cnt++] = i;
		}
			
	}
	if(cnt == 0)
	{
		cout<<"No";
	}
	else{
		int n = cnt;
		while(cnt>1)
		{
			cout<<rs[n - cnt --]<<",";
		}
		cout<<rs[n - cnt];
	}
	return 0;
}