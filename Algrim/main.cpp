/*
堆排序算法
*/

#include<iostream>
using namespace std;


class Dui{
    public:
        int length;
        int* arr;

        Dui(int length){
            this->arr = new int[length];
            this->length = length;
            cout<<"请输入"<<this->length<<"个数:"<<endl;
            for(int i = 0;i < length;i ++){
                cin>>this->arr[i];
            }
        }

        ~Dui(){
            delete(this->arr);
            this->arr = NULL;
        }

        void create

        void display(){
            for(int i = 0;i < this->length;i ++){
                cout<<this->arr[i]<<" ";
            }
            cout<<endl;

        }

};
int main(int argc,char** argv){

    Dui* d = new Dui(10);
    d->display();
    delete(d);
    d = NULL;
    return 0;
}
