/*���� E: ���Բ�ʿ���Թ���
��Ŀ����
���Բ�ʿ�����������ֱ��� A,B,C �����Թܣ�A,B,C�ֱ��������� 1�� 20�������������A �� B �Թܶ��ǿյģ��� C �Թ���װ��
����ͭ��Һ�ġ���ʱ�����Բ�ʿ������ͭ��Һ��һ���Թܵ�����һ���Թ��У�ֱ�������Թ�װ����ԭ�Թܿ��ˡ���Ȼÿһ�ι�ע����
��ȫ�ġ��������Բ�ʿ������ô���ڣ�������������Һ�ڵ��Ĺ����в����ж�ʧ��

дһ������ȥ�������Բ�ʿ�ҳ��� A �Թ��ǿյ�ʱ��C �Թ�������ͭ��Һ��ʣ�������п����ԡ�

����
�����������������ÿ������������������һ�У�Ϊ�ո�ָ��������������ֱ�Ϊ���� A,B,C��

���
�������һ�У�������г��� A �Թ��ǿյ�ʱ��C �Թ���Һ��ʣ�������п����ԡ�

��������
2 5 10
�������
5 6 7 8 9 10
����
����Ŀ������ʾ�����������Թܵ����������

һ��ʼ�Թ�a��b��Ϊ�գ�c����

��a��ʱc�Ŀ���ȡֵ������С��������

˼·
�������ݽṹset<int>�洢�𰸣�ȥ��+���򣩡�

��Ϊ��3���Թܣ����Ե�ˮ�ķ�����6�֣�����д��ÿ�ֿ��ܣ�dfs��

��λ����visited�����壺�߹��ĵ�Ͳ���Ҫ�����ˣ�û�еĻ�û��ֹͣ��

����*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
set<int> s;
int na,nb,nc;
bool visited[25][25][25];
void dfs(int a,int b,int c)
{
    if(visited[a][b][c]) return;
    visited[a][b][c] = true;
    if(!a) s.insert(c);
    if(a <= nb-b) dfs(0,a+b,c);
    else dfs(a-nb+b,nb,c);
    if(b <= na-a) dfs(a+b,0,c);
    else dfs(na,a-na+b,c);
    if(a <= nc-c) dfs(0,b,a+c);
    else dfs(a-nc+c,b,nc);
    if(c <= na-a) dfs(a+c,b,0);
    else dfs(na,b,c-na+a);
    if(b <= nc-c) dfs(a,0,b+c);
    else dfs(a,b-nc+c,nc);
    if(c <= nb-b) dfs(a,b+c,0);
    else dfs(a,nb,c-nb+b);
}
int main()
{
    while(~scanf("%d %d %d",&na,&nb,&nc))
    {
        s.clear();
        memset(visited,0,sizeof(visited));
        dfs(0,0,nc);
        set<int>::iterator it = s.begin();
        printf("%d",*it);
        it++;
        for(; it != s.end(); it++)
        {
            printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}
