#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
bool f(string k)
{
	string s;
	s=k;
	reverse(k.begin(),k.end());//k数组左右颠倒 （是algorithm的函数） 
	if(k==s)
	return true;
	else return false;
}
string dtox(int digital,int r)//n进制转化 
{
	string result="";
	const char s[37]="0123456789abcdefghijklmnopqrstuvwxyz";
	if(digital==0){
		return "0";
	}
	while(digital!=0){
		int tmp =digital%r;
		result+=s[tmp];
		digital/=r;
	}
	reverse(result.begin(),result.end());
	return result;
}
int main()
{
int e,k,flag=0,i=0;
	
	while((cin>>e)&&(e!=0))
{
     for(int r=2;r<=16;r++)
	{
	if(f(dtox(e,r))==true)
	flag=1;
    }
	if(flag==0)
	cout<<"Number "<<e<<" is not a palindrom"<<endl;
	else 
	{cout<<"Number "<<e<<" is palindrom in basis ";
	for(int r=2;r<=16;r++)
	{
	if(f(dtox(e,r))==true)
    cout<<r<<" ";
    }
    cout<<endl;
	}
	flag=0;	
}
return 0;

}
