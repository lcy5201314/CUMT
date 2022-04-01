#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
map<char,int>q;
int n,h[1024],ans;
string s1,s2;
int lson[1024],rson[1024];
int tag[1024];
char buildtree(int s,int t){
    memset(tag,0,sizeof(tag));
    if(s==t) return s2[s];
    for(int i=s;i<=t;i++){
        tag[s2[i]]=1;
        //cout<<s2[i];
    }
    //cout<<endl;
    int lx=-1,rx=-1;
    for(int i=0;i<n;i++){
        if(lx==-1){
            if(tag[s1[i]]){
                lx=i;
            }
        }
        else{
            if(!tag[s1[i]]){
                rx=i-1;
                break;
            }
        }
    }
    if(rx==-1) rx=t;
    char root=s1[lx];int pla;
    for(int i=s;i<=t;i++){
        if(root==s2[i]){
            pla=i;
            break;
        }
    }
    if(s<=pla-1) lson[root]=buildtree(s,pla-1);
    if(pla+1<=t) rson[root]=buildtree(pla+1,t);
    return root;
}
void dfs(char ss){
    if(ss==0){
        return;
    }
    ans=max(ans,h[ss]);
    h[lson[ss]]=h[rson[ss]]=h[ss]+1;
    dfs(lson[ss]);
    dfs(rson[ss]);//cout<<ss<<'*';
}
int main(){
    while(cin>>n){
        memset(h,0,sizeof(h));
        memset(lson,0,sizeof(lson));
        memset(rson,0,sizeof(rson));
        ans=0;
        //q.erase(q.begin(),q.end());
        cin>>s1>>s2;
        char x=buildtree(0,n-1);
        h[x]=1;
        dfs(x);
        cout<<ans<<endl;
    }
    return 0;
}
