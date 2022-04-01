/*问题 E: 沙子的质量
题目描述
设有N堆沙子排成一排，其编号为1，2，3，…，N（N< =300）。每堆沙子有一定的数量，可以用一个整数来描述，
现在要将N堆沙子合并成为一堆，每次只能合并相邻的两堆，合并的代价为这两堆沙子的数量之和，合并后与这两堆沙子相邻的沙子
将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同，如有4堆沙子分别为1 3 5 2我们可以先合并1、2堆，代价为4，
得到4 5 2又合并1，2堆，代价为9，得到9 2，再合并得到11，总代价为4+9+11=24，如果第二步是先合并2，3堆，则代价为7，
得到4 7，最后一次合并代价为11，总代价为4+7+11=22；问题是：找出一种合理的方法，使总的代价最小。输出最小代价。

输入
第一行一个数N表示沙子的堆数N。 第二行N个数，表示每堆沙子的质量。 a[i]< =1000。

输出
合并的最小代价。

样例输入
4
1 3 5 2
样例输出
22
题意
合并时由于选择的顺序不同，合并的总代价也不相同，找出总代价小的方案。

思路
dp。

开一个一维数组sum，用于存储前缀和。

开一个二维数组dp，dp[j][i]代表合并j到i的代价，一开始把它全部置为足够大的数，dp方程：

dp[i][i] = 0;
dp[j][i] = min(dp[j][i],dp[j][k]+dp[k+1][i]+sum[i]-sum[j-1]);
解释：

只有一堆沙子，则不需要合并，故代价为0；
三重循环：
i（从 2 到 n）：合并右界
j（从 i 到 1，逆序）：合并左界
为什么要逆序呢？
比如说，求出(2,3)才能求(1,3)
k（从 j 到 i）：分界点
dp[j][k]表示合并从 j 到 k 的沙子所需要的代价；
dp[j][k]表示合并从 k 到 i 的沙子所需要的代价；
sum[i]-sum[j-1]前缀和相减代表从j到i堆的沙子数量之和；
这样子，最后的答案就是dp[1][n]，输出即可。

代码1*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN = 305;
int dp[MAXN][MAXN];
int main()
{
    int n,i,j,k,a[MAXN],sum[MAXN] = {0};
    memset(dp,1,sizeof(dp));//初始化为较大值 
    cin>>n;
    for(i = 1; i <= n; i++)
    {
    	cin>>a[i]; 
        sum[i] = sum[i-1]+a[i];//储存前缀和 
        dp[i][i] = 0;
    }
    for(i = 2; i <= n; i++)//i(2-n)合并右界 
    {
        for(j = i; j >= 1; j--)//j(i-1,逆序)合并左界 
        {
            for(k = j; k <= i; k++)//k 分界点 
                dp[j][i] = min(dp[j][i],dp[j][k]+dp[k+1][i]+sum[i]-sum[j-1]);
                             //合并j到i   合并j到k + 合并k+1到i + j到i堆的沙子数量之和
        }
    }
    cout<<dp[1][n]; 
    return 0;
}
