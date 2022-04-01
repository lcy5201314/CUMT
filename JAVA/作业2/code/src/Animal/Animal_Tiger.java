package Animal;

public class Animal_Tiger extends Animal {
    @Override
    public String get_animal(){
        return "这是一只老虎";
    }

    @Override
    public String get_number(){
        tiger++;
        return "老虎的数量:"+ tiger;
    }
}
