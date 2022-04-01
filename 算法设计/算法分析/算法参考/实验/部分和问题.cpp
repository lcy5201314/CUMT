/*问题 E: 部分和问题
题目描述
给定n个整数，判断是否可以从中选择若干数字，使得他们的和恰好为k。

输入
多组测试用例。

对于每组测试用例，第一行一个正整数n，第二行n个整数，第三行一个整数k。

1≤N≤20，输入整数及k均小于1e8。

输出
若可以使得和为k，输出”Yes”,否则”No”。

样例输入
4
1 2 4 7
13
样例输出
Yes
题意
如题目描述所示。

思路
dfs。

代码*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 25;
int n,a[maxn],k;
bool dfs(int l,int sum)
{
    if(sum == k) return true;
    if(l == n) return false;
    return dfs(l+1,sum)||dfs(l+1,sum+a[l]);
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&k);
        if(dfs(0,0)) puts("Yes");
        else puts("No");
    }
    return 0;
}
