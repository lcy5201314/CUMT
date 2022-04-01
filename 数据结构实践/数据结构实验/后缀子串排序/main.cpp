#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool jud(string s1,string s2) 
{
     return  s1 < s2;                  
}
int main ()
{
    int i,j;
    char SR[1000]; 
    string SC[1000];
    while(cin>>SR)
    { 
        int le=strlen(SR);
        for(i=0;i<le;i++)
        {
            string a="";
            for(j=i;j<le;j++)
                a+=SR[j];
            SC[i]=a;   
        }   
        sort(SC,SC+le,jud);
        for(i=0;i<le;i++)
            cout<<SC[i]<<endl;
    }
    return 0; 
}

