#include <stdio.h>
#include <stdlib.h>
#define OFFSET 500000
int Hash[1000001];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
            int i;
        for(i= -500000;i<=500000;i++){
            Hash[i+OFFSET] = 0;
        }
        for(i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            Hash[x +OFFSET]++;
        }
        for(i=500000;i>=-500000;i--){
            while(m>0&&Hash[i+OFFSET]--){
                    printf("%d",i);
                m--;
                if(m!=0) printf(" ");
                else{
                    printf("\n");
                    break;
                }
            }
        }
    }
 
    return 0;
}

