/*    输入包含多组数据，其中第一行为数据组数T（T<=10）
        每组数据第一行为一个字符串S，由数字、字母以及常见字符组成（不含空格），第二行为一个整数k代表加密时向后的偏移量
		（|S|<=1000000,-1000000000<=k<=1000000000）
输出
        对每组数据，输出一行字符串，代表输入中的密文对应的明文。

样例输入
1
DEFGHIJKLMNOPQRSTUVWXYZABC
3
样例输出
ABCDEFGHIJKLMNOPQRSTUVWXYZ*/ 
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char num[1000000];
		int k;
		cin>>num;
		cin>>k;
		k=k%26;
		for(int i=0;i<strlen(num);i++)
		{
			if(num[i]>='A'&&num[i]<='Z') //A-Z 
			{
				num[i]=num[i]-k;
//			 	while(1)
//				{
//				if(num[i]>'Z')
//				num[i]-=26;
//				else break;
//				}
				while(1)
				{
				if(num[i]<'A')
				num[i]+=26;
				else break;
			}
		}
		else if(num[i]>='a'&&num[i]<='z')//a-z
			{
				num[i]=num[i]-k;
			
//			while(1)
//			{
//				if(num[i]>'z')
//				num[i]-=26;
//				else break;
//			}
			while(1)
			{
				if(num[i]<'a')
				num[i]+=26;
				else break;
			}
		}
			
		cout<<num[i];
		 } 
		 cout<<endl;
}
return 0;
}
