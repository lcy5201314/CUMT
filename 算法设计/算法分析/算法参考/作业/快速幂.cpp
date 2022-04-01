/*���� C: ������
��Ŀ����
img

����
����������������50�顣ÿ�������������һ������x(1<=x<=25000)

���
��ÿ�����������һ�У�����f(x)��100000007ȡ��Ľ����

��������
3
4
5
�������
33
289
3414
����
����Ŀ������ʾ����������x��

11+22+...+xx+1
�Ľ�������

˼·
��һ���㹻�������洢

11+22+...+xx
�����ʱ��+1���ɡ�

��Ȼ��Ŀ�ǡ������ݡ����Ǿ������ÿ�����ģ��ɣ�

��ʼ����

f[0] = 0��

f[i] = f[i-1] + poww(i,i)

ע�⣬�������ܻ����������Ҫ��������֪ʶ

(a+b)modc=(amodc+bmodc)modc
��д��

f[0] = 0;

f[i] = (f[i-1]%mod+poww(i,i)%mod)%mod;

ע�⣺������+1��Ҫ��% mod��

����*/
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
