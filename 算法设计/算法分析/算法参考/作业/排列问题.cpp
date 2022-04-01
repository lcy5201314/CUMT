/*问题 B: 排列问题
题目描述
输入一个可能含有重复字符的字符串，打印出该字符串中所有字符的全排列。

输入
单组测试数据，输入数据是一个长度不超过10个字符的字符串，以逗号结尾。

输出
打印出该字符串中所有字符的全排列。以字典序顺序输出，用空格分隔。

样例输入
abc,
样例输出
abc acb bac bca cab cba
题意
去掉,后打印字符串的全排列（有可能有重复字符）。

思路
递归。

（TLE）用一个set（去重+排序）保存结果，递归交换第i位和第j位（递归后还得把它们换回去，有点像dfs）。
c++中的std::set，是基于红黑树的平衡二叉树的数据结构实现的一种容器，因为其中所包含的元素的值是唯一的，因此主要用于去重
和排序。

但是，研表究明，上述代码会超时！原因可能是后台数据量过大、存在太多冗余计算、用了cin、cout。后来，惊奇发现语言自带这种
函数，叫做next_permutation()，震惊！后来为了避免重复造轮子（其实是懒得自己模拟捂脸），就用了这函数。
注意：这题用cin、cout好像一定TLE，所以用stdio吧！

代码1（TLE）
//set消重
#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
string str;
int len;
set<string> s;
void f(int i)
{
    if(i != len)
    {
        s.insert(str);
        for(int j = i; j < len; j++)
        {
            swap(str[i],str[j]);
            f(i+1);
            swap(str[i],str[j]);
        }
    }
}
int main()
{
    cin>>str;
    len = str.length() - 1;
    str.resize(len);
    f(0);
    set<string>::iterator it = s.begin();
    cout<<*it;
    it++;
    for(;it != s.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}
代码2*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char str[15];
    scanf("%s",str);
    int len = strlen(str)-1;
    str[len] = '\0';
    sort(str,str+len);
    printf("%s",str);
    while(next_permutation(str,str+len))
    {
        printf(" %s",str);
    }
    printf("\n");
    return 0;
}
