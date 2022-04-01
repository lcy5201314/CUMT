# include <iostream>
using namespace std;
int main ()
{
    long long int c[20]; c[0]=1;
    for(int i=1;i<=20;i++)
    {
        c[i]=c[i-1]*(4*i-2)/(i+1);
    }
    int n;
    while(cin>>n)
    {
        cout<<c[n]<<endl;
    }
}

