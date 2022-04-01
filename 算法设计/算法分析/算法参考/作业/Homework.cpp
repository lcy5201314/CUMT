/*问题 D: Homework
题目描述
临近开学了，大家都忙着收拾行李准 备返校，但 I_Love_C 却不为此担心!因为他的心思全在暑假作业上：目前为止还未开动。

暑假作业是很多张试卷，我们这些从试卷里爬出来的人都知道，卷子上的题目有选择题、填空题、简答题、证明题等。而做选择题的
好处就在于工作量很少，但又因为选择题题目都普遍很长。如果有 5 张试卷，其中 4张是选择题，最后一张是填空题，很明显做
最后一张所花的时间要比前 4张长很多。但如果你只做了选择题，虽然工作量很少，但表面上看起来也已经做了4/5的作业了。

I_Love_C决定就用这样的方法来蒙混过关，他统计出了做完每一张试卷所需的时间以及它做完后能得到的价值（按上面的原理，
选择题越多价值当然就越高咯）。

现在就请你帮他安排一下，用他仅剩的一点时间来做最有价值的作业。

输入
测试数据包括多组。每组测试数据以两个整数 M,N(1<M<20,1<N<10000)开头，分别表示试卷的数目和 I_Love_C 剩下的时间。
接下来有 M 行，每行包括两个整数 T,V(1<T<N,1<V<10000)分别表示做完这张试卷所需的时间以及做完后能得到的价值，
输入以 0 0 结束。

输出
对应每组测试数据输出 I_Love_C 能获得的最大价值。保留小数点 2 位

提示：float 的精度可能不够，你应该使用 double 类型。

样例输入
4 20
4 10
5 22
10 3
1 2
0 0
样例输出
37.00
题意
就是背包问题。

思路
Greedy。先将所有按性价比（即v[i]/w[i]）排序，则每次选取性价比最高的，直到容量装满。

代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 20;
struct Hw
{
    double w,v;
    bool operator < (const Hw &c)const
    {
        return v/w > c.v/c.w;//如果该物体性价比大于背包此时的性价比，则装入该物体，即装入该物体能增加背包的性价比 
    }
}hw[maxn];//将每张试卷的性价比记录在一个结构体内 
int main()
{
    int n,c;//n为物品个数，c为背包容量 
    while(cin>>n>>c)
    {
        if(!n && !c) break;
        for(int i = 0; i < n; i++)
        {
        	cin>>hw[i].w>>hw[i].v;//输入每个物品的重量及价值 
        }
        sort(hw,hw+n);//将试卷性价比从小到大排序 
        double cur = double(c);//cur=背包容量 
        double ans = 0;//ans=背包价值 
        for(int i = 0; i < n; i++)
        {
            if(cur >= hw[i].w)  //背包容量大于物体重量，可以装下 
            {
                cur -= hw[i].w;  //背包容量减去该物品重量 
                ans += hw[i].v;  // 背包价值加上该物品价值 
            }
            else                //装不下 
            {
                ans += cur/hw[i].w*hw[i].v; 
               
                break;
            }
        }
        printf("%.2f",ans);
    }
    return 0;
}
