#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
 
const int INF = 0x3fffffff;
int n,s,m;
int G[51][51];
bool vis[51]={false};
int d[51];
 
void Dijkstra(int s)
{
	fill(d,d+51,INF);
	d[s] = 0;
	for (int i=0;i<n;i++)
	{
		int u=-1 , MIN = INF;
		for (int j=0;j<n;j++)
		{
			if (vis[j]==false && d[j]<MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return ;
		vis[u] = true;
		for (int v=0;v<n;v++)
		{
			if (vis[v]==false &&G[u][v]!=0 && d[u]+G[u][v]<d[v] )
			d[v] = d[u]+G[u][v];
		}
	}
}
 
int main()
{
	int i,j,k;
	cin>>n>>s;
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			cin>>G[i][j];
		}
	}
	Dijkstra(s);
	for (i=0;i<n;i++)
	{
		if (i!=s)
		{
			if (d[i]==INF )
			cout<<"-1"<<" ";
			else
			cout<<d[i]<<" ";
		}
		
	}
	cout<<endl;
	
	return 0;
}
