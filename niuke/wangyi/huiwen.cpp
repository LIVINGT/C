#include<bits/stdc++.h>

using namespace std;

void count(vector<long>& a,int n)
{
	int i = 0;
	int j = n - 1;
	int rs = 0;
	while(i < j)
	{
		if(a[i] == a[j])
		{
			i ++;
			j --;
		}
		else if(a[i] < a[j])
		{
			a[i + 1] = a[i + 1] + a[i];
			i ++;
			rs ++;
		}
		else
		{
			a[j - 1] = a[j - 1] + a[j];
			j --;
			rs ++;
		}
	}
	cout<<rs<<endl;
}


int main()
{
	vector<long> ss;
	int n;
	cin>>n;
	long temp;
	int c = n;
	while(n--)
	{
		cin>>temp;
		ss.push_back(temp);
	}
	count(ss,c);
    
    return 0;
}