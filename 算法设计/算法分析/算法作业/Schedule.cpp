#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
#define maxn 100100
#define maxm 100100
#define LL long long
using namespace std;
typedef pair<LL,LL> pr;
vector<pr>len;
int main()
{
    LL T;
    scanf("%lld",&T);
    while(T--)
    {
        len.clear();
        LL n;
        scanf("%lld",&n);
        LL tm=0;
        for(LL i=1;i<=n;i++)
        {
            LL l,r;scanf("%lld %lld",&l,&r);
            len.push_back(make_pair(l,1));
            len.push_back(make_pair(r,-1));
        }
        LL maxk=0;
        LL cnt=0;
        sort(len.begin(),len.end());
        LL ll[maxn],rr[maxn];
        memset(ll,0,sizeof ll);
        memset(rr,0,sizeof rr);
        for(LL i=0;i<len.size();i++)
        {
            if(len[i].second==1)
            {
                cnt++;
                if(maxk<cnt)
                {
                    if(ll[cnt]==0)
                        ll[cnt]=len[i].first;
                   maxk=cnt;
                }
            }
            else
            {
                rr[cnt]=len[i].first;
                if(maxk<cnt) maxk=cnt;
                cnt--;
            }
        }
        for(LL i=1;i<=maxk;i++)
        {
            tm+=(rr[i]-ll[i]);
        }
        printf("%lld %lld\n",maxk,tm);
    }
  
    
    return 0;
}

