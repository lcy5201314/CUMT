#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	char a[128];
	int i,l,n;
	float s;
	while(cin.getline(a,128))
	{
		l=strlen(a);
		for(i=s=n=0;i<l;i+=2)
		{
			if(a[i]=='A')
		    {
				s+=4.0;
			}
			else if(a[i]=='B')
			{
				s+=3.0;
			}
			else if(a[i]=='C')
			{
				s+=2.0;
			}
			else if(a[i]=='D')
			{
				s+=1.0;
			}
			else if(a[i]!='F')
			{
				n++;
			}
	}
		n?cout<<"Unknown"<<endl:cout<<fixed<<setprecision(2)<<s/((l+1)/2)<<endl;
	} 
 	return 0;
}
