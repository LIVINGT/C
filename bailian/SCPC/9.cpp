#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void rsget(char* s)
{
	int len = strlen(s);
	for(int i = 0;i < len;i ++)
	{
		
		if((s[i] > 'z' && s[i] < 'a') || (s[i] > 'Z' && s[i] < 'A'))
			cout<<s[i];
		else
		{
			if(s[i] == 'Z')
				cout<<'A';
			else if(s[i] == 'z')
				cout<<'a';
			else
				cout<<(s[i]++);
		}
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char s[80];
	char c = getchar();
	for(int i = 0;i < n;i ++)
	{
		scanf("%[^\n]",s);
		rsget(s);
		c = getchar();
	}
	return 0;
}
