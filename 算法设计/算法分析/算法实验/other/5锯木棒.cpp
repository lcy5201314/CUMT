/*��Ŀ����
xiaok��������ٹ�Ӷ���˸�����ľ������һ����ΪL��ľ��������Σ�����Ҫ֧��������LԪǮ��xiaok����һ��ʼֻ�г�ΪL��һ��ľ��������������n�Σ�ÿ�γ��ȷֱ�ΪL1,L2,��,Ln����xiaok��������Ҫ�������˶���Ǯ��

����
��һ����������n,L(13</sup>,n9</sup>)

�ڶ���n������L1,L2,��,Ln��0<Li<L,�ұ�֤L1+L2+��+Ln=L��

���
���һ����������ʾ��С����

��������
3 21
8 5 8
�������
34
��ʾ
�Ȱ�ľ�����13��8���Σ�����21���ٰ�13�Ƕξ��5��8������13���ܻ���13+21=34

�����ԣ�̰�ģ�������ȼ����У����ο�����������

����*/
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
