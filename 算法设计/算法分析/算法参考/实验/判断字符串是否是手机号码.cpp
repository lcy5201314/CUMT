/*���� A: �ж��ַ����Ƿ����ֻ�����
��Ŀ����
�ֻ�������һ�����֣�����Ϊ 11 λ�����ҵ�һλ������ 1�����ڸ���һ���ַ�����������Ҫ�ж�����ַ����Ƿ�����ֻ���ʽ��
����
����������ݡ�ÿ����������һ���ַ�����
���
�����ַ��������ֻ������ʽ����� 1��������� 0��
��������
12345612345
�������
1
����
Water������һ���ַ������ж��ַ����ǲ���һ���ֻ����롣
˼·
���ɷ�װ��һ������ bool �� check() �����У������������棺
�ǲ��� 11 λ��
��λ�ǲ���Ϊ ��1����
ÿλ�ǲ������֡�
����*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool check(char str[])
{
    if(strlen(str) != 11) return false;
    if(str[0] != '1') return false;
    for(int i = 0; i < 11; i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
int main()
{
    char str[999999];
    while(~scanf("%s",str))
    {
        if(check(str)) puts("1");
        else puts("0");
    }
    return 0;
}
