#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char c;
	cin>>c;
	for(int i = 1;i <= 3;i ++)
	{
		for(int j = 1;j <= 5;j ++)
		{
			if(i == 1 && j == 3)
				cout<<c;
			else if(i == 2 && j>1 && j < 5)
				cout<<c;
			else if(i == 3)
				cout<<c;
			else
				cout<<" ";
			
		}
		cout<<endl;
	}
	return 0;
}
