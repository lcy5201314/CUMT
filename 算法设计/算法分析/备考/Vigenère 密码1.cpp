/*��һ��Ϊһ���ַ�������ʾ��Կ kk�����Ȳ����� 100100�����н�������Сд��ĸ��

�ڶ���Ϊһ���ַ�������ʾ�����ܺ�����ģ����Ȳ����� 10001000�����н�������Сд��ĸ��

���
����� 11 �У�һ���ַ�������ʾ������Կ����������Ӧ�����ġ�
��������
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm
�������
Wherethereisawillthereisaway*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char k[105],s[1005];//kΪ��Կ��aΪ���� 
	int i;
	cin>>k>>s;
	int len=strlen(k);//�����Կ���� 
	for(i=0;i<len;i++)
	{
	    k[i]=tolower(k[i]);//tolower����������Կȫ����ΪСд��ĸ 
	}
	char ans;
	for(i=0;s[i]!=0;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			ans=(s[i]-'a'-(k[i%len]-'a')+26)%26+'a';//��i����len�����ĳ��ȴ�����Կ����ʱk[i%len]ʵ���ظ�������Կ 
		}                               			//s[i]-'a'Ϊ������ĸ��ascֵ��k[i%len]-'a'Ϊ��Կ��ĸ��ascֵ
		else 										//+26��ֹ���ָ�ֵ 
		ans=(s[i]-'A'-(k[i%len]-'a')+26)%26+'A';
		cout<<ans;
	}
	cout<<endl;
	return 0;	
}
