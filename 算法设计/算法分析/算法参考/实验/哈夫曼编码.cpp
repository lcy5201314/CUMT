/*���� B: ����������
��Ŀ����
����һֻ����Сд��ĸ���ַ�������������������ĳ���

����
��һ��һ������T�����������ĸ�����������T�У�ÿ��һ���ַ�����0<T<=2000,�ַ�������0<L<=1500.

���
����ÿ���ַ������������������볤��

��������
3
hrvsh
lcxeasexdphiopd
mntflolfbtbpplahqolqykrqdnwdoq
�������
10
51
115
����
����һ���ַ�����������Ĺ��������볤�ȡ�

˼·
ֱ��STL��<queue>����һ��priority_queue�����ȼ����У���ע��ÿ�γ�������С�ġ�

����*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 2000;
int num[30],ans;
struct cmp1
{
    bool operator()(int& a,int& b)
    {
        return a > b;
    }
};
int main()
{
    int t;
    char str[maxn];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        memset(num,0,sizeof(num));
        int len = strlen(str);
        for(int i = 0; i < len; i++)
            num[int(str[i]-'a')]++;
        priority_queue<int,vector<int>,cmp1> pq;
        for(int i = 0; i < 26; i++)
            if(num[i]) pq.push(num[i]);
//        if(pq.size() == 1)
//        {
//            printf("%d\n",pq.top());
//        }
        ans = 0;
        while(pq.size() > 1)
        {
            int a,b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a+b);
            ans += a+b;
        }
        printf("%d\n",ans);
    }
    return 0;
}
