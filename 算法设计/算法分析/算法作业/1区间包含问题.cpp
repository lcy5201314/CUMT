#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
struct s
{
    int b,e;
    bool operator < (const s&c)const
    {
        //if(e == c.e) return b < c.b;
        return e < c.e;
    }
}a[maxn];
int main()
{
    int n,m,l,r;
    while(~scanf("%d %d",&n,&m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d",&a[i].b,&a[i].e);
        }
        sort(a,a+n);
        for(int cas = 0; cas < m; cas++)
        {
            scanf("%d %d",&l,&r);
            int j = 0,ans = 0;
            while(a[j].b < l) j++;
            for(int i = j; i < n && a[i].e <= r; i++)
            {
                if(a[i].b >= a[j].e || i == j)
                {
                    ans++;
                    j = i;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
