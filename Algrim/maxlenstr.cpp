#include<iostream>
#include<string>

using namespace std;


/**
 * 求两个字符串的最大公共子序列
 * 
 **/

string s1;
string s2;
int maxLen[1000][1000];//maxLen[i][j] 表示s1的前i个字符的与s2的前j个字符的最长公共子序列

int main()
{
	while(cin>>s1>>s2)
	{
		int len1 = s1.length();
		int len2 = s2.length();
		
		for(int i = 0;i < len1;i ++)
		{
			maxLen[i][0] = 0;
		}
		for(int i = 0;i < len2;i ++)
		{
			maxLen[0][i] = 0;
		}

		for(int i = 1;i <= len1;i ++)
		{
			for(int j = 1;j <= len2;j ++)
			{
				if(s1[i - 1] == s2[j - 1])
				{
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				}
				else
				{
					maxLen[i][j] = max(maxLen[i - 1][j],maxLen[i][j - 1]);
				}
			}
		}

		cout<<maxLen[len1][len2]<<endl;

	}
	return 0;
}