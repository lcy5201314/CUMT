#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int N=0,i=0;
	cin>>N;
	string s[27];
	for(i=0;i<N;i++)
	{
		cin>>s[i];
	}
	sort(s,s+N);//����algorithm,sort(a,a=10,)�������ղ���Ϊ��������cmp��Ϊ���� 
	for(i=0;i<N;i++)
	{
		cout<<s[i]<<' ';
	}
	return 0;
}
