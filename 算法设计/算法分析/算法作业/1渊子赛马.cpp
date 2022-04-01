#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1e3+5;
int main()
{
    int n,a[maxn],b[maxn],cnt1,cnt2;
    while(~scanf("%d",&n) && n)
    {
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i++) scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > b[j])
            {
                cnt1++;
                j++;
            }
            else cnt2++;
        }
        if(cnt1 > cnt2) puts("YES");
        else puts("NO");
    }
    return 0;
}
