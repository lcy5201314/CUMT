package Animal;

public class Animal {
    static int bear=0,lion=0,tiger=0,monkey=0,giraffe=0;

    String get_animal(){
        return null;
    }
    String get_number(){
        return null;
    }

    String get_all_animal(){
        String names = "";
        if(bear > 0){
            names = names + "熊,";
        }
        if(lion > 0){
            names = names + "狮子,";
        }
        if(tiger > 0){
            names = names + "老虎,";
        }
        if(monkey > 0){
            names = names + "猴子,";
        }
        if(giraffe > 0){
            names = names + "长颈鹿,";
        }
        return names;
    }

    void get_all_number(){
        System.out.println("动物园的动物及其数量有：");
        System.out.println("熊的数量:"+ bear);
        System.out.println("狮子的数量:"+ lion);
        System.out.println("老虎的数量:"+ tiger);
        System.out.println("猴子的数量:"+ monkey);
        System.out.println("长颈鹿的数量:"+ giraffe);
    }
}
