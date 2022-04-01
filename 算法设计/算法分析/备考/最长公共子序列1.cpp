/*问题 A: 最长公共子序列
题目描述
给你一个序列 X 和另一个序列 Z，当 Z 中的所有元素都在X中存在，并且在 X 中的下标顺序是严格递增的，
那么就把 Z 叫做 X 的子序列。
例如：Z= 是序列 X= 的一个子序列，Z 中的元素在X中的下标序列为 <1,2,4,6>。
现给你两个序列 X 和 Y，请问它们的最长公共子序列的长度是多少？
输入
输入包含多组测试数据。每组输入占一行，为两个字符串，由若干个空格分隔。每个字符串的长度不超过 100。
输出
对于每组输入，输出两个字符串的最长公共子序列的长度。
样例输入
abcfbc abfcab
programming contest 
abcd mnp
样例输出
4
2
0
题意
求“最长公共子序列”最优值，即最长公共子序列的长度。
思路
DP 经典题。
输入两个字符串后，用 la、lb 分别存储 a 数组和 b 数组的长度：
la = strlen(a);
lb = strlen(b);
如何 DP ？写一个双层循环，i 从 0 到 la-1，j 从 0 到 lb-1。
状态转移方程：
if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
最后，输出 dp[la][lb] 即可。
代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int main()
{
    char a[maxn],b[maxn];
    int la,lb;
    while(cin>>a>>b)
    {
        la = strlen(a);
        lb = strlen(b);
        int i,j;
        for(i = 0; i < la; i++) dp[i][0] = 0;
        for(i = 0; i < lb; i++) dp[0][i] = 0;//第0行0列置为0 
        for(i = 1; i <= la; i++)
        {
            for(j = 1; j <= lb; j++)
            {
                if(a[i-1] == b[j-1]) 
				dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[la][lb]<<endl;
    }
    return 0;
}
