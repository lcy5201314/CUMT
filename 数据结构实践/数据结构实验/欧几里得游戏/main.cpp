#include<iostream>
using namespace std;
int main()
{
    int a,b,s;
    int step;
    while(cin>>a>>b&&(a!=0||b!=0))
    {   
        step=1;
        if(a==b) 
        {
            cout<<"xiaoming wins"<<endl;
        }
        else
        {
           while(a!=b)
        {
            if(a<b)
            {
                s=a;
                a=b;
                b=s;
            }
            step++;
            if(a/b!=1)
            {
                    break;
            } 
             
                a=a%b;
        }
        if(step%2==1)
            cout<<"xiaohong wins"<<endl;
        else
            cout<<"xiaoming wins"<<endl;
        }
  
    }
    return 0;
}

