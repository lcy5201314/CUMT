#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct Gene{
	int start,end,id;
};
bool cmp(Gene a,Gene b)
{
	if(a.start!=b.start)
	{
		return a.start<b.start;
	}
	else return a.end<b.end;
}
void print(int *path,Gene*g,int start,int lay)
{
	if(start==-1)return;
	print(path,g,path[start],lay+1);
	cout<<g[start].id;
	if(lay!=0)cout<<' ';
	else cout<<endl;
} 
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		Gene g[1001];
		int path[1001];
		int count[1001];
		memset(path,-1,sizeof(path));
		memset(count,0,sizeof(count));
		for(int i=0;i<n;i++)
		{
			cin>>g[i].start>>g[i].end;
			g[i].id=i+1; 
		}
		sort(g,g+n,cmp);
		count[0]=1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(g[j].end<g[i].start)
				{
					if(count[i]<count[j])
					{
						count[i]=count[j];
						path[i]=j;
					}
				}
			}
			count[i]++; 
		}
		int max=0;int flag;
		for(int i=0;i<n;i++)
		    if(max<count[i])
		       {
		       	max=count[i];
		       	flag=i;
		       }
	   //cout<<max<<endl;
	   print(path,g,flag,0);
	}
}
