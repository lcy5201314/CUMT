/*���� A: ����ת��
��Ŀ����
����һ��ʮ������������Ȼ�����������Ӧ�İ˽�������

����
����һ��ʮ����������n(1��n��106) ��

���
���n��Ӧ�İ˽������������һ�С�

��������
10
�������
12
����
����ʮ���ƣ�����˽��ơ�

˼·
Water����ֱ����cout<<oct<<n<<endl;��Ҳ����printf("%o\n",n);��Ҳ�����Լ�дһ��ת�����Ƶĵݹ麯����

����1
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    printf("%o\n",n);
    //cout<<oct<<n<<endl;
    return 0;
}
����2*/
#include<iostream>
using namespace std;
char* tbl="0123456789ABCDEF";
void f(int dec,int base)
{
    if(dec)
    {
        f(dec/base,base);
        cout<<tbl[dec%base];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    f(n,8);
    printf("\n");
    return 0;
}
