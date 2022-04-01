/*问题 A: 判断字符串是否是手机号码
题目描述
手机号码是一串数字，长度为 11 位，并且第一位必须是 1，现在给出一个字符串，我们需要判断这个字符串是否符合手机格式。
输入
多组测试数据。每组数据输入一个字符串。
输出
若该字符串符合手机号码格式，输出 1，否则输出 0。
样例输入
12345612345
样例输出
1
题意
Water，输入一个字符串，判断字符串是不是一个手机号码。
思路
（可封装在一个返回 bool 的 check() 函数中）考虑三个方面：
是不是 11 位；
首位是不是为 “1”；
每位是不是数字。
代码*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool check(char str[])
{
    if(strlen(str) != 11) return false;
    if(str[0] != '1') return false;
    for(int i = 0; i < 11; i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
int main()
{
    char str[999999];
    while(~scanf("%s",str))
    {
        if(check(str)) puts("1");
        else puts("0");
    }
    return 0;
}
