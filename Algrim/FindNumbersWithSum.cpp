#include<iostream>
#include<vector>
#include<cstring>


using namespace std;

/**
 * 输入一个递增排序的数组和一个数字S，
 * 在数组中查找两个数，使得他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 **/
vector<int> FindNumbersWithSum(vector<int> array,int sum) {
	int f[array.size()];
	memset(f,0,sizeof(f));
	int mm = 1000000;
	vector<int> r;
	for(int i = 0;i < array.size();i ++)
	{
		if(f[i])
			continue;
		for(int j = i + 1;j < array.size();j ++)
		{
			if(f[j])
				continue;
			if(array[i] + array[j] == sum && array[i] * array[j] < mm)
			{
				r.clear();
				r.push_back(array[i]);
				r.push_back(array[j]);
				f[i] = 1;
				f[j] = 1;
				mm = array[i] * array[j];
				break;
			}
		}
	}
	return r;
}

int main()
{
	vector<int> array;
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);
	array.push_back(7);
	array.push_back(8);
	array.push_back(9);
	vector<int> rs;
	rs = FindNumbersWithSum(array,10);

	for(int i = 0;i < rs.size();i ++)
	{
		cout<<rs[i]<<" ";
	}

	return 0;
}