/*���� F: �����������
��Ŀ����
һ���ַ���A���Ӵ�������ɴ�A��˳��ѡ�����ɸ��ַ����ɵĴ�����A=��cdaad�� ,˳��ѡ1��3��5���ַ��͹����Ӵ��� cad�� ,
�ָ��������ַ����������ǵ�������Ӵ���

����
��һ�������ַ����ÿո�ֿ����������ĳ��Ⱦ�С��2000 ��

���
��Ӵ��ĳ��ȡ�

��������
abccd aecd
�������
3
����
���������ַ���a��b������������������г��ȡ�

˼·
dp�����⡣

��һ����ά����dp��Ȼ��˫��ѭ����dp���̣�

���a[i-1] == b[j-1]�Ļ���dp[i][j] = dp[i-1][j-1]+1;
���򣨲�һ����ȡ��ģ���dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
�����ӣ����Ĵ𰸾���dp[lena][lenb]��������ɡ�

����*/
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
