#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long t,len=0;
    while(n--)
    {
        cin>>t;
        len=0;
        int i,d=1;
        for(i=0;i<t;i++)
        {
            len=(len+d)%10000;//为了不让数溢出 
            d=d+2;
        }
        cout<<len<<endl;
    }
    return 0;
}

