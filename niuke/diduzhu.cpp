#include<iostream>
#include<cstring>
using namespace std;

long cnt = 0;

long n;
long m;


void dfs2(int **a,int i,int j,int t)
{
	if(t == 2 * n){cnt ++;return;}
	if(i >= 4) return;
	if(j >= n) return;
	if(a[i][j])
	{
		dfs2(a,i+1,j,t);
		dfs2(a,i,j+1,t);
	}
	else{
		if(a[i+1][j] && a[i][j + 1]) return;
		if(a[i + 1][j]){
			a[i][j + 1] = 1;
			a[i][j] = 1;
			t ++;
			dfs2(a,i+1,j,t);
			a[i][j + 1] = 0;
			a[i][j] = 0;
			dfs2(a,i,j+1,t);
			
		}
		else
		{
			a[i + 1][j] = 1;
			a[i][j] = 1;
			t ++;
			dfs2(a,i+1,j,t);
			a[i + 1][j] = 0;
			a[i][j] = 0;
			dfs2(a,i,j+1,t);
			
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t > 0){
		cin>>n>>m;
		int** a = new int *[4];
		for(int i = 0;i < 4;i ++){
			a[i] = new int[n];
			memset(a[i],0,sizeof(a[i]));
		}
		
		// for(int i = 0;i < 6;i ++)
		// {
		// 	for(int j =0;j < n+2;j ++)
		// 		cout<<a[i][j]<<" ";
		// 	cout<<endl;
		// }
		dfs2(a,0,0,0);
		
		cout<<cnt/2%m<<endl;
		t--;
	}
	
	
	return 0;
}