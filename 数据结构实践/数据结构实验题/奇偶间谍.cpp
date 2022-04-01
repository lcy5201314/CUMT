#include<iostream>
using namespace std;
int main()
{
	int a[10];
	int i,odd=0,eve=0;
	for(i=0;i<10;i++)
		cin>>a[i];
	for(i=0;i<10;i++)
	{
		if(a[i]%2==0)	
			eve++;
		if(a[i]%2==1)	
			odd++;
	}
	if(eve==1)
	{
		for(i=0;i<10;i++)
			if(a[i]%2==0) cout<<a[i];
	}
	if(odd==1)
	{
		for(i=0;i<10;i++)
			if(a[i]%2==1) cout<<a[i];
	}
	return 0;
 } 
