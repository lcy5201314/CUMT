/* ZOJ3981 Balloon Robot */

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 1;
int seat[N], d[N];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, p, a, b;
        scanf("%d%d%d", &n, &m, &p);
        for(int i = 0; i < n; i++) scanf("%d", &seat[i]);

        LL sum = 0;
        for(int i =0; i < p; i++) {
            scanf("%d%d", &a, &b);
            d[i] = (seat[a - 1] - 1 - b % m + m) % m;
            sum += d[i];
        }
        sort(d, d + p);

        LL ans = (LL)1e18;
        for(int i = 0; i < p; i++)
            if(i == 0 || d[i] != d[i - 1])
                ans = min(ans, sum + i * LL(m) - LL(p) * d[i]);

        printf("%lld\n", ans);
    }

    return 0;
}

