#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num[3];
        cin>>num[0]>>num[1] >>num[2];
        sort(num,num+3);
        if(num[0]*num[0]+num[1]*num[1]==num[2]*num[2])
            cout << "good" << endl;
        else if(num[0]==num[1]||num[1]==num[2]||num[0]==num[2])
            cout << "perfect" << endl;
        else
            cout << "just a triangle" << endl;
    }
    return 0;
}

