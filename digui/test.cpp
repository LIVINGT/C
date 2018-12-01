#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int i = 0;
	int rs = 0;
	int n;
	cin>>n;
	for(i = 1;;i ++)
	{
		rs += i;
		if(rs >= n)
			break;
	}
	bool shun = 0;
	if(i & 1)
		 shun = 1;
	
	if(!shun)
		cout<<(i - rs + n)<<"/"<<(rs - n + 1)<<endl;
	else
		cout<<rs - n + 1<<"/"<<<<endl;
	return 0;
}
