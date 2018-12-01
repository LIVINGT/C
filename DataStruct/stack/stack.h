#include<iostream>
using namespace std;

template<typename Type>
class Stack
{
    private:
        int top,MaxSize;
        Type *stack;
    public:
        Stack(int MaxSize);
        ~Stack();
        inline bool add(const Type item);
        inline bool remove(const Type& item);
        inline bool is_empty();
        inline bool is_full();
        void display();
};


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
