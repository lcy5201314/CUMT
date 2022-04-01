#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
int n;
while(cin>>n)
{
int a[1000];
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
int sum=0;
for(int i=1;i<n;i++)
{
sum+=a[i]+a[i-1];
a[i]=a[i]+a[i-1];
sort(a+i,a+n);
}
cout<<sum<<endl;
}
}
