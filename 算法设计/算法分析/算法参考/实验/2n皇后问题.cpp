/*���� C: 2n�ʺ�����
��Ŀ����
����һ�� n\n*�����̣���������һЩλ�ò��ܷŻʺ�����Ҫ�������з��� n ���ڻʺ�� n���׻ʺ�ʹ����������ڻʺ󶼲���
ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ����ܹ��ж����ַŷ���n С�ڵ��� 8��

����
����ĵ�һ��Ϊһ������ n����ʾ���̵Ĵ�С��

������ n �У�ÿ�� n �� 0 �� 1 �����������һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ 0����ʾ��Ӧ��λ�ò�����
�Żʺ�

���
���һ����������ʾ�ܹ��ж����ַŷ�

��������
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
�������
2
����
n�ʺ�����++����������ɫ�Ļʺ�ͬɫ�以������n�ʺ�������������ͬ�С��С��Խǣ���ע�������������Ӳ��ܷ�ͬһ��λ�á�

˼·
dfs��

����*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 10;
int map[maxn][maxn];
int x1[maxn],x2[maxn],ans,n;
bool check1(int xx,int yy)
{
    if(!map[xx][yy]) return false;
    for(int i = 0; i < xx; i++)
    {
        if(yy == x1[i]) return false;
        if(abs(xx - i) == abs(yy - x1[i])) return false; //б�Խ�
    }
    return true;
}
bool check2(int xx,int yy)
{
    if(!map[xx][yy]) return false;
    for(int i = 0; i < xx; i++)
    {
        if(yy == x2[i]) return false;
        if(abs(xx - i) == abs(yy - x2[i])) return false; //б�Խ�
    }
    return true;
}
void queen(int l)
{
    if(l == n)
    {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(check1(l,i))
        {
            x1[l] = i;
            map[l][i] = 0;
            for(int j = 0; j < n; j++)
            {
                if(check2(l,j))
                {
                    x2[l] = j;
                    queen(l+1);
                    x2[l] = -1;
                }
            }
            map[l][i] = 1;
            x1[l] = -1;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    ans = 0;
    queen(0);
    printf("%d",ans);
    return 0;
}
