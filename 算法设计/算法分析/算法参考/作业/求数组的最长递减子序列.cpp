/*���� B: ���������ݼ�������
��Ŀ����
����һ���������У����������ݼ���ע�ⲻ�ǡ����������������С�

����
����������У���һ�а���һ��������N��N<=1000������ʾ������������еĳ��ȡ��ڶ��а����ÿո�ָ�����N��������
������Χ����Ϊ[-30000,30000]��

���
����������У���һ�а���һ��������N��N<=1000������ʾ������������еĳ��ȡ��ڶ��а����ÿո�ָ�����N��������
������Χ����Ϊ[-30000,30000]��

��������
8
9 4 3 2 5 4 3 2
�������
9 5 4 3 2
����
DP�����⣬��������Ϊ����������С�

˼·
����*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int dp[maxn],last[maxn];
int main()
{
    int n,a[maxn],ans = 0,ansp = 1,ansa[maxn];
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    dp[1] = 1;
    last[1] = -1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        last[i] = -1;
        for(int j = 1; j < i; j++)
        {
            if(a[j] > a[i] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
                last[i] = j;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] > ans)
        {
            ans = dp[i];
            ansp = i;
        }
    }
    int j = ansp;
    for(int i = ans; ; i--)
    {
        ansa[i] = a[j];
        if(last[j] == -1) break;
        j = last[j];
    }
    for(int i = 1; i <= ans; i++) printf("%d ",ansa[i]);
    return 0;
}
