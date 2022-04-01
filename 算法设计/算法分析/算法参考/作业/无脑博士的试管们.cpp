/*问题 E: 无脑博士的试管们
题目描述
无脑博士有三个容量分别是 A,B,C 升的试管，A,B,C分别是三个从 1到 20的整数，最初，A 和 B 试管都是空的，而 C 试管是装满
硫酸铜溶液的。有时，无脑博士把硫酸铜溶液从一个试管倒到另一个试管中，直到被灌试管装满或原试管空了。当然每一次灌注都是
完全的。由于无脑博士天天这么折腾，早已熟练，溶液在倒的过程中不会有丢失。

写一个程序去帮助无脑博士找出当 A 试管是空的时候，C 试管中硫酸铜溶液所剩量的所有可能性。

输入
多组测试用例，对于每组测试用例，输入包括一行，为空格分隔开的三个数，分别为整数 A,B,C。

输出
输出包括一行，升序地列出当 A 试管是空的时候，C 试管溶液所剩量的所有可能性。

样例输入
2 5 10
样例输出
5 6 7 8 9 10
题意
如题目描述所示，给定三个试管的最大容量。

一开始试管a、b都为空，c满。

求a空时c的可能取值，按从小到大排序。

思路
采用数据结构set<int>存储答案（去重+排序）。

因为有3个试管，所以倒水的方法有6种，暴力写出每种可能，dfs。

三位数组visited的意义：走过的点就不需要再走了，没有的话没法停止。

代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
set<int> s;
int na,nb,nc;
bool visited[25][25][25];
void dfs(int a,int b,int c)
{
    if(visited[a][b][c]) return;
    visited[a][b][c] = true;
    if(!a) s.insert(c);
    if(a <= nb-b) dfs(0,a+b,c);
    else dfs(a-nb+b,nb,c);
    if(b <= na-a) dfs(a+b,0,c);
    else dfs(na,a-na+b,c);
    if(a <= nc-c) dfs(0,b,a+c);
    else dfs(a-nc+c,b,nc);
    if(c <= na-a) dfs(a+c,b,0);
    else dfs(na,b,c-na+a);
    if(b <= nc-c) dfs(a,0,b+c);
    else dfs(a,b-nc+c,nc);
    if(c <= nb-b) dfs(a,b+c,0);
    else dfs(a,nb,c-nb+b);
}
int main()
{
    while(~scanf("%d %d %d",&na,&nb,&nc))
    {
        s.clear();
        memset(visited,0,sizeof(visited));
        dfs(0,0,nc);
        set<int>::iterator it = s.begin();
        printf("%d",*it);
        it++;
        for(; it != s.end(); it++)
        {
            printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}
