/*���� D: ͼ��m��ɫ����
��Ŀ����
����������ͨͼG��m�ֲ�ͬ����ɫ������Щ��ɫ��ͼ�ĸ���������һ����ɫ����ĳ�ַ���ʹ��ͼ��ÿ���ߵ�2���������ɫ������ͬ��
����һ������ķ������ҳ����еķ�����

����
��һ����3��������n��k��m���ֱ��ʾn�����㣬k���ߣ�m����ɫ
������k�У�ÿ��2������������ʾһ���ߵ���������

���
���в�ͬ����ɫ������

��������
5 8 4 
1 2
1 3 
1 4
2 3
2 4
2 5
3 4
4 5
�������
48
����
����һ��ͼ����ɫ�����󷽰�����

˼·
���ڽӾ����ͼ��1��ʾ��i�͵�j���бߡ�

dfs��ÿ�ο�Ŀǰ�����ɫ�Ƿ�����������������������һ�㡣

����*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 2e3 + 5;
int n,k,m,ans;
int map[maxn][maxn];
int color[maxn];
void dfs(int d)
{
    if(d == n+1)
    {
        ans++;
        return;
    }
    for(int i = 1; i <= m; i++)     //��ɫm��
    {
        bool flag = true;
        for(int j = 1; j <= n; j++)     //n����
        {
            if(map[d][j] && color[j] == i)  //��ͨ����ɫΪi��ʧ��
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            color[d] = i;   //Ⱦɫ
            dfs(d+1);       //��һ���
            color[d] = 0;   //�ص�δȾɫ״̬
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for(int i = 0; i < k; i++)
    {
        int tmp1,tmp2;
        scanf("%d %d",&tmp1,&tmp2);
        map[tmp1][tmp2] = 1;
        map[tmp2][tmp1] = 1;
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
