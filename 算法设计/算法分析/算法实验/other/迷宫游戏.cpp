#include <cstdio>
#include <algorithm>
using namespace std;

int a[5][5], ans = 99999;

typedef struct		//��Ҫ��¼·������Ӧ�����ý�����飬ÿ����һ�Σ��������浱ǰ����ֵ�����˳�򽫽��������ɵõ�·�� 
{
	int x;
	int y;
}node;

node path[25], way[25];		 //path���ڴ浱ǰ·����way���ڴ����·�� 

void dfs(node cur, int count)	//״̬Ϊ��ǰ��㣬��ǰ���� 
{
	int i, j, k;
	if(ans > count && cur.x == 4 && cur.y == 4)		//Ѱ����·�� 
	{
		ans = count; 
		for(i = 0;i < count;i++)	//��·����way 
		{
			way[i].x = path[i].x;
			way[i].y = path[i].y;
		}
	}
	else
	{
		for(k = 0;k < 4;k++)	//����4������ 
		{
			i = cur.x, j = cur.y;
			switch(k)
			{
				case 0: i++; break;
				case 1: i--; break;
				case 2: j++; break;
				case 3: j--; break;
			}
			if(i >= 0 && j >= 0 && i <= 4 && j <= 4 && a[i][j] == 0)	//������Χ�����ظ�����������չ�Ľ����� 
			{
				path[count].x = i;		//����չ���浱ǰ����ֵ 
				path[count].y = j;
				a[i][j] = 2;			//��ʾ����·�� 
				dfs(path[count], count+1);	//�Ʋ�������չ����״̬ 
				a[i][j] = 0;			//���� 
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

