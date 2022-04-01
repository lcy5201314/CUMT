#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1000000+5;
int L,n,a[maxn];
int main(){

	int t;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		scanf("%d%d",&L,&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		int Min=0,Max=0;
		for(int i=1;i<=n;++i){
			Min=max(Min,min(a[i],L-a[i]));
			Max=max(Max,max(a[i],L-a[i]));
		}
		printf("%d %d\n",Min,Max);
	}
	return 0;
} 
