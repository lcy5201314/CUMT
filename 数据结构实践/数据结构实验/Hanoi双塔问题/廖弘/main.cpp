#include<iostream>
using namespace std;
int num[1000];
int n,len=1;
void r()
{
    int c=0;
    for(int i=1;i<=len;i++)
	{
        num[i]=num[i]*2;
        num[i]+=c;
        if(num[i]<10)
		{
           c=0;
        }
        else
		{
            c=num[i]/10;
            num[i]=num[i]%10;
            if(i==len){
                len=i+1;
            }
        }
    }
}
int main()
{ 
    cin>>n;
    num[1]=1;
    for(int i=1;i<=n;i++)
	{
        r();
    }
    num[1]-=1;
    r();
    for(int i=len;i>=1;i--)
	{
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}
