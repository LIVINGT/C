#include<bits/stdc++.h>

using namespace std;

int W[20];
int T[20];
int N;
int dp(int n,int t)
{
	if(n == 0 || t == 0)
	{
		return 0;
	}
	if(n < N &&  W[N - n] > W[N - n - 1])
	{
		return dp(n - 1,t);
	}
	if(t < T[N - n])
	{
		return dp(n - 1,t);
	}
	return max(dp(n - 1,t),dp(n - 1,t - T[N - n]) + W[N - n]);
}

int main(int argc, char const *argv[])
{
	int t;
	while(cin>>N>>t){
		
		for(int i = 0;i < N;i ++)
		{
			cin>>W[i];
		}
		for(int i = 0;i < N;i ++)
		{
			cin>>T[i];
		}
		cout<<dp(N,t)<<endl;
	}
	return 0;
}
