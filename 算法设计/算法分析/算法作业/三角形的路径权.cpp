/*如输入样例所示出了一个数字三角形。请编一个程序计算从顶至底的某处的一条路径，使该路径所经过的数字的总和最大。
每一步可沿左斜线向下或右斜线向下走；1< 三角形行数< 25；三角形中的数字为整数< 1000；
输入
输入第一行为N，表示有N行 后面N行表示三角形每条路的路径权。
输出
输出路径所经过的数字的总和最大的答案。
样例输入
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
样例输出
30*/
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace  std;
const int maxn=30;
int dp[maxn][maxn];//记录每个阶段的最大值
int main()
{
	int n,i,j;
	cin>>n;
for(int i=1;i<=n;i++)
for(int j=1;j<=i;j++)
cin>>dp[i][j];
for(int i=n;i>=1;i--)
for(int j=1;j<=i;j++)
{

	if(i==n)
	{
		dp[i][j]=dp[i][j];
	}
	else{
    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];}
 }
 printf("%d\n",dp[1][1]);
 }
 
