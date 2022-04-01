/*问题 D: 组合运算式
题目描述
请考虑一个被空格分隔的，由1到N的整数组成的递增数列：1 2 3 …N。现在请在数列中插入表示加的“+”，或者表示减“-”，
亦或者表示空白的“ ”(例如1-2 3就等于1-23)，来将每一对数字组合成一个表达式（第一个数字前无空格）。计算该表达式的结果
并判断其值是否为0。请你写一个程序找出所有产生和为零的长度为N的数列。

输入
输入为一行，包含一个整数N，3≤N≤9。

输出
输出为所有在每对数字间插入“+”, “-”, 或 “ ”后能得到和为零的数列，并按照字典（ASCII码）序排列。

样例输入
7
样例输出
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
题意
三种填充方式，ASCII从小到大分别为' '（空格）、+、'-'。

按字典序输出可行解（使最终答案为0），其中空格代表拼接。

思路
dfs，用一个参数int pre存储本次增量（遇到空格的时候有用）。

遇到空格的时候往回推。

代码*/
#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int OP[15] = {1,1};
void dfs(int d,int sum,int pre)
{
    sum += pre;
    if(d == n)
    {
        if(!sum)
        {
            printf("1");
            for(int i = 2; i <= n; i++)
            {
                if(!OP[i]) printf(" %d",i);
                else if(OP[i] == 1) printf("+%d",i);
                else printf("-%d",i);
            }
            printf("\n");
        }
        return;
    }
    OP[d+1] = 0;
    if(pre >= 0) dfs(d+1,sum-pre,pre*10+d+1);
    else dfs(d+1,sum-pre,pre*10-d-1);
    OP[d+1] = 1;
    dfs(d+1,sum,d+1);
    OP[d+1] = 2;
    dfs(d+1,sum,-d-1);
}
int main()
{
    scanf("%d",&n);
    dfs(1,0,1);
    return 0;
}
