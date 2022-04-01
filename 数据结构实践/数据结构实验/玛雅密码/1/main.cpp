#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

queue <string> Q;    //����BFS��
map <string, int> M;    //����������ÿ���ַ�����Ӧ��ֵ��Ҳ�����ַ����ĸ߶ȼ�һ

string Swap(string s, int i){    //�����ַ����ĵ� i λ�͵� i + 1 λ 
        char temp;
        temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
        return s;
}

int BFS(string str){
    string newStr;
    M.clear();    //���map
    while(!Q.empty()) Q.pop();    //��ն���
    Q.push(str);
    M[str]=0;
    while(!Q.empty()){
        str=Q.front();
        Q.pop();    //ȡ�����ף�����str
        for(int i=0; i<(int)str.length()-1; i++){    //str.length() ���޷����� 
            newStr=Swap(str, i);    //���ַ�����str����iλ��i+1λ�õ�
            if(M.find(newStr)==M.end()){    //�������ַ���û���ֹ�
                M[newStr]=M[str]+1;    //���ڳ��ֹ��ˣ��ҽ���������������һ��� 1 
                if(newStr.find("2012", 0)!=string::npos)    //�ҵ��� 2012 
                    return M[newStr];
                else 
                    Q.push(newStr);    //����Ҫ���Ǽ��� bfs�������������
            }
        }
    }
    return -1;    //������ɣ�û���ַ���Ҫ����ַ���������-1
}

int main(){
    int n;
    string str;
    while(cin >> n){
        cin >> str;
        if(n < 4)    //��ʱ�϶�������Ҫ�� 
            cout << -1 << endl;
        else{
            if(str.find("2012") != string::npos)
                cout << 0;    //�жϳ�ʼ�ַ�����û�� 2012 
            else
                cout << BFS(str) << endl;
        }
            
    }
    return 0;
}
