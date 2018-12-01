/********************************/
/**          快速排序           **/
/*******************************/
#include<iostream>

using namespace std;

void quicksort(int* arr,int left,int right)
{
    int i,j;
    if(left < right)
    {
        i = left;j = right;
        arr[0] = arr[i];
        do
        {
            while(arr[j] > arr[0] && i < j) j--;
            if(i < j)
            {
                arr[i] = arr[j];
                i ++;
            }
            while(arr[0] > arr[i] && i < j) i ++;
            if(i < j)
            {
                arr[j] = arr[i];
                j --;
            }
        }while(i != j);

        arr[i] = arr[0];
        quicksort(arr,left,i - 1);
        quicksort(arr,i + 1,right);
    }

}

int main(int* argc,char** argv)
{
    int arr[10];
    for(int i = 1;i < 9;i ++)
        arr[i] = 10 - i;
    cout<<endl;
    quicksort(arr,1,8);
    for(int i = 1;i < 9;i ++)
        cout<<arr[i]<<" ";

}
