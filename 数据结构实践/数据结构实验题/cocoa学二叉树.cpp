#include<iostream>
using namespace std;
int main()
{
	int n,i,flag=1;
	cin>>n;
	int a[n-1],k[n-1];
	for(i=0;i<n-1;i++)
	{
		cin>>a[i]>>k[i];
	 } 
	for(i=0;i<n-1;)
	{
		if(k[i]!=k[i+1])	
		{
			break;
			flag=0;
		}
		else i+=2;
	}
	if (flag==0) cout<<"NO";
	else cout<<"YES";
	
	return 0;
 } 
 
 
 /*
 #include<iostream>
 using namespace std;
 int main()
 {
 	int n,i;
	cin>>n;
	int a[n-1],k[n-1];
	for(i=0;i<n-1;i++)
	{
		cin>>a[i]>>k[i];
	 } 
	for(i=0;i<n-1;i++)
	{
		int flag=0;	//ע�����ѭ����ÿ�������¿�ʼi��һ�ֶ�Ҫ���¼���������flag��ǰ�涨�廹���ں��涨�壬��û�취����flag��ֵ 
		for(int j=0;j<n-1;j++)
		{
			if(b[i]==b[j])
			{
				flag++; //�Լ����Լ��ȽϵĹ����л���2�Σ�����ýڵ�������Σ��Ƚϴ���Ҳ����2 
			}
		}
		if(flag==1)	//�Ƚϵó����Ľ������ֻ�����Լ����Լ����Լ��Ƚ�1�Ρ� 
		{
			cout<<"NO"<<endl;
			return 0;	//ѧϰһ�����д����ֱ��return 0,�����������������������䶼��ִ�У�����breakֻ����ѭ�����ݡ� 
		}
	}
	cout<<"YES"<<endl;	//�������������������ѭ���Ƚ�һֱ��i=n-2������˵��ÿ���ڽ�㶼�ظ��������Ρ�����ֱ��cout<<yes�� 
	return 0; 
 }
 */
