/*���� C: ���λ�ѩ��
��Ŀ����
zcbϲ����ѩ����������һ����ѩ���������ѩ����һ�����Σ�Ϊ�˼�㣬������r��c�еľ�������ʾÿ����Ρ�Ϊ�˵õ�������ٶȣ�
���е�·�߱���������б�� ���������е��Ǹ����Σ����Դ�ĳ���㻬�����������ĸ����ڵĵ�֮һ������24-17-16-1��
��ʵ25-24-23��3-2-1��������ʵ���������һ����

����
��1��:��������r��c(1 �� r, c �� 100)����ʾ��������С���2..r+1��:ÿ��c��������ʾ�������

���
��һ��:���1����������ʾ���Ի��е���󳤶ȡ�

��������
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
�������
25
����
���Ż���·�ߣ��߶ȱ���Խ��Խ�͡����п���ѡ���ĸ������ϡ��¡����ң����·�ߵĳ��ȡ�

˼·
˼·һ�����ѡ�
����������ά���飺

h[i][j]�������ڴ洢ÿ����ĸ߶ȣ�
l[i][j]�������ڴ洢��ÿһ��������Եõ����·�ߵĳ��ȣ�
visited[i][j]���������жϵ�i�е�j�еĵ��Ƿ��߹���
���ǿ��Կ���4*2������dir[i][j]�����洢����

���ң�1,0
���£�0,1
����-1,0
���ϣ�0,-1
��ϰ��дһ��bool check(int x,int y)���������жϵ�ǰ�ĵ��Ƿ��ڽ���

���ǣ�����true��
���򣬷���false��
��Ȼ�������ж�����Ϊif(x > 0 && x <= r && y > 0 && y <= c)��

�ؼ���dfs()������ôд��

���������dfs()�����ͳ����dfs()�������в�ͬ���������̴�����£�

����õ��Ѿ����ʹ��ˣ�����Ҫ����ȥ�ˣ�ֱ��return��
if(visited[x][y]) return;
�ѵ�ǰ���visited��Ϊtrue��
visited[x][y] = true;
�������Ϳ�ʼ������Χ�ĵ�(xx,yy)���ݹ����dfs()�����������Χ�ĵ�������Ǿ��õ�ǰl[x][y]��l[xx][yy]��һ��max����l[x][y]��
���l[x][y]�д洢�ľ��Ǵ�(x,y)����������г��ȣ����Ǳ����¾Ϳ��Եõ����մ𰸡�

˼·������ά
��ά���飬һ���ͺ��ѵ����ӣ������ǾͰ�����ά���һ�¡���ά->һά��

��ôʵ���أ�

����ṹ��node���洢����x��y�͸߶�h��
һ���ڶ������}��;֮��ֱ�Ӷ�������
дһ��bool check(int i,int j)�����������ж������Ƿ�Ϊ���ڵ㣨�ϡ��¡����ң���
����Ϊmain()�����е�ʵ�����̵档

����ʱ��ô����ֱ������for�����Ƚ����
a[n].x = i;
a[n].y = j;
scanf("%d",&a[n].h);
�������sort()һ�£�ע���ڽṹ����������<����h�Ӵ�С�ţ�
�������е���DP�������������������
��ʼ��dp[i] = 1
��ʱ�����ڵ�i����㣬ǰ��Ľ��j��h�������Ǿ��ж���ÿ�����Ƿ������ڵ㣨ǰ�涨���check()�����������ǣ���ִ��dp[i] = max(dp[i],dp[j]+1);
����ans��dp[i]��������ֵ
����1�����ѣ�
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 105;
int r,c;
int h[maxn][maxn],l[maxn][maxn];
bool visited[maxn][maxn];
int dir[4][2] = {1,0, 0,1, -1,0, 0,-1};
bool check(int x,int y)
{
    if(x > 0 && x <= r && y > 0 && y <= c) return true;
    return false;
}
void dfs(int x,int y)
{
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int xx = x+dir[i][0];
        int yy = y+dir[i][1];
        if(check(xx,yy) && h[x][y] > h[xx][yy])
        {
            dfs(xx,yy);
            l[x][y] = max(l[x][y],l[xx][yy]+1);
        }
    }
}
int main()
{
    scanf("%d %d",&r,&c);
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            scanf("%d",&h[i][j]);
            l[i][j] = 1;
        }
    }
    int ans = -1;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            dfs(i,j);
            ans = max(ans, l[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
����2����ά��*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int mod=1e9+7;
const int inf=0x7f7f7f7f;
const int maxn=5e4+50;
struct node
{
    int x,y,h;
    bool operator < (const node &c) const
    {
        return h > c.h;
    }
}a[maxn];
int dp[maxn];
int r,c;
bool check(int i,int j)
{
    if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) == 1)  //�ж��Ƿ������ڵ�
        return true;
    return false;
}
int main()
{
    scanf("%d%d",&r,&c);
    int n = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1;j <= c; j++)
        {
            a[n].x = i;
            a[n].y = j;
            scanf("%d",&a[n].h);
            n++;
        }
    }
    sort(a,a+n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(check(i,j))
                dp[i] = max(dp[i],dp[j]+1);
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
