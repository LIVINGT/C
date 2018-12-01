#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 5;
const int M = 1e6 + 22;
const int INF = 0x3f3f3f3f;
const int mod = 19260817;

int n,m;
int head[maxn],ecnt = -1;

class Edge
{
	public:
		int v,next;
		Edge(int V,int Next):v(V),next(Next){}

};

Edge edge[maxn << 2];


inline void add_edge(int u,int v)
{
	Edge e(v,head[u]);
	edge[++ ecnt] = e;
	head[u] = ecnt;
}


/*int main()
{
	int n,m;
	int a,b;
	cin>>n>>m;
	if(n == 1)
	{
		cout<<1<<endl;
		return 0;
	}
	int M[n+1][n+1];
	memset(M,0,sizeof(M));
	for(int i = 0;i < m; i++)
	{
		
		cin>>a>>b;
		M[a][b] = 1;
		M[b][a] = 1;
	}
	int e[n + 1];
	memset(e,0,sizeof(e));
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			e[i] += M[i][j];
		}
	}
	int rs[n];
	memset(rs,0,sizeof(rs));
	int cnt = 0;
	for(int i = 1;i <= n;i ++)
	{
		
		if(e[rs[cnt]] < e[i]){
			if(cnt>0)
				cnt = 0;
			rs[cnt] = i;
			continue;
		}
		if(e[rs[cnt]] == e[i])
		{
			cnt += 1;
			rs[cnt] = i;
		}
		
	}
	
	for(int i = 0;i <= cnt;i ++)
		cout<<rs[i]<<" ";
	cout<<endl;
	return 0;
}
*/



