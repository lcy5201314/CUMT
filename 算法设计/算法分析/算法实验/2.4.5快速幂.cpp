/*
����Ŀ������ʾ����������x��11+22+...+xx+1�Ľ�������
˼·
��һ���㹻�������洢11+22+...+xx�����ʱ��+1���ɡ�
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
��ÿ�����������һ�У�����f(x)��100000007ȡ��Ľ���� 
3
4
5
�������
33
289
3414*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e8 + 7;   //10^8��7 
const int MAXN = 25000;
ll f[MAXN];
ll poww(ll x,ll n)//����x^n,��ǰΪi^i 
{
    ll ans = 1;
    x%=mod; 
    while(n)
    {
        if(n%2==1)//���nΪ���� 
        {
        ans = ans * x % mod;  //��������x
		}
        		x = x * x % mod;    //ÿ��x���� 
		n/=2;    //��n >>= 1;n����һλ 
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

