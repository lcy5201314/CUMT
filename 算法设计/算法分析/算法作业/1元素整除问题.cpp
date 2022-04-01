#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a[20];
    for(int i = 0; i < 20; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(i != j && a[i]%a[j] == 0 )
            {
                printf("%d\n",a[i]);
                break;
            }
        }
    }
    return 0;
}
