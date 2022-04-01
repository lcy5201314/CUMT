#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main()
{
	int c,i,j,n=0;
	cin>>c;
	while(n<c)
	{
		char a[50],t;
		for(i=0;i<50;i++)
		{
			a[i]='#';
		}
		cin>>a;
		for(i=0;a[i]!='#';i+=2)
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		for(i=0;a[i]!='#';i++)
			cout<<a[i];
		n=n+1;
	}	
	return 0;
}
