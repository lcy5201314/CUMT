#include<stdio.h>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int flag=0;
        long long x;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            flag^=x;
        }
        if(flag)
       printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}


