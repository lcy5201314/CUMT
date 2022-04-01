#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    string wo[30];
    scanf("%d",&n);
    for(int i = 0; i < n; i++) cin>>wo[i];
    sort(wo,wo+n);
    cout<<wo[0];
    for(int i = 1; i < n; i++) cout<<" "<<wo[i];
    cout<<endl;
    return 0;
}
