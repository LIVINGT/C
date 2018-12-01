#include<iostream>
#include<string>
#include<vector>
#define EPS 1e-6

using namespace std;

/**未完成表达式输出
 * 
 **/
void insert(vector<double>& s,string c){
	if(c.length() > 2){cout<<"ERROR"<<endl;exit(1);}
	else
	{
		switch(c[0])
		{
			case 'A':s.push_back(1);break;
			case '2':s.push_back(2);break;
			case '3':s.push_back(3);break;
			case '4':s.push_back(4);break;
			case '5':s.push_back(5);break;
			case '6':s.push_back(6);break;
			case '7':s.push_back(7);break;
			case '8':s.push_back(8);break;
			case '9':s.push_back(9);break;
			case '1':s.push_back(10);break;
			case 'J':s.push_back(11);break;
			case 'Q':s.push_back(12);break;
			case 'K':s.push_back(13);break;
			default:break;
		}
	}
}

bool is_zero(double x)
{
	return x < EPS;
}



bool count_24(vector<double> s,int n)
{
	if(n == 1)
	{
		// if(is_zero(s[0] - 24)){
		// 	return true;
		// }
		return is_zero(s[0] - 24);
	}
	vector<double> b;
	for(int i = 0;i < n - 1;i ++)
		for(int j = i + 1;j < n;j ++)
		{
			int m = 0;
			for(int k = 0;k < n;k ++)
				if(i != k && j != k)
				{
					b.push_back(s[k]);
					m ++;
				}
			b.push_back(s[i] + s[j]);
			if(count_24(b,m + 1))
			{
				cout<<s[i]<<"+"<<s[j];
				return true;
			}
			b.pop_back();
			b.push_back(s[i] * s[j]);
			if(count_24(b,m + 1))
			{
				cout<<s[i]<<"*"<<s[j];
				return true;
			}
			b.pop_back();
			b.push_back(s[i] - s[j]);
			if(count_24(b,m + 1))
			{
				cout<<s[i]<<"-"<<s[j];
				return true;
			}
			b.pop_back();
			b.push_back(s[j] - s[i]);
			if(count_24(b,m + 1))
			{
				cout<<s[j]<<"-"<<s[i];
				return true;
			}
			b.pop_back();
			if(!is_zero(s[j]))
			{
				b.push_back(s[i]/s[j]);
				if(count_24(b,m + 1))
				{
					cout<<s[i]<<"/"<<s[j];
					return true;
				}
				b.pop_back();
			}
			if(!is_zero(s[i]))
			{
				b.push_back(s[j]/s[i]);
				if(count_24(b,m + 1))
				{
					cout<<s[j]<<"/"<<s[i];
					return true;
				}
			}

		}
		cout<<"NONE"<<endl;
		return false;
}

int main()
{
	vector<double> s;
	string temp;
	for(int i = 0;i < 4;i ++)
	{
		cin>>temp;
		insert(s,temp);
	}

	count_24(s,4);

	return 0;
}