#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mod 1000000007
#define mem(a) memset(a,0,sizeof(a))
 
using namespace std;
 
const int maxn = 10000 + 5 , inf = 0x3f3f3f3f;
 
int a[maxn],up[maxn],down[maxn],dp[maxn];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans = 1 ;
        mem(a);
        for(int i = 0 ; i < n ; i++ ) scanf("%d",&a[i]);
        int cnt = 0;
        dp[0] = a[0];
        up[0] = 1;
        for(int i = 1 ; i < n ; i++){
            if(a[i]>dp[cnt]) dp[++cnt] = a[i];
            if(a[i]<dp[cnt]){
                int k = lower_bound(dp,dp+cnt+1,a[i]) - dp ;
                dp[k] = a[i];
            }
            up[i]=cnt+1;
        }
        cnt = 0 ;
        mem(dp);
        dp[0] = a[n-1];
        down[n-1] = 1;
        for(int i = n - 2 ; i>= 0 ; i--){
            if(a[i]>dp[cnt]) dp[++cnt] = a[i];
            if(a[i]<dp[cnt]){
                int k = lower_bound(dp,dp+cnt+1,a[i]) - dp ;
                dp[k] = a[i];
            }
            down[i]=cnt+1;
        }
        for(int i = 0 ; i<n ; i++){
            if(up[i]==down[i]&&up[i]>ans) ans = up[i];
        }
        printf("%d\n",2*(ans)-1);
    }
}
