/*���� D: ���kС
��Ŀ����
����n(1<=n<=1000000)��Ԫ�أ����kС��(1<=k<=n)��

����
һ����������һ��������������n��k���ڶ�������n����ͬ��int��Χ�ڵ�����

���
���һ�У������kС����

��������
5 2
1 5 3 2 4
�������
2
����
����Ŀ������ʾ��

˼·
��򵥵Ĵ��룺sort()������������a[k-1]��

ע�⣺����̫�󣬲�Ӧ����main()�п�����Ӧ��ȫ�ֿ���

����*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
const int MAXN = 1000000;
using namespace std;
int n,k,a[MAXN];
int main()
{
    cin>>n>>k;
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d\n",a[k-1]);
    return 0;
}
