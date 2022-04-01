/*给定长度为n的字符串S（1<=n<=2000,S中只有大写字母）作为明文，要求构造一个字符串T作为密文，起初T是一个空串，之后反复执行
以下任意操作
1.从S的头部删除一个字符，加入到T的尾部
2.从S的尾部删除一个字符，加入到T的尾部
最后S会变成空串，T会变成一个长度为n的字符串作为密文。当然并非所有的构造方案都是符合条件的，我们要求构造出的密文T的字典
序尽可能小，你能找出这个字典序最小的密文吗？
输入
输入包含多组数据，每组数据占两行，第一行为一个整数n（1<=n<=2000）代表字符串S的长度，第二行为一个长度为n的字符串S代表
明文，保证S中只有大写字母
输出
对每组数据，输出一行字符串，代表构造出的字典序最小的密文T
样例输入
6
ACDBCB
样例输出
ABCBCD*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    char s[2005];
    while(cin>>n)
    {
        cin>>s;
        int i = 0,j = n-1;//i为头，j为尾 
        while(i <= j)
        {
            bool flag = false;
            for(int k = 0; i+k < j-k; k++)//从第一位到中间进行比较，如果头尾相同继续比较，如果不同则跳出 
            {
                if(s[i+k] < s[j-k])//如果头小置为true 
                {
                    flag = true; 
                    break;
                }
                if(s[i+k] > s[j-k]) 
                {
                	break;//否则继续为false 
				}
            }           
            if(flag) 
            {
				cout<<s[i++];//正序输出 
			}
            else 
            {            
            	cout<<s[j--];//逆序输出 	
			}  
			        
        }
       cout<<endl;
    }
    return 0;
}
