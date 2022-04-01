/*问题 B: 求数组的最长递减子序列
题目描述
给定一个整数序列，输出它的最长递减（注意不是“不递增”）子序列。

输入
输入包括两行，第一行包括一个正整数N（N<=1000），表示输入的整数序列的长度。第二行包括用空格分隔开的N个整数，
整数范围区间为[-30000,30000]。

输出
输入包括两行，第一行包括一个正整数N（N<=1000），表示输入的整数序列的长度。第二行包括用空格分隔开的N个整数，
整数范围区间为[-30000,30000]。

样例输入
8
9 4 3 2 5 4 3 2
样例输出
9 5 4 3 2
题意
DP经典题，类似问题为最长递增子序列。

思路
代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int dp[maxn],last[maxn];
int main()
{
    int n,a[maxn],ans = 0,ansp = 1,ansa[maxn];
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    dp[1] = 1;
    last[1] = -1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        last[i] = -1;
        for(int j = 1; j < i; j++)
        {
            if(a[j] > a[i] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
                last[i] = j;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] > ans)
        {
            ans = dp[i];
            ansp = i;
        }
    }
    int j = ansp;
    for(int i = ans; ; i--)
    {
        ansa[i] = a[j];
        if(last[j] == -1) break;
        j = last[j];
    }
    for(int i = 1; i <= ans; i++) printf("%d ",ansa[i]);
    return 0;
}
