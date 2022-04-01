#include <iostream>
#include <cstring>
using namespace std;
void EJZ(int num,int start,int *bin);
int *tranIP(string ori);
string And(int *IP,int *submit);
 
void EJZ(int num,int start,int *bin)
{
    int locate=start*8;
    for(int i=0;i<8;i++)
    {
        bin[locate+7-i]=num%2;
        num/=2;
    }
}
 
int *tranIP(string ori)
{
    int num=0,start=0;
    bool flag=0;
    int bin[32]={0};
    for(int i=0;ori[i]!='\0';i++)
    {
        if(ori[i]=='.')
        {
            flag=1;
            continue;
        }
        if(flag)
        {
            EJZ(num,start++,bin);
            num=0;
        }
        num=num*10+ori[i]-'0';
        flag=0;
    }
    return bin;
}
 
string And(int *IP,int *submit)
{
    int num;
    string outcome;
    for(int k=0;k<32;k++)
    {
        num=IP[k]&submit[k];
        outcome=outcome+char(num+'0');
    }
    return outcome;
}
 
int main()
{
    string IP,submit_ori;
    cin>>IP>>submit_ori;
    int IPnum[32]={0};
    int submit_orinum[32]={0};
    memcpy(IPnum, tranIP(IP), sizeof(IPnum));
    memcpy(submit_orinum, tranIP(submit_ori), sizeof(submit_orinum));
    string AndIP;
    AndIP=And(IPnum,submit_orinum);
    int n;
    cin>>n;
    string QT;
    string QTAnd;
    for(int i=0;i<n;i++)
    {
        cin>>QT;
        int QTnum[32]={0};
        memcpy(QTnum, tranIP(QT), sizeof(QTnum));
        QTAnd=And(QTnum,submit_orinum);
        if(QTAnd==AndIP)
        cout<<"INNER"<<endl;
        else if(QTAnd!=AndIP)
        cout<<"OUTER"<<endl;
    }
    return 0;
}

