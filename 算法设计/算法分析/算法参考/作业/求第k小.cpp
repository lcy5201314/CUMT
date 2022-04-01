/*问题 D: 求第k小
题目描述
给定n(1<=n<=1000000)个元素，求第k小数(1<=k<=n)。

输入
一组样例。第一行输入两个整数n和k。第二行输入n个不同的int范围内的数。

输出
输出一行，输出第k小数。

样例输入
5 2
1 5 3 2 4
样例输出
2
题意
如题目描述所示。

思路
最简单的代码：sort()函数排序后输出a[k-1]。

注意：数组太大，不应该在main()中开，而应在全局开。

代码*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
const int MAXN = 1000000;
using namespace std;
int n,k,a[MAXN];
int main()
{
    cin>>n>>k;
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d\n",a[k-1]);
    return 0;
}
