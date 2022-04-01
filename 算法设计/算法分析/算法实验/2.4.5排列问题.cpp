/*题目描述
输入一个可能含有重复字符的字符串，打印出该字符串中所有字符的全排列。

输入
单组测试数据，输入数据是一个长度不超过10个字符的字符串，以逗号结尾。

输出
打印出该字符串中所有字符的全排列。以字典序顺序输出，用空格分隔。

样例输入
abc,
样例输出
abc acb bac bca cab cba*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[10];
	cin>>str;
	int len=strlen(str)-1;   //字母个数 
	str[len]=' ';            //空格分隔 
	sort(str,str+len);        //进行排列 
    cout<<str;
	while(next_permutation(str,str+len))	//next_permutation函数将按字母表顺序生成给定序列的下一个较大的排列，直到整个序列为降序为止
	{
		cout<<" "<<str;
	}
	cout<<endl;
	return 0;
}
