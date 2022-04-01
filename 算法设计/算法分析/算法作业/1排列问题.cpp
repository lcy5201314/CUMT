#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char str[10];
    cin>>str;
    int len = strlen(str)-1;
    str[len] = '\0';
    sort(str,str+len);
    cout<<str;
    //next_permutation函数将按字母表顺序生成给定序列的下一个较大的排列，直到整个序列为降序为止
    while(next_permutation(str,str+len))
    {
        cout<<" "<<str;
    }
    cout<<endl;
    return 0;
}
