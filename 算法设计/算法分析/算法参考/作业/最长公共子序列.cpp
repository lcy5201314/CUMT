/*问题 F: 最长公共子序列
题目描述
一个字符串A的子串被定义成从A中顺次选出若干个字符构成的串。如A=“cdaad” ,顺次选1，3，5个字符就构成子串” cad” ,
现给定两个字符串，求它们的最长共公子串。

输入
第一行两个字符串用空格分开。两个串的长度均小于2000 。

输出
最长子串的长度。

样例输入
abccd aecd
样例输出
3
题意
输入两个字符串a和b，求它们最长公共子序列长度。

思路
dp经典题。

开一个二维数组dp，然后双重循环，dp方程：

如果a[i-1] == b[j-1]的话，dp[i][j] = dp[i-1][j-1]+1;
否则（不一样，取大的），dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
这样子，最后的答案就是dp[lena][lenb]，输出即可。

代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN = 2005;
int dp[MAXN][MAXN];
int main()
{
    int lena,lenb,i,j;
    char a[MAXN],b[MAXN];
    cin>>a>>b;
    lena = strlen(a);
    lenb = strlen(b);
    for(i = 1; i <= lena; i++)
    {
        for(j = 1; j <= lenb; j++)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d\n",dp[lena][lenb]);
    return 0;
}
