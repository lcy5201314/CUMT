/*问题 D: 01背包问题
题目描述
已知有N种物品和一个可容纳C重量的背包。每种物品i的重量为Wi，价值为Pi。那么，采用怎样的装包方法才会使装入背包物品的
总价值最大。
输入
包含多组测试数据。第一行为一个整数T(1<=T<=10)，代表测试数据个数。
接下来有T组测试数据。每组测试数据第一行为背包的重量C(C<10000)和物品个数N(N<1000)。接下来的N行分别为物品的重量
cost(1<=cost<=100)和价值val(1<=val<=3000000)。（注意：结果可能超过int范围）
输出
对每组测试数据，输出其对应的所装物品的最大价值。
样例输入
1
10 5
2 6
2 3
6 5
5 4
4 6
样例输出
15
题意
如题目描述所示，经典DP题。
思路
先看题目最后的注意，结果可能超过int范围，故采用long long类型。我一般这样写：typefef long long ll;把它“重命名”一下，
以后写起来比较简便。
注意在stdio（scanf、printf）中，要写出%lld。
有两种写法（分别对应下面的代码1和代码2）.
第一种，也就是书上的这种，m[i][j]代表从第i件物品开始的、在最大容量为j的情况下可以获得的最大收益，最后结果保存在m[1][c]；
第二种，比较常见的写法，m[i][j]前i件物品、在最大容量为j的情况下可以获得的最大收益，最后结果保存在m[n][c]。
（初始状态）以第二种为例，首先第一行和第一列全置为0，因为
0物品，0价值；
0容量，0价值。
（状态转移方程）
if (背包体积j小于物品i的体积)
    m[i][j] = m[i-1][j]; //背包装不下第i个物体，目前只能靠前i-1个物体装包
else m[i][j] = max(m[i-1][j], m[i-1][j-w[i]] + v[i]);
代码1
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
ll m[maxn][maxn];
int main()
{
    int t,n;
    ll c,w[maxn],v[maxn];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d",&c,&n);
        for(int i = 1; i <= n; i++)
            scanf("%lld %lld",&w[i],&v[i]);
        int i,j,jMax = min(w[n]-1,c);
        for(j = 0; j <= jMax; j++) m[n][j] = 0;
        for(j = w[n]; j <= c; j++) m[n][j] = v[n];
        for(i = n-1; i > 1; i--)
        {
            jMax = min(w[i]-1,c);
            for(j = 0; j <= jMax; j++)m[i][j] = m[i+1][j];
            for(j = w[i]; j <= c; j++) m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
        }
        m[1][c] = m[2][c];
        if(c >= w[1]) m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]);
        printf("%lld\n",m[1][c]);
    }
    return 0;
}
代码2*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
const int maxc = 1e4 + 5;
const int inf = 0x3f3f3f3f;
ll dp[maxn][maxc];
int main()
{
    int t,n;
    ll c,w[maxn],v[maxn];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d",&c,&n);
        for(int i = 1; i <= n; i++)
            scanf("%lld %lld",&w[i],&v[i]);
        for(int i = 0; i <= c; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= n; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            int jMax = min(c,w[i]);
            for(int j = 1; j < jMax; j++)
                dp[i][j] = dp[i-1][j];
            for(int j = w[i]; j <= c; j++)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
        printf("%lld\n",dp[n][c]);
    }
    return 0;
}
