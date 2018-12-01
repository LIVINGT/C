#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,n;
	cin>>a>>b>>n;
	int s = b - a;
	int rs = a;
	while(n > 1)
	{
		rs += s;
		n --;
	}
	cout<<rs;
	return 0;
}
