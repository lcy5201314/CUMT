/*问题 E: 配对元素
题目描述
给出2个序列A={a[1]，a[2]，…，a[n]}，B={b[1]，b[2]，…，b[n]}，从A、B中各选出n个元素进行一一配对
（可以不按照原来在序列中的顺序），并使得所有配对元素差的绝对值之和最大。

输入
输入的第1行为1个整数n 第2行包含n个整数，题目中的A序列。 第3行包含n个整数，题目中的B序列。

输出
一个数，最大配对。

3与6配对，2与7配对，5与4配对，6与1配对，绝对值之差和为14 对于10%的数据，有n≤20； 对于30%的数据，有n≤100； 
对于50%的数据，有n≤1000； 对于100%的数据，有n≤10000；a[i]，b[i]≤1000。

样例输入
4
2 5 6 3
1 4 6 7
样例输出
14
题意
思路
Water，Greedy。

先对两个数组排下序，然后用个变量ans存储答案。

为了让差值和最大，那我们就取a中最小和b中最大，a中第二小和b中第二大……

代码*/
#include<iostream>
#include<algorithm
#include<string>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
const int maxn = 1e4 + 5;
int main()
{
    int n,a[maxn],b[maxn],ans = 0;
    scanf("%d",&n);
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int i = 0; i < n; i++)
    {
        ans += abs(a[i]-b[n-1-i]);
    }
    printf("%d\n",ans);
    return 0;
}
