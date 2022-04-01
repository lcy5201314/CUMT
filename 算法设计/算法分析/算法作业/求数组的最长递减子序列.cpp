#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;


int dp[maxn],last[maxn];
int main()
{
    int n,a[maxn],ans = 0,ansp = 1,ansa[maxn];
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) 
        scanf("%d",&a[i]);
    dp[1] = 1;
    last[1] = -1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        last[i] = -1;
        for(int j = 1; j < i; j++)
        {
            if(a[j] > a[i] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
                last[i] = j;
            }
        }
    }
    //找到最大的
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] > ans)
        {
            ans = dp[i];
            ansp = i;
        }
    }
    
    int j = ansp;
    for(int i = ans; ; i--)
    {
        ansa[i] = a[j];
        if(last[j] == -1) break;
        j = last[j];
    }
    for(int i = 1; i <= ans; i++) 
        printf("%d ",ansa[i]);
    return 0;
}




















 public class LDSProblem {
   2:     public static void maxSubstrDecrease(int[] array) {
   3:         // 数组array中的前i个元素中，最长递减子序列的长度是LDS[i]
   4:         int len = array.length;
   5:         int[] LDS = new int[len];
   6:         int max = 0;
   7:         for (int i = 0; i < len; i++) {
   8:             LDS[i] = 1;
   9:             for (int k = 0; k < i; k++) {
  10:                 // LDS[i+1]=max{1,LDS[k]+1}, array[i+1]<array[k],for any k<=i;
  11:                 if (array[i] < array[k] && LDS[k] + 1 > LDS[i]) {
  12:                     LDS[i] = LDS[k] + 1;
  13:                 }
  14:             }
  15:         }
  16:         max = maxsub(LDS);
  17:         System.out.println("最长递减子序列的长度为:" + max);
  18:         System.out.println("LDS数组为:");
  19:         print(LDS);
  20:         System.out.print("最长递减子序列为:\n");
  21:         print(array, LDS, max, len - 1);
  22:     }
  23:  
  24:     // max:最长子序列长度
  25:     // end:最长递减子序列中的最后一个元素
  26:     // lds:数组array中的前i个元素中，最长递减子序列的长度数组
  27:     private static void print(int[] array, int[] lds, int max, int end) {
  28:         if (max == 0)
  29:             return;
  30:         int i = end;
  31:         while (lds[i] != max)
  32:             i--;
  33:         print(array, lds, max - 1, i - 1);
  34:         System.out.print(array[i] + " ");
  35:     }
  36:  
  53:     public static void main(String[] args) {
  54:         int[] array = new int[] { 9, 4, 3, 2, 5, 4, 3, 2 };
  55:         /*        System.out.println("数组为:");
  56:          print(array);*/
  57:         maxSubstrDecrease(array);
  58:     }
  59: }