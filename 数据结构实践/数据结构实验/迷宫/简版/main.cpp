#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
 
int ex = 0, ey = 0,sx = 0, sy = 0;
int ne[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
char map[100][101];
int step[100][100];
 
bool check(int a, int b)
{
    if (a >= n || b >= m || a < 0 || b < 0 )
        return 1;
    else
        return 0;
}
 
void bfs(int x, int y, int z, int k)
{
    int x1, y1;
    step[x][y] = 1;
    queue<pair<int, int> > q;
    pair<int, int> head, tail;
    q.push(make_pair(x, y));
    while(!q.empty())
    {
        head = q.front();
        q.pop();
        for (int j = 0; j < 4; j++)
        {
            x1 = head.first + ne[j][0];
            y1 = head.second + ne[j][1];
            if (check(x1, y1))
                continue;
            if ((step[x1][y1] == 0 && map[x1][y1] == '-') || map[x1][y1] == 'E')
            {
                tail.first = x1;
                tail.second = y1;
                step[x1][y1] = step[head.first][head.second] + 1;
                q.push(tail);
                if (x1 == z && y1 == k)
                {
                    return;
                }
            }
             
 
        }
    }
}
 
 
int main()
{
    int A;
    cin >> A;
    while(A--)
    {
        sx = 0;
        sy = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> map[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m;j++)
            {
                if (map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                if(map[i][j]=='E')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        bfs(sx, sy, ex, ey);
        cout << step[ex][ey] - 1 << endl;
    }
    return 0;
}

