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
		int flag=0;	//注意这里，循环是每次在重新开始i的一轮都要重新计数。不管flag在前面定义还是在后面定义，都没办法更新flag的值 
		for(int j=0;j<n-1;j++)
		{
			if(b[i]==b[j])
			{
				flag++; //自己和自己比较的过程中会有2次，如果该节点出现两次，比较次数也会变成2 
			}
		}
		if(flag==1)	//比较得出来的结果就是只出现自己，自己和自己比较1次。 
		{
			cout<<"NO"<<endl;
			return 0;	//学习一下这个写法，直接return 0,结束整个主函数，下面的语句都不执行，比用break只结束循环更狠。 
		}
	}
	cout<<"YES"<<endl;	//如果是满二叉树，整个循环比较一直到i=n-2结束，说明每个节结点都重复出现两次。可以直接cout<<yes了 
	return 0; 
 }
 */
