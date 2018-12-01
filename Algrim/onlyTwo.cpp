#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        
        int curr[2],n = 0;
        int flag[data.size()+1];
        memset(flag,0,sizeof(flag));
        for(int i = 0;i < data.size();i ++)
        {
            if(n == 2)
                break;
			if(flag[i])
				continue;
            
            for(int j = i+1;j < data.size();j ++)
            {
                if(data[i] == data[j] && !flag[j])
                {
                    flag[j] = 1;
                    flag[i] = 1;
                    break;
                }
                    
            }
            if(!flag[i]){
                curr[n++] = data[i];
            }
        }
        *num1 = curr[0];
        *num2 = curr[1];
        
    }
int main()
{
	vector<int> a;
	
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(4);
	a.push_back(6);
	int m1,m2;
	FindNumsAppearOnce(a,&m1,&m2);
	// cout<<m1<<m2<<endl;
	return 0;
}