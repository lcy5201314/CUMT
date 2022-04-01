// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*1、实现霍夫曼编、解码
  （1）输入一系列字符及其出现频率并以此构造霍夫曼树进行编码并输出码表，另输入一段文字，对其进行霍夫曼编码。例：CASTCASTSATATATASA
  （2）在1中已构成的霍夫曼树的基础上，输入一段01编码，要求输出其解码的原文。例：111011001110110011001001001001100
*/

/*
CASTCASTSATATATASA
111011001110110011001001001001100

*/
/*
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
const  int DefaultSize = 20;
struct HuffmanNode {
    int count;
    char data;
    HuffmanNode* leftChild, * rightChild;
    HuffmanNode(char d = '`', int p = 0, HuffmanNode* left = NULL, HuffmanNode* right = NULL)
        :count(p), data(d), leftChild(left), rightChild(right) {}
};

bool cmp(HuffmanNode* a, HuffmanNode* b) {
    return a->count > b->count;
}

class HuffmanTree {
public:
    ~HuffmanTree() { destroy(root); }
    HuffmanNode* root;
    map<char, string> code;
    string s1;
    HuffmanTree(string s) {
        s1 = s;
        int size = 0;
        HuffmanNode* w[100];
        for (int i = 0; i < s.length(); i++) {
            int j = 0, flag = 1;
            for (; j < size; j++) {
                if (w[j]->data == s[i]) {
                    flag = 0;
                    w[j]->count++;
                    break;
                }
            }
            if (flag) {
                w[j] = new HuffmanNode;
                w[j]->data = s[i];
                w[j]->count++;
                size++;
            }
        }
        for (int i = 0; i < size - 1; i++) {
            sort(w, w + size - i, cmp);
            w[size - i - 2] = new HuffmanNode('`', w[size - i - 1]->count + w[size - i - 2]->count, w[size - i - 1], w[size - i - 2]);
        }
        root = w[0];
    }
    void destroy(HuffmanNode*& subTree) {
        if (subTree != NULL) {
            destroy(subTree->leftChild);
            destroy(subTree->rightChild);
            delete subTree;
        }
    }
    void output() {
        makecode(root, "");
    }
    void makecode(HuffmanNode* subtree, string s) {
        if (subtree->data != '`') {
            code[subtree->data] = s;
            cout << subtree->data << " " << s << endl;
            return;
        }
        makecode(subtree->leftChild, s + "0");
        makecode(subtree->rightChild, s + "1");
    }
    void decode(string s) {
        string ans = "";
        for (int i = 0; i < s.length();) {
            HuffmanNode* now = root;
            while (now->data == '`') {
                if (s[i] == '0') {
                    now = now->leftChild;
                }
                else {
                    now = now->rightChild;
                }
                i++;
            }
            ans += now->data;
        }
        cout << ans;
    }
    string tocode() {
        string ans = "";
        for (int i = 0; i < s1.length(); i++) {
            ans += code[s1[i]];
        }
        return ans;
    }
};


int main() 
{
    string s;
    cout << "请输入霍夫曼树构建字符" << endl;
    cin >> s;
    HuffmanTree a(s);
    cout << "字符及其编码如下" << endl;
    a.output();
    cout << "霍夫曼编码如下：" << endl;
    cout << a.tocode() << endl;
    cout << "请输入需要解码的字符：" << endl;
    cin >> s;
    cout << "解码结果如下：" << endl;
    a.decode(s);
    return 0;
}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调


#include <iostream>
using namespace std;
const int maxn = 1005;
int n, m, s, t;
int inf = 0xffffff;
int book[maxn], dist[maxn], pre[maxn];
int e[maxn][maxn];
void TraceBack(int pre[], int n)
{
    if (n == s)
    {
        cout << n << " ";
    }
    else
    {
        TraceBack(pre, pre[n]);	//递归输出点n前一个点的最短路径
        cout << n << " ";		//输出点n
    }
}
int main()
{
    int u;
    //n个顶点，m条边
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                e[i][j] = 1;
            }
            else
            {
                e[i][j] = inf;
            }
        }
    }
    //读入初始边
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = c; //a->b 距离为c
    }
    //初始化dis数组和pre数组
    for (int i = 1; i <= n; i++)
    {
        dist[i] = e[s][i];
        if (dist[i] != inf)
        {
            pre[i] = s;
        }
    }
    //设起点前面的点为0
    pre[s] = 0;
    //初始化book数组
    for (int i = 1; i <= n; i++)
    {
        book[i] = 0;
    }
    //将起点加入S集合中
    book[s] = 1;

    //Dijkstra
    for (int i = 1; i <= n; i++)
    {
        
        int min = inf;
        for (int j = 1; j <= n; j++)
        {
            if (book[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        book[u] = 1;
        for (int k = 1; k <= n; k++)
        {
            if (e[u][k] < inf)
            {
                if (dist[k] > dist[u] + e[u][k])
                {
                    dist[k] = dist[u] + e[u][k];
                    pre[k] = u;
                }
            }
        }
    }
    if (dist[t] < inf)
    {
        cout << dist[t] << endl;
        TraceBack(pre, t);
    }
    else
    {
        cout << "can't arrive" << endl;
    }
    return 0;
}

