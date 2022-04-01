import java.util.Scanner;

public class RegularExercise {
    private static final String Password = "^(?!([A-Z]*|[a-z]*|[0-9]*|[!-/:-@\\[-`{-~]*|[A-Za-z]*|[A-Z0-9]*|[A-Z!-/:-@\\[-`{-~]*|[a-z0-9]*|[a-z!-/:-@\\[-`{-~]*|[0-9!-/:-@\\[-`{-~]*)$)[A-Za-z0-9!-/:-@\\[-`{-~]{8,20}$";
    private static final String identification_number = "(^[1-9]\\d{5}(18|19|20)\\d{2}((0[1-9])|(10|11|12))(([0-2][1-9])|10|20|30|31)\\d{3}[0-9Xx]$)|" +
            "(^[1-9]\\d{5}\\d{2}((0[1-9])|(10|11|12))(([0-2][1-9])|10|20|30|31)\\d{3}$)";
    private static final String Email = "\\w+@\\w+[.]\\w+";
    boolean is_Complex_Password(String text){
        return text.matches(Password);
    }

    boolean is_Complex_identification_number(String text){
        return text.matches(identification_number);
    }

    boolean is_Complex_Email(String text){
        return text.matches(Email);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        RegularExercise R = new RegularExercise();
        String text = "Li010209@";
        System.out.println(R.is_Complex_Password(text));
        text = "142225200102095037";
        System.out.println(R.is_Complex_identification_number(text));
        text = "lichunyang@163.com";
        System.out.println(R.is_Complex_Email(text));
        while (true) {
            System.out.println("***************************");
            System.out.println("请选择判断类型：");
            System.out.println("[0]退出");
            System.out.println("[1]判断密码是否复杂");
            System.out.println("[2]判断身份证号码规范");
            System.out.println("[3]判断电子邮件规范");
            int op = scan.nextInt();
            String str = "";
            switch (op) {
                case 0 :
                    System.out.println("感谢使用");
                    System.exit(0);

                case 1 :
                    System.out.println("请输入密码：");
                    str = scan.next();
                    System.out.println(R.is_Complex_Password(str));
                    break;

                case 2 :
                    System.out.println("请输入身份证：");
                    str = scan.next();
                    System.out.println(R.is_Complex_identification_number(str));
                    break;

                case 3 :
                    System.out.println("请输入电子邮件：");
                    str = scan.next();
                    System.out.println(R.is_Complex_Email(str));
                    break;


            }
        }
    }

}
