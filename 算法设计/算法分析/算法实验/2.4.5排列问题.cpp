/*��Ŀ����
����һ�����ܺ����ظ��ַ����ַ�������ӡ�����ַ����������ַ���ȫ���С�

����
����������ݣ�����������һ�����Ȳ�����10���ַ����ַ������Զ��Ž�β��

���
��ӡ�����ַ����������ַ���ȫ���С����ֵ���˳��������ÿո�ָ���

��������
abc,
�������
abc acb bac bca cab cba*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[10];
	cin>>str;
	int len=strlen(str)-1;   //��ĸ���� 
	str[len]=' ';            //�ո�ָ� 
	sort(str,str+len);        //�������� 
    cout<<str;
	while(next_permutation(str,str+len))	//next_permutation����������ĸ��˳�����ɸ������е���һ���ϴ�����У�ֱ����������Ϊ����Ϊֹ
	{
		cout<<" "<<str;
	}
	cout<<endl;
	return 0;
}
