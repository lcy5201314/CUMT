/*问题 A: 单词排序
题目描述
小红学会了很多英文单词，妈妈为了帮小红加强记忆，拿出纸、笔，把 N 个单词写在纸上的一行里，小红看了几秒钟后，
将这张纸扣在桌子上。妈妈问小红：“你能否将这 N 个单词按照字典排列的顺序，从小到大写出来？”小红按照妈妈的要求写出了
答案。现在请你编写程序帮助妈妈检查小红的答案是否正确。注意：所有单词都由小写字母组成，开头字母全都不相同，
单词两两之间用一个空格分隔。

输入
输入包含两行。

第一行仅包括一个正整数N(0<N≤26)。

第二行包含N个单词，表示妈妈写出的单词，两两之间用一个空格分隔。

单个单词长度不超过1010。

输出
输出仅有一行。针对妈妈写出的单词，按照字典排列的顺序从小到大排列成一行的结果，每个单词后带一个空格。

样例输入
4
city boy tree student
样例输出
boy city student tree
题意
如题目描述所示。

思路
Water，可以用string数组存储，sort函数一下输出即可。

代码*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    string wo[30];
    scanf("%d",&n);
    for(int i = 0; i < n; i++) cin>>wo[i];
    sort(wo,wo+n);
    cout<<wo[0];
    for(int i = 1; i < n; i++) cout<<" "<<wo[i];
    cout<<endl;
    return 0;
}
