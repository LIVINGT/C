#include<bits/stdc++.h>

using namespace std;

bool yunYear(int year);

// void 
bool illg(int y)
{
	
	bool is_yun = yunYear(y);

	int day = y / 100;
	int moth = y % 100;
	int m = moth/10 + (moth % 10) * 10;
	int d = day/10 + (day % 10) * 10;
	if(m > 12 || m < 1) return false;
	if(d < 1) return false;
	if(m == 2)
	{
		if(is_yun && d > 29) return false;
		else if(!is_yun && d > 28) return false;
	}
	else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if(d > 31) return false;
	}
	else
	{
		if(d > 30) return false;
	}
	return true;

}

bool yunYear(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}



int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T --)
	{
		string start,end;
		cin>>start>>end;
		int j = 4;
		
		int s = atoi(start.erase(j).c_str());
		int e = atoi(end.erase(j).c_str());
		int rs = 0;
		for(int i = s;i <= e;i ++)
			if(illg(i))
				rs ++;
		cout<<rs<<endl;
	}
}
