#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int a[200];
	int n,i,j;
	memset(a,0,sizeof(a));
	cin>>n;
	a[1]=2;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			a[j]*=2;
		}
  		for(j=1;j<i;j++)
		{
			while(a[j]>=10)
			{
				a[j]-=10;
				a[j+1]+=1;
			}
		}
		a[1]+=2;
		while(a[1]>=10)
		{
			a[1]-=10;
			a[2]++;
		}
	}
	int k=100;
	while(a[k]==0)
	{
		k--;
	}
	for(i=k;i>0;i--)
		cout<<a[i];
	return 0;
}
