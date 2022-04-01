/*问题 C: 汽车费用
题目描述
一个特别的单行街道在每公里处有一个汽车站。顾客根据他们乘坐汽车的公里使来付费。例如下表就是一个费用的单子。
没有一辆车子行驶超过10公里，一个顾客打算行驶n公里(1<=n<100)，它可以通过无限次的换车来完成旅程。最后要求费用最少。

输入
第一行十个整数分别表示行走1到10公里的费用(<=500)。注意这些数并无实际的经济意义，即行驶10公里费用可能比行驶一公里少。
第二行一个整数n表示，旅客的总路程数。

输出
仅一个整数表示最少费用。

样例输入
12 21 31 40 49 58 69 79 90 101
15
样例输出
147
题意
给一张价格表，对应1-10km分别多少钱，可通过无限次的换车来完成旅程。输入一个距离，求最少费用。

思路
dp，有最优子结构性质。

完全背包问题。把距离看成背包，先求出1km的最小价格，再求出2km的最小价格……直到求出n km的最小价值。

代码*/
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[105];
int main()
{
    int n;
    for(int i = 1; i <= 10; i++)
    {
        scanf("%d",&dp[i]);
    }
    scanf("%d",&n);
    for(int i = 11; i <= n; i++)
        dp[i] = inf;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            dp[i] = min(dp[i],dp[j]+dp[i-j]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
