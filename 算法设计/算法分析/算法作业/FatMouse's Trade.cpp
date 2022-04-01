#include<stdio.h>
#include<algorithm>
using namespace std;
struct f
{
    double c;
    int nai,cat;
 
};
bool pai(f x,f y)
{
    if(x.c>y.c)
    return true;
    else
    return false;
}
int main()
{
    int m,zong,i,j=0,n,b;
    f a[1005];
    while(~scanf("%d%d",&zong,&m))
    {
        double r=0;
            if(zong==-1&&m==-1)
        {
            break;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a[i].nai,&a[i].cat);
            a[i].c=a[i].nai*1.0/a[i].cat;
        }
        sort(a,a+m,pai);
 for(i=0;i<m;i++)
        {
            if(zong>a[i].cat||zong==a[i].cat)
            {
                r=a[i].nai+r;
                zong=zong-a[i].cat;
            }
            else
            {
                r=zong*1.0*a[i].c+r;
                zong=0;
                if(zong==0)
                {
                    break;
                }
 
            }
            if(zong==0)
                {
                    break;
                }
 
        }
        printf("%.3lf\n",r);
    }
 
    return 0;
}
