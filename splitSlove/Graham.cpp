#include<iostream>
#include<cstdio>
#include<random>
using namespace std;

/**
 * 凸包问题:Graham扫描
 **/

#define NIL 0 

typedef struct point
{
    float x,y;
    struct point *prev,*next;
} P;

class PointSet
{
    friend int cmp(P p1,P p2);
    private:
        P* ptslist;
        float Area(P p1,P p2,P p0){//计算三个连续的点构成的是什么旋转
            return (p1.x - p2.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
        }
        P* findNode(P*,float x,float y);//寻找插入结点,在之后插入

    public:
        PointSet():ptslist(NULL){}
        void insert(float x,float y);
        void convexHull();
        P* sort();
        void scan();
        P* getPtlist(){return ptslist;}
        void printList(P* p)
        {
            P* temp = p;
            while(temp){
                cout<<"("<<temp->x<<","<<temp->y<<")"<<"-->";
                temp = temp->next;
            }
            cout<<endl;
        }
};

P* PointSet::findNode(P* p,float x,float y)
{
    P* temp = p;
    P* prev = NULL;
    while(temp){

        if(temp->y > y)
            return prev;
        else if(temp->y == y && temp->x > x)
            return prev;
        else
            {
                prev = temp;
                temp = temp->next;
            }
        
    }
    return prev;
}

void PointSet::scan()
{
    P* p = ptslist;
    P *p1 = p,*p2,*p3;
    float temp;

    do{
        p2 = p1->next;
        if(p2->next) p3 = p2->next;
        else p3 = p;
        temp = Area(*p1,*p2,*p3);
        if(temp >= 0.0) p1 = p1->next;
        else
        {
            p1->next = p3;
            p3->prev = p1;
            delete p2;
            p1 = p1->prev;
        }
    }while(!((p3 == p) && (temp >= 0.0)));
}
/**
P* PointSet::sort_()
{
    P* p = NULL;
    P* pt = this->ptslist;
    P* prev;
    while(pt)
    {
        if(!p)
        {
            p = (P*)malloc(sizeof(P));
            p->x = pt->x;
            p->y = pt->y;
            p->next = NULL;
            p->prev = NULL;
        }else
        {
            prev = this->findNode(p,pt->x,pt->y);
            P* newP = (P*)malloc(sizeof(P));
            newP->x = pt->x;
            newP->y = pt->y;
            newP->next = NULL;
            newP->prev = NULL;
            if(prev)
            {
                //插在prev后
                newP->next = prev->next;
                newP->prev = prev;
                prev->next = newP;
            }
            else
            {
                //插在开头
                P* t = p;
                newP->next = t;
                newP->prev = t->prev;
                t->prev = newP;
                p = newP;
            }
        }
        pt = pt->next;
    }   
    return p;
}
**/

P* PointSet::sort()
{
    P* p = ptslist->next;
    P* pt = ptslist;
    while(p){
        if(p->y < pt->y)
            pt = p;
        else if (p->y == pt->y)
        {
            if(p->x < pt->x)
                pt = p;
        }
        p = p->next;
    }
}


void PointSet::convexHull()
{
    this->ptslist = sort();
    printList(ptslist);
    this->scan();
    printList(ptslist);
}

void PointSet::insert(float x,float y)
{
    P* p = (P*)malloc(sizeof(P));
    p->x = x;
    p->y = y;
    if(!this->ptslist){
        this->ptslist = p;
        this->ptslist->next = NULL;
        this->ptslist->prev = NULL;
        return;
    }
    P* temp = this->ptslist;
    while(temp->next)
    {
        temp = temp->next;
    }
    p->next = temp->next;
    p->prev = temp;
    temp->next = p;
}

int main()
{
    int a[10] = {4,1,3,1,4,6,2,7,2};
    PointSet ps;
    for(int i = 0;i<10;i++)
    {
        ps.insert(i + a[i],i + a[i]);
    }
    ps.printList(ps.getPtlist());
    P* p = ps.sort();
    ps.printList(p);

    ps.convexHull();

    return 0;
}