/*


#include<iostream>
#include<algorithm>
using namespace std;
 
int dfs(char* pre,char* in,int n)
{
    if(n == 0) 
    {
        return 0;
    }
    int i;
    for(i = 0; i < n; i++)
    {
        if(in[i] == pre[0])
        {
            break;
        }
    }
    int left = dfs(pre+1,in,i);  
    int right = dfs(pre+i+1,in+i+1,n-i-1);  
    return max(left,right)+1; 
}
int main()
{
    int n;
    while(cin >> n) 
	{
    char pre[n+1],in[n+1];
    cin >> pre >> in;
    cout << dfs(pre,in,n) << endl;
    }
    return 0;
}


*/

/*
#include <iostream>
using namespace std;
void Qs(int ar[], int lo, int hi)
{
	if (hi <= lo) return;
	int i;
	i = lo;
	int j;
	j = hi + 1;
	int k;
	k = ar[lo];
	while (true)
	{
		while (ar[++i] < k)
		{
			if (i == hi) {
				break;
			}
		}
		while (ar[--j] > k)
		{
			if (j == lo) {
				break;
			}
		}
		if (i >= j) break;
		int temp;
		temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}
	int t;
	t = ar[lo];
	ar[lo] = ar[j];
	ar[j] = t;
	Qs(ar, lo, j - 1);
	Qs(ar, j + 1, hi);
}
int main()
{
	int num;
	cin >> num;
	int sd[num];
	for (int i = 0; i < num; i++)cin >> sd[i];
	Qs(sd, 0, num - 1);
	for (int i = 0; i < num; i++)cout << sd[i] << ' ';
	return 0;
}
*/

#include <iostream>
using namespace std;
int QS(int *a[],int i,int j) {
	if (i >= j) return 0;
	int key = a[0],flag=0;
	while (i < j) {
		while (a[j] > key&&j > i) {
			j--;
		}
		key = a[j];
		a[j] = a[flag];
		a[flag] = key;
		flag = j;
		while (a[i]<key&&j>i) {
			i++;
		}
		key = a[i];
		a[i] = a[flag];
		a[flag] = key;
		flag = i;
	}
	QS(a, 0, flag - 1);
	QS(a, flag + 1, N - 1);
	/*
	while (key < a[j] && j < 0) {
		j--;
		if (i == j) {
			QS(a, 0, flag-1);
			QS(a, flag + 1, N - 1);
		}
	}
	*/
}
int main() {
	int N;
	cin >> N;
	while (N > 10000) {
		cout << "输入过大请重新输入" << endl;
		cin >> N;
	}
	int a = new int[N];
	delete[]a;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	QS(a, 0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
