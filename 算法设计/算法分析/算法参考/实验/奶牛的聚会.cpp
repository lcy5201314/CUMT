/*问题 D: 奶牛的聚会
题目描述
农历新年马上就要到了，奶牛们计划举办一次聚会庆祝新年的到来。但是，奶牛们并不喜欢走太远的路，这会给他们的聚会带来消极情绪
，当一头奶牛的消极指数为 Wi，他参加聚会所需行走的距离为 Si，那么他就会给聚会带来 S3i?Wi 的消极情绪。所有奶牛所在位置都
在一条直线上，已知所有奶牛的坐标和消极指数，求如何确定聚会地点，使得所有奶牛给聚会带来的消极情绪之和最小，输出消极情绪
之和的最小值。
输入
第一行包含一个整数 Ca (Ca <= 20) ，表示有 Ca 组测试数据。
对于每组测试数据：第一行包含一个整数 n (1 <= n <= 50000) ，表示奶牛的数量。接下来 n 行每行包含两个浮点数 
Xi 和 Wi (-106 <= Xi <=106, 0 < Wi <15)。
输出
对于每组测试数据，输出 “Case #c: ans” ，其中c表示测试数据编号，ans 表示消极情绪之和的最小值，结果四舍五入为一个整数。
样例输入
1
5
0.9 2
1.4 4
3.1 1
6.2 1
8.3 2
样例输出
Case #1: 300
题意
如题目描述所示。
思路
这题和 B 题类似，不同的是 B 题是单调函数，而此题是先减后增的函数，取的点一定在最左边奶牛的家和最右边奶牛的家的中间，
故我们设两个变量 L 和 R 存储最左边的点的坐标和最右边点的坐标。一开始我们可以把 L 设为正无穷大，R 设为负无穷大，
然后边输入边更新 。原问题可看作一个先减后增的函数，我们的目标是求最小值。
三分：子问题规模缩小到原来的 2/3。
初始化：L 足够大，R 足够小。
在输入时L = min(L,x[i]); R = max(R,x[i]);更新L和R，使他们最后为区间的左界和右界。
m1 为 [L,R) 的 1/3 分位点，m2 为 [L,R) 的 2/3 分位点。
写一个计算取某点时的结果 double f()，每次比较 f(m1) 和 f(m2) ：
若 f(m1) > f(m2)，则最小值一定在 [L+(R-L)/3,R) 区域内，更新 L = m1；
否则，最小值一定在 [L,R-(R-L)/3) 区域内，更新 R = m2。
代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
double x[50005],w[50005];
int t,n;
double f(double t)
{
    double sum = 0.0;
    for(int i = 0; i < n; i++)
    {
        double d = t-x[i];
        if(d < 0) d = -d;
        sum += d*d*d*w[i];
    }
    return sum;
}
int main()
{
    double m1,m2,l,r;
    scanf("%d",&t);
    for(int cas = 1; cas <= t; cas++)
    {
        scanf("%d",&n);
        l = inf;
        r = -inf;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf %lf",&x[i],&w[i]);
            l = min(l,x[i]);
            r = max(r,x[i]);
        }
        while(r-l > eps)
        {
            m1 = l+(r-l)/3;
            m2 = r-(r-l)/3;
            if(f(m1) < f(m2)) r = m2;
            else l = m1;
        }
        printf("Case #%d: %lld\n",cas,ll(f(l)+0.5));
    }
    return 0;
}
