#include<iostream>
#include<math.h>
using namespace std;
int n=0;
int num=0;
int a[100];       //��Ӧ�� 
int visit[100];  //������� 0��ʾδ�� 1��ʾ���� 
int isPrime(int k)  //�ж�����x�Ƿ�Ϊ���� 
{
	int i,n;
	n=(int)sqrt(k);
	for(i=2;i<=n;i++)
		if(k%i==0) return 0;
	return 1;     		
}
 
void dfs(int id)
{    //������� 
	if(id==n&&isPrime(a[0]+a[n-1])==1) //ȫ���������ҵ�һ��Ԫ�غ����һ��Ԫ�����Ϊ��������� 
	{
		//for(int i=0;i<n;i++)
			//cout<<a[i]<<' ';  //��������� 
			//cout<<endl;
			num++;
			return ;
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(visit[i]==0&&isPrime(i+a[id-1])){    //iλ��û�б�ռ�� �� ��ǰһ��Ԫ�����Ϊ���� 
				a[id]=i;         //��i���뻷�� 
				visit[i]=1;       //��־λռ�� 
				dfs(id+1);       //��ʼ��һ��������̽ 
				visit[i]=0;      //��Ϊ��һ����Ϊi+1������ֵ0 
			}
		}
	}
	 
}
int main(void)
{
	while(cin>>n)
{

	visit[100]={0};
	a[0]=1;  //��Ϊ�ǻ����Ե�һ��Ԫ�ع̶� 
	visit[1]=1; //1���� 
	dfs(1);	//�ӵ�һ��Ԫ�ؿ�ʼ 
cout<<num<<endl;
num=0;
}
   
	return 0;	
} 
