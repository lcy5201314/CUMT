/*
给定n(1<=n<=1000000)个元素，求第k小数(1<=k<=n)。 
一组样例。第一行输入两个整数n和k。第二行输入n个不同的int范围内的数。 
输出一行，输出第k小数。 
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

