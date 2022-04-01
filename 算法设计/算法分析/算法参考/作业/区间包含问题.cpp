/*问题 E: 区间包含问题
题目描述
已知 n 个左闭右开区间 [a,b)，对其进行 m 次询问，求区间[l,r]最多可以包含 n 个区间中的多少个区间，并且被包含的所有区间
都不相交。

输入
输入包含多组测试数据，对于每组测试数据：

第一行包含两个整数 n ,m (1≤n≤100000,1≤m≤100) 。

接下来 n 行每行包含两个整数 a ,b (0≤a9</sup>) 。

接下来 m 行每行包含两个整数 l ,r (0≤l9</sup>) 。

输出
对于每组测试数据，输出 m 行，每行包含一个整数。

样例输入
4 3
1 3
2 4
1 4
1 2
1 2
1 3
1 4
样例输出
1
1
2
题意
活动安排问题，n个活动，m次query。

思路
Greedy。

输入结束后，把所有活动按结束时间从小到大排序。

定义ans，先给它赋值1。

循环遍历所有活动，符合不相交、不越界就可选。

优化：

在结束时间超过r后跳出循环。
二分寻找第一个满足的活动（我没用）。
两种写法（本质上是一样的）：

用一个j来记录上一个被选的活动；

每次选活动后直接l = a[i].e;。

千万别写if(e == c.e) return b < c.b;否则必定WA，不知为何。

千万要在结束时间超过r后跳出循环，不然必定TLE。

千万不要用cin、cout，不然好像也是必定TLE。

代码1
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
代码2*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    int b,e;
    bool operator < (const node & c)const
    {
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
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(a[i].b >= l)
                {
                    if(a[i].e <= r)
                    {
                        ans++;
                        l = a[i].e;
                    }
                    else break;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
