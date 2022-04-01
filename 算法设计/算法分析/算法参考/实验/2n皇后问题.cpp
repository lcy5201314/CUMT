/*问题 C: 2n皇后问题
题目描述
给定一个 n\n*的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入 n 个黑皇后和 n个白皇后，使任意的两个黑皇后都不在
同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n 小于等于 8。

输入
输入的第一行为一个整数 n，表示棋盘的大小。

接下来 n 行，每行 n 个 0 或 1 的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为 0，表示对应的位置不可以
放皇后。

输出
输出一个整数，表示总共有多少种放法

样例输入
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
2
题意
n皇后问题++，有两种颜色的皇后，同色间互相满足n皇后问题条件（不同行、列、对角），注意任意两个棋子不能放同一个位置。

思路
dfs。

代码*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 10;
int map[maxn][maxn];
int x1[maxn],x2[maxn],ans,n;
bool check1(int xx,int yy)
{
    if(!map[xx][yy]) return false;
    for(int i = 0; i < xx; i++)
    {
        if(yy == x1[i]) return false;
        if(abs(xx - i) == abs(yy - x1[i])) return false; //斜对角
    }
    return true;
}
bool check2(int xx,int yy)
{
    if(!map[xx][yy]) return false;
    for(int i = 0; i < xx; i++)
    {
        if(yy == x2[i]) return false;
        if(abs(xx - i) == abs(yy - x2[i])) return false; //斜对角
    }
    return true;
}
void queen(int l)
{
    if(l == n)
    {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(check1(l,i))
        {
            x1[l] = i;
            map[l][i] = 0;
            for(int j = 0; j < n; j++)
            {
                if(check2(l,j))
                {
                    x2[l] = j;
                    queen(l+1);
                    x2[l] = -1;
                }
            }
            map[l][i] = 1;
            x1[l] = -1;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    ans = 0;
    queen(0);
    printf("%d",ans);
    return 0;
}
