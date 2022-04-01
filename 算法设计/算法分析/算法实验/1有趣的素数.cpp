#include<iostream>
#include<math.h>
using namespace std;
int n=0;
int num=0;
int a[100];       //对应环 
int visit[100];  //标记数组 0表示未用 1表示已用 
int isPrime(int k)  //判断数字x是否为整数 
{
	int i,n;
	n=(int)sqrt(k);
	for(i=2;i<=n;i++)
		if(k%i==0) return 0;
	return 1;     		
}
 
void dfs(int id)
{    //输出条件 
	if(id==n&&isPrime(a[0]+a[n-1])==1) //全部填满而且第一个元素和最后一个元素相加为素数就输出 
	{
		//for(int i=0;i<n;i++)
			//cout<<a[i]<<' ';  //输出素数环 
			//cout<<endl;
			num++;
			return ;
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(visit[i]==0&&isPrime(i+a[id-1])){    //i位置没有被占用 且 与前一个元素相加为素数 
				a[id]=i;         //则将i放入环中 
				visit[i]=1;       //标志位占用 
				dfs(id+1);       //开始下一个数的试探 
				visit[i]=0;      //因为下一个数为i+1，所以值0 
			}
		}
	}
	 
}
int main(void)
{
	while(cin>>n)
{

	visit[100]={0};
	a[0]=1;  //因为是环所以第一个元素固定 
	visit[1]=1; //1已用 
	dfs(1);	//从第一个元素开始 
cout<<num<<endl;
num=0;
}
   
	return 0;	
} 
