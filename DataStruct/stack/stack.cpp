#include<iostream>
#include "stack.h"
#include </home/hui/daily/C_workspace/DataStruct/stack/stack.h>

using namespace std;

template<typename Type>
Stack<Type>::Stack(int MaxSize)
{
    this->top = 0;
    this->stack = new Type[MaxSize];
}

template<class Type>
Stack<Type>::~Stack()
{
    delete(this->stack);
    this->stack = NULL;
    this->top = 0;
}

template<typename Type>
bool Stack<Type>::add(const Type item)
{
    if(this->top < this->MaxSize)
    {
        this->stack[top++] = item;
        return true;
    }
    return false;

}

template<class Type>
bool Stack<Type>::remove(const Type& item)
{
    int k = -1;
    for(int i = 0;i < this->top;i ++)
    {
        if(this->stack[i] == item && k == -1)
        {
            k = i;
            break;
        }
    }
    if(k == -1){
        return false;
    }
    int index = k;
    for(int i = k + 1;i < this->top;i ++)
    {
        if(this->stack[i] == item){
            this->top --;
            continue;
        }
        else
        {
            this->stack[index++] = this->stack[i]; 
        }
        
    }
    this->top --;
    return true;
}

template<class Type>
bool Stack<Type>::is_empty()
{
    return this->top == 0;
}

template<class Type>
bool Stack<Type>::is_full()
{
    return this->top == this->MaxSize;
}

template<class Type>
void Stack<Type>::display()
{
    for(int i = 0;i < this->top;i ++)
    {
        cout<<this->stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Stack<int> a(10);
    for(int i = 1;i < 10;i ++)
    {
        a.add(i);
    }
    a.add(2);
    a.display();
    a.remove(2);
    a.display();
    return 0;
}