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
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int main()
{
    int t,n,len;
    char str[maxn];
    cin>>t;
    while(t--)
    {
        cin>>str>>n;
        n %= 26;
        len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = 'A'+(str[i]-'A'-n+26)%26;
            else if(str[i] >= 'a' && str[i] <= 'z')
                str[i] = 'a'+(str[i]-'a'-n+26)%26;
        }
        cout<<str<<endl;
    }
    return 0;
}
