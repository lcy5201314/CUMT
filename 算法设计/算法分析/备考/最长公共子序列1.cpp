/*���� A: �����������
��Ŀ����
����һ������ X ����һ������ Z���� Z �е�����Ԫ�ض���X�д��ڣ������� X �е��±�˳�����ϸ�����ģ�
��ô�Ͱ� Z ���� X �������С�
���磺Z= ������ X= ��һ�������У�Z �е�Ԫ����X�е��±�����Ϊ <1,2,4,6>��
�ָ����������� X �� Y���������ǵ�����������еĳ����Ƕ��٣�
����
�����������������ݡ�ÿ������ռһ�У�Ϊ�����ַ����������ɸ��ո�ָ���ÿ���ַ����ĳ��Ȳ����� 100��
���
����ÿ�����룬��������ַ���������������еĳ��ȡ�
��������
abcfbc abfcab
programming contest 
abcd mnp
�������
4
2
0
����
������������С�����ֵ��������������еĳ��ȡ�
˼·
DP �����⡣
���������ַ������� la��lb �ֱ�洢 a ����� b ����ĳ��ȣ�
la = strlen(a);
lb = strlen(b);
��� DP ��дһ��˫��ѭ����i �� 0 �� la-1��j �� 0 �� lb-1��
״̬ת�Ʒ��̣�
if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
������ dp[la][lb] ���ɡ�
����*/
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
        for(i = 0; i < lb; i++) dp[0][i] = 0;//��0��0����Ϊ0 
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
