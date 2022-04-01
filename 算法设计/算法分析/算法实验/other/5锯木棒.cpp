/*题目描述
xiaok大佬最近再雇佣工人给他掰木棒。把一根长为L的木棒锯成两段，他需要支付给工人L元钱。xiaok大佬一开始只有长为L的一根木棒，他想把它锯成n段，每段长度分别为L1,L2,…,Ln，问xiaok大佬最少要付给工人多少钱？

输入
第一行两个整数n,L(13</sup>,n9</sup>)

第二行n个整数L1,L2,…,Ln（0<Li<L,且保证L1+L2+…+Ln=L）

输出
输出一个整数，表示最小花费

样例输入
3 21
8 5 8
样例输出
34
提示
先把木棒锯成13和8两段，花费21，再把13那段锯成5和8，花费13，总花费13+21=34

很明显，贪心，设个优先级队列，（参考哈夫曼树）

代码*/
#include<bits/stdc++.h>
using namespace std;
struct cmp1
{
    bool operator()(int& a,int& b)
    {
        return a>b;
    }
};
int main()
{
    priority_queue<int,vector<int>,cmp1> pq;
    int n,l,s;
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        pq.push(s);
    }
    int sum=0;
    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        sum=sum+a+b;
        pq.push(a+b);
    }
    cout<<sum<<endl;
}
