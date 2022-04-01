#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char maze[100][101];
int nxt[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int stx = 0, sty = 0, ex = 0, ey = 0;
int n, m;
int steps[100][100];
bool check(int x, int y)
{
    if (x >= n || y >= m || x < 0 || y < 0 )
        return 1;
    else
        return 0;
}
void bfs(int x, int y, int z, int k)
{
    queue<pair<int, int > > q;
    int xx, yy;
    pair<int, int> head, tail;
    steps[x][y] = 1;
    q.push(make_pair(x, y));
    while(!q.empty())
    {
        head = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            xx = head.first + nxt[i][0];
            yy = head.second + nxt[i][1];
            if (check(xx, yy))
                continue;
            if ((steps[xx][yy] == 0 && maze[xx][yy] == '-') || maze[xx][yy] == 'E')
            {
                tail.first = xx;
                tail.second = yy;
                steps[xx][yy] = steps[head.first][head.second] + 1;
                q.push(tail);
                if (xx == z && yy == k)
                {
                    return;
                }
            }
            

        }
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        stx = 0;
        sty = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m;j++)
            {
                if (maze[i][j] == 'S')
                {
                    stx = i;
                    sty = j;
                }
                if(maze[i][j]=='E')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        bfs(stx, sty, ex, ey);
        cout << steps[ex][ey] - 1 << endl;
    }
    return 0;
}
