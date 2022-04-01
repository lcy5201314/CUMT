#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n>=1&&n<=100)
    {
    int num;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>num;
        if(num>=32)
        cout<<(char)(num);
        else
        cout<<"error";
    }
    } 
    else
    cout<<"error";
        return 0;
}

