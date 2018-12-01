#include<iostream>
#include<cstring>

using namespace std;

#define N 10000

const float p[N];
const float w[N];

/**
 * p,w 分别存放物品的价值和重量,满足p[i] / w[i] > p[i + 1] / w[i + 1]
 * m为背包能存放多重物品,n为物品个数
 **/
void GreedyKnapsack(int n,float m)
{
	float x[n];

	memset(x,0.0,sizeof(x));
	float U = m;
	int i = 0;
	for(;i < n;i ++)
	{
		if(w[i] > U) break;
		x[i] = 1.0;
		U -= w[i];
	}
	if(i <= n) x[i] = U/w[i];

}