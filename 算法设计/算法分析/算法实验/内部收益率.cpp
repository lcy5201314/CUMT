/*题目两边等式同乘 (1+IRR)T。则原题相当于求：CF0(1+IRR)T+CF1(1+IRR)T?1+?+CFT=0 的解，则可使用二分法。

L 初始值取 -1.0，R 初始值取常规正无穷大（一般取 0x3F3F3F3F）。
*/ 
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
int main()
{
    int t;
    double cf[13],l,r,m;
    while(~scanf("%d",&t) && t)
    {
        for(int i = 0; i <= t; i++)
        {
            scanf("%lf",&cf[i]);
        }
        l = -1.00;
        r = inf;
        while(r-l > eps)
        {
            m = (l+r)/2;
            double sum = 0.0;
            for(int i = 0; i <= t; i++)
            {
                sum += cf[i]*pow(1+m,t-i);
            }
            if(sum > 0) l = m;
            else r = m;
        }
        printf("%.2lf\n",l);
    }
    return 0;
}
