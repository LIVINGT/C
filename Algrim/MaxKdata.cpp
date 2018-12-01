#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdio>
#include<time.h>
using namespace std;
//将数组a中k个大的数移动到右边
void spl(int *a,int k,int l,int r)
{
	if(r < l) return;
	if(k == r-l + 1) return;//刚好足够
	int ll = l,rr = r;
	int temp = a[l];
	do{
		while(a[rr] >= temp && ll != rr) rr --;
		if(ll < rr)
		{
			a[ll] = a[rr];
			ll ++;
		}
		while(a[ll] <= temp && ll != rr) ll ++;
		if(ll < rr)
		{
			a[rr] = a[ll];
			rr --;
		}
		
	}while( ll != rr);
	a[ll] = temp;
	// return;
	if(r - ll + 1 == k)
	{
		return;
	}
	else if(r - ll + 1 < k)
	{
		spl(a,k - r + ll - 1,l,ll -1);
	}
	else
	{
		spl(a,k,ll + 1,r);
	}
}


int main()
{
	int a[10];
	for(int i = 0;i < 10;i ++)
	{
		a[i] = 10 - i;
	}

	spl(a,4,0,9);
	for(int i = 9;i >= 9-4 + 1;i --)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;

	return 0;
}