/*问题 B: 渊子赛马
题目描述
赛马是一古老的游戏，早在公元前四世纪的中国，处在诸侯割据的状态，历史上称为“战国时期”。在魏国作官的孙膑，
因为受到同僚庞涓的迫害，被齐国使臣救出后，到达齐国国都。 赛马是当时最受齐国贵族欢迎的娱乐项目。上至国王，下到大臣，
常常以赛马取乐，并以重金赌输赢。田忌多次与国王及其他大臣赌输赢，屡赌屡输。一天他赛马又输了，回家后闷闷不乐。
孙膑安慰他说：“下次有机会带我到马场看看，也许我能帮你。” 孙膑仔细观察后发现，田忌的马和其他人的马相差并不远，
只是策略运用不当，以致失败。 比赛前田忌按照孙膑的主意，用上等马鞍将下等马装饰起来，冒充上等马，与齐王的上等马比赛。
第二场比赛，还是按照孙膑的安排，田忌用自己的上等马与国王的中等马比赛，在一片喝彩中，只见田忌的马竟然冲到齐王的马前面，
赢了第二场。关键的第三场，田忌的中等马和国王的下等马比赛，田忌的马又一次冲到国王的马前面，结果二比一，田忌赢了国王。 
就是这么简单，现在渊子也来赛一赛马。假设每匹马都有恒定的速度，所以速度大的马一定比速度小的马先到终点（没有意外！！）。
不允许出现平局。最后谁赢的场数多于一半(不包括一半)，谁就是赢家(可能没有赢家)。渊子有 N(1<=n<=1000)匹马参加比赛。
对手的马的数量与渊子马的数量一样，并且知道所有的马的速度。聪明的你来预测一下这场世纪之战的结果，看看渊子能否赢得比赛。

输入
输入有多组测试数据。 每组测试数据包括 3 行： 第一行输入 N。表示马的数量。 第二行有 N 个整型数字，即渊子的 N 匹马的速度。
 第三行有 N 个整型数字，即对手的 N 匹马的速度。 当 N 为 0 时退出。

输出
若通过聪明的你精心安排，如果渊子能赢得比赛，那么输出YES。 否则输出NO。

样例输入
5
2 3 3 4 5
1 2 3 4 5
4
2 2 1 2
2 2 3 1
0
样例输出
YES
NO
题意
赛马。

思路
都先从小到大排序。

设两个变量cnt1、cnt2分别存储两人赢的场次。

代码*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1e3+5;
int main()
{
    int n,a[maxn],b[maxn],cnt1,cnt2;
    while(~scanf("%d",&n) && n)
    {
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i++) scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > b[j])
            {
                cnt1++;
                j++;
            }
            else cnt2++;
        }
        if(cnt1 > cnt2) puts("YES");
        else puts("NO");
    }
    return 0;
}
