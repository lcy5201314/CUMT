/*排序是一种很频繁的计算任务。一个实际的例子是，当我们给某项竞赛的优胜者按金银铜牌排序的时候。在这个任务中可能的值只有三
种1，2和3。我们用交换的方法把他排成升序的。
写一个程序计算出，计算出的一个包括1、2、3三种值的数字序列，排成升序所需的最少交换次数。
输入
输入第1行为类别的数量N（1≤N≤1000）
输入第2行到第N+1行，每行包括一个数字（1或2或3）。
输出
输出包含一行，为排成升序所需的最少交换次数。
样例输入
9
2
2
1
3
3
3
2
3
1
样例输出
4*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x = 0, y = 0, z = 0;
	int num[1005];
	int sum[3] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		sum[num[i] - 1]++;
	}
	for (int i = 0; i < sum[0]; i++)
	{
		if (num[i] != 1)
			x++;
	}
	for (int i = sum[0]; i < sum[0] + sum[1]; i++)
	{
		if (num[i] == 3)
			y++;
	}
	for(int i=sum[0]+sum[1];i<sum[0]+sum[1]+sum[i];i++)
		if (num[i] == 2)
		{
			z++;
		}
	cout << x + max(y, z);
	return 0;
}
