/*���� D: 01��������
��Ŀ����
��֪��N����Ʒ��һ��������C�����ı�����ÿ����Ʒi������ΪWi����ֵΪPi����ô������������װ�������Ż�ʹװ�뱳����Ʒ��
�ܼ�ֵ���
����
��������������ݡ���һ��Ϊһ������T(1<=T<=10)������������ݸ�����
��������T��������ݡ�ÿ��������ݵ�һ��Ϊ����������C(C<10000)����Ʒ����N(N<1000)����������N�зֱ�Ϊ��Ʒ������
cost(1<=cost<=100)�ͼ�ֵval(1<=val<=3000000)����ע�⣺������ܳ���int��Χ��
���
��ÿ��������ݣ�������Ӧ����װ��Ʒ������ֵ��
��������
1
10 5
2 6
2 3
6 5
5 4
4 6
�������
15
����
����Ŀ������ʾ������DP�⡣
˼·
�ȿ���Ŀ����ע�⣬������ܳ���int��Χ���ʲ���long long���͡���һ������д��typefef long long ll;��������������һ�£�
�Ժ�д�����Ƚϼ�㡣
ע����stdio��scanf��printf���У�Ҫд��%lld��
������д�����ֱ��Ӧ����Ĵ���1�ʹ���2��.
��һ�֣�Ҳ�������ϵ����֣�m[i][j]����ӵ�i����Ʒ��ʼ�ġ����������Ϊj������¿��Ի�õ�������棬�����������m[1][c]��
�ڶ��֣��Ƚϳ�����д����m[i][j]ǰi����Ʒ�����������Ϊj������¿��Ի�õ�������棬�����������m[n][c]��
����ʼ״̬���Եڶ���Ϊ�������ȵ�һ�к͵�һ��ȫ��Ϊ0����Ϊ
0��Ʒ��0��ֵ��
0������0��ֵ��
��״̬ת�Ʒ��̣�
if (�������jС����Ʒi�����)
    m[i][j] = m[i-1][j]; //����װ���µ�i�����壬Ŀǰֻ�ܿ�ǰi-1������װ��
else m[i][j] = max(m[i-1][j], m[i-1][j-w[i]] + v[i]);
����1
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
ll m[maxn][maxn];
int main()
{
    int t,n;
    ll c,w[maxn],v[maxn];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d",&c,&n);
        for(int i = 1; i <= n; i++)
            scanf("%lld %lld",&w[i],&v[i]);
        int i,j,jMax = min(w[n]-1,c);
        for(j = 0; j <= jMax; j++) m[n][j] = 0;
        for(j = w[n]; j <= c; j++) m[n][j] = v[n];
        for(i = n-1; i > 1; i--)
        {
            jMax = min(w[i]-1,c);
            for(j = 0; j <= jMax; j++)m[i][j] = m[i+1][j];
            for(j = w[i]; j <= c; j++) m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
        }
        m[1][c] = m[2][c];
        if(c >= w[1]) m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]);
        printf("%lld\n",m[1][c]);
    }
    return 0;
}
����2*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
const int maxc = 1e4 + 5;
const int inf = 0x3f3f3f3f;
ll dp[maxn][maxc];
int main()
{
    int t,n;
    ll c,w[maxn],v[maxn];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d",&c,&n);
        for(int i = 1; i <= n; i++)
            scanf("%lld %lld",&w[i],&v[i]);
        for(int i = 0; i <= c; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= n; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            int jMax = min(c,w[i]);
            for(int j = 1; j < jMax; j++)
                dp[i][j] = dp[i-1][j];
            for(int j = w[i]; j <= c; j++)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
        printf("%lld\n",dp[n][c]);
    }
    return 0;
}
