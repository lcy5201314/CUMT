/*
如题目描述所示，就是输入x求11+22+...+xx+1的结果输出。
思路
开一个足够大的数组存储11+22+...+xx输出的时候+1即可。
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
对每个样例，输出一行，代表f(x)对100000007取余的结果。 
3
4
5
样例输出
33
289
3414*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e8 + 7;   //10^8加7 
const int MAXN = 25000;
ll f[MAXN];
ll poww(ll x,ll n)//计算x^n,当前为i^i 
{
    ll ans = 1;
    x%=mod; 
    while(n)
    {
        if(n%2==1)//如果n为奇数 
        {
        ans = ans * x % mod;  //底数乘以x
		}
        		x = x * x % mod;    //每次x倍增 
		n/=2;    //或n >>= 1;n右移一位 
    }
    return ans;
}
int main()
{
    f[0] = 0;
    for(ll i = 1; i < MAXN; i++)
    {
        f[i] = (f[i-1]%mod+poww(i,i)%mod)%mod;  //(a+b)%c=(a%c+b%c)%c
    }
	ll n;
    while(cin>>n)
    cout<<(f[n]+1)%mod<<endl;
    return 0;
}

