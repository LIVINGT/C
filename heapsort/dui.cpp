#include<iostream>
using namespace std;


/****************************/
/**        堆排序算法        **/
/****************************/

/**
    arr为数组,k为需要交换的位置,m为堆的大小(等待排序元素个数)
**/
void shift(int* arr,int k,int m)
{
    int i,j,finished;
    i = k;j = 2 * i;
    arr[0] = arr[k];
    finished = 0;

    while((j <= m) && (!finished))
    {
        if((j < m) && (arr[j + 1] < arr[j])) j ++;//右孩子小于左孩子,j指向右孩子
        if(arr[0] <= arr[j]) finished = 1;
        else
        {
            arr[i] = arr[j];
            i = j;j = 2 * j;
        }
    }
    arr[i] = arr[0];
}

/**
    arr 为数组,n为数组大小
**/
void heapSort(int* arr,int n)
{
    int i;
    for(i = n/2;i >= 1;i --)shift(arr,i,n);
    //根节点和最后一个元素交换位置
    for(i = n;i >= 2;i --)
    {
        arr[0] = arr[1];
        arr[1] = arr[i];
        arr[i] = arr[0];
        shift(arr,1,i - 1);
    }
}

void display(int* arr,int n){
    for(int i = 1;i < n;i ++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int main(){
    int n = 10;
    int arr[n];
    for(int i = 1;i < 10;i ++)
        cin>>arr[i];
    display(arr,n);
    heapSort(arr,n-1);
    display(arr,n);

    return 0;

}


