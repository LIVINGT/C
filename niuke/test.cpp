#include<bits/stdc++.h>

using namespace std;
int MaxLen[1001][1001];
int maxLen(string s1)
{
    string s(s1.rbegin(),s1.rend());
    for (int i = 0; i < s.length(); ++i)
        MaxLen[i][0] = 0;

	for (int i = 0; i < s.length(); ++i)
        MaxLen[0][i] = 0;

    for(int i = 1;i <= s1.length();i ++)
        for(int j = 1;j <= s.length();j ++)
        {
            if(s1[i - 1] == s[j - 1])
            {
                MaxLen[i][j] = MaxLen[i - 1][j - 1] + 1;
            }
            else
            {
                MaxLen[i][j] = max(MaxLen[i - 1][j],MaxLen[i][j - 1]);
            }
        }
    
    return MaxLen[s1.length()][s.length()];
}


int main()
    
{
    string s;
    while(cin>>s)
    {
        if(s.length() == 1)
            cout<<1;
        else
        {
            cout<<(s.length() - maxLen(s));
        }
    }
    return 0;
}