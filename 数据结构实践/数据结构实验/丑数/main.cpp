#include<iostream> 
#include<string.h>
using namespace std;
#define N 5842
long long f[N];
int main()
{
	int i,j,k,n;
	int next[4] = {2,3,5,7};
	f[1]=1;
	for(i=2;i<=5842;i++)
	{
		f[i]=2000000001;
		for(j=0;j<4;j++)
		{
			for(k=i-1;k>=1;k--)
			{
				if(f[k]*next[j]<=f[i-1])
					break;
				if(f[k]*next[j]<f[i])
					f[i]=f[k]*next[j];
			}
		}
    }
	string s;
	while((cin>>n)&&(n!=0))
	{
	if(n%10==1&&n%100!=11)
	s="st";
	else if(n%10==2&&n%100!=12)
	s="nd";
	else if(n%10==3&&n%100!=13)
	s="rd";
	else s="th";
		cout<<"The "<<n<<s<<" humble number is "<<f[n]<<"."<<endl;
	}
	return 0;
}

