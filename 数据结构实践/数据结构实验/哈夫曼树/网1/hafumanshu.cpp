#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
 
int main(){
	int i,N,x,Weight;
    while(scanf("%d",&N) != EOF){
		Weight = 0;
		priority_queue<int, vector<int>, greater<int> > MinHeap;
		for(i = 0;i < N;i++){
			scanf("%d",&x);
			MinHeap.push(x);
		}
		while(MinHeap.size() > 1){
			int a = MinHeap.top();
			MinHeap.pop();
			int b = MinHeap.top();
			MinHeap.pop();
			Weight += a + b;
			MinHeap.push(a + b);
		}
		printf("%d\n",Weight);
	}
	return 0;
}

