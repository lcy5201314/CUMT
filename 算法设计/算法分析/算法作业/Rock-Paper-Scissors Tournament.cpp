#include <iostream>
#include <stdio.h>
#include <string.h>
 
using namespace std;
 
const int N = 100;
int w[N], l[N];
 
int main()
{
    int n, k, flag = 0;
    while(scanf("%d", &n) == 1 && n) {
        memset(w, 0, sizeof(w));
        memset(l, 0, sizeof(l));
 
        if(flag)
            printf("\n");
        flag = 1;
 
        scanf("%d", &k);
        for(int i = 0; i < k * n * (n - 1) / 2; i++) {
            int p1, p2;
            char m1[15], m2[15];
            scanf("%d%s%d%s", &p1, m1, &p2, m2);
            if(m1[0] == m2[0])
                continue;
            if((m1[0] == 'r' && m2[0] == 's') || (m1[0] == 's' && m2[0] == 'p') || (m1[0] == 'p' && m2[0] == 'r'))
                w[p1]++, l[p2]++;
            else if((m2[0] == 'r' && m1[0] == 's') || (m2[0] == 's' && m1[0] == 'p') || (m2[0] == 'p' && m1[0] == 'r'))
                w[p2]++, l[p1]++;
        }
 
        for(int i = 1; i <= n; i++)
            if(w[i] + l[i])
                printf("%.3f\n", (double)w[i] / (l[i] + w[i]));
            else
                printf("-\n");
    }
 
    return 0;
}
 
