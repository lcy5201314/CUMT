#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int mod=1e9+7;
const int inf=0x7f7f7f7f;
const int maxn=5e4+50;
struct node
{
    int x,y,h;
    bool operator < (const node &c) const
    {
        return h > c.h;
    }
}a[maxn];
int dp[maxn];
int r,c;
bool check(int i,int j)
{
    if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) == 1)  //判断是否是相邻点
        return true;
    return false;
}
int main()
{
    scanf("%d%d",&r,&c);
    int n = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1;j <= c; j++)
        {
            a[n].x = i;
            a[n].y = j;
            scanf("%d",&a[n].h);
            n++;
        }
    }
    sort(a,a+n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(check(i,j))
                dp[i] = max(dp[i],dp[j]+1);
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
