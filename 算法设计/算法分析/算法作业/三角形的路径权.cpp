/*������������ʾ����һ�����������Ρ����һ���������Ӷ����׵�ĳ����һ��·����ʹ��·�������������ֵ��ܺ����
ÿһ��������б�����»���б�������ߣ�1< ����������< 25���������е�����Ϊ����< 1000��
����
�����һ��ΪN����ʾ��N�� ����N�б�ʾ������ÿ��·��·��Ȩ��
���
���·�������������ֵ��ܺ����Ĵ𰸡�
��������
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
�������
30*/
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace  std;
const int maxn=30;
int dp[maxn][maxn];//��¼ÿ���׶ε����ֵ
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
 
