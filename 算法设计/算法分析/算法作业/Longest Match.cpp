#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
 
struct node
{
    int num;          //记录单词的个数
    string w[1010];   //单词序列
};
int f[1010][1010];    //Xi 中前i个单词 与 Yj 中前j个单词 最大公共子序列个数为f[i][j] 
void devide(string s,node &t)
{
    int len=s.size();
    t.num=1;
    for(int i=0; i<len; i++)
    {
        if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9') )
        {
            t.w[t.num]+=s[i];
        }
        else t.num++;
    }
    int n=0;
    for(int i=1; i<=t.num ; i++)
    {
        if(!t.w[i].empty())
            t.w[++n]=t.w[i];
    }
    t.num=n;
}
int main()
{
    int ca=1;
    while(!cin.eof())
    {
        string X,Y;
        node t1,t2;
        getline(cin,X);
        devide(X,t1);      //把x中的单词取出来
        getline(cin,Y);
        devide(Y,t2);       //同上
        printf("%2d. ",ca++);
        if(X.empty() || Y.empty())     
        {
            printf("Blank!\n");
            continue;
        }
        memset(f,0,sizeof(f));
        for(int i=1; i<=t1.num; i++)
            for(int j=1; j<=t2.num; j++)
            {                                        //计算前i个单词 和 前j个单词最大匹配数
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if(t1.w[i] == t2.w[j])
                    f[i][j]=max(f[i][j] , f[i-1][j-1]+1);
            }
        printf("Length of longest match: %d\n",f[t1.num][t2.num]);
 
    }
    return 0;
}
