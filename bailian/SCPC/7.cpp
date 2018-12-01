#include<bits/stdc++.h>

using namespace std;

bool involve(int x)
{
	while(x != 0)
	{
		if(x % 10 == 2)
			return true;
		x /= 10;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int a,b;
	while(cin>>a>>b){
		if(a>b)
			cout<<0<<endl;
		else
		{
			int rs = 0;
			for(int i = a;i <= b;i ++)
			{
				if(involve(i))
					continue;
				rs ++;
			}
			cout<<rs<<endl;
		}
	}
	return 0;
}
