#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//寻找连续数和为sum(求因数)
vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > rs;
	for(int n = (int)sqrt(sum * 2);n >= 2; n --)
	{
		if((n&1) == 1 && sum % n == 0 || (sum % n) * 2 == n)
		{
			vector<int> r;
			for(int j = 0,k = (sum / n) - (n - 1) / 2;j < n;j ++,k ++)
				r.push_back(k);
			rs.push_back(r);
		}
		
	}
	return rs;
}