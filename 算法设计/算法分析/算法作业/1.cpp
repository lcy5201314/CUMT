#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN = 1000000;
using namespace std;
int n,k,a[MAXN];
int main()
{
    cin>>n>>k;
    for(int i = 0; i < n; i++) 
    cin>>a[i]; 
    sort(a,a+n);
    cout<<a[k-1];
    return 0;
}
