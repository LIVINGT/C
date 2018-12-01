#include<bits/stdc++.h>

using namespace std;

bool is(int m)
{
	if(m % 5 == 0 || m % 3 == 0)
		return true;
	while(m !=0)
	{
		if(m % 10 == 3 || m % 10 == 5)
			return true;
		m /= 10;
	}
	return false;
}


int main()
{
	int n;
	cin>>n;
	int rs = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(!is(i))
			rs += i * i;
	}
	cout<<rs;
	return 0;
}