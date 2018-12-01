#include<bits/stdc++.h>

using namespace std;
class Node
{
    public:
        char c;
        Node* next;
		Node* end;
        Node(){
            next = NULL;
			end = this;
        }
        void insert(char c)
        {
            Node* t = new Node();
			t->c = c;
			t->next = NULL;

			if(!this->next)
			{
				this->next = t;
				end = t;
			}
            end->next = t;
			end = t;
        }

		//程序到这,使用尾结点指针
        void move(Node* node)
        {
            Node* temp = this;
            while(temp->next != node)
            {
                temp = temp->next;
            }
			
            temp->next = node->next;
            node->next = NULL;
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        bool isUpper(char c)
        {
            if(c >= 'A' && c <= 'Z')
                return true;
            else
                return false;
        }
    
        void run(int n)
        {
			Node* temp = this;
            while(temp->next && n > 0)
            {
				if(isupper(temp->next->c)){
                	move(temp->next);
					n--;
					continue;
				}
				temp = temp->next;
				n --;
            }
            display();
        }
        void display()
        {
            Node* temp = this->next;
            while(temp)
            {
                cout<<temp->c;
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main()
{
    char c;
    while(1){
        Node* head = new Node();
		int n = 0;
        while((c = getchar()) != '\n')
		
		{
			n ++;
            head->insert(c);}
        head->run(n);
    }
    return 0;
}