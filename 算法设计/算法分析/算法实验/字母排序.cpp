/*XXXX��ͻȻ����������ã���������Բ�ͨ��������ѧ���Ǿ����о�������������26��Ӣ����ĸ��ɵĵ�����
����������еĳ������������֣���Ӣ����ĸ������˳��ͬ���ָ���������˳���ٸ���������˵��ÿ������
����ʵ��ÿ��Ӣ�ĵ��ʣ��ÿո���������������������˵�����֣�������������ӻس�����
(��Ϊ������������У�����������û��0��Ҳ����˵�����˵������Ǵ���0������)��
���磬������������ĸ����˳����abcdefg����.xyz������a< b< c< ��..< x< y< z abcd efg hhh ihg
�ĸ��ַ���������������еĳ��ȷֱ�Ϊ4 3 3 1��
����
��1��2��Ϊ�ַ��� ��������������1�ܵڶ��г��ȡ�255��
���
����𰸣�������������
��������
abcdefghijklmnopqrstuvwxyz
abcd efg hhh ihg
�������
4331*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
char str[maxn];
map<char,int>mp;//����һ��map����mp  ӳ�� �ַ��� --->���� 
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
