#include<iostream>
#include<algorithm>
using namespace std;
int map[1000+10][1000+10];
const int inf=0x3f3f;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)   //将整张图初始化为inf 
			map[i][j]=inf;
	for(int i=0;i<=1000;i++)      //因为本题不存在自环，所以把ii初始化为0 
		map[i][i]=0;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v]=min(map[u][v],w);     //inf为最大整型数
		map[v][u]=map[u][v];            //因为是个无向图，从u到v跟从v到u应该是一样的 
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
				map[j][k]=min(map[j][k],map[j][i]+map[i][k]);
				//把当前最小的存在[j][k]中，map[j][i]+map[i][k]即所有的从j到k的路径 
		}	
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		cout<<map[a][b]<<endl;
	}
	return 0;
}
