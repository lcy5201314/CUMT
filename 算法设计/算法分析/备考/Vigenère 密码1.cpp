/*第一行为一个字符串，表示密钥 kk，长度不超过 100100，其中仅包含大小写字母。

第二行为一个字符串，表示经加密后的密文，长度不超过 10001000，其中仅包含大小写字母。

输出
输出共 11 行，一个字符串，表示输入密钥和密文所对应的明文。
样例输入
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm
样例输出
Wherethereisawillthereisaway*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char k[105],s[1005];//k为密钥，a为密文 
	int i;
	cin>>k>>s;
	int len=strlen(k);//算出密钥长度 
	for(i=0;i<len;i++)
	{
	    k[i]=tolower(k[i]);//tolower函数：将密钥全部改为小写字母 
	}
	char ans;
	for(i=0;s[i]!=0;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			ans=(s[i]-'a'-(k[i%len]-'a')+26)%26+'a';//若i大于len即密文长度大于密钥长度时k[i%len]实现重复利用密钥 
		}                               			//s[i]-'a'为密文字母的asc值；k[i%len]-'a'为密钥字母的asc值
		else 										//+26防止出现负值 
		ans=(s[i]-'A'-(k[i%len]-'a')+26)%26+'A';
		cout<<ans;
	}
	cout<<endl;
	return 0;	
}
