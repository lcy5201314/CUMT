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
