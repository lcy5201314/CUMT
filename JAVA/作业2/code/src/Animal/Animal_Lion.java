package Animal;

public class Animal_Lion extends Animal{
    @Override
    public String get_animal(){
        return "这是一只狮子";
    }

    @Override
    public String get_number(){
        lion++;
        return "狮子的数量:"+ lion;
    }
}
