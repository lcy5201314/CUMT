/*在一个数组中找出和最大的连续几个数。（至少包含一个数）

例如：

数组A[] = [-2,1,-3,4,-1,2,1,-5,4]，则连续的子序列[4,-1,2,1]有最大的和6.


输入
第一行输入一个不超过1000的整数n。

第二行输入n个整数A[i]。

输出
输出一个整数，表示最大的和。

样例输入
3
1 1 -2
样例输出
2*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
 
    int i;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
 
    int j;
    int sumPrevious=0,sum=arr[0];
    for(j=0;j<n;j++)
    {
        if(sumPrevious<0)
            sumPrevious=arr[j];
        else
            sumPrevious+=arr[j];
 
        if(sum < sumPrevious)
            sum = sumPrevious;
    }
    cout << sum;
    return 0;
}


