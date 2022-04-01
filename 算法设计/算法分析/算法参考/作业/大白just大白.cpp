/*问题 I: 大白just大白
题目描述
大家都知道，大白对学术要求是很严格的。抄作业、考试作弊神马的在大白这简直不能忍。

这不刚刚过去的期末考试。有n个学生被查出来有问题。

大白给了他们申辩的机会，每个学生可以提交一段文字，作为申辩理由。但是大白发现来的人总会有一些奇怪的理由。

大白提前列了m个常见借口关键字。他想看看来申辩的学生中最烂的申辩理由是什么。

所谓最烂申辩理由就是，申辩里，含有常见借口关键字最多的。

含有关键字，指的是，理由中出现了一串和关键字完全匹配的字符串，如果出现大写小写不同，也认为匹配。比如，关键字是 bed 
理由中出现Bedroom算含有一个关键字。

输入
一个输入可能有多个case，每个case第一行两个数。分别代表n 和 m

接下来m行，每行一个关键字（字符串）

再接下来n行字符串。m和n都不大于20

每一个借口和借口关键字只会包含大小写字母，长度不会超过4000个字符。

输出
对于每个case输出一行字符串，表示最烂的理由。若有多个理由包含相同数目的关键字，按输入顺序输出靠前的那个。

样例输入
2 3
love
cumt
ACM
ILoveCUMTACM
cumtAACM
2 2
A
b
Ab
bA
样例输出
ILoveCUMTACM
Ab
题意
m个关键词，n个借口，找出包含（子串）关键词种类最多的借口。（0<=n,m<=20,关键词、借口长度L<=4e4），注意不区分大小写。

思路
可以把主串和模式串都转成全大写（或全小写）。

注意，由于要输出原来的串，故所有主串都要保存原稿。

实现可用string类下的find()函数。

代码*/
#include<iostream>
#include<string>
using namespace std;
const int MAXN = 21;
int main()
{
    int n,m,i,j;
    string text[MAXN],pattern[MAXN];
    string texx[MAXN],patterr[MAXN];
    while(~scanf("%d %d",&n,&m))
    {
        for(i = 0; i < m; i++)
        {
            cin>>pattern[i];
            patterr[i] = pattern[i];
            for(j = 0; patterr[i][j] != '\0'; j++)
            {
                if(islower(patterr[i][j])) patterr[i][j] = patterr[i][j]+'A'-'a';
            }
            //cout<<patterr[i]<<endl;
        }
        for(i = 0; i < n; i++)
        {
            cin>>text[i];
            texx[i] = text[i];
            for(j = 0; texx[i][j] != '\0'; j++)
            {
                if(islower(texx[i][j])) toupper(texx[i][j]);
            }
            //cout<<texx[i]<<endl;
        }
        int maxx = -1,maxt = -1,cur;
        for(i = 0; i < n; i++)
        {
            cur = 0;
            for(j = 0; j < m; j++)
            {
                string::size_type idx = texx[i].find(patterr[j]);
                if(idx != string::npos) cur++;
            }
            if(cur > maxx)
            {
                maxx = cur;
                maxt = i;
            }
        }
        cout<<text[maxt]<<endl;
    }
    return 0;
}
