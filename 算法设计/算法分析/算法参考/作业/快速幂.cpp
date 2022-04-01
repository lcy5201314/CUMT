/*问题 C: 快速幂
题目描述
img

输入
多组测试样例，最多50组。每组测试样例给定一个整数x(1<=x<=25000)

输出
对每个样例，输出一行，代表f(x)对100000007取余的结果。

样例输入
3
4
5
样例输出
33
289
3414
题意
如题目描述所示，就是输入x求

11+22+...+xx+1
的结果输出。

思路
开一个足够大的数组存储

11+22+...+xx
输出的时候+1即可。

既然题目是“快速幂”，那就愉快地用快速幂模板吧！

初始化：

f[0] = 0；

f[i] = f[i-1] + poww(i,i)

注意，这样可能会溢出，所以要利用数论知识

(a+b)modc=(amodc+bmodc)modc
改写成

f[0] = 0;

f[i] = (f[i-1]%mod+poww(i,i)%mod)%mod;

注意：最后输出+1后还要再% mod！

代码*/
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
