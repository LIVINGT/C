#include<iostream>
#include<vector>

using namespace std;
long long InversePairsCore(vector<int>& data,vector<int>& copy,int l,int r);
/**
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，
 * 则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
 * 并将P对1000000007取模的结果输出。 即输出P%1000000007
**/
int InversePairs(vector<int> data) {
	int l = data.size();
	if(!l)
		return 0;
	vector<int> copy;
	for(int i = 0;i < l;i ++)
		copy.push_back(data[i]);
	return (InversePairsCore(data,copy,0,l - 1) % 1000000007);
}

long long InversePairsCore(vector<int>& data,vector<int>& copy,int l,int r)
{
	if(l == r)
	{
		copy[l] = data[l];
		return 0;
	}

	int mid = (l + r)>>1;
	int p = l;
	int i = l,j = mid + 1;

	long long cnt = 0;

	long long left = InversePairsCore(copy,data,l,mid);
	long long right = InversePairsCore(copy,data,mid + 1,r);

	while((i <= mid) && (j <= r))
	{
		if(data[i] > data[j])
		{
			copy[p ++] = data[i ++];
			cnt += (r - j + 1);
		}
		else
		{
			copy[p ++] = data[j ++];
		}
	}

	while(i <= mid)
	{
		copy[p ++] = data[i ++];
	}
	while(j <= r)
	{
		copy[p ++] = data[j ++];
	}

	return cnt + left + right;

}

int main()
{
	vector<int> a;
	int temp;
	for(int i = 0;i < 8;i ++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	cout<<InversePairs(a)<<endl;
	return 0;
}