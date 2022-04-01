package Animal;
import java.util.Scanner;

public class Console {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("*****************欢迎来到lowly-li的动物园!*****************");
        while (true) {
            System.out.println("请选择你的操作：\t[0]退出\t[1]添加动物\t[2]查看全部动物");
            int option = scan.nextInt();
            if(option == 0){
                System.out.println("欢迎下次光临动物园");
                break;
            }
            else if(option == 1){
                //循环添加：
                while (true){
                    System.out.println("********************************************************");
                    System.out.println("请选择添加的动物：\t[0]结束添加\t[1]熊\t[2]狮子\t[3]老虎\t[4]猴子\t[5]长颈鹿");
                    int animal_index = scan.nextInt();
                    if (animal_index == 0){
                        break;
                    }
                    Animal animal = AnimalFactory.get_name(animal_index);
                    if(animal != null){
                        System.out.println(animal.get_animal());
                        System.out.println(animal.get_number());
                    }
                    else{
                        System.out.println("其他动物还未引进，请重新输入");
                    }
                }
            }
            else if(option == 2){
                Animal animal = new Animal();
                System.out.println("动物园的动物有：");
                System.out.println(animal.get_all_animal());
                animal.get_all_number();
            }
            else {
                System.out.println("输入错误，请重新输入");
            }
            System.out.println();
            System.out.println("********************************************************");
        }
        scan.close();
    }
}
