#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char str[10];
    cin>>str;
    int len = strlen(str)-1;
    str[len] = '\0';
    sort(str,str+len);
    cout<<str;
    //next_permutation����������ĸ��˳�����ɸ������е���һ���ϴ�����У�ֱ����������Ϊ����Ϊֹ
    while(next_permutation(str,str+len))
    {
        cout<<" "<<str;
    }
    cout<<endl;
    return 0;
}
