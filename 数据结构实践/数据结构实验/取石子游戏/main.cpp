#include <iostream>
using namespace std;
int main()
{
    int C,m,n;
    cin>>C;
    while(C--)
    {
        cin>>n>>m;
        if(n%(m+1))
        cout<<"first"<<endl;
        else
        cout<<"second"<<endl;
    }
    return 0;
}

