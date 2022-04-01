/*问题 D: 图的m着色问题
题目描述
给定无向连通图G和m种不同的颜色，用这些颜色给图的各个顶点着一种颜色，若某种方案使得图中每条边的2个顶点的颜色都不相同，
则是一个满足的方案，找出所有的方案。

输入
第一行有3个正整数n，k和m，分别表示n个顶点，k条边，m种颜色
接下来k行，每行2个正整数，表示一条边的两个顶点

输出
所有不同的着色方案数

样例输入
5 8 4 
1 2
1 3 
1 4
2 3
2 4
2 5
3 4
4 5
样例输出
48
题意
给定一个图、颜色数，求方案数。

思路
用邻接矩阵存图：1表示点i和点j间有边。

dfs，每次看目前设的颜色是否符合条件，若符合则进入下一层。

代码*/
#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 2e3 + 5;
int n,k,m,ans;
int map[maxn][maxn];
int color[maxn];
void dfs(int d)
{
    if(d == n+1)
    {
        ans++;
        return;
    }
    for(int i = 1; i <= m; i++)     //颜色m种
    {
        bool flag = true;
        for(int j = 1; j <= n; j++)     //n个点
        {
            if(map[d][j] && color[j] == i)  //连通且颜色为i则失败
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            color[d] = i;   //染色
            dfs(d+1);       //下一结点
            color[d] = 0;   //回到未染色状态
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for(int i = 0; i < k; i++)
    {
        int tmp1,tmp2;
        scanf("%d %d",&tmp1,&tmp2);
        map[tmp1][tmp2] = 1;
        map[tmp2][tmp1] = 1;
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
