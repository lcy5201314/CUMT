/*���� E: �����������
��Ŀ����
��֪ n ������ҿ����� [a,b)��������� m ��ѯ�ʣ�������[l,r]�����԰��� n �������еĶ��ٸ����䣬���ұ���������������
�����ཻ��

����
�����������������ݣ�����ÿ��������ݣ�

��һ�а����������� n ,m (1��n��100000,1��m��100) ��

������ n ��ÿ�а����������� a ,b (0��a9</sup>) ��

������ m ��ÿ�а����������� l ,r (0��l9</sup>) ��

���
����ÿ��������ݣ���� m �У�ÿ�а���һ��������

��������
4 3
1 3
2 4
1 4
1 2
1 2
1 3
1 4
�������
1
1
2
����
��������⣬n�����m��query��

˼·
Greedy��

��������󣬰����л������ʱ���С��������

����ans���ȸ�����ֵ1��

ѭ���������л�����ϲ��ཻ����Խ��Ϳ�ѡ��

�Ż���

�ڽ���ʱ�䳬��r������ѭ����
����Ѱ�ҵ�һ������Ļ����û�ã���
����д������������һ���ģ���

��һ��j����¼��һ����ѡ�Ļ��

ÿ��ѡ���ֱ��l = a[i].e;��

ǧ���дif(e == c.e) return b < c.b;����ض�WA����֪Ϊ�Ρ�

ǧ��Ҫ�ڽ���ʱ�䳬��r������ѭ������Ȼ�ض�TLE��

ǧ��Ҫ��cin��cout����Ȼ����Ҳ�Ǳض�TLE��

����1
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
struct s
{
    int b,e;
    bool operator < (const s&c)const
    {
        //if(e == c.e) return b < c.b;
        return e < c.e;
    }
}a[maxn];
int main()
{
    int n,m,l,r;
    while(~scanf("%d %d",&n,&m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d",&a[i].b,&a[i].e);
        }
        sort(a,a+n);
        for(int cas = 0; cas < m; cas++)
        {
            scanf("%d %d",&l,&r);
            int j = 0,ans = 0;
            while(a[j].b < l) j++;
            for(int i = j; i < n && a[i].e <= r; i++)
            {
                if(a[i].b >= a[j].e || i == j)
                {
                    ans++;
                    j = i;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
����2*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    int b,e;
    bool operator < (const node & c)const
    {
        return e < c.e;
    }
}a[maxn];
int main()
{
    int n,m,l,r;
    while(~scanf("%d %d",&n,&m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d",&a[i].b,&a[i].e);
        }
        sort(a,a+n);
        for(int cas = 0; cas < m; cas++)
        {
            scanf("%d %d",&l,&r);
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(a[i].b >= l)
                {
                    if(a[i].e <= r)
                    {
                        ans++;
                        l = a[i].e;
                    }
                    else break;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
