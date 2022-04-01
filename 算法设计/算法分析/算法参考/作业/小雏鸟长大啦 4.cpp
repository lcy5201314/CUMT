/*问题 C: 小雏鸟长大啦 4
题目描述
陶行知先生说：”吃自己的饭，滴自己的汗，自己的事自己干”。

但是有些小雏鸟做作业喜欢抄别人的！

大白开发了代码自动查重功能。

已知有两个字符串，a和b，如果b串与a串的内容一模一样，那就是抄袭无误了。但是有些小雏鸟把心思用在了歪处。他们会在代码里
加入一些干扰变量，使得上述判断方法失灵。

大白需要改进算法，帮他实现新的查重算法。

输入
两行字符串，分别代表字符串a和b。长度不超过100。

输出
输出b是否抄袭了a。

当b中存在去掉一些字符后和a字符串一致的数据(长度，顺序，内容都相等)的时候，输出yes，否则输出no

样例输入
int c;
int a,b,c=0;
样例输出
yes
题意
输入两行字符串，若b中包含a则输出yes，否则输出no

思路
可以使用两个下标i, j分别指向a, b字符串正在比较的字符。

若a[i] == b[j]，则i++（每次i++判断i是否>=lena，若是，则比较结束，输出yes）, j++；
否则j++（每次j++判断i是否>=lenb，若是，则比较结束，输出no）。
注意：由于要输入整行，故输入用gets()或getline()

代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN = 105;
int main()
{
    char a[MAXN],b[MAXN];
    gets(a);
    gets(b);
    int lena = strlen(a),lenb = strlen(b);
    int i = 0,j = 0;
    while(true)
    {
        if(a[i] == b[j])
        {
            i++;
            if(i >= lena)
            {
                puts("yes");
                return 0;
            }
            j++;
        }
        else j++;
        if(j >= lenb)
        {
            puts("no");
            return 0;
        }
    }
}
