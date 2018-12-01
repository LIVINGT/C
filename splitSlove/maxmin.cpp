#include<iostream>

using namespace std;
/**
 * 分治法找最大值和最小值
 **/

int* a;


template<class Type>
/**
 * 从i到j中的max和min
 **/
void binary_maxmin(int i,int j,Type& max,Type& min)
{
    if(i == j) max = min = a[i];
    else if (i == j -1){
        if(a[i] < a[j]){max = a[j];min = a[i];}
        else{max = a[i];min = a[j];}

    }
    else
    {
        int mid = (i + j) / 2;
        Type max_,min_;
        binary_maxmin(i,mid,max,min);
        binary_maxmin(mid+1,j,max_,min_);

        if(max < max_) max = max_;
        if(min > min_) min = min_;
    }
}

int main()
{
    a = new int[10];
    for(int i = 0;i < 10;i ++)
    {
        cin>>a[i];
    }
    int max = 100000,min = -10000000;
    binary_maxmin(0,9,max,min);
    cout<<"max:"<<max<<"min:"<<min<<endl;
    return 0;
}