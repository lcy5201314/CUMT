/*问题 C: 矩阵连乘
题目描述
给定 n 个矩阵 {A1,A2,…,An}，及 m 个矩阵连乘的表达式，判断每个矩阵连乘表达式是否满足矩阵乘法法则，如果满足，
则计算矩阵的最小连乘次数，如果不满足输出 MengMengDa 。
输入
输入数据由多组数据组成（不超过 10 组样例）。每组数据格式如下：
第一行是 2 个整数 n (1?n?26) 和 m (1?m?3)，表示矩阵的个数。
接下来 n 行，每行有一个大写字母，表示矩阵的名字，后面有两个整数 r 和 c，分别表示该矩阵的行数和列数，其中 1<r,c<100。
第 n+1 行到第 n+m 行，每行是一个矩阵连乘的表达式（2?矩阵个数?100）。
输出
对于每个矩阵连乘表达式，如果运算不满足矩阵乘法法则的情况（即左矩阵列数与右矩阵的行数不同），则输出 MengMengDa ，
否则输出最小矩阵连乘次数。
数据保证结果不超过 1e9 。
样例输入
3 2
A 10 100
B 5 50
C 100 5
ACB
ABC
样例输出
7500
MengMengDa
题意
矩阵连乘题，首先判断是否可连乘，可以则输出最小连乘次数，否则输出 MengMengDa 。
因为这题不要求求最优解，所以代码会稍微简单一点。
思路
先来回顾下我们上课学的矩阵连乘填表方法，不妨把它封装成一个 MatrixChain() 函数。
回忆一下填表的过程，首先，因为如果只有一个矩阵的话，那就不需要乘了，结果肯定是0，于是把对角线全部置为 0。
for(int i = 1; i <= n; i++) dp[i][i] = 0;
然后写一个三层循环：
第一层循环 r 从 2 到 n，表示连乘矩阵的个数
第二层循环 i 从 1 到 n-r+1，表示左界下标，那么右界下标 j 就等于 i+r-1
第三层循环 k 从 i 到 j-1，表示隔板位置，这个隔板把原来的问题一分为二
书上的代码把那个表对应的二维矩阵叫做 m[i][j]，因为本题输入也叫 m，所以我们就叫它 dp[i][j] 吧。
这样，让 dp[i][j] 中存储 dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j] 的最小值。
先输入 n 个矩阵的名字（单个字符）、行数和列数。这时候我们可以使用 STL 中的 map，这种容器使用红黑树实现，插入、查找、
删除的时间复杂度都是 O(logn)；当然也可以使用基于哈希表的 unordered_map，这样插入、查找、删除的时间复杂度都是 O(1)；
注意：虽是单个字符，若让 C++ 读入单个字符，可以为 \n，为了避免使用 getchar() 函数，通常使用元素个数为 2 的 char 类型
数组存储单个字符。
m 次 query，每次读入一个字符串。令 len = strlen(str)，若 len 个矩阵可连乘（对于任意两个连续矩阵，
前一个矩阵的列数=后一个矩阵的行数），则输出最小矩阵连乘次数，否则输出 MengMengDa 。
首先，不满足矩阵乘法法则的情况好判断，遍历一遍 len 个矩阵，若左矩阵列数与右矩阵的行数不同，则直接输出 MengMengDa 
并 break ；
若满足矩阵连乘条件，则我们要构造p数组，构造过程参考代码；
可以封装一个 void MatrixChain(int p[],int n) 函数，用于执行 DP，调用该函数后，结果在 dp[1][len] 中。
这题我居然 -11！一开始错是因为 RE（运行时错误），开的数组太小。后来 WA（答案错误），几经周折，终于找到了原因。
我把如下代码：
MatrixChain(p,len);
printf("%d\n",dp[1][len]);
写成了
MatrixChain(p,n);
printf("%d\n",dp[1][n]);
真是太粗心了！
我还发现很多同学还不会用 STL 中的 map，在算法题中，map 真的很好用，map 就是映射（mapping）也可以视为字典（dictionary）
，通过它可以建立键（key）值（value）映射。
比如说这题，可以开个结构体叫做 Matrix 用来存储某个矩阵的行数和列数。
假设我想查询A矩阵的行列值，我就可以直接 dir['A'] 。
头文件：#include<map>
定义：map<char,int> dir;
插入：dir[nam[0]] = tmp;
查询：dir[c]
代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
void MatrixChain(int p[],int n)
{
    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int r = 2; r <= n; r++)
    {
        for(int i = 1; i <= n-r+1; i++)
        {
            int j = i+r-1;
            dp[i][j] = dp[i+1][j]+p[i-1]*p[i]*p[j];
            for(int k = i+1; k < j; k++)
            {
                int t = dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                dp[i][j] = min(dp[i][j],t);
            }
        }
    }
}
struct Matrix
{
    int r,c;
};
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        map<char,Matrix> dir;
        char nam[8],str[105];
        int r,c;
        for(int i = 0; i < n; i++)
        {
            scanf("%s %d %d",nam,&r,&c);
            Matrix tmp;
            tmp.r = r;
            tmp.c = c;
            dir[nam[0]] = tmp;
        }
        for(int cas = 0; cas < m; cas++)
        {
            scanf("%s",str);
            int len = strlen(str);
            int p[maxn];
            p[0] = dir[str[0]].r;
            p[1] = dir[str[0]].c;
            bool flag = true;
            for(int i = 1; i < len; i++)
            {
                if(dir[str[i]].r != dir[str[i-1]].c)
                {
                    flag = false;
                    break;
                }
                p[i+1] = dir[str[i]].c;
            }
            if(!flag) puts("MengMengDa");
            else
            {
                MatrixChain(p,len);
                printf("%d\n",dp[1][len]);
            }
        }
    }
    return 0;
}
