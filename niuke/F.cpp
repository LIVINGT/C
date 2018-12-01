#include<iostream>
#include<list>

using namespace std;
list<int> r;
void _3(int num)
{
				list<int>::iterator it;
				int i = 0;
				for(it = r.begin();it != r.end();it ++)
				{
					i ++;
					if(*it == num)
					{
						break;
					}
				}
				cout<<i<<endl;
}

void _4(int num)
{
	list<int>::iterator it;
	int i = 0;
	for(it = r.begin();it != r.end();it ++)
	{
		i ++;
		if(i == num)
		{
			cout<<*it<<endl;
			break;
		}
	}
}


void _5(int num)
{
	r.sort();
	list<int>::iterator it;
	int rs = -1;
	for(it = r.begin();it != r.end();it ++)
	{
		if(*it >= num){
			
			break;
		}
		rs = *it;
	}
	cout<<rs<<endl;
}

void _6(int num)
{
	r.sort();
	list<int>::iterator it;
	int rs = -1;
	for(it = r.begin();it != r.end();it ++)
	{
		if(*it >= num){
			rs = *it;
			break;
		}
	}
	cout<<rs<<endl;
}
int main()
{
	int n;
	cin>>n;
	
	for(int j = 0;j < n;j ++)
	{
		int num,x;
		cin>>num>>x;
		switch(num)
		{
			case 1:
				r.push_back(x);break;
			case 2:
				r.remove(x);break;
			case 3:
				_3(x);
				break;
			case 4:
				_4(x);
				break;
			case 5:
				_5(x);
				break;
			case 6:
				_6(x);
				break;
			default:
				break;
		}
	}
}