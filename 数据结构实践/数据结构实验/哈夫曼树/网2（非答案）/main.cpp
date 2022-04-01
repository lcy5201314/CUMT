#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n,temp,a,b;
    int weight;
    priority_queue<int,vector<int>,greater<int> > minheap;
    while(cin>>n)
    {
        weight = 0;
        for(int i= 0;i < n;i++)
        {
            cin>>temp;
            minheap.push(temp);
        }
        while(minheap.size()!= 1)
        {
            a = minheap.top();
            minheap.pop();
            b = minheap.top();
            minheap.pop();
            weight = weight + a +b;
            minheap.push(a+b);
              
        }
        cout<<weight<<endl;
        minheap.pop();
    }   
    return 0;
}

