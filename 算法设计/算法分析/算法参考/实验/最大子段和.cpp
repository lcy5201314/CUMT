/*问题 E: 最大子段和
题目描述
给定n个整数组成的序列a1,a2,…an, 求子段和ai+ai+1+…+aj（子段可为空集）的最大值。

输入
包含多组测试数据。第一行为一个整数T(1<=T<=20)，代表测试数据个数。

每组测试数据第一行为一个整数n，代表有n个整数(1<=n<=10000)。

接下来一行有n个数x(-1000<=x<=1000)。

输出
输出其对应的最大子段和。

样例输入
1
6
2 -11 4 13 -1 2
样例输出
18
提示
子段可为空集，答案为0

题意
求最大字段（连续）和。

思路
DP基础题，新开一个b辅助数组，我们这样定义它：b[j]存储选取第j个元素时a[1],...,a[j]的最大子段和。

递归定义b数组（b[0]需初始化为0）：

（前面为正数，有用则要）若b[j-1] > 0，则b[j] = b[j-1] + a[j]；
（前面为负数，无用则丢）否则b[j] = a[j]。
则易得出最优值为b数组中的最大值（因为题目要求若为负数则输出0，所以要和0做一次max）。

代码*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 1e4 + 5;
int main()
{
    int t,n,a[maxn],b[maxn] = {0};
    scanf("%d",&t);
    while(t--)
    {
        int ans = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            if(b[i-1] > 0) b[i] = b[i-1]+a[i];
            else b[i] = a[i];
            ans = max(ans,b[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
