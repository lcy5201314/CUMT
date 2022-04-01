//public class first {
//    public static void main(String[] args) {
//        int[] nums = new int[10000];
//        int sum = 0;
//        int i = 1;
//        nums[1] = 1;
//        while (sum < 10000){
//            sum += nums[i];
//            i++;
//            nums[i] = nums[i-1]*i;
//        }
//        System.out.print("累加之和:" + sum+ "\nn的值:" + (i-1));
//    }
//}


//import java.util.Scanner;
//public class first {
//    public static void main(String[] args) {
//        Scanner scanr = new Scanner(System.in);
//        System.out.println( "输入一个字符：" );
//        char str = scanr.next().charAt(0);
//        String ans;
//        if(str >= '0' && str <= '9'){
//            ans = "数字";
//        }
//        else if((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')){
//            ans = "西文字母";
//        }
//        else{
//            ans = "其他的字符";
//        }
//        System.out.print("你输入的是：:" + ans );
//    }
//}

//
//import java.util.Scanner;
//public class first {
//    private static int gac(int a, int b) {
//        if(a<b){
//            swap(a,b);
//        }
//        while(b!=0){
//            int c = a%b;
//            a=b;
//            b=c;
//        }
//        return a;
//    }
//    private static void swap(int a, int b) {
//        a=a^b;
//        b=a^b;
//        a=a^b;
//    }
//    public static void main(String[] args) {
//        Scanner scan = new Scanner(System.in);
//        System.out.println( "输入两个正整数：" );
//        int num1 = scan.nextInt();
//        int num2 = scan.nextInt();
//        int ans = gac(num1,num2);
//        System.out.print("两个正整数的最大公约数:" + ans );
//    }
//}


import java.util.Scanner;
public class first {
    public static void main(String[] args) {
        int ans = 1000;
        for (ans = 1000; ans <= 1100; ans++){
            if((ans % 3 == 2) && (ans % 5 == 3)  && (ans % 7 == 2)){
                break;
            }
        }
        System.out.print("假设一个数在1000到1100之间，那除以3结果余2,；除以5结果余3,；除以7结果余2（中国剩余定理），此数为:" + ans );
    }
}


//import java.util.Scanner;
//public class first {
//    public static void main(String[] args) {
//        double h = 100.00 / 2;
//        double sum = 100;
//        for (int i = 2; i <= 10; i++){
//            sum += 2 * h;
//            h /= 2;
//        }
//        System.out.println("第10次触地时经历的总路程:" + sum);
//        System.out.println("第10次触地时经历的反弹高度:" + h);
//    }
//}
