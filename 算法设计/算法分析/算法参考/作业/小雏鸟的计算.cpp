/*问题 J: 小雏鸟的计算
题目描述
小雏鸟们的三角形翅膀终于长出健壮的肌肉和丰满的羽毛，已经跃跃欲试的去准备尝试挑战新的难题了。

考虑以下的算法：

输入 n
印出 n
如果 n = 1 结束
如果 n 是奇数 那么 n=3*n+1
否则 n=n/2
GOTO 2
例如输入 22 得到的数列： 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
据推测此算法对任何整数而言会终止 (当打印出 1 的时候)。虽然此算法很简单，但以上的推测是否真实却无法知道。然而对所有的n ( 0 < n < 1000000 )来说，以上的推测已经被验证是正确的。
给一个输入 n 透过以上的算法我们可以得到一个数列（1作为结尾）。此数列的长度称为n的cycle length。上面提到的例子 22的 cycle length为 16.
问题来了：对任2个整数i，j我们想要知道介于i，j（包含i，j）之间的数所产生的数列中最大的cycle length是多少。

输入
输入可能包含了好几行测试数据，每一行有一对整数 i，j 。

0< i，j < 1000000

输出
对每一对输入 i j你应该要输出 i j和介于i j之间的数所产生的数列中最大的cycle length。

样例输入
1 10
10 1
100 200
201 210
900 1000
样例输出
1 10 20
10 1 20
100 200 125
201 210 89
900 1000 174
题意
如题目描述所示，对任2个整数i、j，输出介于i、j（包含i，j）之间的数所产生的数列中最大的cycle length是多少。

思路
模拟，递归。

代码*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int MAXN = 105;
int cnt;
void fun(int x)
{
    if(x == 1) return;
    if(x % 2) x = 3*x+1;
    else x /= 2;
    fun(x);
    cnt++;
}
int solve(int n)
{
    cnt = 1;
    fun(n);
    return cnt;
}
int main()
{
    int l,r,ans,L,R;
    while(~scanf("%d %d",&L,&R))
    {
        l = L;
        r = R;
        if(l > r) swap(l,r);
        ans = 0;
        for(int p = l; p <= r; p++)
            ans = max(ans,solve(p));
        printf("%d %d %d\n",L,R,ans);
    }
    return 0;
}
