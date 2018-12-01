#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int r = sqrt(n);
    cout<<r<<endl;
    int rs = 0;
    for(int i = 1;i <= r;i ++)
        for(int j = 1;j <= r;j ++)
        {
            if(i * i + j * j == n)
                rs ++;
        }
    int c = 0;
    if(r * r == n)
        c = 4;
       cout<<rs * 4 + c<<endl;
    return 0;
}