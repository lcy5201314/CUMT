#include<iostream>
using namespace std;
int main()
{
	int n,i,j,t;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	 } 
	for(j=0;j<n-1;j++)
		for(i=0;i<n-1-j;i++)
			{
				if(a[i]<a[i+1])
				{
					t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
				}
			}
	cout<<a[1];
	return 0;
 } 
