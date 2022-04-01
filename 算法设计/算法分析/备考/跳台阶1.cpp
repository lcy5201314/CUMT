/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

输入
多组测试样例。每组测试样例包含一个整数n。(1<=n<=100)

输出
每组测试样例输出一行，表示青蛙跳上n级台阶的跳法数量.

所得到的结果模1000000007

Water，Fibonacci 数列，先打个表（牺牲空间换取时间），最好用 long long。
思路
假设青蛙在第 n 级台阶，那么我们倒推一步。
因为它每次可以跳 1 级台阶或者 2 级台阶，所以它上一步只能在第 n-1 级或者第 n-2 级台阶，每次都要对 1e9 + 7 取余所以可写出递推式：f[n] = (f[n-1] + f[n-2]) % mod;。

注意取模！
*/ 
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAX=99999; 
ll f[MAX] = {1,1};  //使得 f[1]=1跳一级台阶有一种跳法 ，f[2]=f[0]+f[1]=2跳两级台阶有两种跳法 
const int mod = 1e9 + 7;
int main()
{
    int n;
    for(int i = 2; i < MAX; i++)
    {
       f[i] = (f[i-1]+f[i-2])%mod;
    }
    while(cin>>n)
    cout<<f[n]<<endl;
    return 0;
}
