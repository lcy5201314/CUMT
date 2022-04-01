#include <iostream>
#include <string>
#include <bits/stdc++
 using namespace std;
 int test(string s)
 {
      char a = s[0];
      int locate = s.find(a, 1);//�ҵ���ͬ���ֵĳ��� 
      while(locate > 0)
      {
        bool flag = false;
         int len = s.length();
         int times =  len/ locate;
         if (len % locate == 0)
         {
             flag = true;
             for (int i = locate;i < len&&flag==true;i += locate)
             {
                 for (int j = 0;j <= locate - 1;j++)
                 {
                     if (s[j] != s[i + j])
                     {
                         flag = false;
                         break;
                     }
                 }
  
             }
              
         }    
         if(flag)
             return times;    
         else
             locate = s.find(a, locate + 1);
     }
     return 1;
 }
  
 int main()
 {
     string s;
     while (cin >> s && s != ".")
     {
         cout << test(s) << endl;
     }
     return 0;
 }

