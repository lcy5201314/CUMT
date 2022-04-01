#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN = 2005;
int dp[MAXN][MAXN];
int main()
{
    int lena,lenb,i,j;
    char a[MAXN],b[MAXN];
    cin>>a>>b;
    lena = strlen(a);
    lenb = strlen(b);
    for(i = 1; i <= lena; i++)
    {
        for(j = 1; j <= lenb; j++)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[lena][lenb]<<endl;
    return 0;
}
