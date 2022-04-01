#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,i,j=0;
	cin>>n;
	char str[n];
	for(i=0;i<n;i++)
	{
		cin>>str[i];
	}
	for(i=0;i<n-3;i++)
	{
		if(str[i]=='C'&&str[i+1]=='U'&&str[i+2]=='M'&&str[i+3]=='T')
		j++;
	}
	cout<<j; 
	return 0;
} 
