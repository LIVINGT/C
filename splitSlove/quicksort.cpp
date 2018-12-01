#include<iostream>
#include</home/hui/daily/C_workspace/DataStruct/stack/stack.h>
using namespace std;

/**
 * 快速排序
 **/


/**
 * 通过递归实现快速排序
 **/
void quickSorted(int * arr,int l,int r)
{
    int i,j;
    if(l < r      )
    {
        i = l,j = r;
        arr[0] = arr[i];
        do
        {
            while((arr[0] < arr[j]) && (i < j)) j --;
            if(i < j){
                arr[i] = arr[j];
                i ++;
            }
            while((arr[0] > arr[i]) && (i < j)) i ++;
            if(i < j)
            {
                arr[j] = arr[i];
                j --;
            }

        }while(i != j);

        arr[i] = arr[0];
        quickSorted(arr,l,i - 1);
        quickSorted(arr,i,r);
    }
}

/**
 * 快速排序循环实现(出现问题,还没解决)
 **/
int SIZE;
void quickSorted2(int *a,int l,int r)
{
    Stack<int> sk(SIZE);
    
    do
    {
        while(l < r)
        {
            a[0] = a[l];
            int i = l,j = r;
            do
            {
                // while((a[0] < a[j]) && (i < j)) j --;
                // while((a[i] < a[0]) && (i <j)) i ++;
                do i ++;
                while(a[i] < a[0]);
                do j --;
                while(a[j] > a[0]);
                if(i > j)
                {
                    int p = a[i];
                    a[i] = a[j];
                    a[j] = p;
                }
            }while(i < j);
            a[l] = a[j];a[j] = a[0];
            if((j - l) < (r-j))
            {
                sk.add(j + 1);
                sk.add(r);
                r = j - 1;   
            }
            else
            {
                sk.add(l);
                sk.add(j - 1);
                l = j + 1;
            }
        };
        if(sk.is_empty()) return;
        sk.remove(r);sk.remove(l);
    } while(1);   
}

int main()
{
    int arr[] = {-1,4,5,6,2,9,0,8,7};
    for(int i = 1;i < 9;i ++)
        cout<<arr[i]<<" ";
    cout<<endl;
    quickSorted2(arr,1,8);
    for(int i = 1;i < 9;i ++)
        cout<<arr[i]<<" ";
    return 0;
}