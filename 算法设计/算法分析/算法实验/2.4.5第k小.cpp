/*
����n(1<=n<=1000000)��Ԫ�أ����kС��(1<=k<=n)�� 
һ����������һ��������������n��k���ڶ�������n����ͬ��int��Χ�ڵ����� 
���һ�У������kС���� 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=1000000;
int n,k,a[MAX];
int main()
{
cin>>n>>k;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
cout<<a[k-1];
return 0;
}

