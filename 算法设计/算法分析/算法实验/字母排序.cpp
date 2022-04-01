/*XXXX年突然有外星人造访，但大家语言不通，不过科学家们经过研究发现外星人用26个英文字母组成的单词中
最长不降子序列的长度来表述数字，且英文字母的排列顺序不同，现给出其排列顺序，再给出外星人说的每个数字
（其实是每个英文单词，用空格隔开），翻译出外星人所说的数字（连续输出，最后加回车）。
(因为是最长不降子序列，所以数字中没有0，也就是说外星人的数字是大于0的数字)。
例如，我们正常的字母排列顺序是abcdefg…….xyz，代表a< b< c< …..< x< y< z abcd efg hhh ihg
四个字符串的最长不降子序列的长度分别为4 3 3 1。
输入
第1，2行为字符串 含义如题描述。1≤第二行长度≤255。
输出
输出答案，含义如题描述
样例输入
abcdefghijklmnopqrstuvwxyz
abcd efg hhh ihg
样例输出
4331*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
char str[maxn];
map<char,int>mp;//定义一个map对象mp  映射 字符型 --->整型 
int dp[maxn];
int main()
{
	cin>>str;
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		mp[str[i]]=i;
			}
	while(cin>>str)
	{
		n=strlen(str);
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			dp[i]=1;
			for(int j=0;j<i;j++)
			{
				if(mp[str[j]]<=mp[str[i]])
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		 } 
		 cout<<ans;
		
			}
	cout<<endl;
	return 0;		
}
