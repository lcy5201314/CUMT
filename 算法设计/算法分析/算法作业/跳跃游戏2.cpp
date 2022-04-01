/*给定一个非负整数数组，假定你的初始位置为数组第一个下标。数组中的每个元素代表你在那个位置能够跳跃的最大长度。
你的目标是到达最后一个下标，并且使用最少的跳跃次数。例如：A = [2,3,1,1,4]，到达最后一个下标的最少跳跃次数为 2。
（先跳跃1步，从下标0到1，然后跳跃3步，到达最后一个下标。一共两次）
输入
第一行输入一个正整数n(1≤n≤100)，接下来的一行，输入n个整数，表示数组A。
输出
最后输出最少的跳跃次数。
样例输入
5
3 1 1 1 1
样例输出
2*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005; 
int dp[maxn];
int ar[maxn];
int n;
///dp[i]中i表示从第0号位置达到i号位置所需要的最小跳跃数

int main()
{
    int n,i,j;
    cin>>n;
    for(i=1; i<=n; i++)
    {
    	 cin>>ar[i];
	}
    memset(dp,0,sizeof(dp));//memset函数是对字节为单位进行赋值的;此处为初始化dp 
	for(i=n-1;i>0;i--)
	if(i+dp[i]>=n) //如果从当前下标i能到达下标n位置，跳跃次数为1； 
	dp[i]=1;
	else
	{
		dp[i]=n;//否则将dp值设为较大值 
		for(j=i+1;j<=i+ar[i];j++)
		{
			dp[i]=min(dp[i],dp[j]+1);
		}
	}
	cout<<dp[1];
       
    return 0;
}

