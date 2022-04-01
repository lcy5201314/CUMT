#include <iostream>
using namespace std;
struct nation
{
        int gold,medal;
        double peo,gop,mep;
        int rank[4];
        int highrank,rankmethod;
};
int main()
{
    int n,m;
    int i,j;
    while(cin>>n>>m)
    {
        nation nat[n];
        for(i=0;i<n;i++)
        {
            cin>>nat[i].gold >>nat[i].medal >>nat[i].peo ;
            nat[i].gop=nat[i].gold/nat[i].peo ;
            nat[i].mep=nat[i].medal /nat[i].peo ;
        }
        int num[m];
        for(i=0;i<m;i++)
        cin>>num[i];
        for(i=0;i<n;i++)
    {
        nat[i].rank[0]=nat[i].rank[1]=nat[i].rank[2] =nat[i].rank[3]=1;
        for(j=0;j<n;j++)
        {   
            if(nat[i].gold<nat[j].gold)
                nat[i].rank[0]++;
        }
        for(j=0;j<n;j++)
        {   
            if(nat[i].medal<nat[j].medal)
                nat[i].rank[1]++;
        }
        for(int j=0;j<n;j++)
        {   
            if(nat[i].gop<nat[j].gop)
                nat[i].rank[2]++;
        }
        for(int j=0;j<n;j++)
        {   
            if(nat[i].mep<nat[j].mep)
                nat[i].rank[3]++;
        }
    }
    for(i=0;i<n;i++)
    {
        nat[i].highrank =nat[i].rank[0];
        nat[i].rankmethod =1;
        for(j=0;j<4;j++)
        {
            if(nat[i].rank[j]<nat[i].highrank)
            {
                nat[i].highrank =nat[i].rank [j];
                nat[i].rankmethod =j+1;
            }
            else if(nat[i].rank[j]==nat[i].highrank)
            {
                if(nat[i].rankmethod >j+1)
                nat[i].rankmethod =j+1;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        cout<<nat[num[i]].highrank <<":"<<nat[num[i]].rankmethod <<endl;
    }
    cout<<endl;
    }
     
    return 0;
}

