#include<iostream>
using namespace std;
char* tbl="0123456789ABCDEF";
void f(int dec,int base)
{
    if(dec)
    {
        f(dec/base,base);
        cout<<tbl[dec%base];
    }
}
int main()
{
    int n;
    cin>>n;
    f(n,8);
    cout<<endl;
    return 0;
}
