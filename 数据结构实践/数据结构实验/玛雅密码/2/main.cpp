#include<iostream>
#include<queue>
#include<map>
using namespace std;

bool check(string str){
	if(str.find("2012")==string::npos){
		return false;
	}
	return true;
}

int main(){
	int n;
	string str;
	while(cin >> n>>str){
		if(n<4){
			cout<<-1<<endl;
			continue;
		}else if(check(str)){
			cout<<0<<endl;
			continue;
		}
		int ans=-1;
		map<string,int> m;
		m[str]=0;//初始
		queue<string> q;
		q.push(str);
		while(!q.empty()){
			string newStr=q.front();
			q.pop();
			if(check(newStr)){
				//如果 还有2020，就记录
				ans=m[newStr];
				break;
			}
			for(int i=1;i<n;i++){
				string s=newStr;
				char tmp=s[i-1];
				s[i-1]=s[i];
				s[i]=tmp;
				if(m.find(s)!=m.end()) continue;//如果之前遍历过了，就不再便利了 
				m[s]=m[newStr]+1;
				q.push(s); 
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}
