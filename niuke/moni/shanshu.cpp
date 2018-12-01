#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n == 0)
        cout<<0<<endl;
    else
    {
        int rs = 0;
        if(n > 1000)
            n = 1000;
        for(int i = 2;i <= n;i ++)
            rs = (rs + 3) % i;
        cout<<rs;
    }
	return 0;    
}