#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string de;
    int i;
    getline(cin,de);
    for(i=0;i<de.size();i++)
    {
        de[i]=tolower(de[i]);
    }
    string ori;
    while(getline(cin,ori))
    {
        string a,b;
    a=ori;b=ori;
    for(i=0;i<a.size();i++)
    {
        a[i]=tolower(a[i]);
    }
    int set;
    set=a.find(de,0);
    while(set!=string::npos)
    {
        b.erase(set,de.size());
        a.erase(set,de.size());
        set=a.find(de,set);
    }
    set=b.find(' ',0);
    while(set!=string::npos)
    {
        b.erase(set,1);
        set=b.find(' ',set);
    }
    cout<<b<<endl;
    }
    return 0;
} 

