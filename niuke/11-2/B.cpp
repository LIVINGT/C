#include<bits/stdc++.h>

using namespace std;
int cnk(int j);
typedef struct Node
{
	int p,v;
}node[10001];
node p;
int N;
void intN()
{
	long long rs = 0;
	for(int i = 1;i <= N;i ++)
	{
		rs += 1;
		int parent = i;
		int j = 0;
		while(p[parent].p && !(p[parent].v & 1))
		{
			parent = p[parent].p;
			j ++;
		}
		rs += cnk(j) * 6;
	}
	cout<<rs<<endl;
}


int cnk(int j)
{
	if(j == 0) return 0;
	if(j == 1) return 1;
	if(j == 2) return 3;

	int rs = 1;
	while(j - 2 >= 0)
	{
		rs *= j--;
	}
	rs >>= 2;
	rs += j;
	return rs;
}

int main()
{
    cin>>N;
    if(N == 1) {cout<<1<<endl;return 0;}
    if(N == 0) {cout<<0<<endl;return 0;}
    for(int i = 0;i <= N;i ++)
    {
        p[i] = {0,-1};
    }
    int s,e,v;
    for(int i = 0;i < N -1;i ++)
    {
    	cin>>s>>e>>v;
    	p[e] = {s,v};
    }
    intN();

    return 0;
}