#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#include <cmath>

using namespace std;
struct node
{
    bool flag;
    int i1,j1,i2,j2;
};
node st[102][102];
int dp[122][122];
bool b[122];
char s[122];
int l;
void dfs (node p)
{
    if(p.flag==0)
    {
        if(p.i1==p.j1)
        {
            b[p.i1]=1;
            return;
        }
        else
        {
          if(p.i1>p.j1) return;
        }
        dfs(st[p.i1][p.j1]);
    }
    else
    {
        dfs(st[p.i1][p.j1]);
        dfs(st[p.i2][p.j2]);
    }
}
void del()
{
    int i,k,j,t;
    i=0;
    dp[0][0]=1;
    st[i][i].flag=0;
    st[i][i].i1=st[i][i].j1=i;

    for(i=1;i<l;i++)
     {
         dp[i][i]=1,dp[i][i-1]=0;
         st[i][i].flag=0;
         st[i][i].i1=st[i][i].j1=i;
         st[i][i-1].flag=0;
         st[i][i-1].i1=i;
         st[i][i-1].j1=i-1;

     }
    for(k=2;k<=l;k++)
    {
        for(i=0;i+k<=l;i++)
        {
            j=i+k-1;
            dp[i][j]=1000;
            if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
              {
                  dp[i][j]=dp[i+1][j-1];
                  st[i][j].flag=0;
                  st[i][j].i1=i+1;
                  st[i][j].j1=j-1;
              }
          for(t=i;t<j;t++)
            {
                if(dp[i][j]>dp[i][t]+dp[t+1][j])
                {
                   dp[i][j]=dp[i][t]+dp[t+1][j];
                   st[i][j].flag=1;
                   st[i][j].i1=i;
                   st[i][j].j1=t;
                   st[i][j].i2=t+1;
                   st[i][j].j2=j;
                }
            }
        }
    }
    memset(b,0,sizeof(b));
    dfs(st[0][l-1]);
    for(i=0;i<l;i++)
    if(b[i])
    {
      if(s[i]=='('||s[i]==')')
       printf("%c%c",'(',')');
       else
       printf("%c%c",'[',']');
    }
    else
     printf("%c",s[i]);
    printf("\n");
}
int main()
{

    while(gets(s)!=NULL)
    {
        if(l=strlen(s))
           del();
        else
          printf("\n");

    }
    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define N 105

using namespace std;

int dp[N][N],mark[N][N];
char str[N];

bool cmp(char a,char b)//判断是否匹配
{
    if((a=='('&&b==')')||(a=='['&&b==']'))
        return true;
    return false;
}

void Print(int l,int r)//输出递归函数
{
    if(l>r)
        return;
    if(l==r)
    {
        if(str[l-1]=='['||str[l-1]==']')
            printf("[]");
        else
            printf("()");
        return;
    }
    if(!mark[l][r])
    {
        printf("%c",str[l-1]);
        Print(l+1,r-1);
        printf("%c",str[r-1]);
    }
    else
    {
        Print(l,mark[l][r]);
        Print(mark[l][r]+1,r);
    }
}

int main()
{
    while(gets(str)!=NULL)
    {
        int len=strlen(str);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len;i++)
        {
            dp[i][i]=1;
        }
        for(int len1=2;len1<=len;len1++)
        {
            for(int i=1;i+len1-1<=len;i++)
            {
                int j=len1+i-1;
                dp[i][j]=INF;
                if(cmp(str[i-1],str[j-1]))
                {
                    dp[i][j]=dp[i+1][j-1];
                    mark[i][j]=0;
                }
                for(int k=i;k<j;k++)
                {
                    if(dp[i][j]>(dp[i][k]+dp[k+1][j]))
                    {
                        dp[i][j]=dp[i][k]+dp[k+1][j];
                        mark[i][j]=k;
                    }
                }
            }
        }
        Print(1,len);
        printf("\n");
    }
    return 0;
}