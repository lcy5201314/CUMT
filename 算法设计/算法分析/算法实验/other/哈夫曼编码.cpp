/*问题 B: 哈夫曼编码
题目描述
给定一只含有小写字母的字符串；输出其哈夫曼编码的长度

输入
第一行一个整数T，代表样例的个数，接下来T行，每行一个字符串，0<T<=2000,字符串长度0<L<=1500.

输出
对于每个字符串，输出其哈夫曼编码长度

样例输入
3
hrvsh
lcxeasexdphiopd
mntflolfbtbpplahqolqykrqdnwdoq
样例输出
10
51
115
题意
给定一个字符串，输出它的哈夫曼编码长度。

思路
直接STL（<queue>）开一个priority_queue（优先级队列），注意每次出的是最小的。

代码*/
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
