#include<iostream>
#include<cstring>

using namespace std;

 int GetUglyNumber_Solution(int index) {
        
		if(index < 7) return index;
        int res[index + 1];
		res[0] = 1;
		int t2 = 0,t3 = 0,t5 = 0;
		for(int i  = 1;i < index;i ++)
		{
			res[i] = min(res[t2] * 2,min(res[t3] * 3,res[t5] * 5));
			if(res[i] == res[t2] * 2) t2 ++;
			if(res[i] == res[t3] * 3) t3 ++;
			if(res[i] == res[t5] * 5) t5 ++;
		}
		return res[index-1];

    }

	int main(int argc, char const *argv[])
	{
		cout<<GetUglyNumber_Solution(7)<<endl;
		cout<<GetUglyNumber_Solution(1)<<endl;
		
	}
	