/*问题 C: 矩形滑雪场
题目描述
zcb喜欢滑雪。他来到了一个滑雪场，这个滑雪场是一个矩形，为了简便，我们用r行c列的矩阵来表示每块地形。为了得到更快的速度，
滑行的路线必须向下倾斜。 例如样例中的那个矩形，可以从某个点滑向上下左右四个相邻的点之一。例如24-17-16-1，
其实25-24-23…3-2-1更长，事实上这是最长的一条。

输入
第1行:两个数字r，c(1 ≤ r, c ≤ 100)，表示矩阵的行列。第2..r+1行:每行c个数，表示这个矩阵。

输出
仅一行:输出1个整数，表示可以滑行的最大长度。

样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
25
题意
沿着滑行路线，高度必须越来越低。滑行可以选择四个方向：上、下、左、右，求最长路线的长度。

思路
思路一：深搜。
先设三个二维数组：

h[i][j]数组用于存储每个点的高度；
l[i][j]数组用于存储从每一点出发可以得到的最长路线的长度；
visited[i][j]数组用于判断第i行第j列的点是否走过。
我们可以开个4*2的数组dir[i][j]用来存储方向：

向右：1,0
向下：0,1
向左：-1,0
向上：0,-1
我习惯写一个bool check(int x,int y)函数用来判断当前的点是否在界内

若是，返回true；
否则，返回false。
显然，它的判断条件为if(x > 0 && x <= r && y > 0 && y <= c)。

关键，dfs()函数怎么写？

我们这里的dfs()函数和常规的dfs()函数稍有不同，它的流程大概如下：

假如该点已经访问过了，则不需要做下去了，直接return；
if(visited[x][y]) return;
把当前点的visited置为true；
visited[x][y] = true;
接下来就开始遍历周围的点(xx,yy)，递归调用dfs()，如果发现周围的点更矮，那就让当前l[x][y]和l[xx][yy]做一下max赋给l[x][y]。
最后，l[x][y]中存储的就是从(x,y)出发的最大滑行长度，我们遍历下就可以得到最终答案。

思路二：降维
二维数组，一看就很难的样子，那我们就把它降维打击一下。二维->一维。

怎么实现呢？

定义结构体node，存储坐标x，y和高度h；
一般在定义后在}和;之间直接定义数组
写一个bool check(int i,int j)函数，用来判断两点是否为相邻点（上、下、左、右）；
以上为main()函数中的实现做铺垫。

输入时怎么处理？直接两层for：（比较巧妙）
a[n].x = i;
a[n].y = j;
scanf("%d",&a[n].h);
输入完后sort()一下，注意在结构体中重载下<，按h从大到小排；
这样就有点像DP：最长上升子序列问题了
初始化dp[i] = 1
此时，对于第i个结点，前面的结点j的h都更大，那就判断下每个点是否是相邻点（前面定义的check()函数），若是，则执行dp[i] = max(dp[i],dp[j]+1);
最后的ans是dp[i]数组的最大值
代码1（深搜）
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 105;
int r,c;
int h[maxn][maxn],l[maxn][maxn];
bool visited[maxn][maxn];
int dir[4][2] = {1,0, 0,1, -1,0, 0,-1};
bool check(int x,int y)
{
    if(x > 0 && x <= r && y > 0 && y <= c) return true;
    return false;
}
void dfs(int x,int y)
{
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int xx = x+dir[i][0];
        int yy = y+dir[i][1];
        if(check(xx,yy) && h[x][y] > h[xx][yy])
        {
            dfs(xx,yy);
            l[x][y] = max(l[x][y],l[xx][yy]+1);
        }
    }
}
int main()
{
    scanf("%d %d",&r,&c);
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            scanf("%d",&h[i][j]);
            l[i][j] = 1;
        }
    }
    int ans = -1;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            dfs(i,j);
            ans = max(ans, l[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
代码2（降维）*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int mod=1e9+7;
const int inf=0x7f7f7f7f;
const int maxn=5e4+50;
struct node
{
    int x,y,h;
    bool operator < (const node &c) const
    {
        return h > c.h;
    }
}a[maxn];
int dp[maxn];
int r,c;
bool check(int i,int j)
{
    if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) == 1)  //判断是否是相邻点
        return true;
    return false;
}
int main()
{
    scanf("%d%d",&r,&c);
    int n = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1;j <= c; j++)
        {
            a[n].x = i;
            a[n].y = j;
            scanf("%d",&a[n].h);
            n++;
        }
    }
    sort(a,a+n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(check(i,j))
                dp[i] = max(dp[i],dp[j]+1);
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
