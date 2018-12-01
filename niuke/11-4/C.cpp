#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eps 1e-6

ll n;
ll p;
ll q;
ll minx,miny,maxx,maxy;

int gongyueshu(ll a,ll b)
{
    if(a < b)
    {
        ll t = a;
        a = b;
        b = t;
    }
    ll r = a % b;
    if(r == 0) return b;
    return gongyueshu(b, r);
}


void search(ll x,ll y)
{
	if(x >= y) return;
	if(y <= 0) return;
	if(gongyueshu(x,y) != 1){
		search(x - 1, y);
		search(x, y - 1);
	}else{

		if(x / y - p / q < eps && x / y - maxx / maxy > eps)
		{
			maxx = x;
			maxy = y;
		}
		if(x / y - p / q > eps && x / y - minx / miny < eps)
		{
			minx = x;
			miny = y;
		}
		search(x - 1, y);
		search(x, y - 1);
	}
	
}


int main(int argc, char const *argv[])
{
	/* code */
	int T;
	cin>>T;
	while(T --)
	{
		minx = miny = 1;
		maxx = maxy = 1;
		cin>>n>>p>>q;
		search(n - 1, n);
		cout<<maxx<<" "<<maxy<<endl;
		cout<<minx<<" "<<miny<<endl;
	}
	return 0;
}