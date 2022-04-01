
#include<iostream>
using namespace std;
#define inf 10000
#define MAXSIZE 51
int Vis[MAXSIZE];
int map[MAXSIZE][MAXSIZE];
int Dis[MAXSIZE];
void Dijkstra(int n,int start){
  Vis[start]=1;
  for(int i=0;i<n;i++){
    Dis[i]=map[start][i];
    if(Dis[i]==0)
    Dis[i]=inf;
  }
  Dis[start]=0;
  for(int i=0;i<n;i++){
    int min=inf,index;
    for(int j=0;j<n;j++){
      if(Dis[j]<min&&!Vis[j]){
        min=Dis[j];
        index=j;
      }
    }
    Vis[index]=1;
    for(int i=0;i<n;i++){
      if(!Vis[i]&&map[index][i]&&Dis[i]>map[index][i]+Dis[index]){
        Dis[i]=map[index][i]+Dis[index];
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  int n,start;
  cin>>n>>start;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>map[i][j];
    }
  }
  Dijkstra(n,start);
  for(int i=0;i<n;i++){
    if(i!=start){
      cout<<Dis[i]<<" ";
    }
  }
  cout<<endl;
  return 0;
}
