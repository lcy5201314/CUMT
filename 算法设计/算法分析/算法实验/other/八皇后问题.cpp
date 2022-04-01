/*问题 C: 八皇后问题
题目描述
努比亚和苏丹没有子女，所以他要从一些有集成资格的继承者中挑选一个出来继承王位。他希望这个继承者足够聪明，所以他准备了
一个西洋棋盘，上面的每个格子中均有一个 1-99 的数字。他又准备了 8 个皇后棋子。

8 皇后的规则就是不能有任何棋子同行或者同列或者同斜线，在满足这个规则的同时，王位继承者还需要让 8 个皇后所在的位置的数字
的和是最大的。

输入
输入一个数字 k(k≤20)，代表棋盘的数量。

接下来有 k 个棋盘，每个棋盘有 64 个数字，分成 8 行 8 列输入，具体可见样例，每一个数字均小于 100。

输出
每一个棋盘对应输出最大的数值， 一共输出 k行

样例输入
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
样例输出
260
题意
n皇后问题变种，固定n == 8，棋盘上每个位置都有相应权值，求总权值最大的可行解。

思路
dfs。

用一个变量记录最大值，每次找到可行解若大于最大值则更新最大值。

代码*/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int map[8][8],x[8],ans,sum;
bool check(int xx,int yy)
{
    for(int i = 0; i < xx; i++)
    {
        if(yy == x[i]) return false;
        if(abs(xx - i) == abs(yy - x[i])) return false;
    }
    return true;
}
void queen(int n)
{
    if(n == 8){ans = max(ans,sum);return;}
    for(int i = 0; i < 8; i++)
    {
        if(check(n,i))
        {
            x[n] = i;
            sum += map[n][i];
            queen(n+1);
            x[n] = -1;
            sum -= map[n][i];
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        sum = 0;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                scanf("%d",&map[i][j]);
        memset(x,-1,sizeof(x));
        queen(0);
        printf("%d\n",ans);
    }
    return 0;
}
