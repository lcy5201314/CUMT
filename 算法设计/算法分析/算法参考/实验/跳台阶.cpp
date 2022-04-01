/*问题 C: 跳台阶
题目描述
一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
输入
多组测试样例。每组测试样例包含一个整数 n。
输出
每组测试样例输出一行，表示青蛙跳上 n 级台阶的跳法数量.
所得到的结果模 1000000007 。
样例输入
3
4
样例输出
3
5
题意
Water，Fibonacci 数列，先打个表（牺牲空间换取时间），最好用 long long。
思路
假设青蛙在第 n 级台阶，那么我们倒推一步。
因为它每次可以跳 1 级台阶或者 2 级台阶，所以它上一步只能在第 n-1 级或者第 n-2 级台阶，每次都要对 1e9 + 7 取余所以可写出
递推式：f[n] = (f[n-1] + f[n-2]) % mod;。
注意取模！
代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
ll f[99999] = {1,1};
const int mod = 1e9 + 7;
int main()
{
    int n;
    for(int i = 2; i < 99999; i++)
    {
        f[i] = (f[i-1]+f[i-2])%mod;
    }
    while(~scanf("%d",&n))
    {
        printf("%lld\n",f[n]);
    }
    return 0;
}
