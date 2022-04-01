#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

queue <string> Q;    //用于BFS树
map <string, int> M;    //用来存树的每层字符串对应的值，也就是字符串的高度减一

string Swap(string s, int i){    //交换字符串的第 i 位和第 i + 1 位 
        char temp;
        temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
        return s;
}

int BFS(string str){
    string newStr;
    M.clear();    //清空map
    while(!Q.empty()) Q.pop();    //清空队列
    Q.push(str);
    M[str]=0;
    while(!Q.empty()){
        str=Q.front();
        Q.pop();    //取出队首，存入str
        for(int i=0; i<(int)str.length()-1; i++){    //str.length() 是无符号数 
            newStr=Swap(str, i);    //新字符串由str交换i位和i+1位得到
            if(M.find(newStr)==M.end()){    //如果这个字符串没出现过
                M[newStr]=M[str]+1;    //现在出现过了，且交换次数比它的上一层多 1 
                if(newStr.find("2012", 0)!=string::npos)    //找到了 2012 
                    return M[newStr];
                else 
                    Q.push(newStr);    //不合要求，那继续 bfs，把它加入队列
            }
        }
    }
    return -1;    //遍历完成，没发现符合要求的字符串，返回-1
}

int main(){
    int n;
    string str;
    while(cin >> n){
        cin >> str;
        if(n < 4)    //此时肯定不符合要求 
            cout << -1 << endl;
        else{
            if(str.find("2012") != string::npos)
                cout << 0;    //判断初始字符串有没有 2012 
            else
                cout << BFS(str) << endl;
        }
            
    }
    return 0;
}
