#include<iostream>
#include<string>

using namespace std;

/**
 * 在一个字符串(0<=字符串长度<=10000，
 * 全部由字母组成)中找到第一个只出现一次的字符,
 * 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
**/

int FirstNotRepeatingChar(string str) {
	int len = str.length();
	if(len == 0) return -1;
	int f[100] = {0};
	int i,rs = -1;
	for(i = 0;i < len;i ++)
	{
		f[str[i] - 'A'] ++;
	}
	for(i = 0;i < len;i ++)
	{
		if(f[str[i] - 'A'] == 1)
			return i;
	}
	return rs;
			
}

int main()
{
	cout<<FirstNotRepeatingChar("dadwqqasa")<<endl;

	return 0;
}