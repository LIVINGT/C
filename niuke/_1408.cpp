#include<cstdio>
using namespace std;
int n,mod,a[6][6];
struct mat{int a[6][6];}t,b;
mat mul(mat a,mat b)
{
    mat c;
    for(int i=0;i<=5;i++)for(int j=0;j<=5;j++)c.a[i][j]=0;
    for(int i=0;i<=5;i++)for(int j=0;j<=5;j++)for(int k=0;k<=5;k++)c.a[i][j]=(c.a[i][j]+1ll*a.a[i][k]*b.a[k][j]%mod)%mod;
    return c;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        a[0][5]=a[1][3]=a[1][5]=a[2][4]=a[2][5]=a[3][1]=a[3][5]=a[4][2]=a[5][0]=a[5][1]=a[5][2]=a[5][3]=a[5][5]=1;
        scanf("%d%d",&n,&mod);
        for(int i=0;i<=5;i++)for(int j=0;j<=5;j++)t.a[i][j]=a[i][j];
        for(int i=0;i<=5;i++)for(int j=0;j<=5;j++)b.a[i][j]=0;
        for(int i=0;i<=5;i++)b.a[i][i]=1;
        for(;n;n>>=1,t=mul(t,t))if(n&1)b=mul(b,t);
        printf("%d\n",b.a[5][5]);
    }
    return 0;
}