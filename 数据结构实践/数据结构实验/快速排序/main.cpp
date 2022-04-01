#include <iostream>
using namespace std;
void Qs(int ar[], int lo, int hi)
{
    if (hi <= lo) return;
    int i;
    i = lo;
    int j ;
    j = hi + 1;
    int k;
    k= ar[lo];
    while (true)
    {
        while (ar[++i] < k)
        {
            if (i == hi){
                break;
            }
        }
        while (ar[--j] > k)
        {
            if (j == lo){
                break;
            }
        }
        if (i >= j) break;
        int temp;
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
    int t;
    t = ar[lo];
    ar[lo] = ar[j];
    ar[j] = t;
    Qs(ar, lo, j - 1);
    Qs(ar, j + 1, hi);
}
int main()
{
    int num;
    cin>>num;
    int sd[num];
    for(int i=0;i<num;i++)cin>>sd[i];
    Qs(sd,0,num-1);
    for(int i=0;i<num;i++)cout<<sd[i]<<' ';
    return 0;
}

