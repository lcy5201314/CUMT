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
