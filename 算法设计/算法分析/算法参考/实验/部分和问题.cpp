/*���� E: ���ֺ�����
��Ŀ����
����n���������ж��Ƿ���Դ���ѡ���������֣�ʹ�����ǵĺ�ǡ��Ϊk��

����
�������������

����ÿ�������������һ��һ��������n���ڶ���n��������������һ������k��

1��N��20������������k��С��1e8��

���
������ʹ�ú�Ϊk�������Yes��,����No����

��������
4
1 2 4 7
13
�������
Yes
����
����Ŀ������ʾ��

˼·
dfs��

����*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 25;
int n,a[maxn],k;
bool dfs(int l,int sum)
{
    if(sum == k) return true;
    if(l == n) return false;
    return dfs(l+1,sum)||dfs(l+1,sum+a[l]);
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&k);
        if(dfs(0,0)) puts("Yes");
        else puts("No");
    }
    return 0;
}
