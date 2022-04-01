/*问题 A: 评分系统
题目描述
英语俱乐部举办了一个叫做“英文金曲大赛”的节目。这个节目有好多人参加，这不，成绩出来了，渊子当是很勇敢，
自告奋勇接下了算出大家的总得分的任务。当时有7个评委，每个评委都要给选手打分，现在要求去掉一个最高分和去掉一个最低分，
再算出平均分。结果精确到小数点后两位。

输入
测试数据包括多个实例。每组数据包括7个实数，代表评委们对该选手的评分。紧接着是选手的名字，名字的长度不超过30个字符。
输入直到文件结束。

输出
输出每位选手名字和最终得分，结果保留两位有效数字。

样例输入
10 10 10 10 10 10 9 xiaoyuanwang
0 0 0 0 0 0 0 beast
样例输出
xiaoyuanwang 10.00
beast 0.00
题意
输入7个数字（double）和人名。

输出人名和去掉最高分和最低分后的平均分。

思路
Water。开一个数组存7个分数，输入完sort()函数一下，最低分在a[0]，最高分在a[6]，那我们直接写个for循环求a[1]+a[2]+...+a[5]
（当然你也可以不用循环直接相加）然后除5输出即可。

代*/ 
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    double a[7];
    char nam[35];
    while(~scanf("%lf",&a[0]))
    {
        for(int i = 1; i < 7; i++)
        {
            scanf("%lf",&a[i]);
        }
        scanf("%s",nam);
        sort(a,a+7);
        double sum = 0;
        for(int i = 1; i < 6; i++)
        {
            sum += a[i];
        }
        sum /= 5;
        printf("%s %.2lf\n",nam,sum);
    }
    return 0;
}
