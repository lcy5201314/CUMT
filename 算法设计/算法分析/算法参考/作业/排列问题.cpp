/*���� B: ��������
��Ŀ����
����һ�����ܺ����ظ��ַ����ַ�������ӡ�����ַ����������ַ���ȫ���С�

����
����������ݣ�����������һ�����Ȳ�����10���ַ����ַ������Զ��Ž�β��

���
��ӡ�����ַ����������ַ���ȫ���С����ֵ���˳��������ÿո�ָ���

��������
abc,
�������
abc acb bac bca cab cba
����
ȥ��,���ӡ�ַ�����ȫ���У��п������ظ��ַ�����

˼·
�ݹ顣

��TLE����һ��set��ȥ��+���򣩱��������ݹ齻����iλ�͵�jλ���ݹ�󻹵ð����ǻ���ȥ���е���dfs����
c++�е�std::set���ǻ��ں������ƽ������������ݽṹʵ�ֵ�һ����������Ϊ������������Ԫ�ص�ֵ��Ψһ�ģ������Ҫ����ȥ��
������

���ǣ��б�������������ᳬʱ��ԭ������Ǻ�̨���������󡢴���̫��������㡢����cin��cout�����������淢�������Դ�����
����������next_permutation()���𾪣�����Ϊ�˱����ظ������ӣ���ʵ�������Լ�ģ�����������������⺯����
ע�⣺������cin��cout����һ��TLE��������stdio�ɣ�

����1��TLE��
//set����
#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
string str;
int len;
set<string> s;
void f(int i)
{
    if(i != len)
    {
        s.insert(str);
        for(int j = i; j < len; j++)
        {
            swap(str[i],str[j]);
            f(i+1);
            swap(str[i],str[j]);
        }
    }
}
int main()
{
    cin>>str;
    len = str.length() - 1;
    str.resize(len);
    f(0);
    set<string>::iterator it = s.begin();
    cout<<*it;
    it++;
    for(;it != s.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}
����2*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char str[15];
    scanf("%s",str);
    int len = strlen(str)-1;
    str[len] = '\0';
    sort(str,str+len);
    printf("%s",str);
    while(next_permutation(str,str+len))
    {
        printf(" %s",str);
    }
    printf("\n");
    return 0;
}
