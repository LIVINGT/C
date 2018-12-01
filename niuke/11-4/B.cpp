#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n)
{
    if(n == 1 || n == 2 || n == 0) return 0;
    if(n & 1) return 1 + solve(n / 2) + solve(n - n / 2);
    else return 2 * solve(n / 2);
}

int main(int argc, char const *argv[])
{
	/* code */
	// int T;
	// cin>>T;
	// while(T --)
	// {
 //        ll n;
 //        cin>>n;
	// 	cout<<solve(n)<<endl;
	// }
	string a,b;
	cin>>a>>b;
	cout<<a<<b<<endl;
	cout<<"hello"<<endl;
	return 0;
}