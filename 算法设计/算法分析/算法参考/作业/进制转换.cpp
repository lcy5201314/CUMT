/*问题 A: 进制转换
题目描述
输入一个十进制正整数，然后输出它所对应的八进制数。

输入
输入一个十进制正整数n(1≤n≤106) 。

输出
输出n对应的八进制数，输出在一行。

样例输入
10
样例输出
12
题意
输入十进制，输出八进制。

思路
Water，可直接用cout<<oct<<n<<endl;，也可以printf("%o\n",n);，也可以自己写一个转换进制的递归函数。

代码1
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    printf("%o\n",n);
    //cout<<oct<<n<<endl;
    return 0;
}
代码2*/
#include<iostream>
using namespace std;
char* tbl="0123456789ABCDEF";
void f(int dec,int base)
{
    if(dec)
    {
        f(dec/base,base);
        cout<<tbl[dec%base];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    f(n,8);
    printf("\n");
    return 0;
}
