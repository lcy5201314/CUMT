#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
const ll mod = 1e8 + 7;
const int MAXN = 25005;
ll f[MAXN];
ll poww(ll x,ll n)
{
    ll ans = 1;
    while(n)
    {
        if(n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans%mod;
}
int main()
{
    f[0] = 0;
    for(ll i = 1; i < MAXN; i++)
    {
        f[i] = (f[i-1]%mod+poww(i,i)%mod)%mod;
    }
    ll n;
    while(~scanf("%lld",&n))
        printf("%lld\n",(f[n]+1)%mod);
    return 0;
}

