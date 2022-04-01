#include <cstdio>
#include <algorithm>
using namespace std;

int a[5][5], ans = 99999;

typedef struct		//若要记录路径，则应该运用结点数组，每遍历一次，就往结点存当前坐标值，最后按顺序将结点输出即可得到路径 
{
	int x;
	int y;
}node;

node path[25], way[25];		 //path用于存当前路径，way用于存最短路径 

void dfs(node cur, int count)	//状态为当前结点，当前步数 
{
	int i, j, k;
	if(ans > count && cur.x == 4 && cur.y == 4)		//寻到短路径 
	{
		ans = count; 
		for(i = 0;i < count;i++)	//存路径给way 
		{
			way[i].x = path[i].x;
			way[i].y = path[i].y;
		}
	}
	else
	{
		for(k = 0;k < 4;k++)	//遍历4个方向 
		{
			i = cur.x, j = cur.y;
			switch(k)
			{
				case 0: i++; break;
				case 1: i--; break;
				case 2: j++; break;
				case 3: j--; break;
			}
			if(i >= 0 && j >= 0 && i <= 4 && j <= 4 && a[i][j] == 0)	//不超范围，不重复遍历，则扩展的结点可走 
			{
				path[count].x = i;		//给扩展结点存当前坐标值 
				path[count].y = j;
				a[i][j] = 2;			//标示已走路径 
				dfs(path[count], count+1);	//移步到该扩展结点的状态 
				a[i][j] = 0;			//回溯 
			} 
		}
	}
}

int main()
{
	int i, j;
	for(i = 0;i < 5;i++)
	for(j = 0;j < 5;j++)
	scanf("%d",&a[i][j]);
	path[0].x = 0, path[0].y = 0;
	dfs(path[0], 1);
	for(i = 0;i < ans;i++)
	printf("(%d, %d)\n",way[i].x, way[i].y);
	return 0;
}

