#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int orignal[24];
int New[24];
int Cmp[24];
int dp[24][24];
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        int a;
        scanf("%d",&a);
        orignal[a]=i;

    }
    while(~scanf("%d",&New[1]))
    {
        Cmp[New[1]]=1;
        for(int i=2; i<=n; i++)
        {
            scanf("%d",&New[i]);
            Cmp[New[i]]=i;
        }
        memset(dp,0,sizeof(dp));
        for(int i=2; i<=n+1; i++)
        {

            for(int j=2; j<=n+1; j++)
            {
                if(Cmp[i-1]==orignal[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        }
        cout<<dp[n+1][n+1]<<endl;

    }

    return 0;
}




const int maxn = 20 + 5;
int d[maxn], a[maxn], id[maxn];

int main(){
    int n, x;  cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        id[i] = x;//第i个事件发生在第x位
    }

    while(~scanf("%d", &x)){
        a[0] = -10;
        a[x] = id[1];
        for(int i = 2; i <= n; ++i){
            scanf("%d", &x);
            a[x] = id[i];//查找第x个事件编号是几
        }
        
        memset(d, 0, sizeof(d));
        int m = 0;
        for(int i = 1; i <= n; ++i){//LIS
            for(int j = 0; j < i; ++j)
                if(a[i] > a[j] && d[j]+1 > d[i])  d[i] = d[j] + 1;
            m = max(m, d[i]);
        }

        printf("%d\n", m);
    }

    return 0;
}
