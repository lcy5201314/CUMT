/*问题 A: 元素整除问题
题目描述
输入20个整数，输出其中能被数组中其它元素整除的那些数组元素。

输入
输入20个整数

输出
按输入顺序输出符合要求的数字，每行输出一个整数。

样例输入
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
样例输出
4
6
8
9
10
12
14
15
16
18
20
21
题意
如题目描述所示。

思路
两层for循环，是的话直接输出并break。

代码*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a[20];
    for(int i = 0; i < 20; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(i != j && a[i]%a[j] == 0 )
            {
                printf("%d\n",a[i]);
                break;
            }
        }
    }
    return 0;
}
