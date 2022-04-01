package Animal;

public class Animal_Monkey extends Animal {
    @Override
    public String get_animal(){
        return "这是一只猴子";
    }

    @Override
    public String get_number(){
        monkey++;
        return "猴子的数量:"+ monkey;
    }
}
