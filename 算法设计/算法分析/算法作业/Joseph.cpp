#include<iostream>
using namespace std;
bool check(int m); 
int k;
int res=0;
int main()
{
	while(cin>>k)
	{
	  if(k!=0)
		
		{
			for(int i=k+1;;i++)
			{
				if(check(i)==true)
				{
				cout<<i<<endl;
				break;
			}
			}
	}
	}
return 0;
 }
 bool check(int m)
    {
	int res=0;
	for(int i=1;i<=k;i++)
    {
    	res=(res+m-1)%(2*k-i+1);
    	if(res<k) return false; 
 	
 }
 return true;
  }
