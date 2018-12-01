#include<string>
#include<iostream>

using namespace std;

int StrToInt(string str) {
        string s(str.rbegin(),str.rend());
        int rs = 0;
		int i = 0;
        for(;i<s.length() - 1;i++)
        {
            if(s[i] > '0' && s[i] < '9'){
                int temp = s[i] - '0';
                for(int j = 0;j < i;j ++)
                    temp *= 10;
                rs += temp;
            }
            else
                return 0;
        }
        if(s[i] > '0' && s[i] < '9'){
                int temp = s[i] - '0';
                for(int j = 0;j < i;j ++)
                    temp *= 10;
                rs += temp;
            }
        else if(s[i] == '-')
            rs = -rs;
        else if(s[i] == '+')
            rs = rs;
        else
           return 0;
        return rs;
    }