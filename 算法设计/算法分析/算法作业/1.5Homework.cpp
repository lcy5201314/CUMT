#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 20;
struct Hw
{
    double w,v;
    bool operator < (const Hw &c)const
    {
        return v/w > c.v/c.w;
    }
}hw[maxn];
int main()
{
    int n,c;
    while(~scanf("%d %d",&n,&c))
    {
        if(!n && !c) break;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf %lf",&hw[i].w,&hw[i].v);
        }
        sort(hw,hw+n);
        double cur = double(c);
        double ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(cur >= hw[i].w)
            {
                cur -= hw[i].w;
                ans += hw[i].v;
            }
            else
            {
                ans += cur/hw[i].w*hw[i].v;
                break;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
