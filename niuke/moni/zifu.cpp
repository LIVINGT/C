#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(cin>>s){
        set<char> d;
        for(int i = 0;i < s.length();i ++)
		{
			int curr = d.size();
			d.insert(s[i]);
			if(curr != d.size())
				cout<<s[i];

		}
		cout<<endl;
           
		
    }
    
    
    return 0;
}