/*��һ���������ҳ������������������������ٰ���һ������

���磺

����A[] = [-2,1,-3,4,-1,2,1,-5,4]����������������[4,-1,2,1]�����ĺ�6.


����
��һ������һ��������1000������n��

�ڶ�������n������A[i]��

���
���һ����������ʾ���ĺ͡�

��������
3
1 1 -2
�������
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


