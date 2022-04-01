#include<iostream>
#include<cstring>
#include<iomanip>
 
using namespace std;
 
const int maxn=30100;
int d[12]={0,10000,5000,2000,1000,500,200,100,50,20,10,5};
long long dp[maxn];
 
int main()
    {
        int x,y;
        char ch;
        while(cin>>x>>ch>>y)
            {
                int val=x*100+y;
                if(val==0) break;
                memset(dp,0,sizeof(dp));
                dp[0]=1;
                int i,j,k;
                for(i=1;i<=11;i++)
                    {
                        for(j=d[i];j<=val;j++)
                            {
                                dp[j]=dp[j]+dp[j-d[i]];
                            }
                    }
                double dval=val/100.0;
                cout<<setiosflags(ios::right)<<setw(6)<<fixed<<setprecision(2)<<dval;
                cout<<setiosflags(ios::right)<<setw(17)<<dp[val]<<endl;
            }
        return 0;
    }


