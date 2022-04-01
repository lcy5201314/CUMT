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
		for(int j=1;j<=1000;j++)   //������ͼ��ʼ��Ϊinf 
			map[i][j]=inf;
	for(int i=0;i<=1000;i++)      //��Ϊ���ⲻ�����Ի������԰�ii��ʼ��Ϊ0 
		map[i][i]=0;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		map[u][v]=min(map[u][v],w);     //infΪ���������
		map[v][u]=map[u][v];            //��Ϊ�Ǹ�����ͼ����u��v����v��uӦ����һ���� 
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
				map[j][k]=min(map[j][k],map[j][i]+map[i][k]);
				//�ѵ�ǰ��С�Ĵ���[j][k]�У�map[j][i]+map[i][k]�����еĴ�j��k��·�� 
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
