#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
char map[105][105]={0};
bool bmap[105][105]={0};//1被访问过 
int x[4]={1,0,-1,0};//tx,ty竖着看,对行进行移动，竖着移，常规+1可认为y轴负方向 
int y[4]={0,1,0,-1};//对列进行移动，横着移，常规+1可认为x轴正方向
int n,m;
struct s
{
    int a,b,step;
};
queue<s> q1;
int bfs() 
{
    int a,b,c=0;
    s t=q1.front();
    a=t.a ,b=t.b;
    while(map[a][b]!='E'&&!q1.empty())
    {
        q1.pop();s ss[4];
        for(int i=0;i<4;i++)
        {
            if(a+x[i]<0||b+y[i]<0||a+x[i]>=n||b+y[i]>=m)continue;
            else if(map[a+x[i]][b+y[i]]=='#'||bmap[a+x[i]][b+y[i]]==1)continue;
            else 
            {
                ss[i].a=a+x[i],ss[i].b=b+y[i],ss[i].step=t.step+1;
                bmap[a+x[i]][b+y[i]]=1;
                q1.push(ss[i]);
            }
        }
        t=q1.front();
        a=t.a ,b=t.b;
        if(map[a][b]=='E')break;    
    }
    if(map[a][b]=='E')return t.step;
    return -1;
}
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        memset(map,0,sizeof(map));
        memset(bmap,0,sizeof(bmap));
        while(!q1.empty())q1.pop();//有n个迷宫需清空队列q1 
            int a,b;
            cin>>n>>m;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    cin>>map[i][j];
                    if(map[i][j]=='S')
                    a=i,b=j;
                }
            bmap[a][b]=1;
            s ss[4];
            for(int i=0;i<4;i++)
            {
                if(a+x[i]<0||b+y[i]<0||a+x[i]>=n||b+y[i]>=m||map[a+x[i]][b+y[i]]=='#')continue;
                else 
                {
                    ss[i].a=a+x[i],ss[i].b=b+y[i],ss[i].step=1;bmap[ss[i].a][ss[i].b]=1;
                    q1.push(ss[i]);
                }
            }
        int step=bfs();
        cout<<step<<endl;
    }
    return 0;
}
