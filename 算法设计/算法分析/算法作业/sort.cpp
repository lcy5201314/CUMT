#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005];
int main()
{
    int m, n;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        for(int i= n-1; i>=n-m; i--)
        {
            if(i==n-m)
                printf("%d\n", a[i]);
            else
                printf("%d ", a[i]);
        }
    }
    return 0;
}
