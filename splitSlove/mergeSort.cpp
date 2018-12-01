#include<iostream>

using namespace std;
/**
 * 合并排序
 **/

int *a;
int *b;

/**
 * l:数组左边界
 * r:数组右边界
 * mid:数组中点
 **/
void merge(int l,int mid,int r)
{
    int h = l,i = l;
    int j = mid + 1,k;

    while( (h <= mid) && (j <= r))
    {
        if(a[h] <= a[j]){b[i] = a[h];h ++;}
        else{b[i] = a[j];j++;}
        i ++;
    }

    if(h > mid){
        for(k = j;k <= r;k ++)
        {
            b[i] = a[k];
            i ++;
        }
    }else{
        for( k = h;k <= mid;k ++){
            b[i] = a[k];
            i ++;
        }
    }

    for(k = l;k <= r;k ++)
        a[k] = b[k];

}




/**
 * l:数组左边界
 * r:数组右边界
 **/
void mergeSort(int l,int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(l,mid);
        mergeSort(mid + 1,r);
        merge(l,mid,r);
    }
}


int main()
{
    a = new int[10];
    b = new int[10];
    for(int i = 0;i < 10;i ++){
        a[i] = 10 - i;
    }
    mergeSort(0,9);
    for(int i = 0;i < 10;i ++)
        cout<<a[i]<<" ";

    cout<<endl;
    return 0;
}