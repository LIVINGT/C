#include<iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926535;

class Node
{
	public:
		int x;
		int y;
		Node* prev;
		Node* next;
		Node(int X,int Y):x(X),y(Y)
		{
			prev = next = this;
		}
};

bool is_you(Node* p1,Node* p2,Node* p3)
{
	//判断是否是右旋转
	return (p2->x - p1->x)*(p3->y - p2->y) > (p3->x - p2->x) * (p2->y - p1->y);
}

double dist(Node* p1,Node* p2)
{
	return sqrt(0.0 + (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

int main()
{
	int n,l;
	cin>>n>>l;
	Node* head,*tail;
	int x1,y1;
	cin>>x1>>y1;
	Node* temp = new Node(x1,y1);
	head = temp;
	tail = temp;
	for(int i = 0;i < n-1;i ++)
	{
		cin>>x1>>y1;
		Node* temp = new Node(x1,y1);
		temp->next = head;
		temp->prev = tail;
		head->prev = temp;
		tail->next = temp;
		tail = temp;
	}

	int cnt = 0;
	while(1)
	{
		if(is_you(head->prev,head,head->next))
		{
			n --;
			cnt = 0;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
		}
		else
		{
			head = head->next;
			cnt ++;
			if(cnt >= n)
				break;
		}
	}

	double sum = 2 * PI * l;
	for(int i = 0;i < n;i ++)
	{
		sum += dist(head,head->next);
		head = head->next;
	}

	int intsum = (int)sum;
	if(sum-intsum < 0.5) cout << intsum << endl;
	else cout << intsum+1 << endl;

	return 0;
}

