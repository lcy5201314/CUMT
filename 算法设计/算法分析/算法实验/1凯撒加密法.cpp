/*    ��������������ݣ����е�һ��Ϊ��������T��T<=10��
        ÿ�����ݵ�һ��Ϊһ���ַ���S�������֡���ĸ�Լ������ַ���ɣ������ո񣩣��ڶ���Ϊһ������k�������ʱ����ƫ����
		��|S|<=1000000,-1000000000<=k<=1000000000��
���
        ��ÿ�����ݣ����һ���ַ��������������е����Ķ�Ӧ�����ġ�

��������
1
DEFGHIJKLMNOPQRSTUVWXYZABC
3
�������
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
