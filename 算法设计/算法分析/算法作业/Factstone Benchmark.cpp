#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int y = 0;
	while (cin >> y && y)
	{
		double  a = log2(4.0);
		for (int i = 1960; i <= y; i += 10)
			a *= 2;
		double  f = 0;
		int i = 0;
		while(f < a)
		{
			++i;
			f += log2(double(i*1.0));
		}
		cout << i - 1 << endl;
	}
	return 0;
}

